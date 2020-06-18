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
	void insertar(string ,string ,string ,string,string ,string ,string ,int );
	void Mostrar(string);
	int tamanio();
	
};

