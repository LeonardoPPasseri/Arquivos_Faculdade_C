#include <stdio.h>

int main(){
    int numConta;
    float saldoAtual;
    char nome[30];
    float quantiaReais;
    int x;

    FILE *ofPtr;
    FILE *tfPtr;


    if ((ofPtr = fopen("oldmast.dat", "w+")) == NULL ||
        (tfPtr = fopen("trans.dat", "w+")) == NULL ){
        printf("Um dos arquivos não pode ser aberto\n");
        return 1;
    }else{
        printf("Conta de transacao\n");
        printf("Digite a conta e o saldo.\n");
        printf("Digite EOF para encerrar a entrada de dados.\n");
        printf("? ");

        while (scanf("%d %f", &numConta, &quantiaReais) == 2) {
            fprintf(tfPtr, "%d %.2f\n", numConta, quantiaReais);
            printf("? ");
        }
        scanf("%s",&x);
        printf("Conta de Oldmast\n");
        printf("Digite a conta, o nome e o saldo.\n");
        printf("Digite EOF para encerrar a entrada de dados.\n");
        printf("? ");

        while (scanf("%d %s %f", &numConta, nome, &saldoAtual) == 3) {
            fprintf(ofPtr, "%d %s %.2f\n", numConta, nome, saldoAtual);
            printf("? ");
        }

    }
    return 0;
}