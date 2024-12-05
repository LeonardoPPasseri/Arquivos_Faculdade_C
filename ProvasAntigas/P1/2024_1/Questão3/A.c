/*
(a) Diferencie arquivo texto de arquivo binario.
(b) Por que a ordena¸c˜ao externa e importante para o manuseio de arquivos?
(c) Diferencie arquivos de registros de tamanho fixo e de tamanho variavel, indicando vantagens
e desvantagens.
(d) Por que e importante fechar os arquivos no final do processamento?
(e) O processo de intercalacao pode ser usado para a realizacao de algumas operacoes de conjuntos
como, por exemplo, a diferenca. Explique resumidamente este uso.

*/

/*
(a) Diferencie arquivo texto de arquivo binário:
Arquivo texto: Dados armazenados como caracteres legíveis (ex.: .txt), fácil de editar, mas ocupa mais espaço.
Arquivo binário: Dados no formato binário do computador (ex.: .dat), mais eficiente, mas ilegível diretamente.

(b) Por que a ordenação externa é importante para o manuseio de arquivos?
É essencial para arquivos grandes demais para a memória, permitindo dividi-los em partes menores, ordená-las separadamente e depois intercalá-las eficientemente.

(c) Diferencie arquivos de registros de tamanho fixo e de tamanho variável, indicando vantagens e desvantagens:
Tamanho fixo:
Vantagens: Acesso rápido, fácil de calcular posições.
Desvantagens: Pode desperdiçar espaço.
Tamanho variável:
Vantagens: Usa menos espaço, flexível para diferentes dados.
Desvantagens: Acesso mais lento, requer percorrer registros anteriores.

(d) Por que é importante fechar os arquivos no final do processamento?
Garante que dados sejam gravados nos arquivos.
Libera recursos do sistema.
Evita corrupção ou inconsistências nos dados.

(e) O processo de intercalação pode ser usado para realizar operações de conjuntos como a diferença? Explique.
Sim. Com dois conjuntos ordenados, a intercalação compara os elementos simultaneamente e inclui no resultado apenas os elementos do primeiro conjunto que não aparecem no segundo, de forma eficiente.



*/