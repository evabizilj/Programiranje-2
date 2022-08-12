
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga.h"

int poisciStudenta(Student** studentje, int stStudentov, int vpisna) {
    for (int i = 0; i < stStudentov; i++)
    {
        if (student[i]->vpisna == vpisna)
            return i;
    }
    return -1;
}

int poisciPO(Student* student, char* predmet) {
    for (int i = 0; student->stPO; i++)
        if (strcmp(student->po[i].predmet, predmet))

    return 42;
}

int dodaj(Student** studentje, int stStudentov, int vpisna, char* predmet, int ocena) {
    
    // ali obstaja student
    indexStudenta = poisciStudenta(studentje, stStudentov, vpisna);

    // ustvari študenta
    if (indexStudenta == -1)
    {
        Student* student = createStudent(vpisna, 1);
        student->po = malloc(10 * sizoef(PO));
    }

    return 42;
}

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}
