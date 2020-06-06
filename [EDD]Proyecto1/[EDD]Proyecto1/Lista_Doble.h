#pragma once
#include "Nodo_Lista.h"
#include <iostream>

using namespace std;

class Lista_Doble
{
public:
	Nodo_Lista* cabeza;
	int tamaniolista;
	Lista_Doble() {
		this -> cabeza = nullptr;
		this->tamaniolista = 0;
	}
	void insertar(string id_transaccion,string id_activo_,string usuario,string departamento,string empresa, string fecha,int dias);
	void Mostrar();
	int tamanio();

};

