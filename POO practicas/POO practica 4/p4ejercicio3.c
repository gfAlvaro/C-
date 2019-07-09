
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NPROC 5

typedef struct params{
	char nombre[10];
	int t_ejec;  // Se introducen
	int t_lleg;  
	int t_com;   // Se calculan
	int t_fin;
	int t_ret;
	int t_esp;
	
	} parametros;

void main(){
    
	int i, j, c=0;
	int quantum=3;
    	parametros aux[NPROC];
    	
	// Inicialización de los datos de procesos
	parametros procesos[NPROC];    
	strcpy(procesos[0].nombre, "A");
	procesos[0].t_ejec = 8;
	procesos[0].t_lleg = 0;
	procesos[0].t_com = 0;
	procesos[0].t_fin = procesos[0].t_ejec;
	procesos[0].t_ret = procesos[0].t_fin;
	procesos[0].t_esp = 0;
	
	strcpy(procesos[1].nombre, "B");
	procesos[1].t_ejec = 4;
	procesos[1].t_lleg = 1;
	
	strcpy(procesos[2].nombre, "C");
	procesos[2].t_ejec = 9;
	procesos[2].t_lleg = 2;
	
	strcpy(procesos[3].nombre, "D");
	procesos[3].t_ejec = 5;
	procesos[3].t_lleg = 3;
	
	strcpy(procesos[4].nombre, "E");
	procesos[4].t_ejec = 2;
	procesos[4].t_lleg = 4;
	
	for(i=0; i<NPROC; i++)
		aux[i]=procesos[i];

	while(1){
		for(j=0; j<NPROC; j++){
			if(aux[j].t_ejec != 0)
				c=1;
				break;
				}			
		if(c==0)
			exit(0);
			
		printf("voy\n");	
		if((aux[j].t_ejec = aux[j].t_ejec - quantum) < 0)
			aux[j].t_ejec = 0;


			
		printf("\nProceso | t_comienzo | t_final | t_retorno | t_espera\n");
		printf("-------------------------------------------------------\n");
			for(i=0; i<NPROC; i++){
				if(i==0)
					aux[i].t_com = 0;
				else
					aux[i].t_com = aux[i-1].t_fin;
				aux[i].t_fin = aux[i].t_com + aux[i].t_ejec;
				aux[i].t_ret = aux[i].t_fin - aux[i].t_lleg;
				aux[i].t_esp = aux[i].t_ret - aux[i].t_ejec;
				if(aux[i].t_ejec != 0)
					printf("   %s \t    %d \t\t %d \t   %d \t      %d\n", aux[i].nombre, aux[i].t_com, aux[i].t_fin, aux[i].t_ret, aux[i].t_esp);
				}
			}
	}


