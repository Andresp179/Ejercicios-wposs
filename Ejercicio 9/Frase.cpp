//Llamamos las librerias.
#include <stdio.h>
#include<locale.h> 

#ifdef _WIN32
#include<windows.h>
#endif

//Ejercicio de Frase,Elaborado por Andres Arturo Perez

//Declaramos los metodos o funcionalidades.
void inicio();
char* obtener_frase(char* frase);
void punto2(char* frase);
void punto3(char* frase);
void punto4(char* frase);
void punto5(char* frase);
void punto6(char* frase);
void punto7(char* frase);
int strlen(char* frase);
void palabra_repetida(char* frase ,int p1,int p2);
void palindroma(char* frase,int p1,int p2,char* pantalla);
void limpiar_pantalla();



int main(){
	setlocale(LC_CTYPE, "Spanish");//funcion que nos ayuda a utilizar caracteres especiales en los printf como ó, é ....
	inicio();
	printf("\nProceso terminado...\n\n");
	//devolvemos el control al sistema
   system("pause");
   return 0;
}

//Metodo de inicio
void inicio(){
	int tamano=0;//Declaramos y definimosla variable para obtener el tamaño de la cadena.
	char frase [60]; //Declaramos la variable para obtener la frase.
	obtener_frase(frase);//obtenemos la frase.
	tamano=strlen(frase);//obtenemos el tamaño de la frase.
	//printf("la frase es: %s",frase);//Comprovamos si en verdad esta guardando la frase
	//printf("\nel tamaño es: %d",tamano);//
	//--------------------------------------------------------------------------------------------------------------
	//validamos que la frase digitada por el usuario sea inferior o igual a 50 caracteres.
	while(tamano>=50){
		limpiar_pantalla();//Limpiamos la pantalla
		printf("\n-------------------------------------------------");
		printf("\nOjo superaste el numero de caracteres especifico.\nRecuerda que no debe superar los 50 caracteres");
		printf("\n-------------------------------------------------\n");
		obtener_frase(frase);
		tamano=strlen(frase);
	}
	//----------------------------------------------------------------------------------------------------------------
	punto2(frase);
	punto3(frase);
	punto4(frase);
	punto5(frase);
	punto6(frase);
	punto7(frase);
}

//Metodo del punto N°2
void punto2(char* frase){
	char pantalla[60];
	int tam=strlen(frase);//Obtenemos el tamaño de la frase.
	int palabras=0;	
	int pun_inicio=0,pun_fin=0;//Definimos los punteros que vamos a utilizar para recorrer la frase.
	//-------------------------------------------------------------------------
	//Mostramos un mensaje ilustre al metodo.
	printf("\n----------------------------------------------");
	printf("\n-------------- Punto N°2 ---------------\n");
	printf("--- Verifica si la palabra es palindromo ---");
	printf("\n----------------------------------------------\n");
	//--------------------------------------------------------------------------
	if(frase[tam-1]==' '){
		palabras--;
	}
	
	for(int i=0;i<tam;i++){
		
		pun_inicio=pun_fin;
		
		
		while(frase[pun_fin]!=' '&& frase[pun_fin]!='\0'){
			pun_fin++;
		
		}
				
		
		if(frase[pun_fin]=='\0'){
			palabras++;	
			i=tam+1;
			palindroma(frase,pun_inicio,pun_fin-1,pantalla);
			break;
		}
		
		if(pun_fin>pun_inicio){
			palabras++;	
				palindroma(frase,pun_inicio,pun_fin-1,pantalla);			
		
		}
		
		pun_fin++;
	}
	printf("\n----------------------------------------------\n");
	printf("\n###############################################\n");
	
}


//Metodo del punto N°3

