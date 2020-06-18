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
	string activo;
	string des;
	int dias;
	bool disp;
	
	Nodo_Lista(string id_transaccion, string id_activo,string activo ,string des, string usuario, string departamento, string empresa, int dias,bool disp) 
	{
		Siguiente = nullptr;
		Anterior = nullptr;

		this->id_transaccion = id_transaccion;
		this->id_activo = id_activo;
		this->activo = activo;
		this->des = des;
		this->usuario = usuario;
		this->disp = disp;
		this->departamento = departamento;
		this->empresa = empresa;
		this->dias = dias;
		
	}
};