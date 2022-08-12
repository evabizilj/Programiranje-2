#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*
Napišite program, ki v podano izhodno datoteko po vrsti izpiše dvomestne šestnajstiške 
kode posameznih bajtov podane vhodne datoteke. Vsaka koda naj se izpiše v svojo vrstico.
*/

int main(int argc, char** argv)
{
	char* entry = malloc(sizeof(char)*21);
	char* exit = malloc(sizeof(char)*21);
	int n; // število bajtov v vhodni datoteki
	scanf("%s", entry);
	scanf("%d", &n);
	scanf("%s", exit);

	FILE* vhod = fopen(entry, "rb");
	FILE* izhod = fopen(exit, "wb");

	unsigned char* crke = (unsigned char*) malloc(sizeof(char) * n);

	for (int i = 0; i < n; i++)
		fread(crke, sizeof(unsigned char), n, vhod);

	for (int i = 0; i < n; i++)
		printf("%02X\n", crke[i]);

	fclose(vhod);
	fclose(izhod);
	return 0;
}




