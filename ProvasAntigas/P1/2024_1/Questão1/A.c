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
    Produto produto_vazio = {"",0,0.0};
    for (int i = 0; i < 100; i++){
        fwrite(&produto_vazio,sizeof(Produto),1,entrada);
    }   
}

//Furadeira 7 58.84
void insere_Registro(FILE *entrada){
    Produto produto;
    Produto produto2;
    int registro = 0;

    fseek(entrada,sizeof(Produto),SEEK_SET);
    fread(&produto2,sizeof(Produto),1,entrada);
    char buffer[3];
    while(!feof(entrada)){
        if(strcmp(produto2.descricao, "") == 0){
            printf("Digite a descricao, quantidade e custo: \n");
            registro = ftell(entrada);
            scanf("%s %d %f" ,produto.descricao, &produto.quantidade, &produto.custo);
            produto.descricao[20] = '\0';
            fseek(entrada, -1, SEEK_CUR);
           
            sprintf(registro, "%d");
            strcat(buffer, produto.descricao);
            
            fwrite(&produto, sizeof(Produto), 1, entrada);
            fseek(entrada, sizeof(Produto) * (registro - 1), SEEK_SET);
            printf("Registro inserido com sucesso!\n");
        }
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