void punto3(char* frase){
	int tam=strlen(frase);//Obtenemos el tamaño de la frase.
	int punt_inicio=0,punt_fin=0;//Definimos los punteros que vamos a utilizar para recorrer la frase.
	int punt_aux1=0,punt_aux2=0;//Variables auxiliares para los punteros.
	//-------------------------------------------------------------------------
	//Mostramos un mensaje ilustre al metodo.
	printf("\n----------------------------------------------");
	printf("\n-------------- Punto N°3 ---------------\n");
	printf("--- Verifica si la frase existe dos(2) veces ---");
	printf("\n----------------------------------------------\n");
	//-------------------------------------------------------------------------
	//Preguntamos si desde un principio el usuario dijito la frase con un espacio al principio.
	if(frase[punt_fin]==' '){
		punt_fin++;
		punt_aux1++;
		punt_aux2++;
	}
	//Ya con el tamaño obtenido realizamos un ciclo para revisar caracter por caracter.
	for(int i=0;i<tam;i++){
		
		punt_inicio=punt_fin;//por cada ciclo va aumentando los punteros es decir recorremos toda la cadena des principio a fin al mismo tiempo.
		
		//Validamos si en el en la frase hay un espacio,salte al siguiente caracter.
		while(frase[punt_fin]!=' '&& frase[punt_fin]!='\0'){
			punt_fin++;
		
		}			
		 //Comparamos si del puntero final es Mayor a puntero inicial, entonces llamamos a la función palabra_repetida.
		 if(punt_fin>punt_inicio){
			palabra_repetida(frase,punt_inicio,punt_fin);
						
		}
		//Una vez verifico el ultimo caracterde la frase, usamos el breack para terminar el ciclo.
		if(frase[punt_fin]=='\0'){
			i=tam+1;
			break;
		}
		
		punt_fin++;
	}
	printf("\n----------------------------------------------\n");
	printf("\n###############################################\n");
	
}
//Metodo para saber si la palabra se repite
void palabra_repetida(char* frase ,int p1,int p2){//Los parametros recibidos son: la frase, el punto del inicio y el punto del final

	int tama=strlen(frase);//obtenemos el tamaño de la frase.	
	int pun_inicio=0,pun_fin=0;//Variable del puntero inicio y puntero final.
	int s=0;//Variable para validar.
	int aux2=0;//Variables auxilires
	
	if(frase[pun_fin]==' '){
		pun_fin++;
	}
	
	while(pun_fin<tama){
	
		pun_inicio=pun_fin;
		
		
		while(frase[pun_fin]!=' '&& frase[pun_fin]!='\0'){
			pun_fin++;
		
		}			

			int aux=p1;
			int auxp=pun_inicio;
			int aux3=0;
			
			while(aux<p2 && auxp<pun_fin ){
			
				if(frase[pun_fin]==' '|| frase[pun_fin] == '\0'){
										
					if(frase[aux]!=frase[auxp] || aux==auxp){
						aux3++;
						
					}	
			    }
					aux++;	
					auxp++;
			}
			
			if(aux3==0){
				aux2++;
				aux=p1;
				auxp=pun_inicio;
					
				while(auxp<pun_fin ){
					frase[auxp]='^';
					auxp++;
			    }
			}
		
		pun_fin++;	
		
	}
	//Obtenemos la palabra por caracteres de la palabra que se repite
		if(frase[p1]!='^'){
		int q=p1;
		printf(" [ ");
		while(q<p2){
			printf("%c",frase[q]);
			q++;
		}
		printf(" ] ");
		printf(" La palabra");
		if(aux2==0){
				
			printf("  no se repite. \n");
		}else{
			aux2++;
			printf("  si se repite en [%d] ocasiones. \n",aux2);
		}
		
		}
	//-----------------------------------------------------------			
}

//Metodo del punto N°4
void punto4 (char* frase){
	//Declaramos y definimos las variables a utillizar.
	int tam=strlen(frase);//Obtenemos el tamaño de la frase
	int palabras=0;//Variable para obtener la cantidad exacta de palabras
	int pun_inicio=0,pun_fin=0;// variables auxiliares.
	//-------------------------------------------------------------------------
	//Mostramos un mensaje ilustre al metodo.
	printf("\n----------------------------------------------");
	printf("\n-------------- Punto N°4 ---------------\n");
	printf("----- Cantidad de palabras en la Frase ------");
	printf("\n----------------------------------------------\n");
	//-------------------------------------------------------------------------
	//Ya con el tamaño obtenido realizamos un ciclo para revisar caracter por caracter
	for(int i=0;i<tam;i++){
		
		//Comprombamos los espacios en blanco
		while(frase[pun_fin]!=' '&& frase[pun_fin]!='\0'){
			pun_fin++;
			palabras++;
		}
				
		//Una vez comprobado el recorrido, es decir cuando llegue al utimo caracter, muestra la cantidad de palabras
		if(frase[pun_fin]=='\0'){
			printf("\nLa cantidad de que contiene la frase digitada.\nEs de [%d] Palabras.\n",palabras);//Mostramos la cantidad de caracteres que tiene la frase
			i=tam+1;
			break;
		}
		
		pun_fin++;
	}
	printf("\n----------------------------------------------\n");
	printf("\n###############################################\n");	
}


