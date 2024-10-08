/*
contar a frequência de cada símbolo no arquivo. Também baseado no copia1. 
Criar uma array com contadores para cada uma dos possíveis símbolos (256 ou de 0 a 255) 
e para cada símbolo lido acumular. Mostrar a tabela na saída padrão. 
*/
#include <stdio.h>

int main(int argc, char** argv){
    FILE *entrada, *saida;
    int c;
    int qtd[256];

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
        qtd[sizeof(c)]++;
        c = fgetc(entrada);
    }
    for(int i=0;i <= 256;i++){
        printf("%c : %d",c,qtd);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}