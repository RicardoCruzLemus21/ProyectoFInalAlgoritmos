#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<clocale>



using namespace std;
 
struct Pacientes{//La estructura de paciente
	int cod;//de 001
	char nombre[15];
	char apellido[15];
	char tel[9];//9999-9999
	float imcInicial;
	float imcActual;
	char tipoIMC[25];
	int edad;
	float altura;// lb a kg
	float peso;// m^2
};

typedef Pacientes paciente;

paciente busqueda(int cod, FILE * puntero);//Funcion de busqueda que devuelve un registro y necesita un el codigo con el que se desea buscar
int maxCode(FILE * puntero);//Funcion que sirve para obtener el codigo mas grande de los registros
void eliminar(int codigo);
void division();
void escribir();
void modificar(int codigo);

int main(){
	setlocale(LC_CTYPE,"Spanish");
	paciente p;//Variable que registre todos los datos del paciente
	int op, op2 ,code; //variable para el menu
	char fin, salto[25];
	string usuario ="";
	string password = "";  //Variables para usuario y contraseña
	bool login = false;

	system("color 90");
	cout<<"\t\tBienvenido al inicio de sesion. \n\n";//Inicio de sesion
		do{//Inicio de sesion
			cout<<"\tUsuario: ";
			cin>>usuario;
			cout<<"\n\tContrase�a: ";
			cin>>password;
			
			if(usuario=="grupo8" && password=="123"){  // Usuario y contraseña
				cout<<"\nInicio de sesion exitoso \n\n";
				login=true;
			}else{
				cout<<"\nInicio de sesion incorrecto\n";
				cout<<"Ingrese nuevamente los datos.\n\n";
			}
		system("PAUSE");		 
		system("cls");
		}while(!login);//Fin de la sesion
		
	FILE * archIngreso;//Puntero que se utilizara para ingresar y actualizar registros
	FILE * archLectura;//Puntero que se utilizara unicamente para lectura del archivo
	FILE *archElimina;
	
	system("color E0");
	printf("\t\tBienvenido Estimado Usuario\n");
	do{	//inicio del do-while
		printf("\nEscoja la opcion deseada:\n\n");
		printf("\t1.Ingreso de paciente Nuevo.\n");
		printf("\t2.Actualizacion de datos.\n");
		printf("\t3.Eliminar Paciente. \n");
		printf("\t4.Reporte General. \n");
		printf("\t5.Consulta Paciente. \n");
		printf("\t6.Generar archivo para impresion.\n");
		printf("\t7.Salir\n"); 
		printf("\nIngresar opcion: ");
		scanf("%d", &op);
		
		system("cls");
		switch(op){//switch
			case 1:																				//Ingreso de los datos
				system("color C0");
				printf("Ingreso de los nuevos pacientes\n");				
				//--------								
				cout << "Bienvenido" << endl;
				op2 = 0;
				archIngreso = fopen("Paciente.txt", "a+")	;
				if (archIngreso != NULL) {
					p.cod=maxCode(archIngreso)+1;
					cout<<"\n";				
						printf("Codigo: %d", p.cod);
				
						cout<<"\n";
						cout<<"\n";
				
						printf("Nombre: ");
						scanf("%s", p.nombre);
					do{
							
				
						cout<<"\n";
												  
	       			    printf("Apellido: ");
						scanf("%s", p.apellido);
						
						cout<<"\n";
				
						printf("Telefono: ");
						scanf("%s", p.tel);
						
						cout<<"\n";
				
						do{
							printf("Edad (entre los 20 y 65 años): ");
							scanf("%d", &p.edad);
							if(p.edad<20 || p.edad>65){
								system("cls");
								printf("La edad debe de estar entre los 20 y 65 años para realizar correctamente los calculos. Intente de nuevo.\n");								
							}
						}while(p.edad<20 || p.edad>65);
							
				
						cout<<"\n";
				
						printf("Altura en m^2: ");
						scanf("%f", &p.altura);
				
						cout<<"\n";
				
						printf("Peso en libras: ");
						scanf("%f", &p.peso);

						cout<<"\n";
				
						p.peso = p.peso/2.205;
				
						p.imcInicial= p.peso/p.altura;
						p.imcActual = p.imcInicial;
						
										
						printf("Su IMC es: %0.2f\n", p.imcInicial);

						if(p.imcActual <16.00){
							strcpy(p.tipoIMC, "Delgadez Severa");
						}
						if(p.imcActual >=16.00 && p.imcActual <=16.99){
							strcpy(p.tipoIMC, "Delgadez Moderada");
						}
						if(p.imcActual >=17.00 && p.imcActual <=18.49){
						    strcpy(p.tipoIMC, "Delgadez Leve");
						}
						if(p.imcActual >=18.50 && p.imcActual <=24.99){
							strcpy(p.tipoIMC, "Peso Normal");
						}
						if(p.imcActual >=25.00 && p.imcActual <=29.99){
							strcpy(p.tipoIMC, "PreObeso");
						}
						if(p.imcActual >=30.00 && p.imcActual <=34.99){
							strcpy(p.tipoIMC, "Obesidad Leve");
						}
						if(p.imcActual >=35.00 && p.imcActual <=39.99){
							strcpy(p.tipoIMC, "Obesidad Media");
						}
						if(p.imcActual >=40.00){
							strcpy(p.tipoIMC, "Obesidad Morbida");
						}		
		
													
						cout<<"Su clasificacion de IMC esta en: "<<p.tipoIMC<<endl;
						system("PAUSE");
						system("cls");
				
				printf( "Si desea finalizar el ingreso presione ctrl +z, de lo contrario prosiga\n" );
				fprintf(archIngreso, "%d \t%s \t%s \t%s \t%0.2f \t%0.2f \t%s %d \t%0.2f \t%0.2f\n", p.cod, p.nombre, p.apellido, p.tel, p.imcInicial, p.imcActual, p.tipoIMC, p.edad, p.altura, p.peso);
  				//otro registro
  				
  				p.cod++;
				  printf("Codigo: %d", p.cod);
				
						cout<<"\n";
						cout<<"\n"; 
				
						printf("Nombre: ");
						scanf("%s", p.nombre);
  				if(feof(stdin)){//cierre del archivo
  					op2=1;
				  }
					}while(op2!=1);//fin del ciclo	
				}//fin del if apertura del archivo
				else{
					printf("El archivo no pudo abrirse\n");
				}
				fclose(archIngreso);
				break;
				
			case 2:																		
				system("color D0");	
				printf("Actualizacion de los registros\n");												//Actualizacion de datos
				printf("Ingrese el codigo del paciente:  ");
				scanf("%d", &code);
				
				modificar(code);
				break;
					
			case 3:	
			system("color 30");
				printf("Eliminacion de un registro\n");												//Eliminar Registros
				printf("Ingrese el codigo del paciente: ");
				scanf("%d", &code);
				op2 = 0;
				archLectura = fopen("Paciente.txt", "r");
								
				if(archLectura != NULL){
					p = busqueda(code, archLectura);
					if(p.cod == -1){
						printf("no se encontro el registro %d\n", code); 
						fclose(archLectura);  
					}
					else{
						printf("Desea eliminar el registro del paciente:\n\n");
						printf("Codigo\t Nombre y Apellido \tTelefono \tIMC Inicial \tIMC Actual \tTipo \t\tEdad \tAltura \tPeso\n");
						division();
						printf("%5d %10s %10s \t%10s \t%0.2f \t\t%0.2f \t\t%7s %4d \t%0.2f \t%0.2f\n", p.cod, p.nombre, p.apellido, p.tel, p.imcInicial, p.imcActual, p.tipoIMC, p.edad ,p.altura, p.peso);
						fclose(archLectura);
						do{
							printf("1. Si.\n2. No\n");
							scanf("%d", &op2);
						}while(op2!=1 && op2!=2);
						if(op2 == 1){
							eliminar(p.cod);
						}
					}				
				}
				else{
					printf("No se pudo abrir el archivo.\n");
					fclose(archLectura);
				}
				
				
				break;
			 
			case 4:	
				system("color 80");
				printf("Reporte general");																	//Reporte General
				archLectura = fopen("Paciente.txt", "r");
				rewind(archLectura);
					if (archLectura != NULL ) {
						printf("\n\n\t Pacientes\n");
						printf("Codigo\t Nombre y Apellido \tTelefono \tIMC Inicial \tIMC Actual \tTipo \tEdad \tAltura \tPeso\n");
						division();
						fscanf(archLectura, "%d %s %s %s %f %f %s %s %d %f %f", &p.cod, &p.nombre, &p.apellido, &p.tel, &p.imcInicial, &p.imcActual, p.tipoIMC, salto, &p.edad, &p.altura, &p.peso);
						while ( !feof( archLectura ) ) {
							strcat(p.tipoIMC, " ");
							strcat(p.tipoIMC, salto);
							printf("\n%5d %10s %10s \t%10s \t%0.2f \t\t%0.2f \t%10s %8d \t%0.2f \t%0.2f\n", p.cod, p.nombre, p.apellido, p.tel, p.imcInicial, p.imcActual, p.tipoIMC, p.edad ,p.altura, p.peso);
							fscanf(archLectura, "%d %s %s %s %f %f %s %s %d %f %f", &p.cod, &p.nombre, &p.apellido, &p.tel, &p.imcInicial, &p.imcActual, p.tipoIMC, salto, &p.edad, &p.altura, &p.peso);						
						}//fin del while
						
						}//fin del if apertura del archivo
						else{
							printf("\nNo se pudo abrir el archivo.\n");
						}
					fclose(archLectura);	
				break;
				
			case 5:
				system("color A0");		
				printf("Consulta Paciente\n");																//Consulta individual
				archLectura = fopen("Paciente.txt", "r");//abriendo el archivo para su lectura
				if(archLectura == NULL){//verificacion si existe
					printf("No pudo abrir el archivo.\n");
				}else{
					//solicitando el codigo para buscar
					printf("Ingrese el codigo del paciente:  ");
					scanf("%d", &code);
				
					//obteniendo la estructura de la funcion
					p = busqueda(code, archLectura);
				
					if(p.cod == -1){
						printf("no se encontro el registro %d\n", code);   
					}
					else{
						printf("Codigo\t Nombre y Apellido \tTelefono \tIMC Inicial \tIMC Actual \tTipo \t\tEdad \tAltura \tPeso\n");
						division();
						printf("%5d %10s %10s \t%10s \t%0.2f \t\t%0.2f \t\t%7s %4d \t%0.2f \t%0.2f\n", p.cod, p.nombre, p.apellido, p.tel, p.imcInicial, p.imcActual, p.tipoIMC, p.edad ,p.altura, p.peso);
					}
				}
							 
				fclose(archLectura);
				cout<<endl;
				break;
				
			case 6:	
				system("color 60");									
				printf("Generar un archivo Word o Excel\n\n");													//Crear archivo de word
				printf("Se generara un archivo adicional donde estaran los datos de la base\n\"Espere un momento\"\n\n");
				escribir();
				

				break;
				
			case 7:
				system("color E0");
				printf("El programa procedera a cerrarse\nPase feliz dia :)\n");
				getch();
				return 0;
				break;
				
			default:
				printf("El dato ingresado no es valido, intente de nuevo\n");
				break;
		}//Fin del switch
		
		system("PAUSE");
		system("cls");
 	}while(op!=7);//fin del do-while	
}
int maxCode(FILE * puntero){																		//Funcion que muestra el codigo maximo
	paciente p;
	char salto[25];
	//para regresar el puntero al inicio del archivo
	rewind(puntero);
	fseek(puntero, 0, SEEK_END);//Funcion que mueve el puntero a la posicion 0
	
	if(ftell(puntero)==0){//Condicional que verifica que el puntero que empezo en la posicion 0 no siga alli.
		p.cod = 0;
	}
	else{
		rewind(puntero);
		do{		
			fscanf(puntero, "%d %s %s %s %f %f %s %s %d %f %f", &p.cod, p.nombre, p.apellido, p.tel, &p.imcInicial, &p.imcActual, p.tipoIMC, salto, &p.edad ,&p.altura, &p.peso);
		}while(!feof(puntero));	
	}	
	return p.cod;//devuelve el ultimo codigo del archivo
}

