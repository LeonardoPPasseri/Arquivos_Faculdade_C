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


LIVRO--
rewind(FILE *stream);  --> Retorna a "cabeça de leitura" para o inicio

int fseek(FILE *stream, long int offset, int whence); --> Pesquisa um bloco em um arquivo de acesso aleatório 
(FILE *stream -> ponteiro para o arquivo
long int offset -> calculo usado para saber o tamanho e cada bloco
int whence -> Valor especifico para começar a pesquisa -> SEEK_SET (Inicio), SEEK_CUR (Local atual)ou SEEK_E (final))
--

*/