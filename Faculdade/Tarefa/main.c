#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
Leonardo Pinto Passeri
João Marcelo
*/
typedef struct _Produto Produto;

struct _Produto
{
    char descricao[40];
    int quantidadeEstoque;
    int minimoEstoque;
    float precoVenda;
};

int menu(FILE *entrada);
void incluirProduto(FILE *entrada);
void registrarVenda(FILE *entrada);
void buscarPorCodigo(FILE *entrada);
void relatorioEstoqueMinimo(FILE *entrada);
void buscarPorDescricao(FILE *entrada);

int main()
{
    srand(time(NULL));
    printf("----Controle de Estoque----\n\n");
    FILE *entrada;
    int saida;
    entrada = fopen("estoque.bin", "rb+");
    if (entrada == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    do
    {
        saida = menu(entrada);
    } while (saida != 1);

    fclose(entrada);
    return 0;
}

int menu(FILE *entrada)
{
    int opcao;
    printf("1- Incluir produto\n2- Registrar venda\n3- Buscar por codigo\n4- Buscar por descricao\n5- Relatorio de produto com estoque abaixo do minimo\n6- sair\n");
    printf("Escolha uma opcao: \n");
    scanf("%d", &opcao);
    fflush(stdin);
    
    switch (opcao)
    {
    case 1:
        incluirProduto(entrada);
        return 0;
    case 2:
        registrarVenda(entrada);
        break;
    case 3:
        buscarPorCodigo(entrada);
        break;
    case 4:
        buscarPorDescricao(entrada);
        break;
    case 5:
        relatorioEstoqueMinimo(entrada);
        break;
    case 6:
        return 1;

    default:
        printf("opcao invalida\n");
        break;
    }
    return 0;
}

void incluirProduto(FILE *entrada)
{
    rewind(entrada);
    printf("Digite a descricao, quantidade em estoque, quantidade minima e preco da venda:\n");
    Produto produto;
    scanf("%s %d %d %f", produto.descricao, &produto.quantidadeEstoque, &produto.minimoEstoque, &produto.precoVenda);
    char descricaoCompleta[40];
    sprintf(descricaoCompleta, "%s %05d", produto.descricao, rand() % 10000);
    strcpy(produto.descricao, descricaoCompleta);
    fseek(entrada, 0, SEEK_END);
    fwrite(&produto, sizeof(Produto), 1, entrada);

    printf("Produto [%s %d %d %.2f] incluido!\n", produto.descricao, produto.quantidadeEstoque, produto.minimoEstoque, produto.precoVenda);
}

void registrarVenda(FILE *entrada)
{
    fseek(entrada, sizeof(Produto), SEEK_SET);
    int inicio = ftell(entrada);
    fseek(entrada, 0, SEEK_END);
    int fim = ftell(entrada);
    int total = (fim - inicio) / sizeof(Produto);

    Produto produto;
    int codigo, vendas, novoEstoque;
    printf("Digite o codigo do produto(0 - %d) e a quantidade vendida: \n", total);
    scanf("%d %d", &codigo, &vendas);
    if (codigo <= total && codigo >= 0)
    {
        fseek(entrada, codigo * sizeof(Produto), SEEK_SET);
        fread(&produto, sizeof(Produto), 1, entrada);
        novoEstoque = produto.quantidadeEstoque - vendas;
        if (novoEstoque >= 0)
        {
            produto.quantidadeEstoque = novoEstoque;
            fseek(entrada, codigo * sizeof(Produto), SEEK_SET);
            fwrite(&produto, sizeof(Produto), 1, entrada);
        }
        else
        {
            printf("Estoque atual não possui quantidade suficiente!\n");
        }
    }
    else
    {
        printf("Codigo invalido\n");
    }
}

void buscarPorCodigo(FILE *entrada)
{
    fseek(entrada, sizeof(Produto), SEEK_SET);
    int inicio = ftell(entrada);
    fseek(entrada, 0, SEEK_END);
    int fim = ftell(entrada);
    int total = (fim - inicio) / sizeof(Produto);

    Produto produto;
    int codigo;
    printf("Digite o codigo do produto (0 - %d): \n", total);
    scanf("%d", &codigo);
    if (codigo <= total && codigo >= 0)
    {
        fseek(entrada, codigo * sizeof(Produto), SEEK_SET);
        fread(&produto, sizeof(Produto), 1, entrada);
        printf("%s %d %d %.2f\n", produto.descricao, produto.quantidadeEstoque, produto.minimoEstoque, produto.precoVenda);
    }
    else
    {
        printf("Produto informado nao foi encontrado\n");
    }
}

void buscarPorDescricao(FILE *entrada)
{
    rewind(entrada);
    Produto produto;
    char descricaoProcurada[40];
    printf("Digite a descricao do produto: \n");
    scanf("%40s", descricaoProcurada);
    int leitura = fread(&produto, sizeof(Produto), 1, entrada);
    int encontrado;
    while (leitura == 1)
    {
        if (strstr(produto.descricao, descricaoProcurada) != NULL)
        {
            printf("%s %d %d %.2f\n",
                   produto.descricao, produto.quantidadeEstoque, produto.minimoEstoque, produto.precoVenda);
            encontrado = 1;
        }
        leitura = fread(&produto, sizeof(Produto), 1, entrada);
    }

    if (!encontrado)
    {
        printf("Nenhum produto encontrado com a descricao: %s\n", descricaoProcurada);
    }
}

void relatorioEstoqueMinimo(FILE *entrada)
{
    printf("====Estoques abaixo da quantidade minima====\n");
    Produto produto;
    rewind(entrada);
    int leitura = fread(&produto, sizeof(Produto), 1, entrada);
    while (leitura == 1)
    {
        if (produto.quantidadeEstoque < produto.minimoEstoque)
        {
            printf("%s %d %d %.2f\n", produto.descricao, produto.quantidadeEstoque, produto.minimoEstoque, produto.precoVenda);
        }
        leitura = fread(&produto, sizeof(Produto), 1, entrada);
    }
    printf("=============================================\n");
}