paciente busqueda(int cod, FILE * puntero){																//funcion para buscar registros por su codigo
	paciente p;
	char salto[25];
	rewind(puntero);
	
	do{	
		fscanf(puntero, "%d %s %s %s %f %f %s %s %d %f %f", &p.cod, p.nombre, p.apellido, p.tel, &p.imcInicial, &p.imcActual, p.tipoIMC, salto, &p.edad ,&p.altura, &p.peso);
		if(cod == p.cod){
			strcat(p.tipoIMC, " ");
			strcat(p.tipoIMC, salto);
			return p;//se devuelve la estructura si se encuentra el registro													 
		}
	}while(!feof(puntero));
	p.cod = -1;
	return p;//Devuelve un valor negativo si no existe el registro
}

void eliminar(int codigo){																			//Funcion para eliminar el registro
	FILE * archEliminar;
	FILE * archFinal;
	char salto[25];
	int i = 0;
	
	archEliminar = fopen("Paciente.txt", "r");
	archFinal = fopen("Final.txt", "a+");
	paciente p; 
	if(archEliminar!= NULL){
		if(archFinal != NULL){
			fscanf(archEliminar, "%d %s %s %s %f %f %s %s %d %f %f", &p.cod, p.nombre, p.apellido, p.tel, &p.imcInicial, &p.imcActual, p.tipoIMC, salto, &p.edad ,&p.altura, &p.peso);
			while(!feof(archEliminar)){
				if(p.cod == codigo){
					printf("\nSe ha borrado el registro %d correctamente \n",codigo);
					i=1;
				}else{
					strcat(p.tipoIMC, " ");
					strcat(p.tipoIMC, salto);
					fprintf(archFinal, "%d \t%s \t%s \t%s \t%0.2f \t%0.2f \t%s %d \t%0.2f \t%0.2f\n", p.cod, p.nombre, p.apellido, p.tel, p.imcInicial, p.imcActual, p.tipoIMC, p.edad ,p.altura, p.peso);
				}
				fscanf(archEliminar, "%d %s %s %s %f %f %s %s %d %f %f", &p.cod, p.nombre, p.apellido, p.tel, &p.imcInicial, &p.imcActual, p.tipoIMC, salto, &p.edad ,&p.altura, &p.peso);			
			}//fin del while
			if(i==0)
				printf("El registro buscado no existes.\n");
			
			fclose(archEliminar);
			fclose(archFinal); 
			remove("Paciente.txt");
			rename("Final.txt", "Paciente.txt");
		}//el archivo abierto
		else{
			printf("No se pudo abrir el archivo.");
			fclose(archEliminar);
			fclose(archFinal);
		}	
	}
	else{
		printf("No se pudo abrir el archivo.");
		fclose(archEliminar);
		fclose(archFinal);
	}
	
}

