#include <signal.h>
#include <stdio.h>
#include <unistd.h> //Para la funcion de retardar el programa.


void handleSignal(int signal){ //Maneja la senial, recibe el numero de senial.

    printf("Jajaja no me matas %d\n", signal); //Cada que presiono CTRL + C, aparece este mensaje.

}


int main(){

    signal(2, handleSignal); //Cuando reciba la 2 hace eso.
    signal(12, handleSignal);

    while(1){

        printf("Trabajando \n");
        sleep(1); //Para que no lo haga demasiado rapido, se duerme un segundo.

    }

    return 0;

}