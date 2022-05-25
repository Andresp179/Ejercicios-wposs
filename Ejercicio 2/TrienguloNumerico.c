#include<stdio.h>

void triangulo_numerico(int num);

main()
{
	int num;
	printf("Introduzca numero..\n");
	scanf("%d",&num); // recibe y asigna el valor a la variable
	
      triangulo_numerico(num);
	
}

void triangulo_numerico(int num){ // metodo de ordenar numeros de mayor a menor
	int t1,t2,aux;
	t1=num;
	t2=1;
	aux=num;
	int i,u;
	for( i=0;i<t1;i++){
		for( u=0;u<t2;u++){
			
			printf("%d",aux);
			aux--;
			
		}
		aux=t1;
		t2++;
		printf("\n");
	}
	
}

