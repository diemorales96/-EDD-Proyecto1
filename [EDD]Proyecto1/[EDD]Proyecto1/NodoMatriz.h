#pragma once
#include <iostream>
#include "Arbol.h"
using namespace std;

class NodoMatriz
{
public:
	NodoMatriz *Siguiente;
	NodoMatriz *Anterior;
	NodoMatriz *Arriba;
	NodoMatriz *Abajo;
	NodoMatriz *Adelante;
	NodoMatriz *Atras;
	NodoArbol * AVL;


	int numero;
	string nombre;
	string contrasena;

	NodoMatriz(string dato1, int dato2, string dato3) {
		Siguiente = nullptr;
		Anterior = nullptr;
		Arriba = nullptr;
		Abajo = nullptr;
		Adelante = nullptr;
		Atras = nullptr;
		AVL = nullptr;

		nombre = dato1;
		numero = dato2;
		contrasena = dato3;
	}
};

