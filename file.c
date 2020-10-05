#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

    int i;
    char* buffer;
    char* password;
    FILE *f;
    long fsize;
    time_t seconds;

    seconds = time(NULL);

    printf("secondi %d\n", seconds);

    /*f = fopen("./mio.txt", "r");

    if(f == 0)
        printf("File non esiste..\n");

    fseek(f, 0, SEEK_END);
    fsize = ftell(f);

    buffer = malloc(fsize + 1);

    fseek(f, 0, SEEK_SET);

    fread(buffer, sizeof(char), fsize, f);
    fclose(f);

    buffer[fsize] = '\0';

    printf("Buffer: %s\n", buffer);

    for(i = 0; (i < strlen(buffer)) && (buffer[i] != '\n'); i ++) ;

    password = malloc(i + 2); // parte da 0 e il carattere di fine stringa

    for(i = 0; (i < strlen(buffer)) && (buffer[i] != '\n'); i ++)
        password[i] = buffer[i];
    password[i] = '\0';

    printf("password: %s, length: %d\n", password, strlen(password));*/


    return 0;
}
