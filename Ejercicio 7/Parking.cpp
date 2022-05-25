//Llamamos las libreria ha utilizar
#include <iostream>
#include<stdio.h>
#include<locale.h> 
#include<string.h>
#include <time.h>
#ifdef _WIN32
#include<windows.h>
#endif
using namespace std;
//Ejercicio de parking

// -----Metodos o funciones----
int menu_principal();
void bienvenida();
int seleccion_tipo();
int seleccion_tipo_salida();
void inicio();
int menu_espacio_auto(char automoviles[10][10]);
int menu_espacio_moto(char motocicleta[6][10]);
void fecha_hora();
char* fecha(char* fecha);
char* hora(char* hora);
void limpiar_pantalla();
//----------------------------------------------
//Variables globales para mostrar salida.
int contador=0;
char tipo_vehiculo[20];
char placa[10];
char estacionamiento[10];
char fecha_actual[20];
char hora_llegada[20];
char hora_salida[20];
double costo;
int hora_estimada;
int minuto_estimada;
//----------------------------------------------
struct datos{
char tipo_vehiculo[20];
char placa[10];
char estacionamiento[10];
char fecha_actual[20];
char hora_llegada[20];
char hora_salida[20];
double costo;
int hora_estimada;
int minuto_estimada;
}historial[50];
//---------------------------------------------


int main(){
	setlocale(LC_CTYPE, "Spanish");//funcion que nos ayuda a utilizar caracteres especiales en los printf como ó, é ....

	inicio();

}


