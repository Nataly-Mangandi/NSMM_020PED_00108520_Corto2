//Pila de platos-Stack
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include <stdio.h>
using namespace std;

struct Plato{
	string material;
	string color;
	bool estado;
};


stack <Plato> PilaSucia;
stack <Plato> PilaLimpia;

//Prototipo
void AgregarPlato();
void Ensuciar1Plato();
void EnsuciarNPlato();
void Limpiar1Plato();

int main(){
	int cP;
	int opcion;
	cout<<"\t || PILA DE PLATOS ||\n\n";
	
	
	bool continuar= true;
    cout<<"\n MENU----------\n";
    do{
    	cout<<"1. Agregar platos \n";
        cout<<"2. Ensuciar 1 plato \n";
        cout<<"3. Ensuciar N platos \n";
        cout<<"4. Limpiar 1 plato \n";
        cout<<"5. Mostrar pila limpia \n";
        cout<<"6. Mostrar pila sucia \n";
        cout<<"7. Salir \n";
        cout<<"Opcion: ";
        cin>>opcion;
    
        switch(opcion){
            case 1: cin.ignore(); AgregarPlato(); break;
            case 2: Ensuciar1Plato(); break;
            case 3: EnsuciarNPlato(); break;
            case 4: Limpiar1Plato();  break;
            case 5: break;
            case 6: break;
            case 7: continuar=false; break;
            default: cout<<"OPCION NO VALIDA \n\n"; break;
        }
        
    }while(continuar);
    
    
    return 0;
	
}

void AgregarPlato(){
	int n= 0;
	struct Plato e;
	cout<<"Ingrese cuantos platos desea agregar: "; ing: cin >> n;
	if (n < 0)
    {
        cout << "No se pueden agregar menos de 1 plato intente otra vez: ";
        goto ing;
    }
    else
    {
        for (int i = 0; i < n ; i++)
        {
            cin.ignore();
            cout << "Ingrese el material del plato: "; getline(cin, e.material);
            gLINE:
            cout << "Ingrese el color del plato: "; cin >> e.color;


            PilaLimpia.push(e);
        }   
    }
    cout << "\t Se han agregado los platos , volvera al menu...\n";
}

void Ensuciar1Plato(){
	struct Plato x=PilaLimpia.top();
	PilaLimpia.pop();
	PilaSucia.push(x);
	
	cout<<"\t Se ha ensuciado 1 plato \n";
}

void EnsuciarNPlato(){
	int n;
	do{
		cout<<"Cuantos platos desea ensuciar?: "; cin>>n;
	}while(n < PilaLimpia.size());

	for(int i=0; i<n; i++){
		Ensuciar1Plato();
	}
	cout<<"\t Se han ensuciado los platos \n";
}

void Limpiar1Plato(){
	
}
