#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Strukture uporabimo, kadar želimo združevati spremenljivke, ki so lahko 
tudi različnih tipov. To delamo, če želimo združiti podatke, ki logično sodijo skupaj, kot na 
primer podatki o študentu: ime, priimek, vpisna stevilka ipd.

Pri nalogi bo potrebno kopirati nize.
    - sprehodimo po nizu do '\0' in sproti kopiramo vrednosti iz enega naslova na drugega
    - strcpy() iz knjižnice string.h (man strcpy)

Strukture si lahko predstavljamo podobno kot klasične podatkovne tipe. 

Tabela 5 števil tipa int:
    int tabela[5];
ali
    int* tabela = (int*) malloc(5 * sizeof(int));

Tabela petih 5 tipa Student:
    Student tabela[5];
ali
    Student* tabela = (Student*) malloc(5 * sizeof(Student));

Nastavljanje vpisne številke za prvega študenta v tabeli:
tabela[0].vpisna = 123;
*(tabela).vpisna = 123;
tabela->vpisna = 123;

Imamo tudi strukturo na 2. nivoju: objekt strukture tipa študent kaže še naprej na tabelo oz. drugo strukturo.
Kazalec študent, ki kaže na tabelo (v tabeli imamo kazalce na konkretno strukturo).
Takih struktur smo vajeni iz Jave (tam je bil objekt, ne struktura), vendar v tabeli nismo imeli nikoli konkretnih
objektov - vedno smo imeli kazalce na objekt oz. tabelo.

Tukaj, na 2. nivoju: kazalec na tabelo struktur (v Javi ni možno).

Vse tabele na 2. nivoju so dolge 10.

Hranili bomo tabelo študentov (natančneje tabelo kazalcev na strukturo študent).
Vsak struct student bo imel povezavo na tabelo njegovih predmetov.
Pomembna razlika med prvo in drugo tabelo je, da imamo tukaj tabelo konkretnih structov in ne kazalcev na struct.

Čemu služi poimenovanje pri definiciji strukture _Student in na koncu še Student?
Zadnje poimenovanje služi poimenovanju tipa.
Da lahko pišemo:
Student student, sicer bi morali vedno, kjer bi potrebovali spremenljivko, pisati struct _Student student

V naši nalogi se predvideva, da (za razliko od slike, kjer je na drugem nivoju točno toliko zapisov, 
kot je opravljanj + 1), je tabela opravljanj vedno dolžine npr. 10

Kako dostopamo do elementov struktur?
->: če imamo pointer kot je npr. student[i]
.: če ni pointer

a->b (*a).b
-> nam ni potrebno uporabiti, če dereferenciramo pointer

če imamo na voljo pointer na strukturo, dostopamo do njenih vrednosti z ->
če imamo na voljo strukturo dostopamo z .

export name=naloga
make test
*/

#define MAX_ST_PO 10 // za tabelo predmet ocen

typedef struct _PO { // par predmet-ocena
    char predmet[4]; // enolična oznaka predmeta (koliko je dejansko uporabljenih)
    int ocena; // ocena pri tem predmetu

} PO;

typedef struct _Student { // podatki o študentu
    int vpisna;// vpisna številka
    PO* po; // kazalec na začetek tabele parov predmet-ocena
    int stPO;  // število parov predmet-ocena
} Student;

/*  V tabeli s stStudentov kazalci, na začetek katere kaže kazalec studentje, 
    poišče kazalec na strukturo, ki predstavlja študenta z vpisno številko vpisna. 
    Če takšen kazalec obstaja, naj funkcija vrne njegov indeks v tabeli, sicer pa naj vrne -1.

    @studentje - tabela kazalcev na strukturo <student>
    @stStudentov - dolžina tabele
    @vpisna - vpisna številka študenta, ki ga iščemo

    @return - indeks v tabeli, če obstaja
*/

int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    for (int i = 0; i < stStudentov; i++)
    {
        // (*studentje[i]).vpisna // i-ti element je kazalec na strukturo
        if (studentje[i]->vpisna == vpisna)
            return i;
    }
    return -1;
}

/*
    V tabeli parov predmet-ocena za podanega študenta (kazalec student kaže na strukturo, ki ga predstavlja) 
    poišče par, v katerem je oznaka predmeta enaka predmet. Če takšen par obstaja, naj funkcija vrne njegov indeks v tabeli, sicer pa naj vrne  ́1.

    @student - kazalec na strukturo <student>
    @predmet - niz <ime predmeta>

    @return - indeks na strukturo predmeta v tabeli, če obstaja

*/