void division(){
	for(int i =0; i<22*5;i++){
		cout<<"-";
	}
	cout<<endl;
}

void escribir(){																				//Funcion para crear el archivo de word
	paciente p;
	char salto[25];
	//estructura para generar un archivo
	FILE * pacientes = fopen("Paciente.txt", "r");
	ofstream archivo;//variable tipo archivo
	archivo.open("Pacientes.doc");//abrir y crear un archivo word
	
	if(archivo.is_open() && pacientes != NULL){
		cout<<"Generando el archivo\n";
		fscanf(pacientes, "%d %s %s %s %f %f %s %s %d %f %f", &p.cod, p.nombre, p.apellido, p.tel, &p.imcInicial, &p.imcActual, p.tipoIMC, salto, &p.edad ,&p.altura, &p.peso);
		archivo<<"Codigo| Nombre/Apellido| 	Tel.| 	IMC Inicial| IMC Actual| 	Tipo|		 Edad| Altura| Peso|\n\n";
		do{
			strcat(p.tipoIMC, " ");
			strcat(p.tipoIMC, salto);
			
			archivo<<p.cod <<"\t"<<p.nombre <<" "<<p.apellido <<"\t\t"<<p.tel <<"\t"<<p.imcInicial <<"\t\t"<<p.imcActual<<"\t\t"<<p.tipoIMC <<"\t   "<<p.edad<<"\t   "<<p.altura<<"\t"<<p.peso<<endl<<endl;
			fscanf(pacientes, "%d %s %s %s %f %f %s %s %d %f %f", &p.cod, p.nombre, p.apellido, p.tel, &p.imcInicial, &p.imcActual, p.tipoIMC, salto, &p.edad ,&p.altura, &p.peso);
		}while(!feof(pacientes));	
	//sleep(5);
	printf("Se ha generado un documento Pacientes.doc\n");
	}else{
		printf("No se pudo abrir el archivo.\n");
	}	
	archivo.close();
	fclose(pacientes);
}
			
