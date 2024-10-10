#include <stdio.h>

int main() {
    int numConta;
    float saldoAtual;
    char nome[30];
    float quantiaReais;
    int encontrado;

    FILE *ofPtr; // Arquivo-mestre
    FILE *tfPtr; // Arquivo de transações
    FILE *nfPtr; // Novo arquivo-mestre
    FILE *auxfPtr; // Arquivo auxiliar

    // Abrindo os arquivos
    if ((ofPtr = fopen("C:\\ArquivoJAVAExemplos\\Arquivos\\oldmast.txt", "r")) == NULL ||
        (tfPtr = fopen("C:\\ArquivoJAVAExemplos\\Arquivos\\trans.txt", "r")) == NULL ||
        (nfPtr = fopen("C:\\ArquivoJAVAExemplos\\Arquivos\\newmast.txt", "w")) == NULL ||
        (auxfPtr = fopen("C:\\ArquivoJAVAExemplos\\Arquivos\\auxmast.txt", "w")) == NULL) {
        printf("Um dos arquivos não pode ser aberto\n");
        return 1;
    } else {
        // Lendo as transações
        while (fscanf(tfPtr, "%d %f", &numConta, &quantiaReais) == 2) {
            encontrado = 0; // Resetar encontrado para cada transação
            rewind(ofPtr); // Reiniciar o arquivo-mestre

            // Lendo o arquivo-mestre
            while (fscanf(ofPtr, "%d %s %f", &numConta, nome, &saldoAtual) == 3) {
                if (numConta == numConta) { // Verifica se houve correspondência
                    encontrado = 1;
                    saldoAtual += quantiaReais; // Atualiza o saldo
                    fprintf(auxfPtr, "%d %s %.2f\n", numConta, nome, saldoAtual);
                    break; // Sai do loop se encontrou a conta
                }
            }
            if (!encontrado) {
                printf("Nao ha correspondência entre o registro de transação e o numero da conta %d\n", numConta);
            }
        }

        // Rewind do arquivo auxiliar para gravar no novo arquivo-mestre
        rewind(auxfPtr);
        while (fscanf(auxfPtr, "%d %s %f", &numConta, nome, &saldoAtual) == 3) {
            fprintf(nfPtr, "%d %s %.2f\n", numConta, nome, saldoAtual);
        }
    }

    printf("Fim do programa\n");
    fclose(ofPtr);
    fclose(tfPtr);
    fclose(nfPtr);
    fclose(auxfPtr); // Fechar o arquivo auxiliar

    return 0;
}
