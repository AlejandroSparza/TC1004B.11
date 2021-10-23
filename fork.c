#include <stdio.h>
#include <unistd.h> //Acceder al fork

int main(){

    int a = 5; //Hasta aqui hay un solo proceso.

    int pid = fork(); //Funcion fork vista.
    //Fork crea dos procesos iguales que corren simultaneamente. La maquina no esta ocupada tanto, so ejecuta todeo el if else.
    if (pid == 0){

        printf("Soy el proceso hijo: pid = %d\n",pid); //Los dos argumentos de prinf, el %d se reemplaza con la parte entera de pid.
    
    }else{

        printf("Soy el proceso padre: pid = %d\n",pid);

    }    

    return 0;
    
}