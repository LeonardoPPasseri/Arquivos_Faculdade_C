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
    int encontrado = NULL;

    FILE *ofPtr;
    FILE *tfPtr;
    FILE *nfPtr;

    if((ofPtr = fopen("oldmast.dat", "r+")) == NULL || (tfPtr = fopen("trans.dat", "r")) == NULL || (nfPtr = fopen("newmast.dat", "w")) == NULL){
        printf("Um dos arquivos não pode ser aberto");
        return 1;
    }else{
        //Preciso comparar o numConta do trans.dat com o numConta do oldmast.dat e se houver iguais, o saldoAtual deve ser somado ao valor do oldmast.saldoAtual
        while(!oef(tfPtr)){
            fscanf(tfPtr, "%d%f", &numConta, &quantiaReais) ;
            float transConta = numConta;
            while(!oef(ofPtr)){
                fscanf(ofPtr, "%d%s%f", &numConta, nome, &saldoAtual); 
                if(transConta == numConta){
                    encontrado = 1;
                    saldoAtual += quantiaReais;
                    break;
                }
            }
            if(!encontrado){
                printf("Nao ha correspondência entre o registro de transação e o numeroda conta %f", transConta);
            }
            rewind(ofPtr);
            fprintf(ofPtr, "%d%s%f", &numConta, nome, &saldoAtual);
        }
        fscanf(ofPtr, "%d%s%f", &numConta, nome, &saldoAtual);
        while(!ofPtr){
            fscanf(ofPtr, "%d%s%f", &numConta, nome, &saldoAtual);
            fprintf(nfPtr, "%d%s%.2f", numConta, nome, saldoAtual);
        }
    }

    fclose(ofPtr);
    fclose(tfPtr);
    fclose(nfPtr);

    return 0;
}