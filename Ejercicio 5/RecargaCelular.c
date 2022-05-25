#include<stdio.h>


int menu_inicio();
void inicio();
void inicio_secundario(char nombre[20][50], char clave[20][50], char correo[20][50], int saldo[20][20], int puntero);
int menu_operador(char nombre[20][50],int puntero);
int menu_usuario(char nombre[20][50],int puntero);
void fecha_hora();


main(){
	
	
	menu_inicio();
	
	
}


int menu_inicio(){
	
	int Num=0;
	
	printf("-------Recarga de Celular---------\n");
	printf("Por favor escoger una de las siguientes opciones: \n");
	printf("1) Inicio de sesion \n");
	printf("2) Registrarse \n");
	printf("3) Salir \n");
	printf("Por favor escoger una opcion \n");
	scanf("%d",&Num);
	return Num;	
		
}


void inicio(){

	char correo[20][50], clave[20][50], nombre[20][50];//manejamos el usuario
	int saldo[20][20];// donde manejamos saldo el usuario
	int num_usuarios=0;

	int opcion=0; //variable que vamos a obtener el valor del manu

	int repeticiones=0, repeticiones_correo=0, repeticiones_clave=0;// (manejo del sistema).
	int n1,n2;

	while(repeticiones==0){
			opcion=menu_inicio();
	
		while(opcion!=1 && opcion!=2 && opcion!=3){
			
		    if(opcion<1 || opcion>3){
		    
		      	printf("Por favor,  Seleccione un numero que se encuentre en el rango del menu.\n ");
		    
		    	opcion=menu_inicio();
			}
		}
		//-----------------------------------------------
		char d3[50];
		switch(opcion){
			//Caso N°1 Para Iniciar Sesión
			case 1:{
			
				char caracter;//Variable en la cual vamos a tener la clave caracter por caracter y a su vez mostramos(*).
				
				
				int res1=0,res2=0;//Vartiables para validar
				
				if(num_usuarios==0){// verificamos que por lo menos alla algun usuario registrado.
				printf("\n No existe usuarios registrado, Por favor registrate primero :D \n");
			
				}else{
					char dato1[30],dato2[30];//Para saber los valores digitado por el usuario.
	                int r=0;
					int resp_d1=0,resp_d2=0,permiso=0;//Variables para validar
					int puntero;
					printf(" ");
					printf(" \n ");
					gets(d3);
					printf("----  Bienvenido al Login   -----  \n");
										
					printf("\nPor favor, Digite el correo Electronico: ");
					gets(dato1);
					printf("\nPor favor, Digite su contraseña: ");// digitalizacion por caracter
				 
					fflush( stdin );//limpiamos el buffer.
					
					while(1){
						caracter=getch();
						if(caracter == 13){
							
							dato2[r]='\0';
							break;
						}else if(caracter ==8){
							if(r>0){
								r--;
								printf("\b \b");//Boramos el caracter mal colocado y tambien *.
							}
						}else{
						printf("*");
						dato2[r]=caracter;
						r++;
				     	}
					}
					int igualesf1,igualesf2,iguales1=0,iguales2=0;
	   						puntero=0;
	   						for( n1=0;n1<20;n1++){ //validamos si el correo elecronico esta registrado.
	   							 igualesf1=0;
								for( n2=0;dato1[n2]!='\0';n2++){
	   								if(correo[n1][n2]!=dato1[n2]){
	   									igualesf1++;
	   									
									}									
								}
								if(igualesf1==0){
										puntero=n1;
										iguales1++;
								}
							}
							for( n1=0;n1<num_usuarios;n1++){ //validamos si la contraseña esta registrada.
	   							 igualesf2=0;
							for( n2=0;dato2[n2]!='\0';n2++){
	   							if(clave[puntero][n2]!=dato2[n2]){
	   								igualesf2++;
								}
									
							}
							if(igualesf2==0){		
								iguales2++;
							}
							}
							
						
							if(iguales1==1 && iguales2==1){ //si son correcto los datos
						
							printf("\nSe ha realizar el inicio de sesión exitosamente.\n");
	                       
	                        
	                        inicio_secundario(nombre,clave,correo,saldo,puntero);
	                        
							}else{
								
	                            printf("Los datos introduccidos son incorrecto.\nPor favor, Verificar nuevamente.\n");
	                           
							}
				}
				break;
			}
		
			case 2:{
				char caracter;//Variable en la cual vamos a tener la clave caracter por caracter y a su vez mostramos(*).
				int r=0;
			
				 
					printf("---Bienvenido al registro---");				
					
					printf(" ");
					printf(" \n ");
				    gets(d3);
				    
					printf("Por favor, Ingrese el nombre completo:");
       				gets(nombre[num_usuarios]);
       				do{
						
						printf("\n Por favor, Ingresa un correo electronico: ");	
		  				gets(correo[num_usuarios]);
		  				int f1,f2;
		  				int resultado=0;
						for(f1=0;correo[num_usuarios][f1]!='\0';f1++){ //validamos que el correo digitado cumpla con los estandares.
							if(resultado>=1 && correo[num_usuarios][f1]=='.'){
							resultado+=2;
							}
							if(correo[num_usuarios][f1]=='@'){
								resultado+=3;
							}
						}
						if(resultado==5){
							repeticiones_correo++;
							repeticiones_correo++;
						}else{
					
							printf("\n El correo ingresado es incorrecto o no cumple con los estandares. \n Por favor intantelo nuevamente.  ");
							
						}
		  				
					}while(repeticiones_correo==0);
					
					int f3,f4;
					int resultado1;
		  			int resultado2;
					do{	
						printf("Por favor ingresa una clave. debes cumplir con el estandar alfanumérico");
											
						while(1){
						caracter=getch();
						if(caracter == 13){
							
							clave[num_usuarios][r]='\0';
							break;
						}else if(caracter ==8){
							if(r>0){
								r--;
								printf("\b \b");//Boramos el caracter mal colocado y tambien *.
							}
						}else{
						printf("*");
						clave[num_usuarios][r]=caracter;
						r++;
				     	}
					}
					
		  				resultado1=0;
		  				resultado2=0;
						for(f3=0;clave[num_usuarios][f3]!='\0';f3++){ //validamos que la contraseña digitada cumpla con el estandar alfanumerico.
							if(clave[num_usuarios][f3] >= '0' && clave[num_usuarios][f3] <= '9'){
								resultado1++;
							}
						}
						for(f4=0;clave[num_usuarios][f4]!='\0';f4++){
							if((clave[num_usuarios][f4]>= 'a' && clave[num_usuarios][f4] <= 'z' ) || (clave[num_usuarios][f4] >= 'A' && clave[num_usuarios][f4] <= 'Z' )) {
								resultado2++;
							}
						}
						if(resultado1>0 && resultado2>0){
							repeticiones_clave++;
						}else{
							
							printf(" La clave ingresada no cumple con el estandar alfanumerica. \n Por favor intantelo nuevamente. ");
						
						}
		  				
					}while(repeticiones_clave==0);
				
					saldo[num_usuarios][0]=100000;
					num_usuarios++;
					
					
				
					printf("\n El usuario se ha  registrado exitosamente. \n ");
				
				    break;
			}
		
			case 3:{
				repeticiones++;
				break;
			}
		
		}
	}
}

