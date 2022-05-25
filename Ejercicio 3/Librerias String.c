#include<stdio.h>
#include<string.h>

int my_strlen(char *cadena);


main()
{
	
inicio();	
}

void inicio(){

	int opcion=0; //variable que vamos a obtener el valor del manu
	//------------------------------------------------------------------------------
	int repeticiones=0;//Variable la cual se utilizara para el manejo del while (manejo del sistema).
	//------------------------------------------------------------------------------
	while(repeticiones==0){
		limpiar_pantalla();
		opcion=menu_principal();//Mostramos el menu principal y obtenemos el valor seleccionado.
		while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 && opcion!=6 && opcion!=7 && opcion!=8){//Solicitamos que el usuario si o si seleccione una de las opciones mostrada---
		    if(opcion<1 || opcion>8){
		    	limpiar_pantalla();		    	
		    	printf("\nPor favor,  Seleccione un numero que se encuentre en el rango del menu.\n ");
		    	opcion=menu_principal();
			}
		} 
	//-------------------------------------------------------------------------------
	char d3[50];
	switch(opcion){
		//---------------------Caso N°1 Strlen Metodo de longitud-----------------------------
		case 1:{
			limpiar_pantalla();
			char confirma='1';//Variable para connfirma los mensajes recibidos.
			char frase[50];
			int longit;
			gets(d3);
			printf("\n**********************************************************\t ");
            printf("\n*                 Libreria: Strlen                       *\t ");
            printf("\n*                                                        *\t ");
            printf("\n*          Metodo de longitud de una cadena.             *\t ");
            printf("\n**********************************************************\t\n ");
            printf("\nPor favor,  Digite una frase: ");
            gets(frase);
            longit=my_strlen(frase);
            printf("\nLa longitud de la frase es: %d",longit);
            do{
			printf("\n--------------------------------------------------------- \n");
            fflush( stdin );//limpiamos el buffer.
			printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
			scanf("%c",&confirma);   
			}while(confirma!=10);
			break;
		}
		//-----------------fin del caso N°1 strlen Metodo de longitud------------------------------
		
		//---------------------Caso N°2 strcat Metodo de concatenar caracteres----------------------
		case 2:{
			limpiar_pantalla();
			char confirma='1';//Variable para confirma los mensajes recibidos.
			char frase1[50], frase2[50];
			gets(d3);
			printf("\n**********************************************************\t ");
            printf("\n*                 Libreria: Strcat                       *\t ");
            printf("\n*                                                        *\t ");
            printf("\n*          Metodo para concatenar dos cadenas            *\t ");
            printf("\n**********************************************************\t\n ");
            printf("\nPor favor,  Digite la primera frase: ");
			gets(frase1);
			printf("\nPor favor, Digite la segunda frase: ");
			gets(frase2);
			printf("\nLa frase concatenada es: %s",my_strcat(frase1,frase2));
			do{
			printf("\n--------------------------------------------------------- \n");
            fflush( stdin );//limpiamos el buffer.
			printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
			scanf("%c",&confirma);   
			}while(confirma!=10);
			break;
		}
		//-------------------------Fin del caso N°2 strcat Metodo de concatenar caracteres---------------
		
		//------------------Caso N°3 strcpy Metodo de copiar cadena-----------------
		case 3:{
			limpiar_pantalla();
			char confirma='1';//Variable para confirma los mensajes recibidos.
			char frase1[50], frase2[50];
			gets(d3);
			printf("\n**********************************************************\t ");
            printf("\n*                 Libreria: Strcpy                       *\t ");
            printf("\n*                                                        *\t ");
            printf("\n*        Metodo para copiar una cadena a otra.           *\t ");
            printf("\n**********************************************************\t\n ");
            printf("\nPor favor,  Digite la primera frase: ");
			gets(frase1);
			printf("\nPor favor, Digite la segunda frase: ");
			gets(frase2);
			printf("\nLa frase copiada de la frase #2 en la frase #1 es: %s",my_strcpy(frase1,frase2));
			do{
			printf("\n--------------------------------------------------------- \n");
            fflush( stdin );//limpiamos el buffer.
			printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
			scanf("%c",&confirma);   
			}while(confirma!=10);
            
			break;
		}
		//---------------------------Fin del caso N°3 strcpy Metodo de copiar cadena-------------
		
		//--------------------------Caso N°4 strncat Metodo concatena un numero de caracteres en otra cadena-----------------
		case 4:{
			limpiar_pantalla();
			char confirma='1';//Variable para confirma los mensajes recibidos.
			char frase1[50], frase2[50];
			int num_caracteres=0;
			gets(d3);
			printf("\n**********************************************************\t ");
            printf("\n*                 Libreria: Strncat                       *\t ");
            printf("\n*    Metodo para concatenar un numero de caracteres       *\t ");
            printf("\n*                   en otra cadena.                       *\t ");
            printf("\n**********************************************************\t\n ");
            printf("\nPor favor,  Digite la primera frase: ");
			gets(frase1);
			printf("\nPor favor, Digite la segunda frase: ");
			gets(frase2);
			printf("\nPor favor, Digite el numero de caracteres que deseas concatenar: ");
			scanf("%d",&num_caracteres);
			printf("\nLa frase concatenada es: %s",my_strncat(frase1,frase2,num_caracteres));
			do{
			printf("\n--------------------------------------------------------- \n");
            fflush( stdin );//limpiamos el buffer.
			printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
			scanf("%c",&confirma);   
			}while(confirma!=10);
			
			break;
		}
		//--------------------------- fin del caso N°4 strncat Metodo concatena un numero de caracteres en otra cadena---------------
		
		//------------------- caso N°5 strncpy Metodo copia un numero de caracteres en otra cadena---------------
		case 5:{
			limpiar_pantalla();
			char confirma='1';//Variable para confirma los mensajes recibidos.
			char frase1[50], frase2[50];
			int num_caracteres=0;
			gets(d3);
		
            printf("\n* Libreria: Strncpy *\t ");
            printf("\n*       Metodo para copiar un numero de caracteres        *\t ");
            printf("\n*                   en otra cadena.                       *\t ");
            printf("\nPor favor,  Digite la primera frase: ");
			gets(frase1);
			printf("\nPor favor, Digite la segunda frase: ");
			gets(frase2);
			printf("\nPor favor, Digite el numero de caracteres que deseas copiar: ");
			scanf("%d",&num_caracteres);
			printf("\nLa frase copiada de la frase #2 en la frase #1 es: %s",my_strncpy(frase1,frase2,num_caracteres));
			do{
			printf("\n--------------------------------------------------------- \n");
            fflush( stdin );//limpiamos el buffer.
			printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
			scanf("%c",&confirma);   
			}while(confirma!=10);
			break;
		}
		//-------------------------Fin del caso N°5 strncpy Metodo copia un numero de caracteres en otra cadena----------------------
		
		//--------------------------Caso N°6 Strcmp Metodo compara dos cadenas, retorna 0 si son exactamente iguales. Retorna -1 si la cadena 1 es menor que la cadena 2, retorna 1 si la cadena 1 es mayor que la cadena 2.-------------------
		case 6:{
			limpiar_pantalla();
			char confirma='1';//Variable para confirma los mensajes recibidos.
			char frase1[50], frase2[50];
			gets(d3);
		    printf("\n* Libreria: Strcmp *\t ");
            printf("\n*         Metodo  que compara dos cadenas, *\t ");
            printf("\n* retorna 0 si son exactamente iguales *\t ");
            printf("\n*  Retorna -1 si la cadena 1 es menor que la cadena 2. *\t ");
            printf("\n*  Retorna 1 si la cadena 1 es mayor que la cadena 2.    *\t ");
            printf("\nPor favor,  Digite la primera frase: ");
			gets(frase1);
			printf("\nPor favor, Digite la segunda frase: ");
			gets(frase2);
			
			int d3=my_strcmp(frase1,frase2);
	        if(d3==0){
		       printf("\nLas frase son exactamente iguales. [ %d ]",d3);
         	}
	        if(d3==1){
		       printf("\nLa frase #1 es mayor a la frase #2 [ %d ]",d3);
	        }
	        if(d3==-1){
	           printf("\nLa frase #1 es menor que la frase #2 [ %d ]",d3);
	          }
	          do{
			printf("\n--------------------------------------------------------- \n");
            fflush( stdin );//limpiamos el buffer.
			printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
			scanf("%c",&confirma);   
			}while(confirma!=10);
            
			break;
		}
		//----------------------Fin del caso N°6 strncpy Metodo compara dos cadenas, retorna 0 si son exactamente iguales. Retorna -1 si la cadena 1 es menor que la cadena 2, retorna 1 si la cadena 1 es mayor que la cadena 2.--------------
		
		
		//------------------------ Caso N°7 Strncmp Metodo compara un numero de caracteres de ambas cadena,  retorna 0 si son exactamente iguales, retorna -1 si la cadena 1 es menor que la cadena 2, retorna 1 si la cadena 1 es mayor que la cadena 2.-------------------------------------------------------------
		case 7:{
			limpiar_pantalla();
			char confirma='1';//Variable para confirma los mensajes recibidos.
			char frase1[50], frase2[50];
			int num_caracteres=0;
			gets(d3);
			printf("\n****************************************************************\t ");
            printf("\n*                      Libreria: Strncmp                       *\t ");
            printf("\n* Metodo  que compara un numero de caracteres de ambas cadena, *\t ");
            printf("\n*          retorna 0 si son exactamente iguales.               *\t ");
            printf("\n*     Retorna -1 si la cadena 1 es menor que la cadena 2.      *\t ");
            printf("\n*     Retorna 1 si la cadena 1 es mayor que la cadena 2.       *\t ");
            printf("\n****************************************************************\t\n ");
            printf("\nPor favor,  Digite la primera frase: ");
			gets(frase1);
			printf("\nPor favor, Digite la segunda frase: ");
			gets(frase2);
			printf("\nPor favor, Digite el numero de caracteres que deseas copiar: ");
			scanf("%d",&num_caracteres);
			int d3=my_strncmp(frase1,frase2,num_caracteres);
	        if(d3==0){
		       printf("\nLas frase son exactamente iguales. [ %d ]",d3);
         	}
	        if(d3==1){
		       printf("\nLa frase #1 es mayor a la frase #2 [ %d ]",d3);
	        }
	        if(d3==-1){
	           printf("\nLa frase #1 es menor que la frase #2 [ %d ]",d3);
	          }
	          do{
			printf("\n--------------------------------------------------------- \n");
            fflush( stdin );//limpiamos el buffer.
			printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
			scanf("%c",&confirma);   
			}while(confirma!=10);
			break;
		}
		//----------------------------Fin del caso N°7 strncmp Metodocompara un numero de caracteres de ambas cadena,  retorna 0 si son exactamente iguales, retorna -1 si la cadena 1 es menor que la cadena 2, retorna 1 si la cadena 1 es mayor que la cadena 2.---------
		
		//---------------------Caso N°8 Salida-----------------
		case 8:{
			repeticiones++;
			break;
		}
		//---------------------Fin del caso N°8 salida--------------
		
	}
		
  }
}
//---------------
char * my_strcat(char *dato1, char *dato2){	//Para concatenar varias cadenas
	int td1=my_strlen(dato1);
	int td2=my_strlen(dato2);
    int largo=0;
	while (dato2[largo]!='\0'){
        dato1[td1]=dato2[largo];
        largo++;
        td1++;
    }
    dato1[td1]='\0';
	return dato1;
}
//-----------------
int my_strlen(char* dato){ //Para saber la longitud
    int longitud=0;
	while (dato[longitud]!='\0'){
        longitud++;  
    } 
	return longitud;
}
//--------------------
char * my_strncat(char *dato1, char *dato2, int n){ //Metodo para concatenar un numero de caracteres a otra cadena.
	int td1=my_strlen(dato1);
	int td2=my_strlen(dato2);
    int largo=0;
	while (dato2[largo]!='\0' && largo<n){
        dato1[td1]=dato2[largo];
        largo++;
        td1++;    
    } 
    dato1[td1]='\0';
	return dato1;
}
//---------------
char * my_strncpy(char *dato1,char *dato2,int n){
	int t=my_strlen(dato1);
	int x, i;
	for(x=0;x<t;x++){
		dato1[x]='\0';
	}
	for(i=0;i<n;i++){
		dato1[i]=dato2[i];
	}
	return dato1;
}
//-------------
char * my_strcpy(char *dato1, char *dato2){
	  int largo=0;
   while (dato2[largo]!='\0'){
        dato1[largo]=dato2[largo]; 
        largo++;
    } 
    dato1[largo++]=dato2[largo++];
	return dato2;
}

