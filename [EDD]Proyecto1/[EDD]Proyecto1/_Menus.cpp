#include "pch.h"
#include "_Menus.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void _Menus::MenuPrincipal() 
{
	int opcion = 0;
	do {
		system("cls");
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Renta de Activos %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 1. Iniciar Sesion  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%     2. Sarli       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;
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
	int opcion;
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
	
	int opcion = 0;

	switch (opcion)
	{
	case 1:
		MenuRegistro();
		break;
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
	cout << endl << endl << "...Ingrese Contraseña..." << endl << " >> ";
	cin >> contrasena;
	cout << endl << endl << "...Ingrese Departamento..." << endl << " >> ";
	cin >> departamento;
	cout << endl << endl << "...Ingrese Empresa..." << endl << " >> ";
	cin >> empresa;

	system("pause");
}

string _Menus::comparar(string usuario) 
{
	for_each(usuario.begin(), usuario.end(), [](char & c) {
		c = ::tolower(c);
	});
	
	return usuario;
}