#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    void encripta(int pass, char *file){
	    FILE *open, *close;
	    char buff[8192];
	    open = fopen(file, "r");
	    close = fopen("copia_cry_encript.cry", "w");
	    fread(&buff, 1, 8192, open);
	    for(int x=0;x<strlen(buff)+1;x++){
		    fprintf(close, "%c", (buff[x] - pass));
		
		}
		fclose(open);
		fclose(close);
		printf("Dados encriptados!\n");
		
		
	}
	
	void decifra(int pass, char *file){
	    FILE *open, *close;
	    char buff[8192];
	    open = fopen(file, "r");
	    close = fopen("copia_cry_decif.txt", "w");
	    fread(&buff, 1, 8192, open);
	    for(int x=0;x<strlen(buff)+1;x++){
		    fprintf(close, "%c", (buff[x] + pass));
		
		}
		fclose(open);
		fclose(close);
		printf("Dados decifrados!\n");
		
	}
    int main(int argc, char *argv[]){
		printf("[]--- (encry v1.0 by: Nukenin) ---[]\n");
		if(argc < 3){
			printf("exemplo de uso: ./encry <senha> <arq> <0 ou 1>\n");
		    printf("info: '0' é para encriptar\n");
		    printf("info: '1' é para decifrar\n");	
		    printf("info: senha deve ser números inteiros\n");
			exit(1);
		}
		int senha = atoi(argv[1]);
		int n = atoi(argv[3]);
		
		if((n == 0)){
		    encripta(senha, argv[2]);	
		}
		else if(n == 1){
		    decifra(senha, argv[2]);	
		}
		else{
		    printf("exemplo de uso: ./encry <senha> <arq> <0 ou 1>\n");
		    printf("info: '0' é para encriptar\n");
		    printf("info: '1' é para decifrar\n");	
		    printf("info: senha deve ser números inteiros\n");
		}
		
	    return EXIT_SUCCESS;	
	}