void modificar(int codigo){																				//Funcion modificar
	
	FILE * archFinal;
	FILE * archIngreso;
	char salto[25];
    
    float kg=0;
	int i = 0, code;
	
	archIngreso = fopen("Paciente.txt", "r");
	archFinal = fopen("Final.txt", "a+");
	paciente p;
	if(archIngreso!= NULL){
			if(archFinal != NULL){
			fscanf(archIngreso, "%d %s %s %s %f %f %s %s %d %f %f", &p.cod, p.nombre, p.apellido, p.tel, &p.imcInicial, &p.imcActual, p.tipoIMC, salto, &p.edad ,&p.altura, &p.peso);
			strcat(p.tipoIMC, " ");
			strcat(p.tipoIMC, salto);
			while(!feof(archIngreso)){
				if(p.cod == codigo){ 
					do{
						printf("Ingrese la edad del paciente (20 a 65 años): ");
						scanf("%d", &p.edad);
						if(p.edad<20 || p.edad>65){
							system("cls");
							printf("La edad debe de estar entre los 20 y 65 años para realizar correctamente los calculos. Intente de nuevo.\n");								
						}
					}while(p.edad<20 || p.edad>65);
				
			 	   printf("\nIngrese el nuevo peso: ");
					scanf("%f", &p.peso);
					printf("\nIngrese la nueva altura: ");
					scanf("%f", &p.altura);	
					p.peso/=2.205;	
	          	  p.imcActual=p.peso /p.altura;
				//
						if(p.imcActual <16.00){
							strcpy(p.tipoIMC, "Delgadez severa");
							}
						if(p.imcActual >=16.00 && p.imcActual <=16.99){
							strcpy(p.tipoIMC, "Delgadez moderada");
						}
						if(p.imcActual >=17.00 && p.imcActual <=18.49){
		  				  strcpy(p.tipoIMC, "Delgadez leve");
						}
						if(p.imcActual >=18.50 && p.imcActual <=24.99){
							strcpy(p.tipoIMC, "Peso normal");
						}
						if(p.imcActual >=25.00 && p.imcActual <=29.99){
							strcpy(p.tipoIMC, "Preobeso");
						}
						if(p.imcActual >=30.00 && p.imcActual <=34.99){
							strcpy(p.tipoIMC, "Obesidad leve");
						}
						if(p.imcActual >=35.00 && p.imcActual <=39.99){
							strcpy(p.tipoIMC, "Obesidad media");
						}
						if(p.imcActual >=40.00){
							strcpy(p.tipoIMC, "Obesidad morbida");
							}	
					//
				 
					i=1;
					printf("Se ha modificado el peso de %s %s\n", p.nombre, p.apellido);
			   
				}
					fprintf(archFinal, "%d \t%s \t%s \t%s \t%0.2f \t%0.2f \t%s %d \t%0.2f \t%0.2f\n", p.cod, p.nombre, p.apellido, p.tel, p.imcInicial, p.imcActual, p.tipoIMC, p.edad ,p.altura, p.peso);
			
				fscanf(archIngreso, "%d %s %s %s %f %f %s %s %d %f %f", &p.cod, p.nombre, p.apellido, p.tel, &p.imcInicial, &p.imcActual, p.tipoIMC, salto, &p.edad ,&p.altura, &p.peso);
				strcat(p.tipoIMC, " ");
				strcat(p.tipoIMC, salto);			
			}//fin del while
			if(i==0)
				printf("El registro buscado no existe.\n");
			
			fclose(archIngreso);
			fclose(archFinal);  
			remove("Paciente.txt");
			rename("Final.txt","Paciente.txt");
		}//el archivo abierto
		else{
			printf("No se pudo abrir el archivo.\n");
			fclose(archIngreso);
			fclose(archFinal);
		}
	} 			
	else{
		printf("No se pudo abrir el archivo.\n");
		fclose(archIngreso);
		fclose(archFinal);
	}	
}
