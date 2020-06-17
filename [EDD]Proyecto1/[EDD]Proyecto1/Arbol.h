#pragma once
#include "NodoArbol.h"
class Arbol
{
public:
	NodoArbol* crearNodo(string,string,string,NodoArbol*);
	void insertarNodo(NodoArbol *&, string,string,string, NodoArbol *);
	void eliminar(NodoArbol *, string);
	void eliminarNodo(NodoArbol *);
	NodoArbol * minimo(NodoArbol *);
	void reemplazar(NodoArbol *, NodoArbol *);
	void destruir(NodoArbol *);
	NodoArbol * Buscar(NodoArbol *,string);
	void Modificar(NodoArbol *&, string, string);
	void preorden(NodoArbol *);
	NodoArbol * devolverAux();

	void graficar();
	void obtenerDot(FILE *file, NodoArbol *cabeza);
};

