#include <stdio.h>
#include <string.h>

int main(){
    FILE *entrada = fopen("arquivo.dat","rb+");

    if(!entrada){
        return 1;
    }
    char c;
    c = fgetc(entrada);
    if(c != EOF){
         if (!isprint(c) && c != '\n' && c != '\r' && c != '\t') {
            printf("O arquivo é binário");
            fclose(entrada);
            return 0;
        }else{
            c = fgetc(entrada);
        }
        
    }
    printf("O arquivo é texto");
    return 0;
}