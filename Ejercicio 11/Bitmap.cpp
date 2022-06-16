//Llamamos a las librerias a utilizar
#include <stdio.h>
#include<string.h>
#include<conio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#ifdef _WIN32
#include<windows.h>
#include<locale.h> 
#endif
using namespace std;
//Ejercicio de Bitmap, Elaborado por Andres Arturo Perez

//Metodos o funciones
void inicio();
void obtener_numero();
void gotoxy (int x, int y);
void interruptor(char *dato);
void bienvenida();
void limpiar_pantalla();


int main(){
	bienvenida();
	limpiar_pantalla();
	inicio();
	return 1;
}
//-------------------------------------------------------------
//Metoo donde empieza todo.
void inicio(){
	obtener_numero();
	char dato1[17];
	int contador=0;
	int contador2=0;
	char caracter;
	char confirma ='1';
	gotoxy(45,1);printf(" ");
	//-----------------
	do{
	caracter=getch();
		if(caracter == 13){//Condicional cuando opriman la tecla entrer				
		dato1[contador]='\0';
		break;
	}
	fflush( stdin );//limpiamos el buffer.	
	while(contador<17){
		caracter=getch();
		if(caracter == 13){//Condicional cuando opriman la tecla entrer				
		dato1[contador]='\0';
		break;
	    }else if(caracter == 8){//Condicional cuando oprima la tecla backpasce
	    	if(contador>0){
	    		contador--;
	    		printf("\b0\b");//Boramos el caracter mal colocado y tambien *.
			}
		}else if(caracter == 65 || caracter == 97){
			printf("A");
			dato1[contador]=caracter;
			contador++;
		}else if(caracter == 66 || caracter == 98){
			printf("B");
			dato1[contador]=caracter;
			contador++;
		}else if(caracter == 67 || caracter == 99){
			printf("C");
			dato1[contador]=caracter;
			contador++;
		}else if(caracter == 68 || caracter == 100){
			printf("D");
			dato1[contador]=caracter;
			contador++;
		}else if(caracter == 69 || caracter ==101){
			printf("E");
			dato1[contador]=caracter;
			contador++;
		}else if(caracter == 70 || caracter == 102){
			printf("F");
			dato1[contador]=caracter;
			contador++;
		}else if(caracter == 48){
			printf("0");
			dato1[contador]=caracter;
			contador++;
		}else if(caracter == 49){
			printf("1");
			dato1[contador]=caracter;
			contador++;
		}else if (caracter == 50){
			printf("2");
			dato1[contador]=caracter;
			contador++;
		}else if (caracter == 51){
			printf("3");
			dato1[contador]=caracter;
			contador++;
		}else if(caracter == 52){
			printf("4");
			dato1[contador]=caracter;
			contador++;
		}else if (caracter == 53){
			printf("5");
			dato1[contador]=caracter;
			contador++;
		}else if(caracter == 54){
			printf("6");
			dato1[contador]=caracter;
			contador++;
		}else if(caracter == 55){
			printf("7");
			dato1[contador]=caracter;
			contador++;
		}else if(caracter == 56){
			printf("8");
			dato1[contador]=caracter;
			contador++;
		}else if(caracter == 57){
			printf("9");
			dato1[contador]=caracter;
			contador++;
		}
	}
}while(caracter!=13);
//--------------------------------
	interruptor(dato1);
	gotoxy(3,22);printf(" "	);
	
	
}
//------------------------------------------------------------
//Metodo donde empieza todo.
void obtener_numero(){
	int i;
	int n=1;
	int x=44,y=1;
	printf("-----------Bienvenido al BitMap.---------");
	printf("\n Por favor, Digita un numero hexadecimal: ");
	gotoxy(x,y);printf("[");
	x++;
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	gotoxy(x,y);printf("0");
	x++;
	x++;
	gotoxy(x,y);printf("]");
	
	
	
	
	for( i =2 ;i<78 ; i++){
		gotoxy(i,3);printf("%c",205);
		gotoxy(i,24);printf("%c",205);		
		
	}
	for( i=6; i < 22; i++){
		gotoxy(5,i);printf("  Bit %d",n);
		n++;
		
	}
	for( i=6; i < 22; i++){
		gotoxy(20,i);printf("  Bit %d",n);
		n++;
		
	}
	for( i=6; i < 22; i++){
		gotoxy(35,i);printf("  Bit %d",n);
		n++;
		
	}
	for( i=6; i < 22; i++){
		gotoxy(50,i);printf("  Bit %d",n);
		n++;
		
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	
	
}
//-----------------------------------------------

//----------------------------------------------
//Metodo del puntero
void gotoxy (int x, int y) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}
//----------------------------------------

