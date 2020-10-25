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

/* Inserisci nella posizione pos */
void inserisci_in_posizione(struct lista **l, int pos, int val){
    
    if(pos <= 0){
        printf("Posizione inserimento in lista non valida\n");
        return;
    }

    if(!(*l) || (pos == 1))
        inserimento_testa(&(*l), val);
    else{
        struct lista *nuovo = malloc(sizeof(struct lista)), *q, *p;
        int indice = 1;

        nuovo->valore = val;
        for(q = (*l); (pos != indice) && (q->next != 0); q = q->next){ 
            indice += 1; 
            p = q;
        }

        if((q->next == 0) && (pos != indice))
            inserimento_coda(&(*l), val);
        else{
            p->next = nuovo;
            nuovo->next = q;
        }
    }
}

/* Cancellazione nella posizione pos */
void elimina_in_posizione(struct lista **l, int pos){
    
    if(!(*l))
        return;
    
    if(pos <= 0){
        printf("Posizione cancellazione in lista non valida\n");
        return;
    }

    if(!(*l) || (pos == 1))
        elimina_testa(&(*l));
    else{
        struct lista *q, *p;
        int indice = 1;

        for(q = (*l); (pos != indice) && (q->next != 0); q = q->next){ 
            indice += 1; 
            p = q;
        }

        if((q->next == 0) && (pos != indice))
            return;

        if((q->next == 0) && (pos == indice))
            elimina_coda(&(*l));
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

    inserisci_in_posizione(&testaLista, 3, 50);
    stampaLista(&testaLista);

    inserisci_in_posizione(&testaLista, 3, 60);
    stampaLista(&testaLista);

    inserisci_in_posizione(&testaLista, 20, 70);
    stampaLista(&testaLista);

    elimina_in_posizione(&testaLista, 20);
    stampaLista(&testaLista);

    elimina_in_posizione(&testaLista, 3);
    stampaLista(&testaLista);

    elimina_in_posizione(&testaLista, 7);
    stampaLista(&testaLista);

    elimina_lista(&testaLista);
    stampaLista(&testaLista);

    return 0;
}
