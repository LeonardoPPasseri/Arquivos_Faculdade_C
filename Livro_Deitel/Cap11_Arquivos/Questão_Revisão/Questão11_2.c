/*
Diga se as afirmações a seguir são verdadeiras ou falsas (para as afirmações falsas, explique o
motivo).
a) A função f scanf não pode ser usada para ler dados da entrada padrão.
b) O programador deve usar explicitamente fopen para abrir os fluxos de entrada padrão,
saída padrão e de exibição padrão de mensagens de erro.
c) Um programa deve chamar explicitamente a função f close para fechar um arquivo.
d) Se o ponteiro de posição do arquivo apontar, em um arquivo seqüencial, para um local
diferente do ínicio do arquivo, esse deve ser fechado e reaberto para leitura a partir do início do
arquivo.
e) A função fprintf pode escrever na saída padrão.
f) Os dados em arquivos de acesso seqüencial são sempre atualizados sem gravação de outros
dados.
g) Não é necessário pesquisar todos os registros em um arquivo de acesso aleatório para
encontrar um registro específico.
h) Os registros em arquivos de acesso aleatório não possuem comprimento uniforme.
i) A função fseek só pode realizar pesquisas relativas ao início do arquivo.

a)false, função f scanf pode ser usada para ler da entrada padrão incluindo o ponteiro
para o fluxo da entrada padrão, stdin, na chamada a f scanf.
b)FALSE, Esses três fluxos são abertos automaticamente pelo C no início da execução do
programa. (os fluxos são abertos automaticamente, porém os ponteiros para os arquivos entrada e saida devem ser abertos com o fopen)
c)FALSE, eles seram de fechados ao fim do programa, mas devem ser fechados usando o fclose()
d)FALSE, pode-se usar a função rewind() para reposicionar o ponteiro para a posição inicial
e)true
f)FALSE,Na maioria dos casos, os registros de arquivos seqüenciais não possuem
comprimento uniforme. Portanto, é possível que a atualização de um registro faça com que outros
dados sejam sobrescritos.
g)true
h)false, os registros de um arquivo de acesso aleatório possuem tamanho uniforme, dessa forma é possivel acessar todos os arquivos ao procurar usando o fseek() 
i)false, na função fseek() é possivel usar como parametro (SEEK_SET (Inicio), SEEK_CUR (Local atual)ou SEEK_E (final)) para determinar o local para iniciar a pesquisa.

*/