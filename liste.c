#include <stdio.h>
#include <stdlib.h>

#include "./lista.h"

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
