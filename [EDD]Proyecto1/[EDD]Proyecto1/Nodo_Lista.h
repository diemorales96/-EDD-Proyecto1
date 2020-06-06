#pragma once
#include <iostream>

using namespace std;

class Nodo_Lista
{
public:
	Nodo_Lista* Siguiente;
	Nodo_Lista* Anterior;
	string id_transaccion;
	string id_activo;
	string usuario;
	string departamento;
	string empresa;
	string fecha;
	int dias;
	
	Nodo_Lista(string id_transaccion, string id_activo, string usuario, string departamento, string empresa, string fecha, int dias) 
	{
		Siguiente = nullptr;
		Anterior = nullptr;

		this->id_transaccion = id_transaccion;
		this->id_activo = id_activo;
		this->usuario = usuario;
		this->departamento = departamento;
		this->empresa = empresa;
		this->fecha = fecha;
		this->dias = dias;
	}
};