void inicio_secundario(char nombre[20][50], char clave[20][50], char correo[20][50], int saldo[20][20], int puntero){
	//--------------------------------------------------------------------------------------
	int caso=0; //variable que vamos a obtener el valor del manu
	int operador=0;//Variable para seleccionar el operador.
	int validador1=0;//Variable con la cual validamos el ciclo.
	int validador3=0;//Variable con la cual validamos el ciclo.
	int validador2=0;//Variable con la cual validamos el ciclo.
	char telefono[20];
	
	//------------------------------------------------------------------------------
	int repeticiones=0;//Variable la cual se utilizara para el manejo del while (manejo del sistema).
	//------------------------------------------------------------------------------
	while(repeticiones ==0){
		caso=menu_usuario(nombre,puntero);
		while(caso!=1 && caso!=2 && caso!=3){
			
		    if(caso<1 || caso>3){
		    	limpiar_pantalla();
		    
		    	printf("\nPor favor,  Seleccione un numero que se encuentre en el rango del menu.\n ");
		    
		    	caso=menu_usuario(nombre,puntero);
			}
		}
		
		char d3[50];
		switch(caso){
		
			case 1:{
				int monto=0;//Variable para validar el monto
				operador=menu_operador(nombre,puntero);
				//-- Solicitamos que el usuario si o si seleccione una de las opciones mostrada----
		        while(operador!=1 && operador!=2 && operador!=3 && operador!=4 && operador!=5){
			      if(operador<1 || operador>5){
		    	 
		    	
		    	  printf("Por favor,  Seleccione un numero que se encuentre en el rango de los operadores.\n ");
		    	 
		    	  operador=menu_operador(nombre,puntero);
			      }
		       }
		       //-----------------------------------------------
		       do{
		       	validador1=0;
		     
		       printf("\nPor favor, digite el numero telefonico: ");
		       gets(telefono);
		       if(strlen(telefono)!=10){
		       	 
		    	  printf("\nPor favor,  Digite un numero valido (Contenga 10 caracteres.).\n ");
		    	  
			   }else{
			   	validador1++;
			   }
			   }while(validador1==0);
			   //---------------------------------------------------
			   do{
			   	validador2=0;
			   	printf("Por favor, digite el monto la cual vas a recargar: ");
			   	scanf("%d",&monto);
				   if(monto>=1000){
			   		validador2++;
				   }else{
				    printf("\nRecuerda que el monto minimo es de $1000.\n ");
		    	   
				   }
			   	
			   }while(validador2==0);
			   //----------------------------------------------------
			   do{
			   	char confirma='1';
			   	validador3=0;
			   
				printf("\n --- Confirmación de la Recarga.--- ");
				if(operador==1){
				printf("\nEl operador seleccionado es: CLARO.\n");
				}
				if(operador==2){printf("\nEl operador seleccionado es: MOVISTAR.\n");}
				if(operador==3){printf("\nEl operador seleccionado es: TIGO.\n");}
				if(operador==4){printf("\nEl operador seleccionado es: WOM.\n");}
				if(operador==5){printf("\nEl operador seleccionado es: VIRGIN MOBILE.\n");}
				printf("El numero telefonico es: %s",telefono);
				printf("\nEl monto a recargar es: $ %d",monto);
				fflush( stdin );//limpiamos el buffer.
				printf("Si estas deacuerdo en confirma la recarga.\n Por favor oprima la tecla enter de lo contrario oprima cualquier tecla: ");
				scanf("%c",&confirma);
				if(confirma!=10){
				
					
				    printf("\nLa recarga ha sido cancelada, Por favor vuelva a intentarlo más tarde");
				 
				    validador3++;
				}else{
					saldo[puntero][0]=saldo[puntero][0]-monto;//Descontamos el saldo con lo que el usuario pago
				
				    printf("\nLa recarga se ha realizado exitosamente.");
				    printf("\n-------------------------------------------------------");
				    validador3++;
				}
				
			   }while(validador3==0);
			 	break;
			}
		
			case 2:{
			
					char confirma='1';
					do{				
				
					printf("\n ----Bienvenido a los detalles----");
				
					printf("\n Nombre :%s", nombre[puntero]);
					printf("\n Correo Electronico :%s", correo[puntero]);
					printf("\n Saldo :%d\n", saldo[puntero][0]);
					fecha_hora();
		 			fflush( stdin );//limpiamos el buffer.
					printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
					scanf("%c",&confirma);
				     }while(confirma!=10);
				break;
			}
			//----------------- Fin del caso N°2 Mostrar Saldo-----------------
			
			//---------- Caso N°3 Salida----------------------
			case 3:{
				repeticiones++;
				break;
			}
		
		}
		
   }
}
int menu_operador(char nombre[20][50],int puntero){
	int r=0;
	
	printf("sr(a). %s \n",nombre[puntero]);
	
	printf("Por favor, Seleccionar una de las cinco operadores:");
	printf("\n (1)	CLARO .");
	printf("\n (2)	MOVISTAR .");
	printf("\n (3)	TIGO .");
	printf("\n (4)	WOM .");
	printf("\n (5)	VIRGIN MOBILE .");
	printf("\n ");	
	
	printf(" \n Por favor, Ingresa un numero del menu de operadores: ");   
    scanf("%d", &r);   
    return r;
}
void fecha_hora() {
    time_t tiempoAhora; // creamos una variable de tipo time_t
	time(&tiempoAhora);
	struct tm *miTiempo=localtime(&tiempoAhora);
	printf("\nFecha: %d/%d/%d  Hora: %d:%d:%d\n",miTiempo->tm_mday,miTiempo->tm_mon,miTiempo->tm_year+1900,miTiempo->tm_hour,miTiempo->tm_min,miTiempo->tm_sec);
	printf("\n-----------------------------------------------------\n");

}
		
		

	

