Apri il terminale (se installato il compilatore GCC - MinGW);
Recati nella cartella dove sono stati scaricati i due file "main.c" e "lista.h";
Digita nel terminale il comando: gcc main.c -o main;
Digita nel terminale il comando per avviare l'eseguibile appena creato: ./main;

** L'output del main è il seguente: **

$ ./main
1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10
2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10
2 - 3 - 4 - 5 - 6 - 7 - 8 - 9
2 - 4 - 5 - 6 - 7 - 8 - 9
2 - 5 - 6 - 7 - 8 - 9
2 - 5 - 7 - 8 - 9
2 - 5 - 7 - 8 - 9
2 - 5 - 50 - 7 - 8 - 9
2 - 5 - 60 - 50 - 7 - 8 - 9
2 - 5 - 60 - 50 - 7 - 8 - 9 - 70
2 - 5 - 60 - 50 - 7 - 8 - 9 - 70
2 - 5 - 50 - 7 - 8 - 9 - 70
2 - 5 - 50 - 7 - 8 - 9
Lista vuota

** AZIONI DEL PROCESSO MAIN DA ASSOCIARE AI COMBIAMENTI SOPRA DELLA LISTA: **

    stampaLista(&testaLista);   -> 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10

    elimina_testa(&testaLista);
    stampaLista(&testaLista);   -> 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10

    elimina_coda(&testaLista);
    stampaLista(&testaLista);   -> 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9

    elimina_elemento(&testaLista, 3);
    stampaLista(&testaLista);   -> 2 - 4 - 5 - 6 - 7 - 8 - 9

    elimina_elemento(&testaLista, 4);
    stampaLista(&testaLista);   -> 2 - 5 - 6 - 7 - 8 - 9

    elimina_elemento(&testaLista, 6);
    stampaLista(&testaLista);   -> 2 - 5 - 7 - 8 - 9

    elimina_elemento(&testaLista, 11);
    stampaLista(&testaLista);   -> 2 - 5 - 7 - 8 - 9

    inserisci_in_posizione(&testaLista, 3, 50);
    stampaLista(&testaLista);   -> 2 - 5 - 50 - 7 - 8 - 9

    inserisci_in_posizione(&testaLista, 3, 60);
    stampaLista(&testaLista);   -> 2 - 5 - 60 - 50 - 7 - 8 - 9

    inserisci_in_posizione(&testaLista, 20, 70);
    stampaLista(&testaLista);   -> 2 - 5 - 60 - 50 - 7 - 8 - 9 - 70

    elimina_in_posizione(&testaLista, 20);
    stampaLista(&testaLista);   -> 2 - 5 - 60 - 50 - 7 - 8 - 9 - 70

    elimina_in_posizione(&testaLista, 3);
    stampaLista(&testaLista);   -> 2 - 5 - 50 - 7 - 8 - 9 - 70

    elimina_in_posizione(&testaLista, 7);
    stampaLista(&testaLista);   -> 2 - 5 - 50 - 7 - 8 - 9

    elimina_lista(&testaLista);
    stampaLista(&testaLista);   -> Lista vuota
