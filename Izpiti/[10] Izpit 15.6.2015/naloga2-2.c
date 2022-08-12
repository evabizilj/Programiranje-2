#include <stdio.h>
#include <stdlib.h>

int ustvariStevilo(int zacetek, int konec, char *stevilo);
int maxVrednost = 0;
	
int main()
{
	char *tabelaStevil = (char*) malloc(1 * sizeof(char));
	char stevilo;
	int stevec = 1;

	while (scanf("%c", &stevilo) != EOF)
	{
		tabelaStevil[stevec - 1] = stevilo;
		stevec++;
		tabelaStevil = realloc(tabelaStevil, stevec * sizeof(char));
	}
	stevec--;
		
	for (int i = 0; i <= stevec - 2; i++)
	{
		int levaStran = ustvariStevilo(0, i, tabelaStevil);
		for (int j = i + 1; j <= stevec - 2; j++)
		{
			int sredina = ustvariStevilo(i + 1, j, tabelaStevil);
			int desnaStran = 0;
			if (j < stevec - 1) 
				desnaStran = ustvariStevilo(j + 1, stevec - 1, tabelaStevil);
			int vsota = levaStran + sredina - desnaStran;
			int minus = levaStran - sredina + desnaStran;
					
			if (vsota > maxVrednost) 
				maxVrednost = vsota;
			if (minus > maxVrednost) 
				maxVrednost = minus;
		}
	}
	printf("%d\n", maxVrednost);
	free(tabelaStevil);
	return 0;
}
	
int ustvariStevilo(int zacetek, int konec, char *stevilo)
{
	char *tabela = (char*) malloc(sizeof(char));
	int i = 0, j = 1;
	for (i = zacetek; i <= konec; i++)
	{
		tabela[j - 1] = stevilo[i];
		j++;
		tabela = realloc(tabela, sizeof(char) * j);
	}
	int vrni;
	sscanf(tabela, "%d", &vrni);
	return vrni;
}