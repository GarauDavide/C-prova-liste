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

int main(){
    struct sockaddr_in sv_addr; // Indirizzo di server
    struct sockaddr_in cl_addr; // Indirizzo client

    struct sockaddr_in addr_prova_peer;
    int addr_prova_peer_length;

    struct sockaddr_in addr_prova_name;
    int addr_prova_name_length;

    struct sockaddr_in addr_server_prova;
    int addr_server_prova_length;

    int listener;   // Socket per l'ascolto
    int newfd, addrlen, ret;
    char buffer[512]; // Buffer

    char ip_prova[INET_ADDRSTRLEN];

    listener = socket(AF_INET, SOCK_STREAM, 0);

    sv_addr.sin_family = AF_INET;
    /* Mi metto in ascolto su tutte le interfacce */
    sv_addr.sin_addr.s_addr = INADDR_ANY;
    sv_addr.sin_port = htons(4242);
    inet_pton(AF_INET, "127.0.0.1", &sv_addr.sin_addr);
    bind(listener, (struct sockaddr*)& sv_addr, sizeof(sv_addr));

    listen(listener, 10);
    printf("Server in ascolto..\n");

    addr_server_prova_length = sizeof(addr_server_prova);
    getsockname(listener, (struct sockaddr*)&addr_server_prova, &addr_server_prova_length);
    printf("Indirizzo server: %s, porta %d\n", inet_ntoa(addr_server_prova.sin_addr), ntohs(addr_server_prova.sin_port));

    addrlen = sizeof(cl_addr);
    newfd = accept(listener, (struct sockaddr*)& cl_addr, &addrlen);
    printf("Nuova connessione accettata..\n");

    inet_ntop(AF_INET, &(cl_addr.sin_addr), ip_prova, INET_ADDRSTRLEN);
    printf("Ip client: %s, porta: %d\n", ip_prova, ntohs(cl_addr.sin_port));

    close(newfd);
    close(listener);

    return 0;
}

/*printf("Indirizzo client: %s, porta %d\n", inet_ntoa(cl_addr.sin_addr), ntohs(cl_addr.sin_port));

getpeername(newfd, (struct sockaddr*)&addr_prova_name, &addrlen);

printf("Indirizzo client: %s, porta %d\n", inet_ntoa(addr_prova_name.sin_addr), ntohs(addr_prova_name.sin_port));*/



/*addr_prova_peer_length = sizeof(addr_prova_peer);
getpeername(newfd, (struct sockaddr*)&addr_prova_peer, &addr_prova_peer_length);

printf ("Indirizzo IP peer:%s \n", inet_ntoa(addr_prova_peer.sin_addr));
printf ("Porta peer:%d \n", ntohs(addr_prova_peer.sin_port));

addr_prova_name_length = sizeof(addr_prova_name);
getsockname(newfd, (struct sockaddr*)&addr_prova_name, &addr_prova_name_length);

printf ("Indirizzo IP peer:%s \n", inet_ntoa(addr_prova_name.sin_addr));
printf ("Porta peer:%d \n", ntohs(addr_prova_name.sin_port));*/
