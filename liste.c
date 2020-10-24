#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
    int valore;
    struct lista *next;
};

/* Inserimento in testa */
void inserimento_testa(struct lista **l, int val){
    struct lista *nuovo = malloc(sizeof(struct lista));

    nuovo->valore = val;
    
    nuovo->next = (*l);
    (*l) = nuovo;
}

/* Inserimento in coda */
void inserimento_coda(struct lista **l, int val){
    if(!(*l))
        inserimento_testa(&(*l), val);
    else{
        struct lista *nuovo = malloc(sizeof(struct lista)), *q;
        nuovo->valore = val;
        for(q = (*l); q->next != 0; q = q->next){ ; }
        q->next = nuovo;
        nuovo->next = 0;
    }
}

/* Elimina in testa */
void elimina_testa(struct lista **l){
    if(!(*l))
        return;
    else{
        struct lista *q;

        q = (*l);
        (*l) = q->next;
        
        free(q);
    }
}

/* Elimina in coda */
void elimina_coda(struct lista **l){
    struct lista *q, *p;

    if(!(*l))
        return;
    else{
        for(q = (*l); q->next != 0; q = q->next)
            p = q;

        p->next = q->next;

        free(q);
    }
}

/* Elimina lista */
void elimina_lista(struct lista **l){
    while((*l))
        elimina_testa(&(*l));
}

/* Elimina elemento val */
void elimina_elemento(struct lista **l, int val){
    if(!(*l))
        return;
    else{
        struct lista *q, *p;
        for(q = (*l); (q->next != 0) && !(q->valore == val); q = q->next)
            p = q;

        if(q->valore != val)
            return;

        if(q == (*l))
            (*l) = q->next;
        else
            p->next = q->next;

        free(q);
    }
}

/* Stampa la lista */
void stampaLista(struct lista **l){
    if(!(*l))
        printf("Lista vuota\n");
    else{
        struct lista *scorriLista;
        for(scorriLista = (*l); scorriLista->next != 0; scorriLista = scorriLista->next)
            printf("%d - ", scorriLista->valore);
        printf("%d\n", scorriLista->valore);
    }
}

int main(int argv, char **argc){
    struct lista *testaLista;
    int arrayInteri [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i;

    testaLista = 0;

    for(i = 0; i < (sizeof(arrayInteri) / 4); i ++)
        inserimento_coda(&testaLista, arrayInteri[i]);

    stampaLista(&testaLista);

    elimina_testa(&testaLista);
    stampaLista(&testaLista);

    elimina_coda(&testaLista);
    stampaLista(&testaLista);

    elimina_elemento(&testaLista, 3);
    stampaLista(&testaLista);

    elimina_elemento(&testaLista, 4);
    stampaLista(&testaLista);

    elimina_elemento(&testaLista, 6);
    stampaLista(&testaLista);

    elimina_elemento(&testaLista, 11);
    stampaLista(&testaLista);

    elimina_lista(&testaLista);
    stampaLista(&testaLista);

    return 0;
}
