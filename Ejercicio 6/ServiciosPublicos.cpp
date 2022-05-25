//Llamamos las libreria ha utilizar
#include<stdio.h>
#include<iostream>
#include <time.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include<windows.h>
#include<locale.h> 
#endif



// -----Metodos o funciones----
int menu_principal();
void inicio();
int menu_usuario(char nombre_usuario[20][50],int puntero);
void inicio_secundario(char nombre_usuario[20][50],char clave_usuario[20][50],char cc_usuario[20][50],int num_usuarios,int saldo_usuario[20][50],int puntero,char numero_factura[20][20]);
int menu_factura(char nombre_usuario[20][50],int puntero);

void fecha_hora();
void hora();
void limpiar_pantalla();


int main (){
	
	inicio();
	

     return 0;	
}

//-------------------------------------------------------------------------------------------------------
//Metodo del menu principal.
int menu_principal(){	
	int r=0;

	printf("Bienvenido, Paga tus Servicios Públicos-----------\n");
	printf("Por favor, Seleccionar una de las cuatro opciones:\n");
	printf("1)	Inicio de sesion.\n");
	printf("2)	Registrarse.\n");
	printf("3)	Salir.\n");
	printf(" Por favor, Ingresa un numero del menu de opciones: ");   
    scanf("%d", &r);   
    return r;	
}

