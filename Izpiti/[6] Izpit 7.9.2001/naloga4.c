/*
Funkcija, ki vstavi element v dvosmerno povezan urejen seznam.
Kazalec na seznam in niz, ki ga vstavljamo. sta podana kot argumenta funkcije.
Pri vstavljanju novega elementa pazite, da ga vstavite na pravo mesto, saj
so elementi urejeni po abecedi.
*/

struct elem
{
    char niz[256]; // vrednost elementa
    struct elem* naprej: // kazalec na naslednji element
    struct elem* nazaj; // kazalec na predhodni element
};

void dodaj(struct elem** p, char niz[])
{
    struct elem *q, *r;

    q = (struct elem*) malloc(sizeof(struct elem));
    strcpy(q->niz, niz);

    // dodaj na zacetek seznama
    if ((*p == NULL) || (strcmp(niz, (*p)->niz) < 0))
    {
        q->naprej = *p;
        q->nazaj = NULL;
        (*p)->nazaj = q;
        *p = q;
    }
    // poisci ustrezno mesto v seznamu za nov element
    else
    {
        r = *p;
        while ((r->naprej != NULL) && (strcmp(niz, r->naprej->niz) > 0))
            r = r->naprej;
        
        // dodaj za element, na katerega kaze r
        q->naprej = r->naprej;
        r->naprej = q;
        q->nazaj = r;
        if (q->naprej != NULL)
            q->naprej->nazaj = q;
    }
}