//------------------------------------------------------------------------
//Metodo del menu principal
int menu_principal(){	
	int r=0;

     printf("\n*---PARKING APP---*\n ");
     printf("\n*---Menú Principal---*\n ");
     printf("Por favor, Seleccionar una de las seis opciones:");
	printf("\n (1)	Registrar Entrada. ");
	printf("\n (2)	Registrar Salida. ");
	printf("\n (3)  Verificar Cupo Automoviles. ");
	printf("\n (4)  Verificar Cupo Motocicletas. ");
	printf("\n (5)	Salir.");
	printf("\n ");	
	printf(" \n Por favor, Ingresa un numero del menu de opciones: ");   
    scanf("%d", &r);   
    return r;	
}
//------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------
//Metodo inicial
void inicio(){
char automoviles[10][10], motocicleta[6][10];//Variable de tipo matriz para almacenar los puestos.
//--automovil--
strcpy(automoviles[0]," ");
strcpy(automoviles[1]," ");
strcpy(automoviles[2]," ");
strcpy(automoviles[3]," ");
strcpy(automoviles[4]," ");
strcpy(automoviles[5]," ");
strcpy(automoviles[6]," ");
strcpy(automoviles[7]," ");
strcpy(automoviles[8]," ");
strcpy(automoviles[9]," ");
//--Motocicleta--
strcpy(motocicleta[0]," ");
strcpy(motocicleta[1]," ");
strcpy(motocicleta[2]," ");
strcpy(motocicleta[3]," ");
strcpy(motocicleta[4]," ");
strcpy(motocicleta[5]," ");
//-----------------------------------------------------------
int num_auto=0, num_moto=0;//Declaramos las variable del tamaño para manejar los arreglos de las variable del los vehiculos.
int validador1=0, validador2=0;//Variable para validar que la placa no este registrada.
int auxiliar=0;//Variable para cambio de puesto.
int minutos_moto[6];//Variable para solicitar los minutos restante.
int minutos_auto[10];//Variable para solicitar los minutos restante.
//------------------------------------------
time_t tiempoAhora; // creamos una variable de tipo time_t
time(&tiempoAhora);
struct tm *miTiempo=localtime(&tiempoAhora);
//--------------------------------------
	int opcion=0; //variable que vamos a obtener el valor del manu
	//------------------------------------------------------------------------------
	int repeticiones=0;//Variable la cual se utilizara para el manejo del while (manejo del sistema).
	//------------------------------------------------------------------------------
	while(repeticiones==0){
		limpiar_pantalla();
		opcion=menu_principal();//Mostramos el menu principal y obtenemos el valor seleccionado.
		while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5){//Solicitamos que el usuario si o si seleccione una de las opciones mostrada---
			
		    if(opcion<1 || opcion>5){
		    	limpiar_pantalla();
		    	
		    	printf("\nPor favor,  Seleccione un numero que se encuentre en el rango del menu.\n ");
		       	opcion=menu_principal();
			}
		} 
		
		//-------------------------------------------------------------------------------	
		char d3[50];
		switch(opcion){
			//---------------------------Caso N°1 Registrar entrada-------------------------------
			case 1:{
				limpiar_pantalla();//Limpiamos pantalla
				int tipo=seleccion_tipo();//Mostramos el menu para seleccionar el tipo del vehiculo.
				int espacio_auto=0, espacio_moto=0;//Variable que van a tener el espacio seleccionado.
				//-------------------------------------------------------------
				while(tipo!=1 && tipo!=2){//Solicitamos que el usuario si o si seleccione una de las opciones mostrada---
		        if(tipo<1 || tipo>2){
		    	limpiar_pantalla();
		    	printf("\nPor favor,  Seleccione un numero que se encuentre en el rango del menu.\n ");
		       	tipo=seleccion_tipo();
			}
		} 
		//-------------------------------------------------------------------------------
		 switch(tipo){
		 	//-----------------------------Caso N°1 Automovil---------------------------------
		 	case 1:{
		 		if(num_auto!=10){
		 			limpiar_pantalla();
					espacio_auto=menu_espacio_auto(automoviles);
					char placa_auto[10];
					int puntero;
					int vali=0;
					char fecha_obtenida[20];
					char hora_obtenida[20];
					char hora_inicial[20];
				    char hora_fin[20];
				    char hor_i[2];
	                char minuto_i[2];
	                char segundo_i[2];
	                char hor_f[2];
	                char minuto_f[2];
	                char segundo_f[2];
					int confimacion;
					char confirma='1';//Variable para connfirma los mensajes recibidos.
					//-------------------------------------------------------------
				    while(espacio_auto!=1 && espacio_auto!=2 && espacio_auto!=3 && espacio_auto!=4 && espacio_auto!=5 && espacio_auto!=6 && espacio_auto!=7 && espacio_auto!=8 && espacio_auto!=9 && espacio_auto!=10){//Solicitamos que el usuario si o si seleccione una de las opciones mostrada---
		              if(espacio_auto<1 || espacio_auto>10){
		    	      limpiar_pantalla();
		    	      printf("\n--------------------------------------------------------------------------\n");
		    	      printf("\nPor favor,  Seleccione un numero que se encuentre en el rango del menu.\n ");
		    	      printf("--------------------------------------------------------------------------\n");
	                  printf("\n######################################################################\n\n");
		    	      espacio_auto=menu_espacio_auto(automoviles);
		    	      }
		    	   }
		    	   //----------------------------------------------------------------
		    	   limpiar_pantalla();
		    	   do{
		    	   	fflush( stdin );//limpiamos el buffer.
		    	   	validador1=0;
		    	   	printf("------------------------------------------------------\n");
		    	   printf("Por favor, Digite el numero de la placa: ");
		    	   gets(placa_auto);
		    	   for(int n1=0;n1<10;n1++){ //validamos si la placa esta registrado.
	   				confimacion=0;
					 for(int n2=0;placa_auto[n2]!='\0';n2++){
	   				   if(automoviles[n1][n2]!=placa_auto[n2]){
	   					confimacion++;
	   									
						}									
					  }
					 if(confimacion==0){
					 puntero=n1;
					 vali++;
					 }
					}
					if(vali==1){
						printf("\n--------------------------------------------------------------------------\n");
		    	        printf("\nOjo esta placa ya se encuentra en el parqueado.\n ");
		    	        printf("--------------------------------------------------------------------------\n");
	                    printf("\n######################################################################\n\n");
					}else{
						validador1++;
						strcpy(automoviles[espacio_auto-1],placa_auto);
						
					}
					
				   }while(validador1==0);
				   //-----------------------------------------------------------------
				   limpiar_pantalla();
				   do{
				   	fflush( stdin );//limpiamos el buffer.
				   	validador2=0;
				   	printf("\nPor favor, digita cuantos minutos vas ha solicitar el sevicio: ");
				   	scanf("%d",&minutos_auto[espacio_auto-1]);
				   	if(minutos_auto[espacio_auto-1]<=59){
				   		validador2++;
					   }else{
					   	printf("\n--------------------------------------------------------------------------\n");
		    	        printf("\nOjo lo maximo que puedes utilizar es de 59 minutos.\n ");
		    	        printf("--------------------------------------------------------------------------\n");
	                    printf("\n######################################################################\n\n");
					   }
				   }while(validador2==0);
				   //-----------------------------------------------------------------
				   do{
				   printf("\n-------------------------------------------------------");
				   printf("\n ------Confirmación del parqueadero---------- ");
				   printf("\n-------------------------------------------------------");
				   fecha_hora();
				   printf("\nTipo de vehiculo: Automovil");
				   printf("\nNumero de la placa: %s",placa_auto);
				   //--------------------------------
				   if(espacio_auto==1){strcpy(historial[contador].estacionamiento,"C-UNO");}
				   if(espacio_auto==2){strcpy(historial[contador].estacionamiento,"C-DOS");}
				   if(espacio_auto==3){strcpy(historial[contador].estacionamiento,"C-TRES");}
				   if(espacio_auto==4){strcpy(historial[contador].estacionamiento,"C-CUATRO");}
				   if(espacio_auto==5){strcpy(historial[contador].estacionamiento,"C-CINCO");}
				   if(espacio_auto==6){strcpy(historial[contador].estacionamiento,"C-SEIS");}
				   if(espacio_auto==7){strcpy(historial[contador].estacionamiento,"C-SIETE");}
				   if(espacio_auto==8){strcpy(historial[contador].estacionamiento,"C-OCHO");}
				   if(espacio_auto==9){strcpy(historial[contador].estacionamiento,"C-NUEVE");}
				   if(espacio_auto==10){strcpy(historial[contador].estacionamiento,"C-DIEZ");}
				   //--------------------------------
				   printf("\nMinutos solicitado por el servicio: %d",minutos_auto[espacio_auto-1]);
				   //------------------------------
				   sprintf(hor_i,"%d",miTiempo->tm_hour);
	               sprintf(minuto_i,"%d",miTiempo->tm_min);
	               sprintf(segundo_i,"%d",miTiempo->tm_sec);
	               strcpy(hora_inicial,hor_i);
	               strcat(hora_inicial,":");
	               strcat(hora_inicial,minuto_i);
	               strcat(hora_inicial,":");
	               strcat(hora_inicial,segundo_i);
	               printf("\nHora inicial: %s",hora_inicial);
	               //------------------------------
	               if((miTiempo->tm_min+minutos_auto[espacio_auto-1])<59){
	               	
	               sprintf(hor_f,"%d",miTiempo->tm_hour);
	               sprintf(minuto_f,"%d",(miTiempo->tm_min+minutos_auto[espacio_auto-1]));
	               sprintf(segundo_f,"%d",miTiempo->tm_sec);
	               historial[contador].hora_estimada=miTiempo->tm_hour;
	               historial[contador].minuto_estimada=(miTiempo->tm_min+minutos_auto[espacio_auto-1]);
				   strcpy(hora_fin,hor_f);
	               strcat(hora_fin,":");
	               strcat(hora_fin,minuto_f);
	               strcat(hora_fin,":");
	               strcat(hora_fin,segundo_f);
	               printf("\nHora estimada de salida: %s",hora_fin);
				   }else{
				   	
				   	sprintf(hor_f,"%d",miTiempo->tm_hour+1);
				   	sprintf(minuto_f,"%d",(miTiempo->tm_min+minutos_auto[espacio_auto-1])-60);
				   	sprintf(segundo_f,"%d",miTiempo->tm_sec);
				   	historial[contador].hora_estimada=miTiempo->tm_hour+1;
				   	historial[contador].minuto_estimada=((miTiempo->tm_min+minutos_auto[espacio_auto-1])-60);
				   	strcpy(hora_fin,hor_f);
	                strcat(hora_fin,":");
	                strcat(hora_fin,minuto_f);
	                strcat(hora_fin,":");
	                strcat(hora_fin,segundo_f);
	                printf("\nHora estimada de salida: %s",hora_fin);
				   }
	               //------------------------------
				   hora(hora_obtenida);
				   strcpy(historial[contador].tipo_vehiculo,"Automovil");
				   strcpy(historial[contador].placa,placa_auto);
				   strcpy(historial[contador].fecha_actual,fecha_obtenida);
				   strcpy(historial[contador].hora_llegada,hora_inicial);
				   strcpy(historial[contador].hora_salida,hora_fin);
				   contador++;
				   num_auto++;
				   fecha(fecha_obtenida);
				   printf("\n-------------------------------------------------------\n");
				   //---------------------------------
				   fflush( stdin );//limpiamos el buffer.
				   printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
				   scanf("%c",&confirma);
			       }while(confirma!=10);
			       limpiar_pantalla();
		    	   
				}else{
				
		    	 printf("\nCupo Lleno en automovil, Por favor vuelva más tarde.\n ");
		    	
				}
				//---------------------------------------------------------------------------------
				break;
			 }
			 //---------------------- Fin del caso N°1 Automovil--------------------------------
			 
			 //------------------Caso N°2 Motocicleta-------------------------------------
			 case 2:{
			 	//-------------------
			 	char placa_moto[10];
				int puntero;
				int vali=0;
				char fecha_obtenida[20];
				char hora_obtenida[20];
				char hora_inicial[20];
				char hora_fin[20];
				char hor_i[2];
	            char minuto_i[2];
	            char segundo_i[2];
	            char hor_f[2];
	            char minuto_f[2];
	            char segundo_f[2];
				int confimacion;
				char confirma='1';//Variable para connfirma los mensajes recibidos.
				//----------------
			 	if(num_moto!=6){
			 		limpiar_pantalla();
						espacio_moto=menu_espacio_moto(motocicleta);
						while(espacio_moto!=1 && espacio_moto!=2 && espacio_moto!=3 && espacio_moto!=4 && espacio_moto!=5 && espacio_moto!=6){//Solicitamos que el usuario si o si seleccione una de las opciones mostrada---
		                if(espacio_moto<1 || espacio_moto>6){
		    	        limpiar_pantalla();
		    	        printf("\n--------------------------------------------------------------------------\n");
		    	        printf("\nPor favor,  Seleccione un numero que se encuentre en el rango del menu.\n ");
		    	        printf("--------------------------------------------------------------------------\n");
	                    printf("\n######################################################################\n\n");
		    	        espacio_moto=menu_espacio_moto(motocicleta);
		    	        }
		    	      }
		    	      //-----------------------------------------------------------------------------
		    	      limpiar_pantalla();
		    	   do{
		    	   	validador1=0;
		    	   	fflush( stdin );//limpiamos el buffer.
		    	   	printf("------------------------------------------------------\n");
		    	   printf("Por favor, Digite el numero de la placa: ");
		    	   gets(placa_moto);
		    	   for(int n1=0;n1<6;n1++){ //validamos si la placa esta registrado.
	   				confimacion=0;
					 for(int n2=0;placa_moto[n2]!='\0';n2++){
	   				   if(motocicleta[n1][n2]!=placa_moto[n2]){
	   					confimacion++;
	   									
						}									
					  }
					 if(confimacion==0){
					 puntero=n1;
					 vali++;
					 }
					}
					if(vali==1){
						printf("\n--------------------------------------------------------------------------\n");
		    	        printf("\nOjo esta placa ya se encuentra en el parqueado.\n ");
		    	        printf("--------------------------------------------------------------------------\n");
	                    printf("\n######################################################################\n\n");
					}else{
						validador1++;
						strcpy(motocicleta[espacio_moto-1],placa_moto);
					}
					
				   }while(validador1==0);
				   //-----------------------------------------------------------------
				   limpiar_pantalla();
				   do{
				   	fflush( stdin );//limpiamos el buffer.
				   	validador2=0;
				   	printf("\nPor favor, digita cuantos minutos vas ha solicitar el sevicio: ");
				   	scanf("%d",&minutos_moto[espacio_moto-1]);
				   	if(minutos_moto[espacio_moto-1]<=59){
				   		validador2++;
					   }else{
					   	printf("\n--------------------------------------------------------------------------\n");
		    	        printf("\nOjo lo maximo que puedes utilizar es de 59 minutos.\n ");
		    	        printf("--------------------------------------------------------------------------\n");
	                    printf("\n######################################################################\n\n");
					   }
				   }while(validador2==0);
				   //-----------------------------------------------------------------
				   do{
				   
				   printf("\n-------------------------------------------------------");
				   printf("\n ------Confirmación del parqueadero---------- ");
				   printf("\n-------------------------------------------------------");
				   fecha_hora();
				   printf("\nTipo de vehiculo: Motocicleta");
				   printf("\nNumero de la placa: %s",placa_moto);
				   printf("\nMinutos solicitado por el servicio: %d",minutos_moto[espacio_moto-1]);
				   //------------------------------
				   
				   //-----------------------------
				   fecha(fecha_obtenida);
				   hora(hora_obtenida);
				   //----------------------------
				   
				   //------------------------------
				   sprintf(hor_i,"%d",miTiempo->tm_hour);
	               sprintf(minuto_i,"%d",miTiempo->tm_min);
	               sprintf(segundo_i,"%d",miTiempo->tm_sec);
	               strcpy(hora_inicial,hor_i);
	               strcat(hora_inicial,":");
	               strcat(hora_inicial,minuto_i);
	               strcat(hora_inicial,":");
	               strcat(hora_inicial,segundo_i);
	               printf("\nHora inicial: %s",hora_inicial);
	               //------------------------------
	               
	               //------------------------------
	               if((miTiempo->tm_min+minutos_moto[espacio_moto-1])<59){
	               sprintf(hor_f,"%d",miTiempo->tm_hour);
	               sprintf(minuto_f,"%d",(miTiempo->tm_min+minutos_moto[espacio_moto-1]));
	               sprintf(segundo_f,"%d",miTiempo->tm_sec);
				   strcpy(hora_fin,hor_f);
	               strcat(hora_fin,":");
	               strcat(hora_fin,minuto_f);
	               strcat(hora_fin,":");
	               strcat(hora_fin,segundo_f);
	               printf("\nHora estimada de salida: %s",hora_fin);
				   }else{
				   	sprintf(hor_f,"%d",miTiempo->tm_hour+1);
				   	sprintf(minuto_f,"%d",(miTiempo->tm_min+minutos_moto[espacio_moto-1])-60);
				   	sprintf(segundo_f,"%d",miTiempo->tm_sec);
				   	strcpy(hora_fin,hor_f);
	                strcat(hora_fin,":");
	                strcat(hora_fin,minuto_f);
	                strcat(hora_fin,":");
	                strcat(hora_fin,segundo_f);
	                printf("\nHora estimada de salida: %s",hora_fin);
				   }
	               //------------------------------
	               
				   //--------------------------------
				   if(espacio_moto==1){strcpy(historial[contador].estacionamiento,"M-UNO");}
				   if(espacio_moto==2){strcpy(historial[contador].estacionamiento,"M-DOS");}
				   if(espacio_moto==3){strcpy(historial[contador].estacionamiento,"M-TRES");}
				   if(espacio_moto==4){strcpy(historial[contador].estacionamiento,"M-CUATRO");}
				   if(espacio_moto==5){strcpy(historial[contador].estacionamiento,"M-CINCO");}
				   if(espacio_moto==6){strcpy(historial[contador].estacionamiento,"M-SEIS");}
				   
				   //--------------------------------
				   
				   strcpy(historial[contador].tipo_vehiculo,"Motocicleta");
				   strcpy(historial[contador].placa,placa_moto);
				   strcpy(historial[contador].fecha_actual,fecha_obtenida);
				   strcpy(historial[contador].hora_llegada,hora_inicial);
				   strcpy(historial[contador].hora_salida,hora_fin);
				   contador++;
				   num_moto++;
				   printf("\n-------------------------------------------------------\n");
				   //---------------------------------
				   fflush( stdin );//limpiamos el buffer.
				   printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
				   scanf("%c",&confirma);
			       }while(confirma!=10);
			       limpiar_pantalla();
		    	      
					}else{
						printf("\n--------------------------------------------------------------------------\n");
		    	        printf("\nCupo Lleno en Motocicleta, Por favor vuelva más tarde.\n ");
		    	        printf("--------------------------------------------------------------------------\n");
	                    printf("\n######################################################################\n\n");
					}
				//----------------------------------------------------------------------------
				break;
			 }
			 //--------------------------Fin del caso N°2 Motocicleta----------------------
		 }
				
				break;
			}
			//---------------------Fin del caso N°1 Registrar entrada ---------------------------------
			
			//---------------------Caso N°2 Registrar Salida -------------------------------------------
			case 2:{
				limpiar_pantalla();//Limpiamos pantalla.
				int tipo=seleccion_tipo_salida();//Mostramos el menu para seleccionar el tipo del vehiculo.
				int espacio_auto=0, espacio_moto=0;//Variable que van a tener el espacio seleccionado.
				int hora_salida_regitrada=0, minuto_salida_registrada=0;//Variable para obtener la hora y minuto registrada.
				//-------------------------------------------------------------
				while(tipo!=1 && tipo!=2){//Solicitamos que el usuario si o si seleccione una de las opciones mostrada---
		          if(tipo<1 || tipo>2){
		    	  limpiar_pantalla();
		    	  printf("\n--------------------------------------------------------------------------\n");
		    	  printf("\nPor favor,  Seleccione un numero que se encuentre en el rango del menu.\n ");
		    	  printf("--------------------------------------------------------------------------\n");
	              printf("\n######################################################################\n\n");
		    	  tipo=seleccion_tipo_salida();
			      }
		       }
			   //--------------------------------------------------------------
			   switch(tipo){
			   	//------------------------Caso N°1 Automovil--------------------------
			   	case 1:{
			   		limpiar_pantalla();
			   		char placa_autos[10];
			   		int validador1=0;
			   		int puntero;
			   		char hora_real_salida[20];
			   		int puntero_historial;
			   		int confimacion;
			   		int vali=0;
			   		int pago=0;
			   		int buscador;//Varible para buscar el usuario.
			   		//-------------------------------------------------------
			   		do{
			   			validador1=0;
			   			fflush( stdin );//limpiamos el buffer.
			   			printf("\nPor favor, digita la placa del vehiculo: ");
			   			gets(placa_autos);
			   			//-------------------------------
			   			for(int n1=0;n1<10;n1++){ //validamos si la placa esta registrado.
	   				     confimacion=0;
					     for(int n2=0;placa_autos[n2]!='\0';n2++){
	   				       if(automoviles[n1][n2]!=placa_autos[n2]){
	   					     confimacion++;			
						    }									
					     } 
					     if(confimacion==0){
					        puntero=n1;
					        vali++;
					      }
					     }
					     //-----------------------------------
					if(vali==1){
						validador1++;
						char confirma='1';//Variable para connfirma los mensajes recibidos.
						//---------------------------------------
						for(int i=0;i<contador;i++){
							if(strcasecmp(historial[i].placa,placa_autos)==0){
								puntero_historial=i;
								break;
							}
						}
						//---------------------------------------
						do{
							fflush( stdin );//limpiamos el buffer.
						
                            printf("\n*-----PARKING APP-----\n ");
                          
                            printf("-----Confirmación de pago del Vehiculo.-----\n");
                           
                            fecha_hora();
                            printf("\n Tipo de vehiculo: %s .",historial[puntero_historial].tipo_vehiculo);
                            printf("\n La placa del vehiculo: %s", historial[puntero_historial].placa);
                            printf("\n Estacionamiento que estaba ubicado: %s",historial[puntero_historial].estacionamiento);
                            printf("\n Hora en la que entro el vehiculo: %s",historial[puntero_historial].hora_llegada);
                            printf("\n Hora estimada de salida del vehiculo: %s",historial[puntero_historial].hora_salida);
                            hora(hora_real_salida);
                            printf("\n Hora real de salida: %s",hora_real_salida);
                            //----------------------------------------------
                            if(miTiempo->tm_hour==historial[puntero_historial].hora_estimada){
                            	if(miTiempo->tm_min<historial[puntero_historial].minuto_estimada){
                            		pago=3000;
								}else{
									int aux=200*(miTiempo->tm_min-historial[puntero_historial].minuto_estimada);
									pago=3000+aux;
								}
							}else{
								pago=6000;
							}
							//-----------------------------------------------
							printf("\n Monto a pagar: %d",pago);
                            //-----------------------------------------------
                            strcpy(automoviles[puntero]," ");
                            //-----------------------------------------------
                            num_auto--;
                            //----------------------------------------------
                            printf("\n---------------------------------------------------------\n");
                            fflush( stdin );//limpiamos el buffer.
				            printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
				            scanf("%c",&confirma);   
						}while(confirma!=10);
						
					}else{
						printf("\n--------------------------------------------------------------------------\n");
		    	        printf("\nOjo esta placa no se encuentra en el parqueado o no esta registrada.\n ");
		    	        printf("--------------------------------------------------------------------------\n");
	                    printf("\n######################################################################\n\n");
						
					}
			   			//-------------------------------
					   }while(validador1==0);
			   		
					break;
				}
				//---------------------Fin del Caso N°1 Automovil-----------------------
				
				//-----------------------Caso N°2 Motocicleta---------------------------
				case 2:{
					limpiar_pantalla();
			   		char placa_moto[10];
			   		int validador1=0;
			   		int puntero;
			   		char hora_real_salida[20];
			   		int puntero_historial;
			   		int confimacion;
			   		int vali=0;
			   		int pago=0;
			   		int buscador;//Varible para buscar el usuario.
			   		//-------------------------------------------------------
			   		do{
			   			validador1=0;
			   			fflush( stdin );//limpiamos el buffer.
			   			printf("\nPor favor, digita la placa del vehiculo: ");
			   			gets(placa_moto);
			   			//-------------------------------
			   			for(int n1=0;n1<10;n1++){ //validamos si la placa esta registrado.
	   				     confimacion=0;
					     for(int n2=0;placa_moto[n2]!='\0';n2++){
	   				       if(motocicleta[n1][n2]!=placa_moto[n2]){
	   					     confimacion++;			
						    }									
					     } 
					     if(confimacion==0){
					        puntero=n1;
					        vali++;
					      }
					     }
					     //-----------------------------------
					if(vali==1){
						validador1++;
						char confirma='1';//Variable para connfirma los mensajes recibidos.
						//---------------------------------------
						for(int i=0;i<contador;i++){
							if(strcasecmp(historial[i].placa,placa_moto)==0){
								puntero_historial=i;
								break;
							}
						}
						//---------------------------------------
						do{
							fflush( stdin );//limpiamos el buffer.
						
                            printf("-----PARKING APP-----\n");                        
                            printf("-----Confirmación de pago del Vehiculo-----");
                            fecha_hora();
                            printf("\n Tipo de vehiculo: %s .",historial[puntero_historial].tipo_vehiculo);
                            printf("\n La placa del vehiculo: %s", historial[puntero_historial].placa);
                            printf("\n Estacionamiento que estaba ubicado: %s",historial[puntero_historial].estacionamiento);
                            printf("\n Hora en la que entro el vehiculo: %s",historial[puntero_historial].hora_llegada);
                            printf("\n Hora estimada de salida del vehiculo: %s",historial[puntero_historial].hora_salida);
                            hora(hora_real_salida);
                            printf("\n Hora real de salida: %s",hora_real_salida);
                            //----------------------------------------------
                            if(miTiempo->tm_hour==historial[puntero_historial].hora_estimada){
                            	if(miTiempo->tm_min<historial[puntero_historial].minuto_estimada){
                            		pago=1000;
								}else{
									int aux=200*(miTiempo->tm_min-historial[puntero_historial].minuto_estimada);
									pago=1000+aux;
								}
							}else{
								pago=2000;
							}
							//-----------------------------------------------
							printf("\n Monto a pagar: %d",pago);
                            //-----------------------------------------------
                            strcpy(motocicleta[puntero]," ");
                            //-----------------------------------------------
                            num_moto--;
                            printf("\n---------------------------------------------------------\n");
                            fflush( stdin );//limpiamos el buffer.
				            printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
				            scanf("%c",&confirma);   
						}while(confirma!=10);
						
					}else{
						printf("\n--------------------------------------------------------------------------\n");
		    	        printf("\nOjo esta placa no se encuentra en el parqueado o no esta registrada.\n ");
		    	        printf("--------------------------------------------------------------------------\n");
	                    printf("\n######################################################################\n\n");
						
					}
			   			//-------------------------------
					   }while(validador1==0);
					break;
				}
				//----------------------Fin del caso N°2 Motocicleta---------------------   
				   
			   }
			   //----------------Fin del switch de tipo de vehiculo de salida.------------------------
				
				break;
			}
			//--------------------- Fin el caso N°2 Registrar Salida ----------------------------------
			
			//----------------------Caso N°3 Verificiar cupo de automovil-----------------------------------
			case 3:{
				limpiar_pantalla();
					char confirma='1';
					do{
					
				    printf("-----PARKING APP-----");
                    printf("-----Verificación de cupo en automovil-----");
                    if(strcmp(automoviles[0]," ")!=0){
						printf("\nEl espacio de C1 esta ocupado por: %s",automoviles[0]);
					}else{
						printf("\nEl espacio de C1 esta libre.");
					}
					if(strcmp(automoviles[1]," ")!=0){
						printf("\nEl espacio de C2 esta ocupado por: %s",automoviles[1]);
					}else{
						printf("\nEl espacio de C2 esta libre.");
					}
					if(strcmp(automoviles[2]," ")!=0){
						printf("\nEl espacio de C3 esta ocupado por: %s",automoviles[2]);
					}else{
						printf("\nEl espacio de C3 esta libre.");
					}
					if(strcmp(automoviles[3]," ")!=0){
						printf("\nEl espacio de C4 esta ocupado por: %s",automoviles[3]);
					}else{
						printf("\nEl espacio de C4 esta libre.");
					}
					if(strcmp(automoviles[4]," ")!=0){
						printf("\nEl espacio de C5 esta ocupado por: %s",automoviles[4]);
					}else{
						printf("\nEl espacio de C5 esta libre.");
					}
					if(strcmp(automoviles[5]," ")!=0){
						printf("\nEl espacio de C6 esta ocupado por: %s",automoviles[5]);
					}else{
						printf("\nEl espacio de C6 esta libre.");
					}
					if(strcmp(automoviles[6]," ")!=0){
						printf("\nEl espacio de C7 esta ocupado por: %s",automoviles[6]);
					}else{
						printf("\nEl espacio de C7 esta libre.");
					}
					if(strcmp(automoviles[7]," ")!=0){
						printf("\nEl espacio de C8 esta ocupado por: %s",automoviles[7]);
					}else{
						printf("\nEl espacio de C8 esta libre.");
					}
					if(strcmp(automoviles[8]," ")!=0){
						printf("\nEl espacio de C9 esta ocupado por: %s",automoviles[8]);
					}else{
						printf("\nEl espacio de C9 esta libre.");
					}
					if(strcmp(automoviles[9]," ")!=0){
						printf("\nEl espacio de C10 esta ocupado por: %s",automoviles[9]);
					}else{
						printf("\nEl espacio de C10 esta libre.");
					}
					printf("\n------------------------------------------------------");
					//----------------------------------------------------------------------
		 			fflush( stdin );//limpiamos el buffer.
					printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
					scanf("%c",&confirma);
				     }while(confirma!=10);
				     limpiar_pantalla();
				break;
			}
			//------------------------Fin del caso N°3 Verificar cupo de automovil--------------------------
			
			//-------------------------Caso N°4 Verificar cupo de motocicleta-------------------------------
			case 4:{
				limpiar_pantalla();
					char confirma='1';
					do{
					
				
                    printf("-----PARKING APP-----\n");
                    printf("-----Verificación de cupo en motocicleta-----\n");
                    if(strcmp(motocicleta[0]," ")!=0){
						printf("\nEl espacio de M1 esta ocupado por: %s",motocicleta[0]);
					}else{
						printf("\nEl espacio de M1 esta libre.");
					}
					if(strcmp(motocicleta[1]," ")!=0){
						printf("\nEl espacio de M2 esta ocupado por: %s",motocicleta[1]);
					}else{
						printf("\nEl espacio de M2 esta libre.");
					}
					if(strcmp(motocicleta[2]," ")!=0){
						printf("\nEl espacio de M3 esta ocupado por: %s",motocicleta[2]);
					}else{
						printf("\nEl espacio de M3 esta libre.");
					}
					if(strcmp(motocicleta[3]," ")!=0){
						printf("\nEl espacio de M4 esta ocupado por: %s",motocicleta[3]);
					}else{
						printf("\nEl espacio de M4 esta libre.");
					}
					if(strcmp(motocicleta[4]," ")!=0){
						printf("\nEl espacio de M5 esta ocupado por: %s",motocicleta[4]);
					}else{
						printf("\nEl espacio de M5 esta libre.");
					}
					if(strcmp(motocicleta[5]," ")!=0){
						printf("\nEl espacio de M6 esta ocupado por: %s",motocicleta[5]);
					}else{
						printf("\nEl espacio de M6 esta libre.");
					}
					printf("\n------------------------------------------------------");
					//----------------------------------------------------------------------
		 			fflush( stdin );//limpiamos el buffer.
					printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
					scanf("%c",&confirma);
				     }while(confirma!=10);
				     limpiar_pantalla();
				break;
			}
			//------------------------------Fin del caso N°4 Verificar cupo de motocicleta----------------------
			
			
			//------------------------------Caso N°5 salida-------------------------
			case 5:{
				repeticiones++;
				break;
			}
			//--------------------- fin del casoN N°5 salida-------------------------
		}
}
}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------
//Metodo para seleccionar espacio del automovil
int menu_espacio_auto(char automoviles[10][10]){

	int r=0;
    printf("-----PARKING APP-----\n");
    printf("-----Selección de espacio en los automoviles-----\n");
    printf("\n**********************************************************\t\n ");
	if(strcmp(automoviles[0]," ")==0){ printf("\n(1) El espacio de C1 esta libre.");}
	if(strcmp(automoviles[1]," ")==0){ printf("\n(2) El espacio de C2 esta libre.");}
	if(strcmp(automoviles[2]," ")==0){ printf("\n(3) El espacio de C3 esta libre.");}
	if(strcmp(automoviles[3]," ")==0){ printf("\n(4) El espacio de C4 esta libre.");}
	if(strcmp(automoviles[4]," ")==0){ printf("\n(5) El espacio de C5 esta libre.");}
	if(strcmp(automoviles[5]," ")==0){ printf("\n(6) El espacio de C6 esta libre.");}
	if(strcmp(automoviles[6]," ")==0){ printf("\n(7) El espacio de C7 esta libre.");}
	if(strcmp(automoviles[7]," ")==0){ printf("\n(8) El espacio de C8 esta libre.");}
	if(strcmp(automoviles[8]," ")==0){ printf("\n(9) El espacio de C9 esta libre.");}
	if(strcmp(automoviles[9]," ")==0){ printf("\n(10) El espacio de C10 esta libre.");}
	printf("\n---------------------------------------------------------");
	printf(" \n Por favor, Ingresa un numero del menú de opciones: ");   
    scanf("%d",&r);   
    return r;
	
}
//-----------------------------------------------------------------------------------

