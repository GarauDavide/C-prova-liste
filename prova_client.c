#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

struct prova{
    char* testo;
    int valore;
    char array[11];
};

int main(){

    struct prova p;
    char* c;
    int a;

    printf("sizeof prova: %d\n", sizeof(p));

    c = "abcd efgh ilmno";

    p.testo = malloc(strlen(c) + 1);
    strcpy(p.testo, c);

    a = (strlen(p.testo)) + sizeof(p.valore) + sizeof(p.array);

    printf("sizeof prova: %d\n", sizeof(p));
    printf("sizeof testo: %d\n", sizeof(p.testo));
    printf("sizeof valore: %d\n", sizeof(p.valore));
    printf("sizeof array: %d\n", sizeof(p.array));
    printf("sizeof a: %d\n", a);

    return 0;
}


//int client_socket_descripter;   // Intero che identifica il descrittore del socket
/*struct sockaddr_in server_addr, client_addr; // Struttura per il server - indirizzo e porta
int ret;

struct sockaddr_in addr_prova_name;
int addr_prova_name_length;

client_socket_descripter = socket(AF_INET, SOCK_STREAM, 0);

memset(&server_addr, 0, sizeof(server_addr));   // Pulizia memeoria
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(4242);
inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

ret = connect(client_socket_descripter, (struct sockaddr*)&server_addr, sizeof(server_addr));
if(ret == -1){
    printf("Connessione con il server non riuscita..\n");
    exit(1);
}

addr_prova_name_length = sizeof(addr_prova_name);
getsockname(client_socket_descripter, (struct sockaddr*)&addr_prova_name, &addr_prova_name_length);

printf ("Indirizzo IP peer:%s \n", inet_ntoa(addr_prova_name.sin_addr));
printf ("Porta peer:%d \n", ntohs(addr_prova_name.sin_port));

printf("Connessione avvenuta con successo..\n");*/

//close(client_socket_descripter);
