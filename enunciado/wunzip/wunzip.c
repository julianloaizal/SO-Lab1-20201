#include <stdio.h>
#define INTLEN 4       /* 4-byte de longitud integer */
#define ASCLEN 1       /* 1-byte de longitud ascii    */

int main(int argc, char *argv[])
{
    FILE *fp;
    char c;
    int n;

    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }
    while (--argc > 0) {
        if ((fp = fopen(*++argv, "r")) == NULL)
            return 1;
        while (fread(&n, INTLEN, 1, fp)) {
            fread(&c, ASCLEN, 1, fp);
            while (n-- > 0)
                printf("%c", c);
        }
        fclose(fp);
    }
    return 0;
}
