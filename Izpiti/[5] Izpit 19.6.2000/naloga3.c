struct elem
{
    int value; // vrednost elementa
    struct elem* left; // kazalec na levo poddrevo
    struct elem* right; // kazalec na desno poddrevo
};

// prvi argument je kazalec na kazalec na koren drevesa, ker se kazalec na
// koren drevesa v funkciji spremeni

void dodaj(struct elem** koren, int n)
{
    struct elem* novi;
    struct elem* tmp;
    struct elem* oldTmp;

    novi = (struct elem*) malloc(sizeof(struct elem));
    novi->value = n;
    novi->left = NULL;
    novi->right = NULL;
    
    if (*koren == NULL)
    {
        *koren = novi;
        return;
    }

    tmp = *koren;

    while (tmp != NULL)
    {
        oldTmp = tmp;
        if (n < tmp->value)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }

    if (n < oldTmp->value)
        oldTmp->left = novi;
    else
        oldTmp->right = novi:
}

}