int poisciPO(Student* student, char* predmet)
{
    // PO* predmetOcena = student->po;
    for (int i = 0; i < student->stPO; i++)
    {
        if (strcmp(student->po[i].predmet, predmet) == 0)
            return i;
    }
    return -1;
}

// kreira strukturo <Student> in vrne kazalec nanjo
Student *createStudent(int vpisna, int stPO)
{
    Student *student = (Student *) malloc(sizeof(Student));
    student->vpisna = vpisna;
    student->po = NULL; // (PO *) malloc(10 * sizeof(PO));
    student->stPO = stPO; // 1
    return student;
}

/*
    Tabelo s stStudentov kazalci, na začetek katere kaže kazalec studentje, obogati s podatkom, da je študent z vpisno številko vpisna na izpitu pri predmetu z oznako predmet prejel oceno ocena.
    Če študent že ima svojo strukturo, naj jo funkcija posodobi (gl. naslednji odstavek), sicer pa naj ustvari novo strukturo in na konec tabele doda kazalec nanjo (lahko predpostavite, da je tabela dovolj velika). Kazalec po v novoustvarjeni strukturi naj kaže na začetek tabele z desetimi alociranimi pari predmet-ocena. Prvi od njih naj vsebuje podano oznako predmeta in podano oceno, ostalih pa ne inicializirajte.
    Če v tabeli parov predmet-ocena za obstoječega študenta že obstaja par s podano oznako predmeta, naj funkcija v tem paru samo nastavi oceno na podano oceno, sicer pa naj na konec tabele doda nov par s podano oznako predmeta in podano oceno. Lahko predpostavite, da je tabela dovolj velika.
    Funkcija naj vrne novo število elementov v tabeli, na začetek katere kaže kazalec studentje.

    @studentje - tabela kazalcev na strukturo <student>
    @stStudentov - dolžina tabele
    @vpisna - vpisna številka študenta, ki mu vpisujemo oceno
    @predmet - niz <ime predmeta>
    @ocena - dosežena ocena pri predmut
*/

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena)
{
    // 1.: poišči študenta v tabeli, vrni indeks študent
    int ixStudenta = poisciStudenta(studentje, stStudentov, vpisna);

    // 2.1: študenta še ni v seznamu --> kreiraj nov zapis oz. študenta
    if (ixStudenta == -1)
    {
        Student *student = createStudent(vpisna, 1);
        student->po = (PO *) malloc(MAX_ST_PO * sizeof(PO));
        // char *strcpy(char *dest, const char *source)
        strcpy(student->po[0].predmet, predmet);
        student->po[0].ocena = ocena;

        // kaže na prvega praznega
        studentje[stStudentov] = student;
        stStudentov++;   // sedaj imamo enega študenta več
    }

    // 2.2: studenta imamo v evidenci opravljanj izpitov
    else
    {
        Student *student = studentje[ixStudenta];

        // ali je naš študent že opravljal predmet
        int ixPO = poisciPO(student, predmet);

        // ni opravljal predmeta
        if (ixPO == -1)
        {
            // študent prvič opravlja predmet
            // int stPO = student->stPO;
            strcpy(student->po[student->stPO].predmet, predmet);
            student->po[student->stPO].ocena = ocena;
            student->stPO++;
        }

        // že opravljal predmet
        else
        {
            // študent opravlja predmet ponovno, posodobi oceno
            student->po[ixPO].ocena = ocena;
        }
    }
    
    return stStudentov;
}

void izpisi(Student** studentje, int stStudentov) {
    for (int i = 0;  i < stStudentov;  i++) {
        printf("%d: [", studentje[i]->vpisna);
        int stPO = studentje[i]->stPO;
        PO* po = studentje[i]->po;
        for (int j = 0;  j < stPO;  j++) {
            if (j > 0) {
                printf(", ");
            }
            printf("%s/%d", po[j].predmet, po[j].ocena);
        }
        printf("]\n");
    }
    printf("\n");
}

void pocisti(Student** studentje, int stStudentov) {
    for (int i = 0;  i < stStudentov;  i++) {
        free(studentje[i]->po);
        free(studentje[i]);
    }
}

int main()
{
    Student* studentje[10];
    int stStudentov = 0;

    stStudentov = dodaj(studentje, stStudentov, 333, "ARS", 8);
    stStudentov = dodaj(studentje, stStudentov, 333, "ODV", 10);
    stStudentov = dodaj(studentje, stStudentov, 333, "P1", 6);

    izpisi(studentje, stStudentov);
    pocisti(studentje, stStudentov);

    exit(0);
    return 0;
}

/*
Pomembno: 
- Tabela študentov vsebuje kazalce na strukture
- tabela ocen pa vsebuje konkretne strukture tipa PO eno za drugim; takih tabel v javi nismo imeli
*/