//Metodo del punto N°5
void punto5(char* frase){
	
	int t=strlen(frase);//Obtenemos el tamaño de la frase.
	int a=0,e=0,i=0,o=0,u=0;//Vaiable para llevar un conteo de las vocales.
	int total=0;//Variable para llevar un conteo de todas las vocales encontrada en la frase.
		//-------------------------------------------------------------------------
	//Mostramos un mensaje ilustre al metodo.	
	printf("\n----------------------------------------------");
	printf("\n-------------- Punto N°5 ---------------\n");
	printf("----------- Cantidad de vocales --------------");
	printf("\n---------------------------------------------\n");
	//-------------------------------------------------------------------------------
	//Ya con el tamaño obtenido realizamos un ciclo para revisar caracter por caracter.
	for(int x=0;x<t;x++){
		if(frase[x]=='a' || frase[x]=='e'|| frase[x]=='i'|| frase[x]=='o'|| frase[x]=='u'){
				switch(frase[x]){
					case 'a':{   a++;   break;}//comenzamos a contar los caracteres que contienen "a".
					case 'e':{   e++;   break;}//comenzamos a contar los caracteres que contienen "e".
					case 'i':{   i++;   break;}//comenzamos a contar los caracteres que contienen "i".
					case 'o':{   o++;   break;}//comenzamos a contar los caracteres que contienen "o".
					case 'u':{   u++;   break;}//comenzamos a contar los caracteres que contienen "u".
					default: puts("Error");
					
				}	
		}
			
			
	}
	    total=(a+e+i+o+u);//Sumamos todas las vocales para saber cuantas se encontraron en la frase
		printf("La cantidad de vocales que contiene la frase es: %d",total);
		printf("\nLas cuales son:\n [%d] con la letra A, [%d] con la letra E, [%d]con la letra I, [%d] con la letra O, [%d] con la letra U",a,e,i,o,u);
		printf("\n");
		printf("----------------------------------------------------------\n");
		printf("\n###############################################\n");

}

