#include "pch.h"
#include "_Menus.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "Matriz.h"
#include "Arbol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista_Doble.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

Matriz* Objeto = new Matriz();
Arbol * ObjetoArbol = new Arbol();
Lista_Doble * ObjetoLista = new Lista_Doble();
NodoMatriz* A;
NodoArbol * B;
Nodo_Lista *aux3 = NULL;
bool descendente = false;
void _Menus::MenuPrincipal() 
{
	int opcion = 0;
	do {
		system("cls");
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Renta de Activos %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 1. Iniciar Sesion  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%     2. Salir       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;
		cout << " >> Ingrese Opcion\n >> ";
		cin >> opcion;
		switch (opcion) {
			case 1:
				MenuLogin();
				break;
			case 2:
				break;
			default:
				cout << "Ingrese opcion disponible\n";
				system("pause");
				break;
		}
	} while (opcion != 2);
}

void _Menus::MenuLogin() 
{
	system("cls");
	
	string usuario;
	string aux;
	string contrasena;
	string departamento;
	string empresa;
	

	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Renta de Activos %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	 Login	      %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n" << endl <<" >> ...";
	cout << "Ingrese Usuario..." << endl<<" >> ";
	cin >> usuario;
	cout << endl << endl << "...Ingrese Contraseña..."<< endl << " >> ";
	cin >> contrasena;

	if ((comparar(usuario) == "admin") && (comparar(contrasena) == "admin"))
	{
		//cout << "esto funciona" <<endl;
		Menuadmin();
	}
	else 
	{
		cout << endl << endl << "...Ingrese Departamento..." << endl << " >> ";
		cin >> departamento;
		cout << endl << endl << "...Ingrese Empresa..." << endl << " >> ";
		cin >> empresa;
		
		if (Objeto->Buscarusuario(usuario, contrasena, departamento, empresa) != NULL)
		{
			MenuUsuario(usuario,contrasena,departamento,empresa);
		}
		else
		{
			cout << "Usuario no encontrado";
			MenuLogin();
		}
	}
}

void _Menus::Menuadmin() 
{	
	system("cls");
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Menu Administrador %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << ">> %% 1. Registrar Usuario"<< endl;
	cout << ">> %% 2. Reporte Matriz Dispersa" << endl;
	cout << ">> %% 3. Reporte Activos Disponibles de un Departamento" << endl;
	cout << ">> %% 4. Reporte Activos Disponibles de una Empresa" << endl;
	cout << ">> %% 5. Reporte Transacciones" << endl;
	cout << ">> %% 6. Reporte Activos de un Usuario" << endl;
	cout << ">> %% 7. Activos rentados por un Usuario" << endl;
	cout << ">> %% 8. Ordenar Transacciones" << endl;
	cout << ">> %% 9. Cerrar sesion" << endl;
	cout << "Ingrese opcion\n >>";
	int opcion = 0;
	
	cin >> opcion;

	switch (opcion)
	{
	case 1:
	{
		MenuRegistro();
		break;
	}
	case 2:
	{
		ReporteMDispersa();

		break;
	}
	case 3:
	{
		Menuadmin();
		break;
	}
	case 4:
	{
		break;
		Menuadmin();
	}
	case 5:
	{
		if (descendente == false)
		{
			ObjetoLista->graficar();
			Menuadmin();
		}
		else
		{
			ObjetoLista->graficades();
			Menuadmin();
		}
		break;
	}
	case 6:
	{
		break;
		Menuadmin();
	}
	case 7:
	{
		int us;
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Activos por Usuario %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
		cin >> us;

		Menuadmin();
		break;
	}
	case 8:
	{
		int opc;
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Ordenar %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 1. Ascendente %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 2. Descendente %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

		
		cout << "Ingrese Opcion: \n";
		cin >> opc;
		switch (opc) {
		case 1:
		{
			descendente = false;
			break;
		}
		case 2:
		{
			descendente = true;
			break;
		}

		}
		{
		default:
			break;
		}
	}
	case 9:
	{
		MenuLogin();
		break;
	}
	}
	system("pause");
}

void _Menus::MenuRegistro() 
{
	system("cls");

	string usuario;
	string contrasena;
	string departamento;
	string empresa;

	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Administrador %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   Crear Usuario  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n" << endl << " >> ...";
	cout << "Ingrese Usuario..." << endl << " >> ";
	cin >> usuario;
	cout << endl << endl << "...Ingrese Contrasena..." << endl << " >> ";
	cin >> contrasena;
	cout << endl << endl << "...Ingrese Departamento..." << endl << " >> ";
	cin >> departamento;
	cout << endl << endl << "...Ingrese Empresa..." << endl << " >> ";
	cin >> empresa;
	Objeto->InsertarElmento(usuario, 1, contrasena, empresa, departamento);
	Menuadmin();
	system("pause");
}


