//Llamamos las libreria ha utilizar
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include <stdlib.h>
#ifdef _WIN32
#include<windows.h>
#include<locale.h> 
#endif

//Ejercicio del Banco, Elaborado por Andres Arturo Pérez

// -----Metodos o funciones----

int menu_principal();
int menu_usuario(char nombre_usuario[20][50],int puntero);
int menu_administrativo();
int menu_funcion();
void inicio_principal();
void inicio_secundario(char nombre_usuario[20][50],char correo_usuario[20][50],char clave_usuario[20][50],char cc_usuario[20][50],int num_usuarios,int estado_usuario[20][2],int saldo_usuario[20][20],int num_cuenta_usuario[20][20],int puntero);
void portal_administrativo(char nombre_usuario[20][50],char correo_usuario[20][50],char clave_usuario[20][50],char cc_usuario[20][50],int num_usuarios,
			int estado_usuario[20][2],int saldo_usuario[20][20],int num_cuenta_usuario[20][20]);
void limpiar_pantalla();


int main (){
	setlocale(LC_CTYPE, "Spanish");
	inicio_principal();
	printf("\n------------------------------------------------\n");
	printf("\nCerrando Sistema en 3");
	printf("\nCerrando Sistema en 2");
	printf("\nCerrando Sistema en 1");
	printf("\nSistema Finalizado");
	//devolvemos el control al sistema
   system("pause");
   return 0;	
}








//Metodo de menu del inicio.

int menu_principal(){
	
	int r=0;
	printf("***************************************************\n");
	printf("---------Bienvenido al Banco TransDébito----------");
	printf("\n**************************************************\n");
	printf("Por favor, Seleccionar una de las siguientes opciones:");
	printf("\n 1)	Inicio de sesión.");
	printf("\n 2)	Registrarse.");
	printf("\n 3)	Portal Administrativo.");
	printf("\n 4)	Salir.");
	printf("\n ");	
	printf(" \n Por favor, Ingresa un numero del menu de opciones: ");   
    scanf("%d", &r);   
    return r;	
}
// Fin del metodo de menu del inicio.

//Metodo del inicio principal del sistema

