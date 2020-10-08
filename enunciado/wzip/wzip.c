#include <stdio.h>
#define INTLEN 4       /* 4-bytes de longitud integer  */
#define ASCLEN 1       /* 1-byte de longitud ascii     */

void write(int, char, FILE*);

int main(int argc, char *argv[])
{
    char c, b = '\0';
    FILE *fp;
    int n;

    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }
    while (--argc > 0) {
        if ((fp = fopen(*++argv, "r")) == NULL)
            return 1;
        while ((c = getc(fp)) != EOF) {
            if (c == b)
                n++;
            else {
                if (b != '\0')
                    write(n, b, stdout);
                b = c;
                n = 1;
            }
        }
        fclose(fp);
    }
    write(n, b, stdout);
    return 0;
}

/*
 * escribir un número entero de 4 bytes en binario
 * seguido de un carácter ascii de 1 byte para funciòn.
 */
void write(int n, char c, FILE *ff)
{
    fwrite(&n, INTLEN, 1, ff);
    fwrite(&c, ASCLEN, 1, ff);
}