//---------------------------------------
//Metodo para encender los Bit
void interruptor(char *dato){
	int f;
	int i2;
	int P=0;
	int caso=1;
	//---------------------------------------Primer Fila--------------------------------------------------
	for( i2=6; i2 < 23; i2++){
		if(caso==5){
			caso=1;
			P++;
	   }
		switch(caso){
			case 1:{
				if(dato[P]=='8'||dato[P]=='9'||dato[P]=='A'|| dato[P]== 'a' || dato[P]=='B' || dato[P]=='b' ||dato[P]=='C' || dato[P]=='c'||dato[P]=='D' || dato[P]=='d'||dato[P]=='E'|| dato[P]=='e'||dato[P]=='F' || dato[P]=='f'){
					gotoxy(5,i2);printf(">");
				}
				caso++;
				break;
			}
			case 2:{
				if(dato[P]=='4'||dato[P]=='5'||dato[P]=='6'||dato[P]=='7'||dato[P]=='C'||dato[P]=='c'||dato[P]=='D'||dato[P]=='d'||dato[P]=='E'||dato[P]=='e'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(5,i2);printf(">");
				}
				caso++;
				break;
			}
			case 3:{
				if(dato[P]=='2'||dato[P]=='3'||dato[P]=='6'||dato[P]=='7'||dato[P]=='A'||dato[P]=='a'||dato[P]=='B'||dato[P]=='b'||dato[P]=='E'||dato[P]=='e'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(5,i2);printf(">");
				}
				caso++;
				break;
			}
			case 4:{
				if(dato[P]=='1'||dato[P]=='3'||dato[P]=='5'||dato[P]=='7'||dato[P]=='9'||dato[P]=='B'||dato[P]=='b'||dato[P]=='D'||dato[P]=='d'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(5,i2);printf(">");
				}
				caso++;
				break;
			}		
		}		
	}
	//------------------------Fin de la primera fila----------------------------------------------
	caso=1;
	//--------------------------Segunda Fila---------------------------------------------------
	for( i2=6; i2 < 23; i2++){
		if(caso==5){
			caso=1;
			P++;
	   }
		switch(caso){
			case 1:{
				if(dato[P]=='8'||dato[P]=='9'||dato[P]=='A'||dato[P]=='a'||dato[P]=='B'||dato[P]=='b'||dato[P]=='C'||dato[P]=='c'||dato[P]=='D'||dato[P]=='d'||dato[P]=='E'||dato[P]=='e'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(19,i2);printf(">");
				}
				caso++;
				break;
			}
			case 2:{
				if(dato[P]=='4'||dato[P]=='5'||dato[P]=='6'||dato[P]=='7'||dato[P]=='C'||dato[P]=='c'||dato[P]=='D'||dato[P]=='d'||dato[P]=='E'||dato[P]=='e'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(19,i2);printf(">");
				}
				caso++;
				break;
			}
			case 3:{
				if(dato[P]=='2'||dato[P]=='3'||dato[P]=='6'||dato[P]=='7'||dato[P]=='A'||dato[P]=='a'||dato[P]=='B'||dato[P]=='b'||dato[P]=='E'||dato[P]=='e'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(19,i2);printf(">");
				}
				caso++;
				break;
			}
			case 4:{
				if(dato[P]=='1'||dato[P]=='3'||dato[P]=='5'||dato[P]=='7'||dato[P]=='9'||dato[P]=='B'||dato[P]=='b'||dato[P]=='D'||dato[P]=='d'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(19,i2);printf(">");
				}
				caso++;
				break;
			}		
		}		
	}
	//--------------------------Fin de la segunda fila--------------------------------------------
	caso=1;
	//---------------------------Tercera fila-------------------------------------------
	for( i2=6; i2 < 23; i2++){
		if(caso==5){
			caso=1;
			P++;
	   }
		switch(caso){
			case 1:{
				if(dato[P]=='8'||dato[P]=='9'||dato[P]=='A'||dato[P]=='a'||dato[P]=='B'|| dato[P]=='b'||dato[P]=='C'|| dato[P]=='c'||dato[P]=='D'|| dato[P]=='d'||dato[P]=='E'|| dato[P]=='e'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(34,i2);printf(">");
				}
				caso++;
				break;
			}
			case 2:{
				if(dato[P]=='4'||dato[P]=='5'||dato[P]=='6'||dato[P]=='7'||dato[P]=='C'|| dato[P]=='c'||dato[P]=='D'|| dato[P]=='d'||dato[P]=='E'|| dato[P]=='e'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(34,i2);printf(">");
				}
				caso++;
				break;
			}
			case 3:{
				if(dato[P]=='2'||dato[P]=='3'||dato[P]=='6'||dato[P]=='7'||dato[P]=='A'|| dato[P]=='a'||dato[P]=='B'|| dato[P]=='b'||dato[P]=='E'|| dato[P]=='e'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(34,i2);printf(">");
				}
				caso++;
				break;
			}
			case 4:{
				if(dato[P]=='1'||dato[P]=='3'||dato[P]=='5'||dato[P]=='7'||dato[P]=='9'||dato[P]=='B'|| dato[P]=='b'||dato[P]=='D'|| dato[P]=='d'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(34,i2);printf(">");
				}
				caso++;
				break;
			}		
		}		
	}
	//----------------------------------Fin de la tercera fila------------------------------------------------
	caso=1;
	//---------------------------------Cuarta fila--------------------------------------------------
	for( i2=6; i2 < 23; i2++){
		if(caso==5){
			caso=1;
			P++;
	   }
		switch(caso){
			case 1:{
				if(dato[P]=='8'||dato[P]=='9'||dato[P]=='A'|| dato[P]=='a'||dato[P]=='B'|| dato[P]=='b'||dato[P]=='C'|| dato[P]=='c'||dato[P]=='D'|| dato[P]=='d'||dato[P]=='E'|| dato[P]=='e'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(49,i2);printf(">");
				}
				caso++;
				break;
			}
			case 2:{
				if(dato[P]=='4'||dato[P]=='5'||dato[P]=='6'||dato[P]=='7'||dato[P]=='C'|| dato[P]=='c'||dato[P]=='D'|| dato[P]=='d'||dato[P]=='E'|| dato[P]=='e'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(49,i2);printf(">");
				}
				caso++;
				break;
			}
			case 3:{
				if(dato[P]=='2'||dato[P]=='3'||dato[P]=='6'||dato[P]=='7'||dato[P]=='A'|| dato[P]=='a'||dato[P]=='B'|| dato[P]=='b'||dato[P]=='E'|| dato[P]=='e'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(49,i2);printf(">");
				}
				caso++;
				break;
			}
			case 4:{
				if(dato[P]=='1'||dato[P]=='3'||dato[P]=='5'||dato[P]=='7'||dato[P]=='9'||dato[P]=='B'|| dato[P]=='b'||dato[P]=='D'|| dato[P]=='d'||dato[P]=='F'|| dato[P]=='f'){
					gotoxy(49,i2);printf(">");
				}
				caso++;
				break;
			}		
		}		
	}
	//-----------------------------Fin de la cuarta fila............................................
}
//-----------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
//Metodo de bienvenia
void bienvenida(){
	 printf("\n**********************************************************\t ");
     printf("\n*                         BITMAP                         *\t ");
     printf("\n*                                                        *\t ");
     printf("\n*                   ^.^ Bienvenido ^.^                   *\t ");
     printf("\n**********************************************************\t\n ");
	int x=0;

    cout<<"CARGANDO COMPOMENTES";
	while(x <=6){
        cout<<".";
        Sleep(500);
        x++;
	}
	printf("\n");
	cout<<"ESPERE";
	while(x <=12){
        cout<<".";
        Sleep(500);
        x++;
	}
    cout<<endl<<endl;
    system("pause");

}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------
//Metodo de limpiar pantalla
void limpiar_pantalla(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
//----------------------------------------------------------
