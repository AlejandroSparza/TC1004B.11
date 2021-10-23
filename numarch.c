#include <unistd.h>

int main(){

    int fd[2]; //Guardamos al pipe (2 ID entrada y salida).
    int pid;
    
    pipe(fd);
    pid = fork(); //Ahora seran 2 procesos.

    if(pid == 0){ //Hijo.

        close(STDIN_FILENO); //Cerrar entrada estandar.
        dup(fd[0]); //La entrada es el primer pipe.
        close(fd[1]); //No se usa la salida, solo la entrada.
        execlp("wc","wc","-l",NULL); //Archivo ws, quiero que se llame wc, le paso "-l".

    }else {

        close(STDOUT_FILENO); //Cerrar salida estandar.
        dup(fd[1]); //Usar salida del pype.
        close(fd[0]); //No uso la entrada del pipe.
        //execlp("ls","ls",NULL);
        execl("/work/bf/minmay", "minmya",NULL); //Acepta la ruta.
   
    }

    return 0;

}