//Metodo del punto N°6
void punto6(char* frase){
		int tam=strlen(frase);//Obtenemos el tamaño de la frase.
		int total=0;//Variable para llevar un conteo de todas las consonantes encontrada en la frase.
		int b=0,c=0,d=0,f=0,g=0,h=0,j=0,k=0,l=0,m=0,n=0,p=0,q=0,r=0,s=0,t=0,v=0,x=0,y=0,z=0;//Vaiable para llevar un conteo de las consonantes.
		//-------------------------------------------------------------------------
	//Mostramos un mensaje ilustre al metodo.	
	printf("\n----------------------------------------------");
	printf("\n-------------- Punto N°6 ---------------\n");
	printf("----------- Cantidad  de consonantes ------------");
	printf("\n---------------------------------------------\n");
	//---------------------------------------------------------------------------------------------------------------------
		//Ya con el tamaño obtenido realizamos un ciclo para revisar caracter por caracter.
		for(int i=0;i<tam;i++){
			if(frase[i]=='b' || frase[i]=='c'|| frase[i]=='d'|| frase[i]=='f'|| frase[i]=='g'|| frase[i]=='h'|| frase[i]=='j'|| frase[i]=='k'|| frase[i]=='l'|| frase[i]=='m'||
			 frase[i]=='n'|| frase[i]=='p'|| frase[i]=='q'|| frase[i]=='r'|| frase[i]=='s'|| frase[i]=='t'|| frase[i]=='v'|| frase[i]=='x'|| frase[i]=='y'|| frase[i]=='z'){
				switch(frase[i]){
					case 'b':{  b++;    break;}//comenzamos a contar los caracteres que contienen "b".
					case 'c':{	c++;	break;}//comenzamos a contar los caracteres que contienen "c".
					case 'd':{	d++;	break;}//comenzamos a contar los caracteres que contienen "d".
					case 'f':{	f++;	break;}//comenzamos a contar los caracteres que contienen "f".
					case 'g':{	g++;	break;}//comenzamos a contar los caracteres que contienen "g".
					case 'h':{	h++;	break;}//comenzamos a contar los caracteres que contienen "h".
					case 'j':{	j++;	break;}//comenzamos a contar los caracteres que contienen "j".
					case 'k':{	k++;	break;}//comenzamos a contar los caracteres que contienen "k".
					case 'l':{	l++;	break;}//comenzamos a contar los caracteres que contienen "l".
					case 'm':{	m++;	break;}//comenzamos a contar los caracteres que contienen "m".
					case 'n':{	n++;	break;}//comenzamos a contar los caracteres que contienen "n".
					case 'p':{	p++;	break;}//comenzamos a contar los caracteres que contienen "p".
					case 'q':{	q++;	break;}//comenzamos a contar los caracteres que contienen "q".
					case 'r':{	r++;	break;}//comenzamos a contar los caracteres que contienen "r".
					case 's':{	s++;	break;}//comenzamos a contar los caracteres que contienen "s".
					case 't':{	t++;	break;}//comenzamos a contar los caracteres que contienen "t".
					case 'v':{	v++;	break;}//comenzamos a contar los caracteres que contienen "v".
					case 'x':{	x++;	break;}//comenzamos a contar los caracteres que contienen "x".
					case 'y':{	y++;	break;}//comenzamos a contar los caracteres que contienen "y".
					case 'z':{	z++;	break;}//comenzamos a contar los caracteres que contienen "z".
					default: puts("Error");	
				}	
			}			
		}
		total=(b+c+d+f+g+h+j+k+l+m+n+p+q+r+s+t+v+x+y+z);//Sumamos todas las consonantes para saber cuantas se encontraron en la frase
		printf("La cantidad de consonantes que contiene la frase es: %d",total);
		printf("\nLa cuales son:\n");
		printf(" [%d] con la letra B, [%d] con la letra C, [%d] con la  letra D, [%d] con la letra F, [%d] con la letra G,\n [%d] con la letra H, [%d] con la letra J, [%d] con la letra K, [%d] con la letra L, [%d] con la letra M,\n [%d] con la letra N, [%d] con la letra P, [%d] con la letra Q, [%d] con la letra R, [%d] con la letra S,\n [%d] con la letra T, [%d] con la letra V, [%d] con la letra X, [%d] con la letra Y, [%d] con la letra Z,",b,c,d,f,g,h,j,k,l,m,n,p,q,r,s,t,v,x,y,z);
		printf("\n");
		printf("----------------------------------------------------------\n");
		printf("\n###############################################\n");	
}

