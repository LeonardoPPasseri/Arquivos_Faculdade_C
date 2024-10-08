#include <stdio.h>

int main() {
    int conta;
    char nome[30];
    float saldo;
    FILE *cfPtr;
    //Programa vai ler um arquivo

    if ((cfPtr = fopen("C:\\ArquivoJAVAExemplos\\TextoExemplo2.txt", "r")) == NULL) {
        printf("Arquivo nao pode ser aberto\n");
    } else {
        printf("%-10s%-13s%s\n", "Conta", "Nome", "Saldo");
        fscanf(cfPtr, "%d%s%f", &conta, nome, &saldo); //Funciona como um fget() pegando sempre o proximo registro
        while (!feof(cfPtr)) {
            printf("%-10d%-13s%7.2f\n", conta, nome, saldo);
            fscanf(cfPtr, "%d%s%f", &conta, nome, &saldo);
        }
        fclose(cfPtr);
    }

    return 0;
}
