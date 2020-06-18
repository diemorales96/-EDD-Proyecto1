#include "pch.h"
#include "Arbol.h"
#include <iostream>
#include <string>

using namespace std;


NodoArbol * aux = NULL;
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

void Arbol::eliminar(NodoArbol *arbol, string c)
{
	if (arbol == NULL) 
	{
		return;
	}
	else if (c<arbol->id)
	{
		eliminar(arbol->izq,c);
	}
	else if (c>arbol->id)
	{
		eliminar(arbol->der,c);
	}
	else
	{
		eliminarNodo(arbol);
	}
}

NodoArbol * Arbol::minimo(NodoArbol *arbol)
{
	if (arbol == NULL)
	{
		return NULL;
	}
	if (arbol->izq)
	{
		return minimo(arbol->izq);
	}
	else
	{
		return arbol;
	}
}

void Arbol::reemplazar(NodoArbol *arbol, NodoArbol *nuevo)
{
	if (arbol->padre)
	{
		if (arbol->id == arbol->padre->izq->id)
		{
			arbol->padre->izq = nuevo;
		}
		else if(arbol->id == arbol->padre->der->id)
		{
			arbol->padre->der = nuevo;
		}
	}
	if (nuevo)
	{
		nuevo->padre = arbol->padre;
	}
}

void Arbol::destruir(NodoArbol *nodo)
{
	nodo->izq = NULL;
	nodo->der = NULL;
	delete nodo;
}

void Arbol::eliminarNodo(NodoArbol *nodo)
{
	if (nodo->izq && nodo->der)
	{
		NodoArbol *menor = minimo(nodo->der);
		nodo->id = menor->id;
		eliminarNodo(menor);
	}
	else if (nodo->izq)
	{
		reemplazar(nodo,nodo->izq);
		destruir(nodo);
	}
	else if (nodo->der)
	{
		reemplazar(nodo,nodo->der);
		destruir(nodo);
	}
	else
	{
		reemplazar(nodo,NULL);
		destruir(nodo);
	}
}

NodoArbol *Arbol::Buscar(NodoArbol *arbol, string id)
{
	if (arbol != NULL)
	{
		if (id > arbol->id)
		{
			Buscar( arbol->der,id);
		}
		else if (id < arbol->id)
		{
			Buscar(arbol->izq,id);
		}
		else if (id == arbol->id)
		{
			cout << "Elemento encontrado\n";
			aux = arbol;
			return arbol;
			
		}
	}
	else
	{
		aux = NULL;
		return arbol;
	}
}

NodoArbol* Arbol::devolverAux()
{
	return aux;
}

void Arbol::Modificar(NodoArbol *& arbol, string id, string descripcion)
{
	if (arbol != NULL)
	{
		
		Buscar(arbol, id);
		if (aux != NULL)
		{
			aux->des = descripcion;
			cout << "Activo Modificado: \n";
			cout << "ID : "<< aux->id<<" ; Nombre : "<<aux->nombre<<" ; Descripcion : "<<aux->des<<"\n";
		}
		else
		{
			cout << "Activo no encontrado";
		}
	}
}

void Arbol::preorden(NodoArbol *temp)
{
	if (temp != NULL)
	{
		if (temp->disponibilidad == 1) {
			cout << ">> ID = " << temp->id << " Nombre = " << temp->nombre << "\n";
		}
		preorden(temp->izq);
		preorden(temp->der);
	}
}

void Arbol::preordenRentados(NodoArbol *temp)
{
	if (temp != NULL)
	{
		if (temp->disponibilidad == 0) {
			cout << ">> ID = " << temp->id << " Nombre = " << temp->nombre << "\n";
		}
		preordenRentados(temp->izq);
		preordenRentados(temp->der);
	}
}
