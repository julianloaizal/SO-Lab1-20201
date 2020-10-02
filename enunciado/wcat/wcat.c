#include <stdio.h> // libreria estandar de cabecera para hacer operaciones imput output 
#include <stdlib.h> // libreria estandar de proposito general de memoria dinamica
#include <time.h> // Libreria para dar formato de hora y fecha

int main(int argc, char *argv[]) {
  //char filename[90];
  char line[801];
  //int numLinea = 1;
  FILE *iF;// Condicional para validar si hay un archivo
  //printf("Ingrese el nombre del archivo: ");
  //fflush(stdin); // Se utiliza para una limpieza del bufer de entrada
  //scanf("%[^\n]s",filename); // Formato para que la entrada pueda aceptar espacios
  while(--argc >0){
    iF = fopen(*++argv, "r");
  //iF = fopen(filename,"r");
  if (iF == NULL) {
    printf("wcat: cannot open file\n");
    exit(1);
  }

  while(fgets(line, 801, iF)!=NULL) {
    //printf("%-5d",numLinea++);
    printf("%s",line);
  } 
  fclose(iF);
  }
  exit(0);
}
