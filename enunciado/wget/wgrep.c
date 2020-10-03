#include<stdio.h>
#include<string.h>

void fimprimirstr(FILE *, char *);

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    if (argc == 2)
        fimprimirstr(stdin, argv[1]);
    else {
        for (int i = 2; i < argc; i++) {
            if ((fp = fopen(argv[i], "r")) == NULL) {
                printf("wgrep: cannot open file\n");
                return 1;
            }
            fimprimirstr(fp, argv[1]);
            fclose(fp);
        }
    }
    return 0;
}

/* 
 * fimprimirstr wrap tiene la función strstr es la que lee 
 * lee linea por linea y si hay una ocurrencia la imprime.
 */
void fimprimirstr(FILE *f, char *p) 
{
    char *buf = NULL;
    size_t n = 0;
    
    while (getline(&buf, &n, f) != -1)
        if (strstr(buf, p) != NULL) 
            printf("%s", buf);
}
