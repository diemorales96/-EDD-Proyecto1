#include "pch.h"
#include "Lista_Doble.h"
#include <iostream>
#include <string>

using namespace std;

void Lista_Doble::insertar(string id_transaccion, string id_activo,string activo,string des, string usuario, string departamento, string empresa, int dias,bool disp)
{
	Nodo_Lista* nuevo = new Nodo_Lista(id_transaccion,id_activo,activo,des,usuario,departamento,empresa ,dias,disp);

	if (tamaniolista == 0)
	{
		cabeza = nuevo;
		cabeza->Siguiente = nuevo;
		cabeza->Anterior = nuevo;
		tamaniolista += 1;
	}
	else
	{

		Nodo_Lista* ultimo = cabeza->Anterior;
		
		/*nuevo->Siguiente = cabeza;
		nuevo->Anterior = ultimo;
		ultimo->Siguiente = nuevo;
		cabeza->Anterior = nuevo;
		ultimo = nuevo;
		tamaniolista += 1;*/
		if (id_transaccion < cabeza->id_transaccion)
		{
			nuevo->Siguiente = cabeza;
			nuevo->Anterior = ultimo;
			ultimo->Siguiente = nuevo;
			cabeza->Anterior = nuevo;
		}
		else if (id_transaccion > ultimo->id_transaccion)
		{
			ultimo->Siguiente = nuevo;
			cabeza->Anterior = nuevo;
			nuevo->Siguiente = cabeza;
			nuevo->Anterior = ultimo;
		}
		else
		{
			Nodo_Lista *aux = cabeza;
			do
			{
				if (aux->id_transaccion < id_transaccion && aux->Siguiente->id_transaccion >id_transaccion) {
					aux->Siguiente->Anterior = nuevo;
					nuevo->Siguiente = aux->Siguiente;
					nuevo->Anterior = aux;
					aux->Siguiente = nuevo;
				}
			} while (aux != cabeza);
		}
	}
}

void Lista_Doble::Mostrar(string usuario) {
	if (cabeza != NULL)
	{
	Nodo_Lista* aux = cabeza;
		while (aux->Siguiente != cabeza) {
			if (aux->usuario == usuario && aux->disp == true)
			{
				cout << ">> ID = " << aux->id_activo << "; Nombre = " << aux->activo << "; Tiempo de Renta = " << aux->dias << " dias;\n";
			}
			aux = aux->Siguiente;
		}
		if (aux->usuario == usuario && aux->disp == true)
		{
			cout << ">> ID = " << aux->id_activo << "; Nombre = " << aux->activo << "; Tiempo de Renta = " << aux->dias << " dias;\n";
		}
	}
}

Nodo_Lista * Lista_Doble::Buscar(string id,string usuario) {
	if (cabeza != NULL)
	{
		Nodo_Lista* aux = cabeza;
		while (aux->Siguiente != cabeza) {
			if (id == aux->id_activo && usuario ==aux->usuario)
			{
				return aux;
			}
			aux = aux->Siguiente;
		}
		if (aux->id_activo == id && usuario == aux->usuario)
		{
			return aux;
		}
	}
}

int Lista_Doble::tamanio() {
	return tamaniolista;
}
void Lista_Doble::graficar() 
{
	FILE * file;
	file = fopen("ReporteTransacciones.dot","w+");
	fprintf(file,"digraph Transacciones{\n");
	fprintf(file, "node [shape=box]\ngraph[ranksep = \"0.5\", nodesep=\"0.6\"];\n");
	generarDot(file,cabeza);

	fprintf(file,"}");
	fclose(file);

	system("dot -Tpng ReporteTransacciones.dot -o ReporteTransacciones.png");
	system("start E:\\Materias\\EDD\\Proyectos\\[EDD]Proyecto1\\[EDD]Proyecto1\\ReporteTransacciones.png");
}

void Lista_Doble::generarDot(FILE* file,Nodo_Lista* n)
{
	Nodo_Lista * aux = n;
	if (aux == nullptr) return;
	do
	{
		string label = aux->id_transaccion + "[label=\"Id : "+aux->id_transaccion+"&#92;nUsuario que rento:"+ aux->usuario+"\"];\n";
		const char * clabel = label.c_str();
		fprintf(file,clabel);
		string enlaces = aux->id_transaccion + "->" + aux->Siguiente->id_transaccion+"\n";
		enlaces += aux->Siguiente->id_transaccion + "->" + aux->id_transaccion + "\n";
		const char* cenlaces = enlaces.c_str();
		
		fprintf(file,cenlaces);
		
		aux = aux->Siguiente;
	} while (aux!=cabeza);
}

void Lista_Doble::graficades()
{
	FILE * file;
	file = fopen("ReporteTransacciones.dot", "w+");
	fprintf(file, "digraph Transacciones{\n");
	fprintf(file, "node [shape=box]\ngraph[ranksep = \"0.5\", nodesep=\"0.6\"];\n");
	generardotdes(file, cabeza);

	fprintf(file, "}");
	fclose(file);

	system("dot -Tpng ReporteTransacciones.dot -o ReporteTransacciones.png");
	system("start E:\\Materias\\EDD\\Proyectos\\[EDD]Proyecto1\\[EDD]Proyecto1\\ReporteTransacciones.png");
}

void Lista_Doble::generardotdes(FILE* file, Nodo_Lista* n)
{
	Nodo_Lista * aux = n->Anterior;
	if (aux == nullptr) return;
	do
	{
		
		string label = aux->id_transaccion + "[labej=\"" + aux->id_transaccion + "&#92;n" + aux->usuario + "\"];\n";
		const char * clabel = label.c_str();
		fprintf(file, clabel);
	
		string enlaces = aux->id_transaccion + "->" + aux->Siguiente->id_transaccion + "\n";
		enlaces += aux->Siguiente->id_transaccion + "->" + aux->id_transaccion + "\n";
		const char* cenlaces = enlaces.c_str();

		fprintf(file, cenlaces);

		aux = aux->Siguiente;
	} while (aux != cabeza->Anterior);
}