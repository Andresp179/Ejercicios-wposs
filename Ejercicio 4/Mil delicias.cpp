#include<stdio.h>



void login();
int my_strlen(char *user);
int Opcion();
void Menu();
int Factura(int n,int n2);
int cant, cant1,cant2;
int valor1, valor2, valor3, valor4,resultado;


main(){
	
login();	
	
}

void login(){
	char user[10]; 
	char pass[10];
	
	printf("*************Programa Mil delicias!!!!!!!!   \n");
	
	printf("Introduzca Usuario..\n");
	scanf("%d", &user);
	printf("Introduzca Password..\n");
    scanf("%d", &pass);
	
	 int cant1=my_strlen(user);
	 int cant2=my_strlen(pass);
	
	if(cant1<3 || cant1>10){		
	 printf("El rango permitido esta entre 3 y 10 caracteres");
		if(cant2>4){
			printf("La cantidad permitida son 4");
		}		
	}else{
		Menu();
		
	}
	
}

int my_strlen(char* dato){
    int longitud=0;
	while (dato[longitud]!='\0'){
        longitud++;  
    } 
	return longitud;
}
void Menu(){
	int op,Opc=0;
	op=Opcion();
    
	switch(op){
	
		case 1:{
		    printf("Ha escogido plato de entrada \n cuantos platos desea? \n");
		    scanf("%d",&cant);	
			valor1=3000;
		    resultado=Factura(valor1, cant);
			printf("El valor a pagar es: %d ", resultado );	    			  
			break;
		}
		case 2:{
			printf("Ha escogido un plato fuerte \n cuantos platos desea? \n");
			scanf("%d",&cant);
			valor2=2900;
			 resultado=Factura(valor2, cant);
			printf("El valor a pagar es: %d ", resultado );	
			break;
		}
		case 3:{			
			printf("Ha escogido postre \n Cuantos postres desea? \n");
			scanf("%d",&cant);
			valor3=1800;
			resultado=Factura(valor3, cant);
			printf("El valor a pagar es: %d ", resultado );	
			break;
		}
		case 4:{
			printf("Ha escogido bebida \n Cuantas bebidas desea? \n  ");
			scanf("%d",&cant);
			valor4=1900;
			resultado=Factura(valor4, cant);
			printf("El valor a pagar es: %d ", resultado );	
			break;
		}		
	}	
}
int Factura(int n, int n2){

 return n*n2;	
	
}

int Opcion(){	
	int result;	
	printf("Escoja Opcion...\n 1: Plato de Entrada \n 2: Plato Fuerte \n 3: Postre \n 4: Bebidas.\n 5: Generar Factura\n");
	scanf("%d",&result);
	
	return result;	
}
