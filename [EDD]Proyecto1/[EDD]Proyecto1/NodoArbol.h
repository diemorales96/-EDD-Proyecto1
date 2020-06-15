#pragma once
#include <iostream>

using namespace std;
class NodoArbol
{
public:
	string id;
	string nombre;
	string des;
	NodoArbol* izq;
	NodoArbol* der;
	NodoArbol *padre;

	NodoArbol() {
		id = "";
		nombre = "";
		des = "";
		izq = NULL;
		der = NULL;
		padre = NULL;
	}

};