//Metodo donde se inicializamos el programa
 void inicio(){
 	//---------------------------------------------------------------------------------------
	char cc_usuario[20][50], clave_usuario[20][50], nombre_usuario[20][50], numero_factura[20][20];//Variable  donde manejamos el usuario
	int  saldo_usuario[20][50];//Variable necesarias para el usuario.
	int num_usuarios=0;//Variable del tamaño para manejar los arreglos de las variable del usuario.
	//--------------------------------------------------------------------------------------
	int opcion=0; //variable menu
	//------------------------------------------------------------------------------
	int repeticiones=0;//Variable para (manejo del sistema).
	//------------------------------------------------------------------------------
	while(repeticiones==0){
		opcion=menu_principal();//Mostramos el menu principal y obtenemos el valor seleccionado.
	
		while(opcion!=1 && opcion!=2 && opcion!=3){
			
		    if(opcion<1 || opcion>3){
		    	limpiar_pantalla();
		    	
		    	printf("\nPor favor,  Seleccione un numero que se encuentre en el rango del menu.\n ");
		    	opcion=menu_principal();
			}
		}
	
		char d3[50];
		switch(opcion){
		
			case 1:{
				char caracter;//Variable en la cual vamos a tener la clave caracter por caracter y a su vez mostramos(*).
				int r=0;
				limpiar_pantalla();
				if(num_usuarios==0){// verificamos que por lo menos alla algun usuario registrado.
				limpiar_pantalla();
			
				printf("\n No existe usuarios registrado, Por favor registrate primero :D \n");
				}else{
						
					char cc[50],clave[50]; // variables para obtenener el correo y contraseña.
					int resp_d1=0,resp_d2=0;// Varible para validar.
					int puntero;
					printf(" ");
					printf(" \n ");
					gets(d3);
					   
						printf("Bienvenido al Login    \n");
										
							printf("\nPor favor, Ingresa el numero de cedula (Sin comillas ni puntos): ");
	   						gets(cc);	
							printf("\n Por favor, ingresa la clave :");
						
						while(1){
						caracter=getch();
						if(caracter == 13){
							
							clave[r]='\0';
							break;
						}else if(caracter ==8){
							if(r>0){
								r--;
								printf("\b \b");//Boramos el caracter mal colocado y tambien *.
							}
						}else{
						printf("*");
						clave[r]=caracter;
						r++;
				     	}
					  }
						
							printf("\n *****");	
	   						printf("\n %s",cc);
	   						printf("\n %s",clave);
	   						int igualesf1,igualesf2,iguales1=0,iguales2=0;
	   						puntero=0;
	   						for(int n1=0;n1<20;n1++){ //validamos si el numeo de cedula esta registrado.
	   							 igualesf1=0;
								for(int n2=0;cc[n2]!='\0';n2++){
	   								if(cc_usuario[n1][n2]!=cc[n2]){
	   									igualesf1++;
	   									
									}									
								}
								if(igualesf1==0){
										puntero=n1;
										iguales1++;
								}
							}
							for(int n1=0;n1<num_usuarios;n1++){ //validamos si la contraseña esta registrada.
	   							 igualesf2=0;
							for(int n2=0;clave[n2]!='\0';n2++){
	   							if(clave_usuario[puntero][n2]!=clave[n2]){
	   								igualesf2++;
								}
									
							}
							if(igualesf2==0){		
								iguales2++;
							}
							}
							
							limpiar_pantalla();
							if(iguales1==1 && iguales2==1){ //si son correcto los datos
							limpiar_pantalla();
							
	                        printf("----Se ha realizar el inicio de sesión exitosamente.\n");
	                      	                        
	                        inicio_secundario(nombre_usuario,clave_usuario,cc_usuario,num_usuarios,saldo_usuario,puntero,numero_factura);
	                        
							}else{
								limpiar_pantalla();
			 	              
	                            printf("\nLos datos introduccidos son incorrecto.\nPor favor, Verificar nuevamente.\n");
	                           
							}
	   							 
					}
				
				break;
			}
		
			case 2:{
				limpiar_pantalla();
				char caracter;//Variable en la cual vamos a tener la clave caracter por caracter y a su vez mostramos(*).
				int r=0;
				int validacion=0,confirma;
				  
					printf("-------------Bienvenido al registro----------------\n");
				
					
					printf(" ");
					printf(" \n ");
				    gets(d3);
				    
					printf("Por favor, Ingrese el nombre completo:");
       				gets(nombre_usuario[num_usuarios]);
       				printf(" \n Por favor, Ingresa su cedula de ciudadania (Sin puntos o comillas): ");
       				gets(cc_usuario[num_usuarios]);
       				printf("\nPor favor, Ingresa su clave: ");
       				//------------------------------
       				printf("el nombre es:",nombre_usuario[0],"Su cedula es:",cc_usuario[0])
						while(1){
						caracter=getch();
						if(caracter == 13){
							
							clave_usuario[num_usuarios][r]='\0';
							break;
						}else if(caracter ==8){
							if(r>0){
								r--;
								printf("\b \b");//Boramos el caracter mal colocado y tambien *.
							}
						}else{
						printf("*");
						clave_usuario[num_usuarios][r]=caracter;
						r++;
				     	}
					  }
					
					saldo_usuario[num_usuarios][0]=1000;
				
					do{
						limpiar_pantalla();
					
						printf("\nConfirmación de la creación de cuenta\n");
						printf("\nNombre del usuario: %s", nombre_usuario[num_usuarios]);
						printf("\nNumero de cedula (C.C): %s",cc_usuario[num_usuarios]);
						printf("\n");
						printf("\nOjo antes de realizar el registro debes depositar la cantidad de $1.000.\nUna vez depositada se dara como finalizado el regitro del usuario.");
						printf("\n¿Deseas depositar los $1.000 iniciales? 0(Si) 1(No) :");
						scanf("%d",&confirma);
						if(confirma==0){
							limpiar_pantalla();
					        printf("\n El usuario se ha  registrado exitosamente. \n ");
					       
					        num_usuarios++;
					        
						}else{
							limpiar_pantalla();
						     printf(" Registro Cancelado.\nVuelva intentarlo nuevamente. ");
					      
						}
						
					}while(validacion!=0);	
			
				break;
			}
			//---------------- Fin del Caso N°2 Registro ----------------------------
			
			//--------------- Caso N°3 Salida ---------------------------------------
			case 3:{
				repeticiones++;
				repeticiones++;
				break;
			}
			//----------- Fin del Caso N°3 Salida ----------------------------------
		}
	}
	
 }
 //----------------------------------------------------------------------------------------------------
 
 //----------------------------------------------------------------------------------------
 // metodo para dale un menu al usuario ingresado
int menu_usuario(char nombre_usuario[20][50],int puntero){
	int r=0;
	limpiar_pantalla();
	printf("----Bienvenido sr(a). %s  al menú . -------\n",nombre_usuario[puntero]);
	printf("Por favor, Seleccionar una de las cinco opciones: \n");
	printf("1)	Ventana de pago. \n");
	printf("2)	Realizar Deposito. \n");
	printf("3)	Mostrar Saldo \n");
	printf("4)	Salir. \n");
		
	printf(" Por favor, Ingresa un numero del menu de opciones: \n");   
    scanf("%d", &r);   
    return r;	
}
//------------------------------------------------------------------------------------
 
 //Metodo inicio para los usuarios que ya este logueado.