//Metodo del punto N°7
void punto7(char* frase){
	int tam=strlen(frase);//Obtenemos el tamaño de la frase.
		int a=0,e=0,i=0,o=0,u=0,espacio=0;//Vaiable para llevar un conteo de las vocales y el espacio.
		int p=0;
		//-------------------------------------------------------------------------
	//Mostramos un mensaje ilustre al metodo.	
	printf("\n--------------------------------------------------");
	printf("\n-------------- Punto N°7 ---------------\n");
	printf("- Cantidad  de espacios y vocales mas utilizada -");
	printf("\n-------------------------------------------------\n");
	//---------------------------------------------------------------------------------------------------------------------
		//Ya con el tamaño obtenido realizamos un ciclo para revisar caracter por caracter.
		for(int i=0;i<tam;i++){
			if(frase[i]=='a' || frase[i]=='e'|| frase[i]=='i'|| frase[i]=='o'|| frase[i]=='u' || frase[i]==' '){
				switch(frase[i]){
					case 'a':{   a++;  break;}//comenzamos a contar los caracteres que contienen "a".
					case 'e':{   e++;  break;}//comenzamos a contar los caracteres que contienen "e".
					case 'i':{   i++;  break;}//comenzamos a contar los caracteres que contienen "i".
					case 'o':{   o++;  break;}//comenzamos a contar los caracteres que contienen "o".
					case 'u':{   u++;  break;}//comenzamos a contar los caracteres que contienen "u".
					case ' ':{   espacio++;  break;}//comenzamos a contar los caracteres que contienen " ".
					default: puts("Error");
					
				}	
			}
			
			
		}
		//------------------------------------------------------------------------------------------------------------------
		//Comprobamos cual vocal es mas utilizada.
		if(a>e && a>i && a>o && a>u){
			printf("La cantidad de espacio que contiene la frase es: %d",espacio);
			printf("\nPor otra parte. La volca mas utiliza es A, ya que en ocasiones se utiliza [%d] veces",a);
			p++;
		}
		if(e>a&& e>i&& e>o&& e>u){
			printf("La cantidad de espacio que contiene la frase es: %d",espacio);
			printf("\nPor otra parte. La volca mas utiliza es E, ya que en ocasiones se utiliza [%d] veces",e);
			p++;	
		}
		if(i>a&& i>e&& i>o&& i>u){
			printf("La cantidad de espacio que contiene la frase es: %d",espacio);
			printf("\nPor otra parte. La volca mas utiliza es I, ya que en ocasiones se utiliza [%d] veces",i);
			p++;
		}
		if(o>a&& o>i&& o>e&& o>u){
			printf("La cantidad de espacio que contiene la frase es: %d",espacio);
			printf("\nPor otra parte. La volca mas utiliza es O, ya que en ocasiones se utiliza [%d] veces",o);
			p++;
		}
		if(u>a&& u>i&& u>o&& u>e){
			printf("La cantidad de espacio que contiene la frase es: %d",espacio);
			printf("\nPor otra parte. La volca mas utiliza es U, ya que en ocasiones se utiliza [%d] veces",u);
			p++;
		}
		if(p<1){
			printf("La cantidad de espacio que contiene la frase es: %d",espacio);
			printf("\nPor otra parte. No hay vocal que se utiliza mas que otra.");
		}
		//------------------------------------------------------
		
		printf("\n----------------------------------------------\n");
	    printf("\n###############################################\n");	

}

//Metodo para obtener la frase
char* obtener_frase(char* frase){
	
	printf("\n--------------------------------------------");
	printf("\n-------------- Bienvenidos -----------------");
	printf("\n--------------------------------------------\n");
	printf("\nRecuerda que no debes superar los 50 caracteres\n");
	printf("Por favor, Digita un frase: ");
	gets(frase);
	printf("\n-------------------------------------------------\n");
	printf("\n###############################################\n");
	
	return frase;
}


//Metodo para validar si la es palindroma.
void palindroma(char* frase,int p1,int p2,char* pantalla){
	int tama=strlen(frase);//Obtenemos el tamaño de la frase.
	int pun_inicio=p1,pun_fin=p2;//Definios los puntos de inicio a fin de los carcteres de la frase.
	int s=0;//Varriable para validar.
	//------------------------------------------------------------------------
	//
	while(frase[pun_inicio]==frase[pun_fin]){	
		//	
		if(pun_inicio>=pun_fin && frase[p1]!='^') {
			if(s<1){
			printf(" [ ");
			int a=p1;
			while(p1<=p2){
			printf(" ( %c ) ",frase[p1]);
			p1++;
			}
			printf("] \n\n");
			}
			s++;
			break;
			
		}
		
		pun_inicio++;
		pun_fin--;
	 //-------------------------------------------------	
	 //Si es palídromala palabra imprimimos el mensaje.
	 if(s<1){
		printf(" La palabra  es  palíndroma.  \n");
    	}
      //-------------------------------------------------
	}
	
}



//Metodo para obtener la longitud de una cadena
int strlen(char* frase){
	int longitud=0;//Variable para obtener el tamaño de la cadena.
	while (frase[longitud]!='\0'){//Realizamos un ciclo para saber el tamaño de la cadena, se detendra cuando encuente el primer espacio null.
        longitud++;//el contador va aumentando mientra allá caracteres.
    } 
	return longitud;//Retornamos el tamaño de la cadena.
}

//Metodo de limpiar pantalla
void limpiar_pantalla(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

