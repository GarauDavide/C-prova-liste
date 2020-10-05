#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	/*char str[15] = "vedi_vincite";
	int vettore[5];
	int i; 
	int str_len = strlen(str);
	int somma = 0;
	int somma_pesata = 0; 	

	for(i = 0; i < 	str_len; i ++){
		somma_pesata += (int)str[i] * (i + 1);
		somma += (int)str[i];
	}
		
	printf("Somma pesata: %d, somma: %d\n", somma_pesata, somma);
	
	printf("Sizeof str: %d, strlen str: %d\n", sizeof(str), strlen(str));	

	printf("Sizeof vettore: %d\n", sizeof(vettore));
	
	char* user = "Davide";
	FILE *tmp_file;
  	char* all_path; 
	char* path1 = "./Utenti/"; 
	char* path2 = ".txt";
  	int all_path_length = strlen(path1) + strlen(path2) + strlen(user) + 1;

  	all_path = malloc(all_path_length);
  	
	strcat(all_path, path1);
	strcat(all_path, user);
	strcat(all_path, path2);
	
	printf("Path: %s, ln: %d, szof: %d\n", all_path, strlen(all_path), sizeof(all_path));*/

	
	struct connections_list{
		char* user;
		char user_id[10];
	}
	
	return 0;
}
