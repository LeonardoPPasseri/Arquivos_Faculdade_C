#include <stdio.h>

int main() {
    int conta;
    char nome[30];
    float saldo;
    FILE *cfPtr;
    //Programa vai criar um arquivo ou rescrever um existente

    if ((cfPtr = fopen("TextoExemplo2.dat", "w")) == NULL) {
        printf("Arquivo nao pode ser aberto\n");
    } else {
        printf("Digite a conta, o nome e o saldo.\n");
        printf("Digite EOF para encerrar a entrada de dados.\n");
        printf("? ");


        while (scanf("%d %s %f", &conta, nome, &saldo) == 3) {
            fprintf(cfPtr, "%d %s %.2f\n", conta, nome, saldo);
            printf("? ");
        }


        fclose(cfPtr);
    }

    return 0;
}