void _Menus::MenuUsuario(string usuario,string contrasena,string dep,string emp)
{
	system("cls");
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Usuario: "<< usuario <<" %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "------------------------------------------------------------------------------------------------------------------------";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 1. Agregar Activo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 2. Eliminar Activo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 3. Modificar Activo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 4. Rentar Activo  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 5. Activos Rentados  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 6. Mis Activos Rentados %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 7. Cerrar Sesion  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

	cout << "Ingrese Opcion: \n";

	int opcion = 0;
	cin >> opcion;
	string id;
	string nombre;
	string des;
	NodoMatriz* aux;
	aux = Objeto->Buscarusuario(usuario, contrasena, dep, emp);
	do
	{
		switch (opcion)
		{
		case 1: {
			system("cls");
			cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Agregar Activo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
			#define LONGITUD_DESEADA 15
			char destino[LONGITUD_DESEADA + 1] = "";
			cadaleatoria(LONGITUD_DESEADA, destino);
			id = destino;
			cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% ...Ingrese Nombre... %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
			cin >> nombre;
			cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% ...Ingrese Descripcion... %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
			cin >> des;
			ObjetoArbol->insertarNodo(aux->AVL,id,nombre,des,NULL);
			MenuUsuario(usuario,contrasena,dep,emp);
			break;
		}
		case 2:
			{
			system("cls");
			cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Eliminar Activo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
			ObjetoArbol->preorden(aux->AVL);
			cout << "\nIngrese id del activo: \n";
			cin >> id;
			ObjetoArbol->eliminar(aux->AVL, id);
			cout << "Activo Eliminado ID : "<<id;
			MenuUsuario(usuario, contrasena, dep, emp);
			break;
		}
		case 3:
		{
			system("cls");
			cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Modificar Activo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
			ObjetoArbol->preorden(aux->AVL);
			cout << "\nIngrese id del activo: \n";
			cin >> id;
			system("cls");
			cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Modificando Activo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

			cout << "\nIngrese nueva descripcion del activo: \n";
			cin >> des;
			ObjetoArbol->Modificar(aux->AVL,id,des);
			system("pause");
			MenuUsuario(usuario, contrasena, dep, emp);
		}
		case 4:
		{
			system("cls");
			Objeto->Buscarusuario(usuario);
			int opcion2 = 0;
			cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 1. Rentar Activo %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
			cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 2. Regresar al menu %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
			cout << "Ingrese Opcion: \n";
			cin >> opcion2;
			switch (opcion2)
			{
			case 1:
			{
				int dias;
				cout << "Ingrese Activo a rentar: \n";
				cin >> id;
				cout << "Ingrese numero de dias a rentar: \n";
				cin >> dias;
				
				string id_trans;

				A = Objeto->Renta(id);
				ObjetoArbol->Buscar(A->AVL,id);
				B = ObjetoArbol->devolverAux();
				B->disponibilidad = 0;
				#define LONGITUD_DESEADA 15
				char destino[LONGITUD_DESEADA + 1] = "";
				cadaleatoria(LONGITUD_DESEADA, destino);
				id_trans = destino;

				ObjetoLista->insertar(id_trans,B->id,B->nombre,B->des,usuario,dep,emp,dias,true);
				system("pause");
				MenuUsuario(usuario, contrasena, dep, emp);
			}
			case 2:
			{
				MenuUsuario(usuario, contrasena, dep, emp);
			}
			}

			system("pause");
		}
		case 5:
		{
			system("cls");
			int opc2 = 0;
			cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 1. Activos Rentados %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";
			
			ObjetoLista->Mostrar(usuario);

			cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 1. Registrar Devolucion %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
			cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 2. Regresar al menu %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";

			cout << "Ingrese Opcion: \n";
			cin >> opc2;
			switch (opc2)
			{
			case 1:
			{
				cout << "Ingrese Activo a devolver: \n";
				cin >> id;
				Nodo_Lista*L;
				L = ObjetoLista->Buscar(id,usuario);
				L->disp = false;
				A = Objeto->Renta(id);
				ObjetoArbol->Buscar(A->AVL, id);
				B = ObjetoArbol->devolverAux();
				B->disponibilidad = 1;
				MenuUsuario(usuario, contrasena, dep, emp);
				break;
			}
			case 2:
				MenuUsuario(usuario, contrasena, dep, emp);
				break;
			}
			

		}
		case 6:
		{
			NodoMatriz *P;
			P = Objeto->Buscarusuario(usuario,contrasena,dep,emp);
			ObjetoArbol->preordenRentados(P->AVL);
		}
		}
	} while (opcion != 7);
	MenuLogin();
}

//Reporte de matriz dispersa

void _Menus::ReporteMDispersa()
{
	Objeto->graficar();
	Menuadmin();
}

//Metodo para convertir de mayusculas a minusculas

string _Menus::comparar(string usuario) 
{
	for_each(usuario.begin(), usuario.end(), [](char & c) {
		c = ::tolower(c);
	});
	
	return usuario;
}

//Metodo para contraseñas alfanumericas aleatorias

int _Menus::rangoaleatorio(int min, int max) {
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void _Menus::cadaleatoria(int Longitud, char *Destino) {
	char Muestra[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	for (int x = 0; x < Longitud; x++) {
		int indiceAleatorio = rangoaleatorio(0, (int)strlen(Muestra) - 1);
		Destino[x] = Muestra[indiceAleatorio];
	}
}
