#pragma once
#include <iostream>
#include "NodoMatriz.h"

using namespace std;

class Matriz
{
public:
	NodoMatriz *cabecera;
	Matriz() {
		cabecera = new NodoMatriz("admin", -1, "admin");
	}

	void InsertarElmento(string usuario, int numero, string contrasena, string empresa, string departamento);
	NodoMatriz* CrearEmpresa(string empresa);
	NodoMatriz* CrearDepartamento(string departamento);
	NodoMatriz* BuscarEmpresa(string empresa, NodoMatriz* inicio);
	NodoMatriz* BuscarDepa(string departamento, NodoMatriz* inicio);

	bool VerificarEmpresa(string empresa, NodoMatriz* incio, NodoMatriz* Usr);
	bool VerificarDepartamento(string depa, NodoMatriz* incio, NodoMatriz* Usr);
};

