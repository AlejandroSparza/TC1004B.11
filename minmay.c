#include <unistd.h>
#include <ctype.h> //Para la funcion de las mayusculas.
#include <stdio.h>

int main(){

    char c; //Caracter a leer.
    char may;
    int n;

    do { //Se ejecuta el ciclo al menos un vez.

        n = read(STDIN_FILENO, &c, 1); //Guardo c.
        may = toupper(c); //Recibe c y me lo regresa en mayusculas.
        write(STDOUT_FILENO, &may, 1); //Escribo c.
   
    } while( n != 0); //Hasta que teclee Ctrl + D.

    return 0;
}