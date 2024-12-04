#include <stdio.h>
#include <string.h>


typedef struct _Produto Produto;
struct _Produto
{
    char descricao[20];
    int quantidade;
    float custo;
};

void cria_arquivo(FILE *entrada){
    Produto produto;
    strcpy(produto.descricao, "");
    produto.descricao[20] = '\0';
    produto.custo = 0;
    produto.quantidade = 0;
    for (int i = 0; i < 100; i++){
        fwrite(&produto,sizeof(Produto),1,entrada);
    }   
}

//3 Furadeira 7 58.84
void insere_Registro(FILE *entrada){
    Produto produto;
    Produto produto2;
    int registro = 0;
    printf("Digite o registro, a descricao, quantidade e custo: \n");
    scanf("%d %s %d %f", &registro, produto.descricao, &produto.quantidade, &produto.custo); // Lê o registro primeiro
    fseek(entrada, sizeof(Produto) * (registro - 1), SEEK_SET); // Ajusta o cálculo do offset
    fread(&produto2, sizeof(Produto), 1, entrada);
    
    produto.descricao[19] = '\0';
    if (strcmp(produto2.descricao, "") == 0) { // Verifica se o registro está vazio
        fseek(entrada, sizeof(Produto) * (registro - 1), SEEK_SET);
        fwrite(&produto, sizeof(Produto), 1, entrada);
        printf("Registro inserido com sucesso!\n");
    } else {
        printf("Registro já adicionado!\n");
    }
}

void lista_Registro(FILE *entrada){
    Produto produto;
    rewind(entrada);
    fread(&produto,sizeof(Produto), 1, entrada);
    int cont = 1;
    int contR = 0;
    int qtdR = 0;
    while(!feof(entrada)){
        printf("Numero: %d // Descricao: %s // Qtd: %d // Custo: %f\n", cont,produto.descricao,produto.quantidade,produto.custo);
        cont += 1;
        if (strcmp(produto.descricao, "") != 0) {
            contR += 1;
            qtdR += produto.quantidade;
        }
        fread(&produto,sizeof(Produto), 1, entrada);
    }
    printf("Total de Registros cadastrados: %d\n", contR);
    printf("Quantidade de produtos cadastrados: %d\n", qtdR);

}

int main(){
    FILE *entrada;
    entrada = fopen("Ferramentas.dat","wb+");
    if(entrada == NULL){
        return 1;
    }
    cria_arquivo(entrada);
    insere_Registro(entrada);
    lista_Registro(entrada);
    printf("Programa Terminado!");

    return 0;
}