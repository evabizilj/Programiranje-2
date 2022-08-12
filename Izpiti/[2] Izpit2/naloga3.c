#include <stdio.h>

typedef struct _Oseba
{
	char* ip; // ime in priimek, npr. Jože Gorišek
	int stOtrok; // število otrok
	struct _Oseba** otroci; // kazalec na prvi element tabele kazalcev na otroke; // NULL, če oseba nima otrok
} Oseba;

// izpiše imena in priimke vseh otrok podane osebe, nato imena in priimke vseh njenih vnukov, nato imena in priimke vseh njenih pravnukov ...
// vsak par imena in priimka naj bo zapisan v svoji vrstici.

// izpise naslednike, ki je na doloceni globini, npr. 0 za svoje otroke
int izpisiNaslednike(Oseba* oseba, int globina)
{
    if (globina == 0)
    {
        for (int i = 0; i < oseba->stOtrok; i++)
            printf("%s\n", oseba->otroci[i]->ip);
        return 1;
    }
    else
    {
        if (oseba->stOtrok == 0)
            return 0;
        int globlje = 0;
        for (int i = 0; i < oseba->stOtrok; i++)
            globlje += izpisiNaslednike(oseba->otroci[i], globina - 1);
        return globlje;
    }
}

void nasledniki(Oseba* oseba)
{
    int globina = 0;
    while (izpisiNaslednike(oseba, globina + 1));

}

void naslednikiR(Oseba* oseba, int globina)
{
	for (int i = 0; i < oseba->stOtrok; i++)
        for (int j = 0; j < globina; j++)
        {
            printf("  ");
			printf("%s\n", oseba->otroci[i]->ip);
			naslednikiR(oseba->otroci[i], globina + 1);
		}
}


// Testiranje
Oseba o1 = {"pravnuk 2212332", 0, NULL};
Oseba o2 = {"pravnuk 12323", 0, NULL};
Oseba *otroci0[2] = {&o1, &o2};
Oseba o3 = {"vnuk 3213", 2, otroci0};

Oseba o4 = {"pravnuk 12", 0, NULL};
Oseba *otroci1[1] = {&o4};
Oseba o5 = {"vnuk 7", 1, otroci1};

Oseba *otroci2[2] = {&o5, &o3};
Oseba o9 = {"otrok 3", 2, otroci2};

Oseba o6 = {"vnuk 4", 0, NULL};
Oseba o7 = {"vnuk 5", 0, NULL};
Oseba o8 = {"vnuk 6", 0, NULL};
Oseba *otroci3[3] = {&o6, &o7, &o8};
Oseba o10 = {"otrok 2", 3, otroci3};

Oseba o11 = {"vnuk 1", 0, NULL};
Oseba o12 = {"vnuk 2", 0, NULL};
Oseba o13 = {"vnuk 3", 0, NULL};
Oseba *otroci4[3] = {&o11, &o12, &o13};
Oseba o14 = {"otrok 1", 3, otroci4};

Oseba *otroci5[3] = {&o14, &o9, &o10};
Oseba o15 = {"glavna", 3, otroci5};

int main()
{	
	nasledniki(&o15);
	printf("\n");
	naslednikiR(&o15, 0);
	return 0;
}
