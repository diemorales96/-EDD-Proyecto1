#pragma once
#include "NodoArbol.h"
class Arbol
{
public:
	NodoArbol* crearNodo(string,string,string,NodoArbol*);
	void insertarNodo(NodoArbol *&, string,string,string, NodoArbol *);


	void graficar();
	void obtenerDot(FILE *file, NodoArbol *cabeza);
};

