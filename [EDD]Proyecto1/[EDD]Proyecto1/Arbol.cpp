#include "pch.h"
#include "Arbol.h"
#include <iostream>
#include <string>

using namespace std;
NodoArbol* Arbol::crearNodo(string id,string nombre,string des, NodoArbol *padre)
{
	NodoArbol* nuevo = new NodoArbol();
	nuevo->id = id;
	nuevo->nombre = nombre;
	nuevo->des = des;
	nuevo->der = nullptr;
	nuevo->izq = nullptr;
	nuevo->padre = padre;

	return	nuevo;
}

void Arbol::insertarNodo(NodoArbol *&arbol, string id,string nombre,string des,NodoArbol *padre)
{
	if (arbol == NULL)
	{
		NodoArbol* nuevo = crearNodo(id,nombre,des, padre);
		arbol = nuevo;
	}
	else
	{
		string valor = arbol->id;
		if (id < valor)
		{
			insertarNodo(arbol->izq, id,nombre,des, arbol);
		}
		else
		{
			insertarNodo(arbol->der, id, nombre, des, arbol);
		}
	}
}

