#pragma once
#include <iostream>

using namespace std;
class NodoArbol
{
public:
	string id;
	string nombre;
	string des;
	int disponibilidad;
	NodoArbol* izq;
	NodoArbol* der;
	NodoArbol *padre;

	NodoArbol() {
		id = "";
		nombre = "";
		des = "";
		disponibilidad = 1;
		izq = NULL;
		der = NULL;
		padre = NULL;
	}

};

