void kodiraj(char* niz, char* koda)
{
    int j = 0;
    char stevilo[6];
    for (int i = 0; i < strlen(niz); i++)
    {
        koda[j++] = niz[i];
        sprintf(stevilo, "%d", i + 1);
        for (int k = 0; k < strlen(stevilo); k++)
            koda[j++] = stevilo[k];
    }
    koda[j] = '\0';
}