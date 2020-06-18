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
	void insertar(string ,string ,string ,string,string ,string ,string ,int,bool );
	void Mostrar(string);
	Nodo_Lista * Buscar(string,string);
	int tamanio();
	void graficar();
	void generarDot(FILE*,Nodo_Lista*);
};

