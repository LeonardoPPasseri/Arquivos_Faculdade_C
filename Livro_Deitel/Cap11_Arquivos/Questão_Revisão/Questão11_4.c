/*
Encontre o erro em cada um dos seguintes segmentos de programa. Explique como o erro pode ser
corrigido.
a) O arquivo referenciado por fPtr ("pagar.dat") não foi aberto.
 fprintf(fPtr, "%ã%s%ã\n", conta, companhia, quantia);
b) open("receber.dat", "r+");
c) A instrução a seguir deve ler um registro do arquivo "pagar. dat". O ponteiro pagPtr se
refere a esse arquivo e o ponteiro recPtr se refere ao arquivo " receber. dat".
fscanf(recPtr, "%d%s%d\n", fcconta, companhia, fcquantia);
d) O arquivo " objetos.dat" deve ser aberto para inclusão de dados no arquivo sem
eliminação dos dados atuais.
if ((tfPtr = fopenCobjetos.dat", "w") ) != NULL)
e) O arquivo " cursos. dat" deve ser aberto para anexação sem modificação do conteúdo
atual do arquivo.
if ((cfPtr = fopenCcursos.dat", "w+")) != NULL)

a)fPtr = fopen("pagar.dat","r") -> O arquivo não foi aberto
b)fPtr = fopen("receber.dat","r+") -> Para abrir precisa "fopen" não "open", "open" nao é uma funçao valida
c)fscanf(pagPtr, "%d%s%d\n", fcconta, companhia, fcquantia) -> Foi usado o ponteiro errado
d)tfPtr = fopen("objetos,dat","a") -> Para adicionar dados ao arquivo, ou abra o arquivo para atualização (" r +") ou abra o
arquivo para anexação (" a").
e)cfPtr = fopenCcursos.dat", "a"


d) Erro: O conteúdo do arquivo é eliminado porque o arquivo é aberto para gravação ("w").
Correção: Para adicionar dados ao arquivo, ou abra o arquivo para atualização (" r +") ou abra o
arquivo para anexação (" a").
e) Erro: O arquivo " cursos . dat" é aberto para atualização no modo " w+" que elimina o
conteúdo atual
Correção: Abra o arquivo no modo " a".
*/