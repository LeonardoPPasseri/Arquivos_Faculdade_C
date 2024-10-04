/*
contar quantas linhas tem um arquivo. 
Usar o copia1.
Basta contar quantas vezes aparece a quebra linha. '\n' ou c == 10
*/

#include <stdio.h>

int main(int argc, char** argv){
    FILE *entrada, *saida;
    int c;
    int qtd;

    if(argc != 3){
        fprintf(stderr,"Erro na chamada do comando.\n");
        fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO].\n", argv[0]);
        return 1;
    }

    entrada = fopen(argv[1],"rb");
    if(entrada == NULL){
        fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
        return 1;
    }

    saida = fopen(argv[2],"wb");
    if(saida == NULL){
        fclose(entrada);
        fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", argv[2]);
        return 1;
    }

    c = fgetc(entrada);
    while(c != EOF){
        if(c == 10){
            qtd++;
        }
        c = fgetc(entrada);
    }
    printf("A quantidade de quebras de linha foi %d",qtd);

    fclose(entrada);
    fclose(saida);

    return 0;
}