void inicio_secundario(char nombre_usuario[20][50],char clave_usuario[20][50],char cc_usuario[20][50],int num_usuarios,int saldo_usuario[20][50],int puntero, char numero_factura[20][20]){
	//--------------------------------------------------------------------------------------
	int caso=0; //variable que vamos a obtener el valor del manu
	//------------------------------------------------------------------------------
	int repeticiones=0;//Variable la cual se utilizara para el manejo del while (manejo del sistema).
	//------------------------------------------------------------------------------
	while(repeticiones ==0){
		caso=menu_usuario(nombre_usuario,puntero);
		while(caso!=1 && caso!=2 && caso!=3 && caso!=4){
			
		    if(caso<1 || caso>5){
		    	limpiar_pantalla();
		    
		    	printf("Por favor,  Seleccione un numero que se encuentre en el rango del menu.\n ");
		       	caso=menu_usuario(nombre_usuario,puntero);
			}
		}
			char d3[50];
			switch(caso){
				//------------------Caso 1:Ventana de pago------------------------
				case 1:{
					bool validar_factura,validar_valor=false;//Varible para validar si el numero de factura tiene 10 caracteres y el valor apagar.
					int vali=0;//Variable para ciclo de pregunta.
					int valor_recibe;//Variable para recibir el valor digitado por el usuario en # de factura.
					char confirma='1';//Variable para connfirma los mensajes recibidos.
					limpiar_pantalla();
					int opcion2=menu_factura(nombre_usuario,puntero);
					//-- Solicitamos que el usuario si o si seleccione una de las opciones mostrada----
		            while(opcion2!=1 && opcion2!=2 && opcion2!=3 && opcion2!=4 && opcion2!=5){
		             if(opcion2<1 || opcion2>5){
		    	     limpiar_pantalla();
		    	   
		    	     printf("Por favor,  Seleccione un numero que se encuentre en el rango del menu.\n ");
		    	      opcion2=menu_factura(nombre_usuario,puntero);
			         }
		            }
		            //Verificamos si cumple con el estandar(10 caracteres) permitido en la digitación del numero de factura.
		            do{
		            	printf("Por favor, Digita el numero de la factura a pagar: \n");
		            	scanf("%s",&numero_factura[puntero]);
		    
		            	if(strlen(numero_factura[puntero])!=10){
		            		limpiar_pantalla();
		            		
		            		printf("El dato digitado por el usuario es invalido.\nRecuerda que debes digitar el # de factura con sus 10 caracteres.\nVuelva a intentarlo \n");
		            		}else{
							limpiar_pantalla();
							vali++;
						}
		            	
					}while(vali==0);
					//Verificamos si cumple con la confirmacion del monto a pagar.
					do{
						vali=0;
						printf("Por favor, Digita el monto a pagar por la factura: \n");
						scanf("%d", &valor_recibe);
						if(valor_recibe>=1000){
						   if(valor_recibe>saldo_usuario[puntero][0]){
						   	printf("Proceso de pago cancelado.\nNo tiene saldo suficiente para realizar el pago,\nPor favor depositar. \n");
						
							do{
								fflush( stdin );//limpiamos el buffer.
					            printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
					            scanf("%c",&confirma);
					        }while(confirma!=10);
							//--------------------------------------------------------------------
							validar_valor=true;
							vali++;
						   }else{
						   	
							saldo_usuario[puntero][0]=saldo_usuario[puntero][0]-valor_recibe;//Descontamos el saldo con lo que el usuario pago
							limpiar_pantalla();
							vali++;
						   }
						   
					    }else{
					  	    limpiar_pantalla();
					  	   
							printf("Cuidado el pago minimo es de $1.000. \n");
							
					  	
					  }
					}while(vali==0);
					
					if(validar_valor){break;}
					
					//Mostramos la confirmacion del pago
					do{
		            //--------------------------------------------------------------------------------
					
					printf("-------------Ventana de pago----------------\n");
										
					if(opcion2==1){ printf("El tipo de factura: CENS. \n");}
					if(opcion2==2){ printf("El tipo de factura: AGUAS KAPITAL. \n");}
					if(opcion2==3){ printf("El tipo de factura: VEOLIA. \n");}
					if(opcion2==4){ printf("El tipo de factura: DIRECTV. \n");}
					if(opcion2==5){ printf("El tipo de factura: CANAL EXITO. \n");}
					
					printf("el Numero de la factura es: %s",numero_factura[puntero]);
					printf("\nValor a pagar: %d",valor_recibe);
					printf("\n");
					hora();
					//----------------------------------------------------------------------------------
					
					fflush( stdin );//limpiamos el buffer.
					printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
					scanf("%c",&confirma);
				   }while(confirma!=10);
					
					break;
				}
				//---------------------- Fin del caso 1: Ventana de pago------------------------
				
				//----------------------- Caso 2: Deposito ----
				--------------------------
				case 2:{
					limpiar_pantalla();
					printf("-Bienvenido %s  al menú de Deposito------------\n ",nombre_usuario[puntero]);
					int valorUsuario;
					int rep2=0;
					do{					
						printf("\n Tu saldo es de : [ %d ] ",saldo_usuario[puntero][0]);
					    printf("\n Ingresa el valor que desea Depositar : ");
					    scanf("%d", &valorUsuario);
					    if(valorUsuario>=1000){
					    	saldo_usuario[puntero][0]=saldo_usuario[puntero][0]+valorUsuario;
							rep2++;
						}else{
							printf("\n El valor ingresado no es correcto. \n Por favor inténtalo de nuevo.  ");
							
						}
					}while(rep2==0);
					break;
				}
				//-------------------- Fin del Caso 2: Deposito -------------------------------------------
				
				//-------- Caso 3: Informacion del usuario ---------------------------------
				case 3:{
					limpiar_pantalla();
					char confirma='1';
					do{
					
				
					printf("Bienvenido a los detalles.------------\n ");
					printf("\n Nombre :%s", nombre_usuario[puntero]);
					printf("\n Cedula de Cuidadania :%s", cc_usuario[puntero]);
					printf("\n Saldo :%d\n", saldo_usuario[puntero][0]);
					fecha_hora();
		 			fflush( stdin );//limpiamos el buffer.
					printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
					scanf("%c",&confirma);
				     }while(confirma!=10);
					break;
				}
				//----------- Fin del caso 3: Informacion del usuario ----------------------
				
				//----------- Caso 5:Salida -----------------------
				case 4:{
					repeticiones++;
					repeticiones++;
					break;
				}
				//---------- Fin del caso 5:Salida -----------------
			}
	}
	
}
//-------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
//Metodo para mostrar la fecha y hora de la consola
void fecha_hora() {
    time_t tiempoAhora; // creamos una variable de tipo time_t
	time(&tiempoAhora);
	struct tm *miTiempo=localtime(&tiempoAhora);
	printf("\nFecha: %d/%d/%d  Hora: %d:%d:%d\n",miTiempo->tm_mday,miTiempo->tm_mon,miTiempo->tm_year+1900,miTiempo->tm_hour,miTiempo->tm_min,miTiempo->tm_sec);
	printf("\n-----------------------------------------------------\n");

}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
//Metodo para mostrar la hora de la consola
void hora() {
    time_t tiempoAhora; // creamos una variable de tipo time_t
	time(&tiempoAhora);
	struct tm *miTiempo=localtime(&tiempoAhora);
	printf("\nHora: %d:%d:%d\n",miTiempo->tm_hour,miTiempo->tm_min,miTiempo->tm_sec);
	printf("\n-----------------------------------------------------\n");

}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
//Metodo para darle un menú de tipo de factura.
int menu_factura(char nombre_usuario[20][50],int puntero){
	int r=0;
	limpiar_pantalla();
	printf("\n --------Bienvenido sr(a). %s  al menú de factura . -------\n\n",nombre_usuario[puntero]);
	printf("Por favor, Seleccionar una de las cinco opciones:");
	printf("\n 1)	CENS .");
	printf("\n 2)	AGUAS KAPITAL .");
	printf("\n 3)	VEOLIA .");
	printf("\n 4)	DIRECTV .");
	printf("\n 5)	CANAL EXITO.\n");
		
	
	printf(" \n Por favor, Ingresa un numero del menu de opciones: ");   
    scanf("%d", &r);   
    return r;
}
//------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
//Metodo para limpiar pantalla
void limpiar_pantalla(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
//------------------------------------------------------------------------------------------
