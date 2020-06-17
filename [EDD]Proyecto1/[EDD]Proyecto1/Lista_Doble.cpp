#include "pch.h"
#include "Lista_Doble.h"
#include <iostream>

using namespace std;

void Lista_Doble::insertar(string id_transaccion, string id_activo,string activo,string des, string usuario, string departamento, string empresa, int dias)
{
	Nodo_Lista* nuevo = new Nodo_Lista(id_transaccion,id_activo,activo,des,usuario,departamento,empresa ,dias);

	if (tamaniolista == 0)
	{
		cabeza = nuevo;
		cabeza->Siguiente = nuevo;
		cabeza->Anterior = nuevo;
		tamaniolista += 1;
	}
	else
	{
		Nodo_Lista* ultimo = cabeza->Anterior;
		nuevo->Siguiente = cabeza;
		nuevo->Anterior = ultimo;
		ultimo->Siguiente = nuevo;
		cabeza->Anterior = nuevo;
		ultimo = nuevo;
		tamaniolista += 1;
	}
}


int Lista_Doble::tamanio() {
	return tamaniolista;
}