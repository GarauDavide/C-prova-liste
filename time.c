#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define N_RUOTE 11
#define N_NUMERI 10
#define N_IMPORTI 5

char all_RUOTE[N_RUOTE][9] = {"bari","cagliari","firenze","genova","milano","napoli","palermo","roma","torino","venezia","tutte"};

struct game_card{
    int r[11];
    int n[10];
    float i[5];
    struct game_card* next;
};

int getMe_RUOTE_associate_pointer(char* r, int n_r){
    int i;

    for(i = 0; (i < N_RUOTE) && (strcmp(r, all_RUOTE[i])); i ++){ ; }

    return i;
}

int* getMe_RUOTE(char* params, int n_params){
    int i, j, z, pointer;
    int* ruote;
    char tmp_r[9];

    ruote = malloc(sizeof(int) * N_RUOTE);

    for(i = 0; i < N_RUOTE; i ++)
        ruote[i] = 0;

    for(i = 0; i < n_params; i ++){
        if(params[i] == '-'){
            i += 1;
            if(params[i] == 'r'){
                i += 2;
                z = 0;
                for(j = i; (j < n_params) && (params[j] != '-'); j ++){
                    if(params[j] != ' '){
                        tmp_r[z] = params[j];
                        z += 1;
                    }else{
                        tmp_r[z] = '\0';
                        pointer = getMe_RUOTE_associate_pointer(tmp_r, strlen(tmp_r));
                        if(pointer != N_RUOTE)
                            ruote[pointer] = 1;
                        z = 0;
                    }
                }
                i = j;
            }
        }
    }

    return ruote;
}

int* getMe_NUMERI(char* params, int n_params){
    int i, j, z, pointer;
    int* numbers;
    char tmp_n[10];

    numbers = malloc(sizeof(int) * N_NUMERI);

    for(i = 0; i < N_NUMERI; i ++)
        numbers[i] = 0;

    for(i = 0; i < n_params; i ++){
        if(params[i] == '-'){
            i += 1;
            if(params[i] == 'n'){
                i += 2;
                z = 0;
                pointer = 0;
                for(j = i; (j < n_params) && (params[j] != '-'); j ++){
                    if(params[j] != ' '){
                        tmp_n[z] = params[j];
                        z += 1;
                    }else{
                        tmp_n[z] = '\0';
                        numbers[pointer] = atoi(tmp_n);
                        z = 0;
                        pointer += 1;
                        if(pointer >= N_NUMERI)
                            return numbers;
                    }
                }
                i = j;
            }
        }
    }

    return numbers;
}

float* getMe_IMPORTI_scommessi(char* params, int n_params){
    int i, j, z, pointer;
    float* importi;
    char tmp_i[10];

    importi = malloc(sizeof(float) * N_IMPORTI);

    for(i = 0; i < N_IMPORTI; i ++)
        importi[i] = 0;

    for(i = 0; i < n_params; i ++){
        if(params[i] == '-'){
            i += 1;
            if(params[i] == 'i'){
                i += 2;
                z = 0;
                pointer = 0;
                for(j = i; (j < n_params) && (params[j] != '-'); j ++){
                    if(params[j] != ' '){
                        tmp_i[z] = params[j];
                        if((j + 1) == n_params){
                            z += 1;
                            tmp_i[z] = params[j + 1];
                            z += 1;
                            tmp_i[z] = '\0';
                            importi[pointer] = atof(tmp_i);
                        }
                        z += 1;
                    }else{
                        tmp_i[z] = '\0';
                        importi[pointer] = atof(tmp_i);
                        z = 0;
                        pointer += 1;
                    }
                    if(pointer >= N_IMPORTI)
                        return importi;
                }
                i = j;
            }
        }
    }

    return importi;
}

struct game_card* create_game_card(char* params, int n_params){
    int* r, * n, j;
    float* i;
    struct game_card* gc;

    gc = malloc(sizeof(struct game_card));

    r = getMe_RUOTE(params, strlen(params));
    n = getMe_NUMERI(params, strlen(params));
    i = getMe_IMPORTI_scommessi(params, strlen(params));

    for(j = 0; j < N_RUOTE; j ++)
        gc->r[j] = r[j];

    for(j = 0; j < N_NUMERI; j ++)
        gc->n[j] = n[j];

    for(j = 0; j < N_IMPORTI; j ++)
        gc->i[j] = i[j];

    return gc;
}

void stamp_card(struct game_card* gc){
    int j;

    for(j = 0; j < 11; j ++)
        printf("-r %d ", gc->r[j]);

    printf("\n");

    for(j = 0; j < 10; j ++)
        printf("%d ", gc->n[j]);

    printf("\n");

    for(j = 0; j < 5; j ++)
        printf("%0.2f ", gc->i[j]);

    printf("\n");
}

void save_game_card_at_personal_file(struct game_card* gc){
    //Mi faccio una funzione che mi ritorna lo username dall lista delle connessioni attive
    //cosi ne approffitto anche per vedere se l'id è valido o meno
    //char* username = "davide";
    char* path = "./davide.txt";
    FILE* fptr;
    int i, j;
    char* buffer;

    fptr = fopen(path, "a+");

    if(fptr == NULL){
        printf("Error!");
        exit(1);
    }



    for(i = 0; i < N_RUOTE; i ++)
        fprintf(fptr, "%d", gc->r[i]);
    fprintf(fptr, "\n");

    for(i = 0; i < N_NUMERI; i ++)
        fprintf(fptr, "%d", gc->n[i]);
    fprintf(fptr, "\n");

    for(j = 0; j < N_IMPORTI; j ++)
        fprintf(fptr, "%0.2f", gc->i[j]);
    fprintf(fptr, "\n");

    fclose(fptr);

}

int main(){
    int i;
    char* giocata = "-r milano gao d roma dfnj udns napoli das -n 28 49 88 21 65 43 53 6 87 37 9 7 2 -i 0 0 2.5 4 8 9";
    int* ruote_associate_alla_giocata;
    int* numeri_giocati;
    float* importi_scommessi;
    struct game_card* card;

    printf("Giocata: %s\n", giocata);

    card = create_game_card(giocata, strlen(giocata));

    stamp_card(card);

    save_game_card_at_personal_file(card);

    return 0;
}
