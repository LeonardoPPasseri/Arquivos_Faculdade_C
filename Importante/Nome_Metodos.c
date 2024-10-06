/*
argc ->
argv ->
stdout ->
stdin ->
stderr ->
wb ->
rb ->
EOF ->

Metodos_Função
fopen(const char *_FileName, const char *_Mode) 
fgetc(FILE *_Stream)
fputc(int _Character, FILE *_Stream)


LIVRO---
rewind(FILE *stream);  --> Retorna a "cabeça de leitura" para o inicio

int fseek(FILE *stream, long int offset, int whence); --> Pesquisa um bloco em um arquivo de acesso aleatório 
(FILE *stream -> ponteiro para o arquivo
long int offset -> calculo usado para saber o tamanho e cada bloco
int whence -> Valor especifico para começar a pesquisa -> SEEK_SET (Inicio), SEEK_CUR (Local atual)ou SEEK_E (final))
---
Modos de abertura--
"w" -> Cria um arquivo ou elimina o contudo de um arquivo antes da gravação dos dados.
"r" -> Para ler um arquivo existente.
"a" -> Para adicionar registros ao final de um arquivo existente
Para abrir um arquivo de forma que ele possa ser gravado e lido, abra o arquivo com um dos três modos de atualização:
O modo "r+" abre um arquivo para leitura e gravação
O modo "w+" cria um arquivo para leitura e gravação. Se o arquivo já existir, o arquivo é aberto e o conteúdo atual é eliminado. 
O modo "a+" abre um arquivo para leitura e gravação — toda gravação é feita no final do arquivo. Se o arquivo não existir, é criado.
--

*/