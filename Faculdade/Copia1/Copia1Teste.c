#include <stdio.h>
// stdout, stdin, stderr
/*
O padrão de entrada, o padrão de saída e o padrão de erros são manipulados 
por meio dos ponteiros de arquivos stdin, stdout e stderr.
stdin -> standard input -> entrada padrão

*/
int main(int argc, char** argv){
    //argc -> quantidade de dados(Nome do arquivo, ponteiro de entrada, ponteiro de saida)
    //char** argv -> Ponteiro para um array de char que pode ser o nome,entrada ou saida -> [0,1,2]

    FILE *entrada, *saida;
    //Ponteiros para um arquivo para ler(entrada) e um para escrever(saida)

    int c;

    if(argc != 3){ //Se argc for diferente de 3, quer dizer que está faltando dados para fazer a copia 
    //Esse if serve como fluxo de exceção
        fprintf(stderr,"Erro na chamada do comando.\n");
        fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO].\n", argv[0]);
        return 1;
    }

    entrada = fopen("C:\\ArquivoJAVAExemplos\\TextoExemplo1.txt","r");
    //entrada recebe o arquivo que será aberto e um modo
    if(entrada == NULL){ //!entrada 
        //Se a entrada for igual a null quer dizer que não foi possivel ler o arquivo.
        fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
        return 1;
    }
    //MODOs
    //“rb” : abre um arquivo para leitura
    //“wb” : cria um arquivo para escrita (deleta e cria um novo arquivo se ele já existir)
    //Modos de aberturas de arquivo em formato binário 
    
    saida = fopen("C:\\ArquivoJAVAExemplos\\TextoExemplo2.txt","w");
    if(saida == NULL){
        fclose(entrada);//Importante fechar a entrada, pois não será usada caso ocorra essa exceção de saida
        fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", argv[2]);
        return 1;
    }

    c = fgetc(entrada); //1- A variavel inteira 'c' recebe o primeiro caracter do arquivo de leitura
    while(c != EOF){ //2- Verificação se esse caracter existe ou é um End of File(EOF) 
        fputc(c,saida); //3- No arquivo de saida é escrito o caracter que foi recebido por c
        //A "cabeça de leitura" é movida para o proximo caracter automaticamente
        c = fgetc(entrada); //4- c recebe o proximo caracter ou recebe um EOF caso não possua mais caracter
    }
    //Chines 'abc'
    /*
    "Cabeça de leitura => a"
    c = 'a'
    while(true)
    saida => "a"
    "Cabeça de leitura => b"
    c = 'b'
    ======
    while(true)
    saida => "ab"
    "Cabeça de leitura => c"
    c = 'c'
    ======
    while(true)
    saida => "abc"
    "Cabeça de leitura => Marcador EOF
    c = EOF
    ======
    while(false)
    */

    fclose(entrada);//Importante fechar os arquivos que foram abertos
    fclose(saida);

    return 0;
}