int my_strcmp(char *dato1, char*dato2){
	int result,largo=0, A1=0, A2=0;
	
	do{
		if(dato[largo]!='\0'){
			A1++;
		}else{
			A1=-1
		}
		if(dato2[largo]!='\0'){
			A2++;
		}else{
			A2=-1;
		}
		if(A1==A2){
			if(dato1[largo]==dato2[largo]){
			result=0;			
		}else{
			if(dato1[largo]>dato2[largo]){
					result=1;
				}else{
					result=-1;
				}			
		}	
	else{
			if(A1>A2){
				result=1;
			}else{
				result=-1;
			}
		}
		if(A1==-1 && A2==-1){
			return result;
		}
		largo++;
		
	}
	while(result=0);
	return result;	
}
}
int my_strncmp(char* dato1,char* dato2,int n){
	int r;
	int i=0;
	int largo=0;
	int t1=0;
	int t2=0;
	
	do{
		
		if(dato1[largo]!='\0'){
			t1++;	
		}else{
			t1=-1;
		}
		if(dato2[largo]!='\0'){
			t2++;
		}else{
			t2=-1;
		}
		if(t1==t2){
			if(dato1[largo]==dato2[largo]){
			printf("[%d]si son iaguales \n",largo);
			r=0;
			}else{
				printf("[%d] no lo son \n",largo);
				if(dato1[largo]>dato2[largo]){
					r=1;
				}else{
					r=-1;
				}
		
			}
		}else{
			if(t1>t2){
				r=1;
			}else{
				r=-1;
			}
		}
		if(t1==-1 && t2==-1){
			return r;
		}
		largo++;
		i++;
		
	}while (r==0 && i<n);	
	return r;
}
