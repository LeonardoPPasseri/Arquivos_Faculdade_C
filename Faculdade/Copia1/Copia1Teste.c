#include <stdio.h>

int main(){
    FILE *entrada, *saida;
    int c;
/*
    if(argc != 3){ 
        fprintf(stderr,"Erro na chamada do comando.\n");
        fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO].\n", argv[0]);
        return 1;
    }

    entrada = fopen("C:\\ArquivoJAVAExemplos\\TextoExemplo1.txt","r");
    if(entrada == NULL){
        fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
        return 1;
    }
    
    saida = fopen("C:\\ArquivoJAVAExemplos\\TextoExemplo2.txt","w");
    if(saida == NULL){
        fclose(entrada);
        fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", argv[2]);
        return 1;
    }
*/ //Retirando essa parte Funcionou

 entrada = fopen("C:\\ArquivoJAVAExemplos\\TextoExemplo1.txt","r");
 saida = fopen("C:\\ArquivoJAVAExemplos\\TextoExemplo2.txt","w");
    c = fgetc(entrada); 
    while(c != EOF){ 
        fputc(c,saida);
        c = fgetc(entrada); 
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}