//------------------------------------------------------------------------
//Metodo para seleccionar espacio de la motocicleta
int menu_espacio_moto(char motocicleta[6][10]){
	int r=0;
    printf("-----PARKING APP-----\n");
    printf("-----Selección de espacio en las motocicletas-----\n");
    if(strcmp(motocicleta[0]," ")==0){ printf("\n(1) El espacio de M1 esta libre.");}
	if(strcmp(motocicleta[1]," ")==0){ printf("\n(2) El espacio de M2 esta libre.");}
	if(strcmp(motocicleta[2]," ")==0){ printf("\n(3) El espacio de M3 esta libre.");}
	if(strcmp(motocicleta[3]," ")==0){ printf("\n(4) El espacio de M4 esta libre.");}
	if(strcmp(motocicleta[4]," ")==0){ printf("\n(5) El espacio de M5 esta libre.");}
	if(strcmp(motocicleta[5]," ")==0){ printf("\n(6) El espacio de C6 esta libre.");}
	printf("\n---------------------------------------------------------");
	printf(" \n Por favor, Ingresa un numero del menú de opciones: ");   
    scanf("%d", &r);   
    return r;
	
}
//-----------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
//Metodo para seleccionar el tipo de vehiculo.
int seleccion_tipo(){
	int r=0;
	
    printf("\n* PARKING APP *\n ");   
    printf("\n* Selección del tipo de vehiculo. *\n ");
   	printf("Por favor, Seleccionar una de las dos opciones:");
	printf("\n (1)	Automovil. ");
	printf("\n (2)	Motocicleta. ");
	printf("\n ");	
	printf(" \n Por favor, Ingresa un numero del menu de opciones: ");   
    scanf("%d", &r);   
    return r;	
	
}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
//Metodo para seleccionar el tipo de vehiculo de salida.
int seleccion_tipo_salida(){
	int r=0;

    printf("\n*                     PARKING APP                        *\n ");   
    printf("\n*    Selección del tipo de vehiculo que va de salida.    *\n ");
   	printf("\n (1)	Automovil. ");
	printf("\n (2)	Motocicleta. ");
	printf("\n ");	
	printf(" \n Por favor, Ingresa un numero del menu de opciones: ");   
    scanf("%d", &r);   
    return r;	
	
}
//------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------
//Metodo para mostrar la fecha y hora de la consola
void fecha_hora() {
    time_t tiempoAhora; // creamos una variable de tipo time_t
	time(&tiempoAhora);
	struct tm *miTiempo=localtime(&tiempoAhora);
	printf("\nFecha: %d/%d/%d  Hora: %d:%d:%d\n",miTiempo->tm_mday,miTiempo->tm_mon,miTiempo->tm_year+1900,miTiempo->tm_hour,miTiempo->tm_min,miTiempo->tm_sec);
	

}
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
//metodo para obtener la fecha
char* fecha(char* fecha){
	time_t tiempoAhora; // creamos una variable de tipo time_t
	time(&tiempoAhora);
	char dia [2];
	char mes [2];
	char ano[4];
	struct tm *miTiempo=localtime(&tiempoAhora);
	sprintf(dia,"%d",miTiempo->tm_mday);
	sprintf(mes,"%d",miTiempo->tm_mon);
	sprintf(ano,"%d",miTiempo->tm_year+1900);
	strcat(fecha,dia);
	strcat(fecha,"/");
	strcat(fecha,mes);
	strcat(fecha,"/");
	strcat(fecha,ano);
	return fecha;
}
//-------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
//metodo para obtener la hora
char* hora(char* hora){
	time_t tiempoAhora; // creamos una variable de tipo time_t
	time(&tiempoAhora);
	char hor[2];
	char minuto[2];
	char segundo[2];
	struct tm *miTiempo=localtime(&tiempoAhora);
	sprintf(hor,"%d",miTiempo->tm_hour);
	sprintf(minuto,"%d",miTiempo->tm_min);
	sprintf(segundo,"%d",miTiempo->tm_sec);
	strcat(hora,hor);
	strcat(hora,":");
	strcat(hora,minuto);
	strcat(hora,":");
	strcat(hora,segundo);
	return hora;
}


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
