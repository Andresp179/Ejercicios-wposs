#include<stdio.h>
int menu_inicio();
int menu_libro();
void Comienzo();
void Inicio();
int caseta();
int cantLibro();


main(){
	Comienzo();
	
}



void Comienzo(){
	int option=0;
	int repeat=0, optCaset=0, libro=0,ntLibro=0, nCaseta1=0,nCaseta2=0,nCaseta3=0;
	char vLibro[4][7]={"Las luces de Septiembre","El príncipe de la Niebla","El Palacio de Medianoche","Marina","La Sombra del Viento","El Juego del Ángel"};
	
	while(repeat==0){
		
		option=menu_inicio();
		
		while(option!=1 && option!=2 && option!=3){
				printf("Por favor,  Seleccione un numero que se encuentre en el rango del menu.\n ");
				option=menu_inicio();
		}
		
		switch(option){
			
			case 1:{
				libro=menu_libro();	
			//	for(int i=0;i<vLibro;i++)
			    int Libro=cantLibro();
				if( Libro>6){
					printf("Las opciones estan entre 1-6.. \n");
					Libro=cantLibro();
				} 
			    
			    
										
				break;
			}
			case 2:{
				optCaset=caseta();
				if(optCaset!=1 || optCaset!=2 || optCaset!=3){
					printf("Por favor escoger un valor en el rango de 1-3 \n");
					optCaset=caseta();
				}
				else{
					optCaset=caseta();
					if(optCaset==1){
						nCaseta1++;
						
					}
					if(optCaset==2){
						nCaseta2++;
						
					}
					if(optCaset==3){
						nCaseta3++;
						
					}
				}
				break;
			}			
			case 3:{
				repeat++;
				break;
			}			
		}
		
	}
}





int menu_inicio(){	
    	int r=0;

     printf("---Venta de Libros---\n");
     printf("---Menu Principal---\n ");
     printf("Por favor, Seleccionar una de las siguientes opciones: \n");
	 printf("1) Seleccionar libro. \n");
	 printf("2) Seleccionar caseta \n");	
	 printf("3) Salir \n");
     scanf("%d", &r);   
    return r;	
}
int  caseta(){
	int r=0;
	printf("---Por favor seleccione la caseta----\n");
	scanf("%d",&r);
	
	if(r<0 || r>3){
		printf("Por favor escoga una opcion entre 1-3 \n");
		scanf("%d",&r);
	}else{
		scanf("%d",&r);
	}
	return r;
}
int cantLibro(){
	int n=0;
	
	printf("Introduzca cantidad de libros. \n");
	scanf("%d",&n);
	return n;
	
}


int menu_libro(){
	
	int Lib=0;	
	printf(" Seleccione uno de los siguientes libros \n");
	printf(" 1) Las luces de Septiembre \n 2) El principe de la Niebla \n 3) El Palacio de Medianoche \n 4) Marina \n 5) La Sombra del Viento \n 6) El Juego del Ángel \n");
	scanf("%d", &Lib);
	return Lib;
	}
