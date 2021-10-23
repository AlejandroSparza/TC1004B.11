#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10000 //Variable global constante (cantidad de hilos).

int saldo; //Variable global.

pthread_mutex_t saldoLock = PTHREAD_MUTEX_INITIALIZER; //Candado inicializado a 1.

void * suma100(void *arg){ //Funcion que regresa y  recibe un apuntador de cualquier cosa. 

    //char * c = (char *) arg; //Para convertir la funcion a su apuntador original.
    //printf("hola desde un hilo %s \n", c);
    int lsaldo; //Obtengo valor global.
    pthread_mutex_lock(&saldoLock); //Poner candado.
    lsaldo = saldo;
    lsaldo += 100; //Lo incremento.
    saldo = lsaldo; //Lo guardo.
    pthread_mutex_unlock(&saldoLock); //Quitar candado.
    pthread_exit(NULL);
 
}

/*
void * suma100(void *arg){

    //char *c = (char *)arg; 
    //printf("hola desde un hilo %s \n",c);
    int lsaldo;
    pthread_mutex_lock(&saldoLock);
    lsaldo = saldo;
    lsaldo += 100;
    saldo = lsaldo;
    pthread_mutex_unlock(&saldoLock);
    pthread_exit(NULL);

}
*/

int main(){

    pthread_t threads[NUM_THREADS]; //Crear hilos. Arreglo donde guardare los ID de los hilos.
    saldo = 0;  
    char *s = "soy un argumento"; //Si quiero mandar eso.

    for(int i = 0; i < NUM_THREADS; i++){

        pthread_create(&threads[i], NULL, suma100, NULL); //Guardar ID de los hilos, atributos, funcion a ejecutar y argumentos.
        //pthread_create(&threads[i], NULL, suma100, NULL); //Aqu
    
    }

    for(int i = 0; i < NUM_THREADS; i++){

        pthread_join(threads[i], NULL);

    }

    printf("Saldo final es %d\n",saldo);
    pthread_exit(NULL); //Termina el proceso.

}