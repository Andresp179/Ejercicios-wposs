#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LONG 100

// Ejercicio venta de libros. Elaborado por Andres Arturo Perez

void filtroPorCasetas(int ventas[3][6], char libros[6][2][LONG]);
void filtroPorLibros(int ventas[3][6], char libros[6][2][LONG]);
void totalVendidos(int ventas[3][6], char libros[6][2][LONG]);
void registrarVenta(int ventas[3][6], int caseta, int libro);
void mostrarLibros(char libros[6][2][LONG]);
void menuRegistrarVenta(int ventas[3][6], char libros[6][2][LONG]);

int main(){
	int ventas[3][6];
	memset(ventas, 0, sizeof(ventas));
	int op = 0;
	char libros[6][2][LONG] = {
		{ 	{'2','4','0','0','0'},
			{'L','a','s',' ','l','u','c','e','s',' ','d','e',' ','s','e','p','t','i','e','m','b','r','e','\0'}
		},{ 	{'2','8','0','0','0'},
			{'E','l',' ','p','r','i','n','c','i','p','e',' ','d','e',' ','l','a',' ','n','i','e','b','l','a','\0'}
		},{ 	{'4','5','0','0','0'},
			{'E','l',' ','p','a','l','a','c','i','o',' ','d','e',' ','m','e','d','i','a','n','o','c','h','e','\0'}
		},{ 	{'1','5','0','0','0'},
			{'M','a','r','i','n','a','\0'}
		},{ 	{'2','7','0','0','0'},
			{'L','a',' ','s','o','m','b','r','a',' ','d','e','l',' ','v','i','e','n','t','o','\0'}
		},{ 	{'3','0','0','0','0'},
			{'E','l',' ','j','u','e','g','o',' ','d','e','l',' ','a','n','g','e','l','\0'}
		}};
	do{
		printf("\tMENU PRINCIPAL\n");
		printf("1. Registrar venta\n");
		printf("2. Total vendidos\n");
		printf("3. Filtro por libros\n");
		printf("4. Filtro por casetas\n");
		printf("5. Salir\n");
		printf("Digite opcion: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				menuRegistrarVenta(ventas, libros);
				break;
			case 2:
				totalVendidos(ventas, libros);
				break;
			case 3:
				filtroPorLibros(ventas, libros);
				break;
			case 4:
				filtroPorCasetas(ventas, libros);
				break;
		}
	}while(op!=5);
	
	system("pause");
	return 0;
}

void filtroPorCasetas(int ventas[3][6], char libros[6][2][LONG]){
	int total, aux, aux2;
	int ventasCasetas[3][2] = { {1, 0}, {2, 0}, {3, 0} };
	printf("\tCantidad ventas por casetas (menor a mayor)\n");
	for(int i=0; i<3; i++){
		total = 0;
		for(int j = 0; j<6; j++){
			total+=ventas[i][j];
		}
		ventasCasetas[i][1] = total;
	}
	for(int i=1; i<3; i++){
		for(int j=0; j<3-i; j++){
			if(ventasCasetas[j][1]>ventasCasetas[j+1][1]){
				aux = ventasCasetas[j][0];
				aux2 = ventasCasetas[j][1];
				ventasCasetas[j][0]=ventasCasetas[j+1][0];
				ventasCasetas[j][1]=ventasCasetas[j+1][1];
				ventasCasetas[j+1][0]=aux;
				ventasCasetas[j+1][1]=aux2;
			}
		}
	}
	for(int j = 0; j<3; j++){
			printf("Caseta %d: vendio %d libros\n", ventasCasetas[j][0], ventasCasetas[j][1]);
	}
	
}

void filtroPorLibros(int ventas[3][6], char libros[6][2][LONG]){
	int ventasEjemplares[6][2]={ {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} };
	int aux = 0, aux2 = 0;
	printf("\tCantidad ventas por libros (mayor a menor)\n");
	for(int i=0; i<3; i++){
		for(int j = 0; j<6; j++){
			ventasEjemplares[j][1]+=ventas[i][j];
		}
	}
	for(int i=1; i<6; i++){
		for(int j=0; j<6-i; j++){
			if(ventasEjemplares[j][1]<ventasEjemplares[j+1][1]){
				aux = ventasEjemplares[j][0];
				aux2 = ventasEjemplares[j][1];
				ventasEjemplares[j][0]=ventasEjemplares[j+1][0];
				ventasEjemplares[j][1]=ventasEjemplares[j+1][1];
				ventasEjemplares[j+1][0]=aux;
				ventasEjemplares[j+1][1]=aux2;
			}
		}
	}
	for(int j = 0; j<6; j++){
			printf("%s: %d\n", libros[ventasEjemplares[j][0]][1], ventasEjemplares[j][1]);
	}
}

void totalVendidos(int ventas[3][6], char libros[6][2][LONG]){
	int ventasEjemplares[6][2]={ {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} };
	int ventaLibro = 0, totalVenta = 0;
	printf("\tTotal ventas libros\n");
	for(int i=0; i<3; i++){
		for(int j = 0; j<6; j++){
			ventasEjemplares[j][1]+=ventas[i][j];
		}
	}
	for(int j = 0; j<6; j++){
			ventaLibro = atoi(libros[ventasEjemplares[j][0]][0]) * ventasEjemplares[j][1];
			totalVenta += ventaLibro;
			printf("%s: %d - $%d\n", libros[ventasEjemplares[j][0]][1], ventasEjemplares[j][1], ventaLibro);
	}
	printf("Total dinero: $%d\n", totalVenta);
}

void registrarVenta(int ventas[3][6], int caseta, int libro){
		ventas[caseta-1][libro-1]+=1;
}

void mostrarLibros(char libros[6][2][LONG]){
	printf("\tLibros\n");
	int j = 1;
	for(int i=0; i<6; i++){
		printf("%d. %s\n", j, libros[i][1]);
		j++;
	}
}

void menuRegistrarVenta(int ventas[3][6], char libros[6][2][LONG]){
	int op = 0, libroSel = 0;
	do{
		printf("\tCASETAS\n");
		printf("1. Caseta 1\n");
		printf("2. Caseta 2\n");
		printf("3. Caseta 3\n");
		printf("Digite opcion: ");
		scanf("%d", &op);
		do{
			mostrarLibros(libros);
			printf("Digite opcion: ");
			scanf("%d", &libroSel);
		}while(libroSel<1 || libroSel>6);
		registrarVenta(ventas, op, libroSel);
	}while(op<1 || op>3);
}

