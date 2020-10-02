//Columna litologica-Desde cero
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
using namespace std;

//Crear nodo----------
struct pilaLito{
	string tSuelo;
	float grosor;
	int dureza;
	struct pilaLito *sig;
};

//Apodo
typedef struct pilaLito *Lito;

//Prototipo de funcion
void ingresar(Lito *s, string tS, float g, int d);
void sacar(Lito *s);
void sacarTodas(Lito s);

//Inicializar la pila-----------
void inicializar(Lito *s){
	
	*s =NULL;
}

bool IsEmpty(Lito *s){
	
	return *s == NULL;
}

int main(){
	int n, d, opcion=0;
	float g;
	string tS;
	Lito s;
	inicializar(&s);
	
	cout<<"||PERFIL LITOLOGICO||\n\n";

	bool continuar= true;
	cout<<"\n MENU----------\n";
	do{
	
		cout<<"1. Ingresar capa  \n";
		cout<<"2. Borrar ultima capa \n";
		cout<<"3. Borrar todas las capas \n";
		cout<<"4. Salir \n";
		cout<<"Opcion: ";
		cin>>opcion;
		cin.ignore();
		
		switch(opcion){
			case 1: 
				cout<<"Ingrese el tipo de capa: "; cin.ignore(); getline(cin, tS);
				do{
					cout<<"Ingrese el grosor(debe ser mayor a 0): "; cin>>g;
				}while(g < 1);
				
				do{
					cout<<"Ingrese la dureza (debe ser mayor a 0): "; cin>>d;
				}while(d < 1);
				
				ingresar(&s, tS, g, d); break;
			case 2: sacar(&s); break;
			case 3: sacarTodas(s); break;
			case 4: continuar=false; break;
			default: cout<<"OPCION NO VALIDA \n\n"; break;
		}
		
	}while(continuar);
	

	return 0;
	system("pause");
}

void ingresar(Lito *s, string tS, float g, int d){
    Lito temp = new(struct pilaLito);
    temp->tSuelo= tS;
    temp->grosor= g;
    temp->dureza= d;
    temp->sig= *s;
    *s= temp;
}

void sacar(Lito *s){
    Lito aux= *s;
    *s= aux->sig;
    delete aux;
    cout<<"\t ULTIMA CAPA BORRADA\n";
}

void sacarTodas(Lito s){
	float suma=0;
	int nodo=0;
	float promedio;
	while(s!=NULL){
		suma+=s->dureza;
		nodo+=1;
		sacar(&s);
	}
	cout<<"\t SE HAN BORRADO TODAS LAS CAPAS\n";
	promedio= suma/nodo;
	cout<<"\t EL PROMEDIO DE DUREZA ES: "<<promedio<<"\n";
}




