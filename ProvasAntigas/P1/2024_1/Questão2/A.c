#include <stdio.h>
#include <string.h>

int main()
{
    char bloco[3] = {'\0'};
    FILE *f = fopen("letras.dat", "rb+");
    // \0\0\0
    fseek(f, -2, SEEK_END);// \0 primeiro
    fread(bloco, sizeof(char), 3, f); //\0\0\0
    printf("(a) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    // (a) \0\0 4 true
    fseek(f, -3, SEEK_END);// \0\0\0
    fread(bloco, sizeof(char), 3, f);// \0\0\0
    printf("(b) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    // (b) \0\0\0 4 true
    fseek(f, 10, SEEK_SET);
    fread(bloco, sizeof(char), 3, f);
    printf("(c) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    fread(bloco, sizeof(char), 3, f);
    printf("(d) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    fseek(f, -3, SEEK_CUR);
    fread(bloco, sizeof(char), 3, f);
    printf("(e) %3.3s %ld %d\n", bloco, ftell(f), feof(f));
    fclose(f);
    return 0;
}
