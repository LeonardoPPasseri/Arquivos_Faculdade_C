#include <stdio.h>
#include <string.h>
//Considere um arquivo letras.dat, cujo conteudo sao as 26 letras do alfabeto maiusculas. Analise
//o trecho abaixo e indique quais serao as saidas. (1,5 pontos, 0,3 cada item)
int main()
{   //Ponteiro (->)
    //A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
    char bloco[3] = {'\0'};
    FILE *f = fopen("letras.dat", "rb+");//->A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
    fseek(f, -2, SEEK_END);//A B C D E F G H I J K L M N O P Q R S T U V W X -> Y Z
    fread(bloco, sizeof(char), 3, f); //A B C D E F G H I J K L M N O P Q R S T U V W X Y Z->
    printf("(a) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    //(a)   YZ 26 0
    fseek(f, -3, SEEK_END); //A B C D E F G H I J K L M N O P Q R S T U V W ->X Y Z
    fread(bloco, sizeof(char), 3, f);//A B C D E F G H I J K L M N O P Q R S T U V W X Y Z ->
    printf("(b) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    //(b)   XYZ 26 0
    fseek(f, 10, SEEK_SET);//A B C D E F G H I J -> K L M N O P Q R S T U V W X Y Z
    fread(bloco, sizeof(char), 3, f);//A B C D E F G H I J K L M -> N O P Q R S T U V W X Y Z
    printf("(c) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    //(c)  KLM 13 0
    fread(bloco, sizeof(char), 3, f);//A B C D E F G H I J K L M N O P -> Q R S T U V W X Y Z
    printf("(d) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    //(d)   NOP 16 0
    fseek(f, -3, SEEK_CUR);//A B C D E F G H I J K L M N ->O P Q R S T U V W X Y Z
    fread(bloco, sizeof(char), 3, f);//A B C D E F G H I J K L M N O P Q -> R S T U V W X Y Z
    printf("(e) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    //(e)   NOP 16 0
    fclose(f);
    return 0;
    //ftell() -> começa a conta a partir do 1
    // false -> 0 e true -> 1
    /*
    (a) YZ  26 0
    (b) XYZ 26 0
    (c) KLM 13 0
    (d) NOP 16 0
    (e) NOP 16 0
    */
}
