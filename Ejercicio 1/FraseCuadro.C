#include<stdio.h>

// Ejercicio Realizado por Andres Arturo Perez

void inicio();
void frase_cuadro(char *n);
int dato1(char *d1);

int main()
{
	inicio();    
}


void inicio(){
	char d1[20];
	printf("\n**********FRASE EN CUADRO************\t\n ");    
	printf("Por favor, Digite una frase: \n");
	gets(d1); 	
   frase_cuadro(d1);
	
}
void frase_cuadro(char *d1){
	int t=dato1(d1);
	int o1=t-1;
	int t2=t-1;
	int largo=0;

	for(int i=0;i<t;i++){
		
		if(i==0){
			printf(" %s\n",d1);
		}else{
		
			if(i>0 && i<t2){
				printf(" %c",d1[i]);
				
				for(int u=1;u<t2;u++){
					printf(" ");
				}
				
				printf("%c \n",d1[o1]);				
				
			}else{
				for(int y=t;y>-1;y--){
					printf("%c",d1[y]);
				}
			}
			
		}
		
			o1--;
	}
	
		
}

int dato1(char* dato){
    int longitud=0;
	while (dato[longitud]!='\0'){
        longitud++;  
    } 
	return longitud;
}





