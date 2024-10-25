/*
Leonardo Pinto Passeri
João Marcello Cavadinha
*/
#include <stdio.h>
#include <string.h>

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};

int main()
{
	FILE *entrada;
	Endereco e;
	int c;
	int inicio = 0;
	int fim;
	int meio;
	char cepPedido[8];
	c = 0;
	int encontrado = 0;
	int aux;

	entrada = fopen("cep_ordenado.dat", "rb");
	if (entrada == NULL)
	{
		printf("Falha ao abrir o arquivo");
		return 1;
	}

	printf("Digite o cep: ");
	scanf("%s", cepPedido);
	fseek(entrada, 0, SEEK_END);
	fim = ftell(entrada) / sizeof(Endereco) - 1;

	while (inicio <= fim)
	{
		c++;
		meio = inicio + (fim - inicio) / 2;
		fseek(entrada, meio * sizeof(e), SEEK_SET);
		fread(&e, sizeof(Endereco), 1, entrada);

		aux = strncmp(cepPedido, e.cep, 8);
		if (aux < 0) // cepPedido < cepVerificado
		{
			fim = meio - 1;
		}
		else if (aux > 0) // cepPedido > cepVerificado
		{
			inicio = meio + 1;
		}
		else
		{
			printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n", e.logradouro, e.bairro, e.cidade, e.uf, e.sigla, e.cep);
			encontrado = 1;
			break;
		}
	}
	if (encontrado == 0)
	{
		printf("CEP nao encontrado!\n");
	}
	printf("Total Lido: %d\n", c);

	fclose(entrada);
}
