#include <stdio.h>
#define TAMANHO 8192
//PQ 8192? Lida-se melhor com blocos de caracteres do que byte a byte 

int main(int argc, char** argv){
    FILE *entrada,*saida;
    char buffer[TAMANHO]; //Array de char com 8192 espaços
    int qtd;

    if(argc != 3){
        fprintf(stderr,"Erro na chamada do comando.\n");
        fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO].\n", argv[0]);
        return 1;
    }

    entrada = fopen(argv[1],"rb");
    if(!entrada){ // "!entrada" <==> "entrada == NULL"
        fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
        return 1;
    }

    saida = fopen(argv[2],"wb");
    if(!saida){ 
        fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", argv[2]);
    }

    qtd = fread(buffer,sizeof(char),TAMANHO,entrada);
    //qtd recebe a quantidade de caracteres que foram armazenados no buffer
    /*
    buffer -> array para armazenamento do bloco
    sizeof(char) -> tamanho de cada caracter
    TAMANHO -> tamanho maximo do buffer
    entrada -> arquivo de leitura)
    */
    while(qtd > 0){ //enquanto houver caracteres para armazenar 
        fwrite(buffer,sizeof(char),qtd,saida); 
        //Escreve o bloco de caracteres que está no buffer no arquivo de saida
        qtd = fread(buffer,sizeof(char),TAMANHO,entrada);
        //A "cabeça" é movida para depois do ultimo caracter do bloco
        //qtd recebe a quantidade de caracter que faltam ou que completa o buffer
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}