void inicio_principal(){
	//Definicimos las variables.
	char nombre_usuario[20][50],correo_usuario[20][50],clave_usuario[20][50],cc_usuario[20][50]; //le damos los espacio en memoria "tipo de variable char".
	int saldo_usuario[20][20],num_cuenta_usuario[20][20], estado_usuario[20][2]; // le damos los espacio en memoria "tipo de variable int".
	int num_usuarios=0; //cantidad de usuarios.
	
	int opcion=0; //variableque vamos a obtener el valor del manu
	int repeticiones=0,repeticiones_correo=0,repeticiones_clave=0;

	
	while(repeticiones ==0){
		//mostramos el menu
		opcion=menu_principal();
		
		//-- Solicitamos que el usuario si o si seleccione una de las opciones mostrada----
		while(opcion!=1 && opcion!=2 && opcion!=3  && opcion!=4){
			
		    if(opcion<1 || opcion>4){
		    	limpiar_pantalla();
		    	printf("\n -----------Por favor,  Seleccione un numero que se encuentre en el rango del menu ---------\n \n ");
		    	opcion=menu_principal();
			}
		}
		//-------------------------------------------------------------------------------
		
			char d3[50];
			switch(opcion){
				//--------------- Caso 1:Logueo del usuario -----------------------
				case 1:{ 
				char caracter;//Variable en la cual vamos a tener la clave caracter por caracter y a su vez mostramos(*).
				int r=0;
						if(num_usuarios==0){// verificamos que por lo menos alla algun usuario registrado.
						limpiar_pantalla();
						    printf("No existe usuarios registrado, Por favor registrate primero :D \n");
				            
						}else{
						limpiar_pantalla();
						char dato1[50],dato2[50]; // variables para obtenener el correo y contraseña.
	
						int resp_d1=0,resp_d2=0,permiso=0;
						int puntero;
						printf(" ");
						printf(" \n ");
					    gets(d3);
					   
						printf(" **************  Bienvenido al Login   *************  \n");
					
						do{
							
							printf("\n Por favor, ingresa el correo electronico:  ");
	   						gets(dato1);	
							printf("\n Por favor, ingresa la clave :");
							//------------------------------
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
						//-------------------------------
	
							//gets(dato2);
							printf("\n *****");	
	   						printf("\n %s",dato1);
	   						printf("\n %s",dato2);
	   						int igualesf1,igualesf2,iguales1=0,iguales2=0;
	   						puntero=0;
	   						for(int n1=0;n1<20;n1++){ //validamos si el correo esta registrado.
	   							 igualesf1=0;
								for(int n2=0;dato1[n2]!='\0';n2++){
	   								if(correo_usuario[n1][n2]!=dato1[n2]){
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
							for(int n2=0;dato2[n2]!='\0';n2++){
	   							if(clave_usuario[n1][n2]!=dato2[n2]){
	   								igualesf2++;
								}
									
							}
							if(igualesf2==0){		
								iguales2++;
							}
							}
							
							limpiar_pantalla();
							if(iguales1==1 && iguales2==1){ //si son correcto
								permiso++;
								printf("\n Sesión Denegada.\n ");
							}else{
								printf("\n el correo o contraseña es incorrecta.");
							}
	   						
	   						
						}while(permiso==0);
							if(estado_usuario[puntero][0]==0){
								printf("\n El usuario no esta habilitado. \n ");
								printf("Por favor, Comunicase con el asesor.\n");
							}else{
								inicio_secundario(nombre_usuario,correo_usuario,clave_usuario,cc_usuario,num_usuarios,estado_usuario,saldo_usuario,num_cuenta_usuario,puntero);
							}
					    }	
						
					break;
				}
				//--------------------------------------Fin del caso 1: Login -----------------------------------------------------
			
			//---------------------------Caso 2: Registro de usuario ----------------------------------------
				case 2:{
				limpiar_pantalla();
				char caracter;//Variable en la cual vamos a tener la clave caracter por caracter y a su vez mostramos(*).
				int r=0;
				limpiar_pantalla();
				    printf("**************************************************\n");
					printf("-------------Bienvenido al registro----------------");
					printf("\n*************************************************\n");
					
					printf(" ");
					printf(" \n ");
				    gets(d3);
				    
					printf("Por favor, Ingrese el nombre completo:");
       				gets(nombre_usuario[num_usuarios]);
       				printf(" \n Por favor, Ingresa su cedula de ciudadania (Sin puntos o comillas): ");
       				gets(cc_usuario[num_usuarios]);
       				do{
						
						printf("\n Por favor, Ingresa un correo electronico: ");	
		  				gets(correo_usuario[num_usuarios]);
		  				int f1,f2;
		  				int resultado=0;
						for(f1=0;correo_usuario[num_usuarios][f1]!='\0';f1++){ //validamos que el correo digitado cumpla con los estandares.
							if(resultado>=1 && correo_usuario[num_usuarios][f1]=='.'){
							resultado+=2;
							}
							if(correo_usuario[num_usuarios][f1]=='@'){
								resultado+=3;
							}
						}
						if(resultado==5){
							repeticiones_correo++;
							repeticiones_correo++;
						}else{
							printf("\n*****************************************************");
							printf("\n El correo ingresado es incorrecto o no cumple con los estandares. \n Por favor intantelo nuevamente.  ");
							printf("\n*****************************************************\n ");
						}
		  				
					}while(repeticiones_correo==0);
					int f3,f4;
					int resultado1;
		  			int resultado2;
					do{	
						printf("\n por favor ingresa una clave. Ojo debes cumplir con el estandar alfanumérico\n (que contenga números y letras y debe ser mínimo de 8 caracteres)");
						printf("\n La contraseña debe ser alfanumerica :")	;
						//------------------------------
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
						//-------------------------------
		  				//gets(clave_usuario[num_usuarios]);
		  				resultado1=0;
		  				resultado2=0;
						for(f3=0;clave_usuario[num_usuarios][f3]!='\0';f3++){ //validamos que la contraseña digitada cumpla con el estandar alfanumerico.
							if(clave_usuario[num_usuarios][f3] >= '0' && clave_usuario[num_usuarios][f3] <= '9'){
								resultado1++;
							}
						}
						for(f4=0;clave_usuario[num_usuarios][f4]!='\0';f4++){
							if((clave_usuario[num_usuarios][f4]>= 'a' && clave_usuario[num_usuarios][f4] <= 'z' ) || (clave_usuario[num_usuarios][f4] >= 'A' && clave_usuario[num_usuarios][f4] <= 'Z' )) {
								resultado2++;
							}
						}
						if(resultado1>0 && resultado2>0){
							repeticiones_clave++;
						}else{
							printf("\n*********************************************************************************************\n ");
							printf(" La clave ingresada no cumple con el estandar alfanumerica. \n Por favor intantelo nuevamente. ");
							printf("\n**********************************************************************************************\n ");
						}
		  				
					}while(repeticiones_clave==0);
					//Una vez ingresado todo los campos y verrificada, al nuevo usuario tendra un monto de 1'000.000 
					num_cuenta_usuario[num_usuarios][0]=100000000+rand()%(9999999999 - 100000000);// numeros entre 1000000000 a 9999999999
					saldo_usuario[num_usuarios][0]=1000000;
					estado_usuario[num_usuarios][0]=0;
					num_usuarios++;
					
					limpiar_pantalla();
					printf("\n El usuario se ha  registrado exitosamente. \n ");
				
					break;
				}
				//----------------------- Fin del caso 2: Registrar un usuario-----------------------
				
				//--------------------------Caso 3: Portal Administrativo -----------------------------
				case 3:{
					limpiar_pantalla();// limpiamos pantalla.
					int p,p2,res1=0,res2=0,rp=0;
					char caracter;//Variable en la cual vamos a tener la clave caracter por caracter y a su vez mostramos(*).
				    int r=0;
					char datos1[50],datos2[50];
					char dd1[50];dd1[0]='a';dd1[1]='d';dd1[2]='m';dd1[3]='i';dd1[4]='n';dd1[5]='@';dd1[6]='w';dd1[7]='p';dd1[8]='o';dd1[9]='s';dd1[10]='s';dd1[11]='.';dd1[12]='c';dd1[13]='o';dd1[14]='m';dd1[15]='\0';
					char dd2[50];dd2[0]='A';dd2[1]='d';dd2[2]='m';dd2[3]='i';dd2[4]='n';dd2[5]='1';dd2[6]='2';dd2[7]='3';dd2[8]='*';dd2[9]='\0';
					
						char d4[20];
						printf(" ");
						printf(" \n ");
					    gets(d4);
					printf("\n**********************************************************************");
					printf("\n -----------  Bienvenido al portal Administrativo   -------------  \n");
					printf("*************************************************************************\n");
					printf("");
					do{
						res1=0;res2=0;
						printf("\n Por favor, ingresa el correo :  ");
		   				gets(datos1);	
						printf("\n Por favor, ingresa la clave :");
		   				//gets(datos2);
		   				//---------------------------------------
		   				while(1){
						caracter=getch();
						if(caracter == 13){
							
							datos2[r]='\0';
							break;
						}else if(caracter ==8){
							if(r>0){
								r--;
								printf("\b \b");//Boramos el caracter mal colocado y tambien *.
							}
						}else{
						printf("*");
						datos2[r]=caracter;
						r++;
				     	}
					  }
		   				//---------------------------------------
		   				if(datos1!='\0'){
						   
		   				  //validamos los datos recibidos.
						  for(p=0;datos1[p]!='\0';p++){
						    	if(datos1[p]!=dd1[p]){
								res1++;
							   }
					    	} 
					   }else{
					   	printf("\nPor favor, Verifique los datos o digite correo\n");
					   }
					   if(datos2!='\0'){
					   
						  for(p2=0;datos2[p2]!='\0';p2++){
						    	if(datos2[p2]!=dd2[p2]){
								res2++;
						    	}
					    	}
				    	}else{
				    		printf("\nPor favor, Verifique los datos o digite la clave");
						}
						if(res1==0 && res2==0){
							rp++;
							limpiar_pantalla();
							portal_administrativo(nombre_usuario,correo_usuario,clave_usuario,cc_usuario,num_usuarios,estado_usuario,saldo_usuario,num_cuenta_usuario);
						}else{
							printf("\n el correo o contraseña es incorrecto. \n");
						}
						
					}while(rp==0);
					
					break;
				}
				//--------- Fin del caso 3: Portal Administrativo----------------------
				
				//-------- Caso 4: Salida -----------------------------------
				case 4:{
					printf(" \n saliendo de la app \n ");
					repeticiones++;
					repeticiones++;
					break;
				}
				//-------- Fin del caso 4: Salida ------------------------------
			}
	}
}

//Metodo inicio para los usuarios que ya este logueado.
void inicio_secundario(char nombre_usuario[20][50],char correo_usuario[20][50],char clave_usuario[20][50],char cc_usuario[20][50],int num_usuarios,int estado_usuario[20][2],int saldo_usuario[20][20],int num_cuenta_usuario[20][20],int puntero){
		
	
	int caso=0,repeticiones=0;
	while(repeticiones ==0){
		caso=menu_usuario(nombre_usuario,puntero);
		while(caso!=1 && caso!=2 && caso!=3 && caso!=4 && caso!=5){
			
		    if(caso<1 || caso>5){
		    	printf("\n -----------Por favor,  Seleccione un numero que se encuentre en el rango de las opciones ---------\n \n ");
		    	caso=menu_usuario(nombre_usuario,puntero);
		    	limpiar_pantalla();
			}
		}
			char d3[50];
			switch(caso){
				//------------------Caso 1:Retiros------------------------
				case 1:{
					limpiar_pantalla();
					printf("\n --------------------Bienvenido sr(a) %s  al menú de retiros------------\n ",nombre_usuario[puntero]);
					int valorUsuario;
					int rep=0;
					do{
					
					printf("\n Tu saldo es de : [ %d ] ",saldo_usuario[puntero][0]);
				    printf("\n Por favor,, Ingresa el valor que desea retirar : ");
				    scanf("%d", &valorUsuario);
				    if(valorUsuario>saldo_usuario[puntero][0]){
				    	printf("\n ****************************************");
				    	printf("\n Ojo el monto del retiro supera el saldo.");
				    	printf("\n******************************************");
					}else{
						saldo_usuario[puntero][0]=saldo_usuario[puntero][0]-valorUsuario;
						rep++;
					}
					}while(rep==0);
					
					break;
				}
				//---------------------- Fin del caso 1: Retiros------------------------
				
				//----------------------- Caso 2: Deposito ------------------------------
				case 2:{
					limpiar_pantalla();
					printf("\n --------------------Bienvenido sr(a). %s  al men? de Deposito------------\n ",nombre_usuario[puntero]);
					int valorUsuario;
					int rep2=0;
					do{					
						printf("\n Tu saldo es de : [ %d ] ",saldo_usuario[puntero][0]);
					    printf("\n Ingresa el valor que desea Depositar : ");
					    scanf("%d", &valorUsuario);
					    if(valorUsuario>0){
					    	saldo_usuario[puntero][0]=saldo_usuario[puntero][0]+valorUsuario;
							rep2++;
						}else{
							printf("\n El valor ingresado no es correcto. \n Por favor inténtalo de nuevo.  ");
						}
					}while(rep2==0);
					break;
				}
				//-------------------- Fin del Caso 2: Deposito -------------------------------------------
				
				//-------------------------- Caso 3: Transferencia -------------------------------------------
				case 3:{
					limpiar_pantalla();
					printf("\n --------------------Bienvenido sr(a). %s  al menu de Transferencia ------------\n ",nombre_usuario[puntero]);
					int valorUsuario,num_cuent;
					int rep3=0,rep4=0,igualesf2=-1,iguales2=0,n2;
					do{
						printf("\n Tu saldo es de : [ %d ] ",saldo_usuario[puntero][0]);
					    printf("\n Ingresa el valor que desea Transferir : ");
					    scanf("%d", &valorUsuario);
					    if(valorUsuario>0){
					    //	saldo_usuario[puntero][0]=saldo_usuario[puntero][0]+valorUsuario;
							rep3++;
						}else{
							printf("\n El valor ingresado no es correcto. \n Por favor intantalo de nuevo.  ");
						}
					}while(rep3==0);
					do{
						
					    printf("\n Por favor ingresa el numero de cuenta de la persona a la que le depositara el dinero. : ");
					    scanf("%d", &num_cuent);
					    
					    		 igualesf2=-1;
							for(n2=0;n2<num_usuarios;n2++){
	   							if(num_cuent==num_cuenta_usuario[n2][0]){
	   								igualesf2=n2;
								}
									
							}
							if(igualesf2!=-1){	
								saldo_usuario[igualesf2][0]=saldo_usuario[igualesf2][0]+valorUsuario;
								saldo_usuario[puntero][0]=saldo_usuario[puntero][0]-valorUsuario;
								rep4++;
							}else{
								printf("\n***********************************************\n ");
								printf(" El numero de cuenta que ingreso no fue encontrado. \n por favor intantelo de nuevo. ");
								printf("\n************************************************\n");
							}
							
					}while(rep4==0);
					printf("\n si entra");
					break;
				}
				//---------- Fin del caso 3: Transferencia---------------------------------
				
				//-------- Caso 4: Informacion del usuario ---------------------------------
				case 4:{
					char confirma='1';
					do{
				    limpiar_pantalla();
					limpiar_pantalla();
					printf("\n**************************************************");
					printf("\n ---------Bienvenido a los detalles.------------ \n");
					printf("\n***************************************************");
					printf("\n Nombre :%s", nombre_usuario[puntero]);
					printf("\n Correo :%s", correo_usuario[puntero]);
					printf("\n Cedula de Cuidadania :%s", cc_usuario[puntero]);
					printf("\n N_Cuenta :%d", num_cuenta_usuario[puntero][0]);
					printf("\n Saldo :%d", saldo_usuario[puntero][0]);
					printf("\n Estado :%d", estado_usuario[puntero][0]);
					printf("\n-------------------------------------------------------\n");
					fflush( stdin );//limpiamos el buffer.
					printf("\nPara volver al menú. Por favor oprima la tecla entrer: ");
					scanf("%c",&confirma);
					}while(confirma!=10);
					break;
				}
				//----------- Fin del caso 4: Informacion del usuario ----------------------
				
				//----------- Caso 5:Salida -----------------------
				case 5:{
					repeticiones++;
					repeticiones++;
					break;
				}
				//---------- Fin del caso 5:Salida -----------------
			}
	}
	
}

// metodo para dale un menu al usuario ingresado
int menu_usuario(char nombre_usuario[20][50],int puntero){
	int r=0;
	limpiar_pantalla();
	printf("\n --------Bienvenido %s  al menu . -------\n\n",nombre_usuario[puntero]);
	printf("Por favor, Seleccionar una de las cinco opciones:");
	printf("\n (1)	Realizar Retiro.");
	printf("\n (2)	Realizar Deposito.");
	printf("\n (3)	Realizar Transferencia.");
	printf("\n (4)	Detalles (Informacion del usuario).");
	printf("\n (5)	Salir.");
	printf("\n ");	
	
	printf(" \n Por favor, Ingresa un numero del menu de opciones: ");   
    scanf("%d", &r);   

    return r;	
}



//Metodo de inicio para el administrador ya logueado
void portal_administrativo(char nombre_usuario[20][50],char correo_usuario[20][50],char clave_usuario[20][50],char cc_usuario[20][50],int num_usuarios,int estado_usuario[20][2],int saldo_usuario[20][20],int num_cuenta_usuario[20][20]){
	int caso=0,repeticiones=0;
	while(repeticiones ==0){
		caso=menu_administrativo();
		while(caso!=1 && caso!=2 && caso!=3){
			
		    if(caso<1 || caso>3){
		    	printf("\n -----------Por favor,  Seleccione un numero que se encuentre en el rango de las opciones ---------\n \n  ");
		    	caso=menu_administrativo();
			}
		}
			char d3[50];
			switch(caso){
				//------------------Caso 1:Listado de usuarios-------------------------------------
				case 1:{
				limpiar_pantalla();
					printf("\n ---------Bienvenido a los detalles.------------ \n");
					int pun;
					for(pun=0;pun<num_usuarios;pun++){
						printf("\n -------------------------------------");
						printf("\n Nombre :%s", nombre_usuario[pun]);
						printf("\n Correo :%s", correo_usuario[pun]);
						printf("\n Cedula de ciudadania. :%s", cc_usuario[pun]);
						printf("\n N_Cuenta :%d", num_cuenta_usuario[pun][0]);
						printf("\n Saldo :%d", saldo_usuario[pun][0]);
						printf("\n Estado :%d", estado_usuario[pun][0]);
						printf("\n");	
					}
					
					
					break;
				}
				//--------------------Fin del caso 2:Listado de usuarios---------------------
				
				//------------------Caso 2: Inhabilitar o Habilitar---------------------------
				case 2:{
					int q=menu_funcion();
					int valorUsuario;
					int rep_do=0;
					int igualesf2,num_cuent;
					int n2;
					while(q!=1 && q!=2){
			
					    if(q<1 || q>2){
					    	printf("\n ///////////////////// Por favor ingresa un número que se encuentre en el rango de las  opciones    ////////////////////////////////////////////////\n \n ");
					    	q=menu_funcion();
						}
					}
					
					do{
						printf("\n Por favor, Ingresa el numero de cuenta : ");
					    scanf("%d", &num_cuent);
					    
					    		 igualesf2=-1;
							for(n2=0;n2<num_usuarios;n2++){
	   							if(num_cuent==num_cuenta_usuario[n2][0]){
	   								igualesf2=n2;
								}
									
							}
							if(igualesf2!=-1){	
								estado_usuario[igualesf2][0]=q-1;
								rep_do++;
							}else{
								printf("\n ********************************************************************************\n ");
								printf("\n El número de cuenta que ingreso no fue encontrado. Por favor intentalo de nuevo.\n ");
								printf("\n *********************************************************************************\n");
							}
					}while(rep_do==0);
						
					break;
				}
				//-----------Fin del Caso 2:Inhabilitar o habilitar--------------------
				
				//--------------Caso 3: Salida--------------------------------				
				case 3:{
					limpiar_pantalla();//Limpiamos pantalla.
					repeticiones++;
					repeticiones++;
					break;
				}
				//---------Fin del caso 3: Salida-----------------------------
			}
	}
}

//Metodo del menu del administrador ya logueado
int menu_administrativo(){
	printf("\n***********************************************************");
	printf("\n --------Bienvenido   al menu  del Administrador. -------\n");
	printf("*************************************************************\n");
	
	printf("Por favor, Seleccionar una de las tres opciones:");
	printf("\n (1)	Lista de usuarios.");
	printf("\n (2)	Inhabilitar o habilitar.");
	printf("\n (3)	Salir.");
	printf("\n ");	
	int n2=0;
	printf(" \n por favor Ingresa un número del menu anterior: ");   
    scanf("%d", &n2);   

    return n2;	
}

//Metodo de menu para innhabilitar o habilitar al usuario
int menu_funcion(){
	printf("\n -------- -------\n\n");
	printf("Por favor selecciona una de las 2 opciones que se muestran continuación. ");
	printf("\n (1)	Inhabilitar.");
	printf("\n (2)	habilitar ");
	printf("\n ");	
	int n2=0;
	printf(" \n por favor Ingresa un número del menu anterior: ");   
    scanf("%d", &n2);   
    return n2;
}

//Metodo de limpiar pantalla
void limpiar_pantalla(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void num_cifra(){
	char num [10];
}

