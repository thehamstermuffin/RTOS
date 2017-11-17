/*
Ruben Omar Valdez Salinas

http://aprendiendo-software.blogspot.mx/2011/12/algoritmo-de-dekker-version-5.html
https://es.slideshare.net/nerexi/algoritmos-de-dekker-55306714
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>//fork, sleep

#define p1_puede_entrar	*(varshar+1)
#define p2_puede_entrar	*(varshar+2)



int main(int argc, char **argv){

        int shmID;
	int retShmem;
	int bufsize=4096;
        char str[32];
        char *retptr;
        const void *dir;
        int *varshar;
        pid_t pid;


	if((retShmem = shmget(IPC_PRIVATE, bufsize, 0777)) == -1){//0666 son los permisos de ejecucion lectura y escritura
                perror("shmget FAILURE !!!");
                exit(EXIT_FAILURE);
        }


        shmID = retShmem;

        printf("Sharedmemory = %d\n",shmID);
        sprintf(str,"ipcs -m --id %i",shmID);
        system(str);



        if(*(retptr=shmat(shmID, NULL, 0666)) == -1){
                sprintf(str,"shmat FAILURE, %d\n",shmID);
                perror(str);
                exit(EXIT_FAILURE);
        }
        printf("Sharedmemory attached at %p\n",retptr);
        sprintf(str,"ipcs -m --id %i",shmID);
        system(str);


        varshar = (int *)retptr;
        *varshar = 5;
        printf("Contenido variable compartida = %i\n",*varshar);
	p1_puede_entrar = 0;		// Algoritmo de Dekker
	p2_puede_entrar = 0;
	*varshar = 1;			// Turno tarea 1


        pid = fork();
	// se tiene que usar wait y waitpid para sincronizar los procesos
        if(pid==0){     //Segmento de codigo para proceso hijo
                while(1){
                        printf("Se esta en el proceso hijo\n");
                        p1_puede_entrar = 1;
			while(p2_puede_entrar){
				if(*varshar == 2){
					p1_puede_entrar = 0;
					while(*varshar == 2);
					p1_puede_entrar = 1;
				}
				printf("Proceso hijo dice HOLA !!!!!!!!\n");
				sleep(1);
				*varshar = 2;
				p1_puede_entrar = 0;
				printf("Saliendo del proceso hijo\n");
			}
		}
        }
	else{          //Segmento ed codigo para proceso padre
		while(1){
                        printf("Se esta en el proceso padre\n");
                        p2_puede_entrar = 1;
			while(p1_puede_entrar){
                                if(*varshar == 1){
                                        p2_puede_entrar = 0;
                                        while(*varshar == 1);
                                        p2_puede_entrar = 1;
                                }
                                printf("Proceso padre dice HOLA !!!!!!!!\n");
                                sleep(3);
				*varshar = 1;
                                p2_puede_entrar = 0;
			}
		}
        }







        exit(EXIT_SUCCESS);
}

