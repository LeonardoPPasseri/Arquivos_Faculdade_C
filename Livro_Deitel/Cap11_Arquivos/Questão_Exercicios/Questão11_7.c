/*
a) ofPtr = fopen("oldmast.dat", "r");
b) tfPtr = fopen("trans.dat", "r");
c) nfPtr = fopen("newmast.dat", "w");
d) fscanf(ofPtr, "%d%s%f", &numConta, nome, &saldoAtual);
e) fscanf(tfPtr, "%d%f", &numConta, &quantiaReais) ;
fj fprintf(nfPtr, "%d%s%.2f", numConta, nome, saldoAtual);
*/

#include <stdio.h>

int main(){
    int numConta;
    float saldoAtual;
    char nome[30];
    float quantiaReais;
    int encontrado;

    FILE *ofPtr;
    FILE *tfPtr;
    FILE *nfPtr; 

    if ((ofPtr = fopen("oldmast.dat", "r")) == NULL ||
        (tfPtr = fopen("trans.dat", "r")) == NULL ||
        (nfPtr = fopen("newmast.dat", "w+")) == NULL){
        printf("Um dos arquivos não pode ser aberto\n");
        return 1;
    }else{    
        while(fscanf(tfPtr, "%d %f", &numConta, &quantiaReais) != EOF){
            int transConta = numConta;
            encontrado = 0;
            while(fscanf(ofPtr, "%d %s %f", &numConta, nome, &saldoAtual) != EOF){
                if(transConta == numConta){
                    encontrado = 1;
                    saldoAtual += quantiaReais;
                    fprintf(nfPtr, "%d %s %.2f\n", numConta, nome, saldoAtual);
                    break;
                }
            }
            if(!encontrado){
                printf("\nNao ha correspondencia entre o registro de transacao e o numero da conta %d\n", transConta);
            }
            rewind(ofPtr);
        }
        rewind(ofPtr);
        rewind(nfPtr);
        int numConta2;
        float saldoAtual2;
        char nome2[30];
        while(fscanf(ofPtr, "%d %s %f", &numConta2, nome2, &saldoAtual2) != EOF){
            int ofnumConta = numConta2;
            encontrado = 0;
            while(fscanf(nfPtr, "%d %s %f", &numConta, nome, &saldoAtual) != EOF){
                if(ofnumConta == numConta){
                    encontrado = 2;
                    break;
                }
            }
            if(encontrado != 2){
                fprintf(nfPtr, "%d %s %.2f\n", numConta2, nome2, saldoAtual2);
            }

            rewind(nfPtr);
        }
    }
    printf("fim do programa");
    fclose(ofPtr);
    fclose(tfPtr);
    fclose(nfPtr);
    fclose(nfPtr);

    return 0;
}