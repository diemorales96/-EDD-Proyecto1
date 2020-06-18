#include "pch.h"
#include "Matriz.h"
#include "NodoMatriz.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "Arbol.h"
#include "Lista_Doble.h"

using namespace std;
Arbol *objetoArbol = new Arbol();
Lista_Doble *objetoLista = new Lista_Doble();
void Matriz::InsertarElmento(string usuario, int numero, string contrasena, string empresa, string departamento)
{
	NodoMatriz* NodoUsr;
	NodoMatriz* NodoEmp;
	NodoMatriz* NodoDepa;

	NodoUsr = new NodoMatriz(usuario, numero, contrasena);
	NodoDepa = BuscarDepa(departamento, cabecera);
	NodoEmp = BuscarEmpresa(empresa, cabecera);


	if (NodoDepa == nullptr)
	{
		NodoDepa = CrearDepartamento(departamento);
	}
	if (NodoEmp == nullptr)
	{
		NodoEmp = CrearEmpresa(empresa);
	}


	if (NodoDepa->Abajo == nullptr)
	{
		NodoDepa->Abajo = NodoUsr;
		NodoUsr->Arriba = NodoDepa;
	}


	else if (NodoEmp->Abajo == nullptr)
	{
		NodoMatriz* aux = NodoDepa->Abajo;
		while (aux->Abajo != nullptr)
		{
			aux = aux->Abajo;
		}

		if (!VerificarEmpresa(empresa, aux, NodoUsr))
		{
			aux->Abajo = NodoUsr;
			NodoUsr->Arriba = aux;
		}
	}


	else
	{
		NodoMatriz* aux = NodoDepa;

		do
		{
			aux = aux->Abajo;

			if (!VerificarEmpresa(empresa, aux, NodoUsr))
			{
				NodoMatriz* auxEmpr = aux->Anterior;
				while (auxEmpr->Anterior != nullptr)
				{
					auxEmpr = auxEmpr->Anterior;
				}
				while (auxEmpr->Arriba != nullptr)
				{
					if (auxEmpr->nombre == empresa)
					{
						NodoUsr->Abajo = aux;
						NodoUsr->Arriba = aux->Arriba;

						aux->Arriba->Abajo = NodoUsr;
						aux->Arriba = NodoUsr;
						break;
					}
					auxEmpr = auxEmpr->Arriba;
				}
			}
		} while ((aux->Abajo != nullptr) && (NodoUsr->Arriba == nullptr));

		if (NodoUsr->Arriba == nullptr && NodoUsr->Adelante == nullptr)
		{
			aux->Abajo = NodoUsr;
			NodoUsr->Arriba = aux;
		}
	}

	if (NodoUsr->Adelante != nullptr)
	{
		return;
	}


	if (NodoEmp->Siguiente == nullptr)
	{
		NodoEmp->Siguiente = NodoUsr;
		NodoUsr->Anterior = NodoEmp;
	}
	else if (NodoDepa->Siguiente == nullptr)
	{
		NodoMatriz* aux = NodoEmp->Siguiente;
		while (aux->Siguiente != nullptr)
		{
			aux = aux->Siguiente;
		}

		if (!VerificarDepartamento(departamento, aux, NodoUsr))
		{
			aux->Siguiente = NodoUsr;
			NodoUsr->Anterior = aux;
		}
	}
	else
	{
		NodoMatriz* aux = NodoEmp;
		do
		{
			aux = aux->Siguiente;
			if (!VerificarDepartamento(departamento, aux, NodoUsr))
			{
				NodoMatriz* auxDepa = aux->Arriba;
				while (auxDepa->Arriba != nullptr)
				{
					auxDepa = auxDepa->Arriba;
				}
				while (auxDepa->Anterior != nullptr)
				{
					if (auxDepa->nombre == departamento)
					{
						NodoUsr->Siguiente = aux;
						NodoUsr->Anterior = aux->Anterior;

						aux->Anterior->Siguiente = NodoUsr;
						aux->Anterior = NodoUsr;
						break;
					}
					auxDepa = auxDepa->Anterior;
				}
			}
		} while (aux->Siguiente != nullptr && NodoUsr->Anterior == nullptr);

		if (NodoUsr->Anterior == nullptr && NodoUsr->Adelante == nullptr)
		{
			aux->Siguiente = NodoUsr;
			NodoUsr->Anterior = aux;
		}
	}

}



NodoMatriz* Matriz::CrearEmpresa(string empresa)
{
	NodoMatriz* emp;
	emp = new NodoMatriz(empresa, -1, "");

	NodoMatriz* aux = cabecera;
	while (aux->Abajo != nullptr)
	{
		aux = aux->Abajo;
	}
	aux->Abajo = emp;
	emp->Arriba = aux;
	return emp;
}

NodoMatriz* Matriz::CrearDepartamento(string departamento)
{
	NodoMatriz* depa;
	depa = new NodoMatriz(departamento, -1, "");

	NodoMatriz* aux = cabecera;
	while (aux->Siguiente != nullptr)
	{
		aux = aux->Siguiente;
	}
	aux->Siguiente = depa;
	depa->Anterior = aux;
	return depa;
}



NodoMatriz* Matriz::BuscarDepa(string depa, NodoMatriz* inicio)
{
	NodoMatriz* aux = inicio;
	while (aux != nullptr)
	{
		if (aux->nombre == depa)
		{
			return aux;
		}
		aux = aux->Siguiente;
	}
	return nullptr;
}

NodoMatriz* Matriz::BuscarEmpresa(string empresa, NodoMatriz* inicio)
{
	NodoMatriz* aux = inicio;
	while (aux != nullptr)
	{
		if (aux->nombre == empresa)
		{
			return aux;
		}
		aux = aux->Abajo;
	}
	return nullptr;
}



bool Matriz::VerificarEmpresa(string empresa, NodoMatriz* inicio, NodoMatriz*Usr)
{
	NodoMatriz* auxEmp = inicio->Anterior;

	while (auxEmp->Anterior != nullptr)
	{
		auxEmp = auxEmp->Anterior;
	}

	if (auxEmp->nombre == empresa)
	{
		while (inicio->Atras != nullptr)
		{
			inicio = inicio->Atras;
		}
		inicio->Atras = Usr;
		Usr->Adelante = inicio;
		return true;
	}

	return false;
}

bool Matriz::VerificarDepartamento(string depa, NodoMatriz* inicio, NodoMatriz*Usr)
{
	NodoMatriz* auxDepa = inicio->Arriba;
	while (auxDepa->Arriba != nullptr)
	{
		auxDepa = auxDepa->Arriba;
	}

	if (auxDepa->nombre == depa)
	{
		while (inicio->Atras != nullptr)
		{
			inicio = inicio->Atras;
		}
		inicio->Atras = Usr;
		Usr->Adelante = inicio;
		return true;
	}
	return false;
}

void Matriz::graficar()
{
	FILE *file;
	file = fopen("MatrizDispersa.dot", "w+");
	fprintf(file, "digraph Matriz{ \n");
	fprintf(file, "node [shape=box]\ngraph[ranksep = \"0.5\", nodesep=\"0.6\"];\n");
	generarDot(file,cabecera);
	fclose(file);
	system("dot -Tpng MatrizDispersa.dot -o MatrizDispersa.png");
	system("start E:\\Materias\\EDD\\Proyectos\\[EDD]Proyecto1\\[EDD]Proyecto1\\MatrizDispersa.png");

}

void Matriz::generarDot(FILE *file,NodoMatriz *n)
{
	NodoMatriz* aux = n;
	string label;
	NodoMatriz* fila = cabecera->Abajo;
	const char* clabel = label.c_str();
	label = cabecera->nombre + "[ label = \"" + cabecera->nombre + "\", width = 1.5," +" style = filled, fillcolor = coral, group = 0 ];\n\n";
	clabel = label.c_str();
	fprintf(file, clabel);
	label = "";
	while (fila != NULL) {
		label += "Fila" + fila->nombre + " [label = \"" + fila->nombre + "\" width = 1.5";
		label += " style = filled, fillcolor = bisque1, group = 0 ];\n";
		fila = fila->Abajo;
	}

	label += "\n //Enlaces de Filas\n";
	fila = cabecera->Abajo;
	while (fila != NULL) {
		if (fila->Abajo != NULL) {
			label += "Fila" + fila->nombre + "->Fila" + fila->Abajo->nombre + " [dir = both];\n";
		}
		fila = fila->Abajo;
	}

	label += "\n //Columnas\n";
	label += "//Cada una con diferente group para alinear verticalmente con los nodos\n";
	NodoMatriz* col = cabecera->Siguiente;
	while (col != NULL) {
		label += "Column" + col->nombre + "[label = \"" + col->nombre + "\" width = 1.5";
		label += " style = filled, fillcolor = pink2, group = " + col->nombre + "];\n";
		col = col->Siguiente;
	}


	label+= "\n //Enlaces de Columnas\n";
	col = cabecera->Siguiente;
	while (col != NULL) {
		if (col->Siguiente != NULL) {
			label += "Column" + col->nombre + "->Column" + col->Siguiente->nombre + " [dir = both];\n";
		}
		col = col->Siguiente;
	}

	col = cabecera->Siguiente;
	label += "\n // Alinear Raiz con Columnas\n";
	label += "{rank = same; " + cabecera->nombre + ";";
	while (col != NULL) {
		label += " Column" + col->nombre + "; ";
		col = col->Siguiente;
	}
	label+= "};\n";
	label += "\n // Enlaces Raiz con primera fila y columna\n";
	label += cabecera->nombre + "->Column" + cabecera->Siguiente->nombre + ";\n";
	label += cabecera->nombre + "->Fila" + cabecera->Abajo->nombre + ";\n";


	label += "\n //Creacion de nodos\n";
	fila = cabecera->Abajo;
	NodoMatriz *filaaux = fila;
	string group = "";
	NodoMatriz *colaux;
	while (fila != NULL) {
		label += "//(^<---------------------- F I L A   " + fila->nombre + "---------------------->\n";
		col = fila->Siguiente;
		
		while (col != NULL) {
			colaux = col;
			while (colaux->Arriba != NULL) {
				colaux = colaux->Arriba;
			}
			group = colaux->nombre; 
			label += "N" + colaux->nombre + "_F" + fila->nombre + " [label = ";
			label += "\"" + col->nombre + "\" width = 1.5 group = " + group + " style = filled, fillcolor = lavenderblush1];\n";
			col = col->Siguiente;
			
		}
		fila = fila->Abajo;
		label += "\n";
	}

	//NO TOCAR DE ACA PARA ARRIBA FUNCIONA BIEN

	label += "\n //Creacion de enlaces de nodos\n";
	fila = cabecera->Abajo;
	filaaux = fila;
	while (fila != NULL) {
		label += "//E N L A C E S  F I L A   " + filaaux->nombre + "\n";
		col = fila->Siguiente;
		while (col != NULL) {

			if (fila->Arriba == cabecera) { 

				label += "Column" + col->Arriba->nombre + "->N" + col->Arriba->nombre + "_F" + filaaux->nombre;
				label += " [dir = both];\n";
			}
			else {


				if (col->Arriba->numero == -1) {
					colaux = col;
					while(colaux->Arriba != NULL) {
						colaux = colaux->Arriba;
					}
					label += "Column" + colaux ->nombre + "->N" + colaux->nombre + "_F" + filaaux->nombre;
					label += " [dir = both];\n";
				}
				else {
					colaux = col;
					while (colaux->Arriba != NULL) {
						colaux = colaux->Arriba;
					}
					label += "N" + colaux->nombre + "_F" + fila->nombre +
						"->N" + colaux->nombre + "_F" + fila->Arriba->nombre;
					label += " [dir = both];\n";
				}
			}
			if (col->Anterior == fila) {

				colaux = col;
				while (colaux->Arriba != NULL) {
					colaux = colaux->Arriba;
				}
				label += "Fila" + filaaux->nombre + "->N" + colaux->nombre + "_F" + filaaux->nombre;
				label += " [dir = both];\n";
			}

			colaux = col;
			NodoMatriz* colaux2;
			while (colaux->Arriba != NULL) {
				colaux = colaux->Arriba;
			}
			
			if (col->Siguiente != NULL) {

				colaux2 = col->Siguiente;
				while (colaux2->Arriba != NULL) {
					colaux2 = colaux2->Arriba;
				}
				label += "N" + colaux->nombre + "_F" + filaaux->nombre +
					"->N" + colaux2->nombre + "_F" + filaaux->nombre;
				label += " [dir = both];\n";
			}
			col = col->Siguiente;
		}
		label += "//Alineacion vertical de nodos con la fila\n";
		col = fila->Siguiente;
		label += "{rank = same; Fila" + filaaux->nombre + "; ";
		colaux = cabecera->Siguiente;
		while (col != NULL) {
			colaux = col;
			while (colaux->Arriba!=NULL)
			{
				colaux = colaux->Arriba;
			}
			label += "N" + colaux->nombre + "_F" + filaaux->nombre+ "; ";
			col = col->Siguiente;
			
		}
		label += " };\n\n";
		fila = fila->Abajo;
		filaaux = fila;
	}

	label += "}\n";

	clabel = label.c_str();
	fprintf(file, clabel);
}

NodoMatriz* Matriz::Buscarusuario(string nombre, string cont, string dep, string emp)
{
	NodoMatriz* fila = cabecera->Abajo;
	while (fila != NULL)
	{
		NodoMatriz* col = fila->Siguiente;
		while (col != NULL)
		{
			NodoMatriz* prof = col;
			NodoMatriz *colaux = col;

			while (colaux->Arriba != NULL)
			{
				colaux = colaux->Arriba;
			}

			if (col->Atras != NULL)
			{
				while (prof!=NULL)
				{
					if(comparar(prof->nombre) == comparar(nombre) && comparar(prof->contrasena) == comparar(cont) && comparar(colaux->nombre) == comparar(dep) && comparar(fila->nombre) == comparar(emp))
					{
						return prof;
					}
					else
					{
						prof = prof->Atras;
					}
				}
			}
			else
			{
				if (comparar(col->nombre) == comparar(nombre) && comparar(col->contrasena) == comparar(cont) && comparar(colaux->nombre) == comparar(dep) && comparar(fila->nombre) == comparar(emp))
				{
					return col;
				}
				else
				{
					col = col->Siguiente;
				}
			}

		}
		
		fila = fila->Abajo;
	}
	return NULL;
}


void Matriz::Buscarusuario(string usuario)
{
	NodoMatriz* fila = cabecera->Abajo;
	
	while (fila != NULL)
	{
		NodoMatriz* col = fila->Siguiente;
		while (col != NULL)
		{
			NodoMatriz* prof = col;
			NodoMatriz *colaux = col;

			while (colaux->Arriba != NULL)
			{
				colaux = colaux->Arriba;
			}

			if (col->Atras != NULL)
			{
				while (prof != NULL)
				{
					if (prof->AVL && prof->nombre !=usuario)
					{
						objetoArbol->preorden(prof->AVL);
						prof = prof->Atras;
					}
					else
					{
						prof = prof->Atras;
					}
				}
			}
			else
			{
				if (col->AVL && col->nombre != usuario)
				{
					objetoArbol->preorden(col->AVL);
					col = col->Siguiente;
				}
				else
				{
					col = col->Siguiente;
				}
			}

		}

		fila = fila->Abajo;
	}
	
}

NodoMatriz * Matriz::Renta(string ident)
{
	NodoMatriz* fila = cabecera->Abajo;

	while (fila != NULL)
	{
		NodoMatriz* col = fila->Siguiente;
		while (col != NULL)
		{
			NodoMatriz* prof = col;
			NodoMatriz *colaux = col;

			while (colaux->Arriba != NULL)
			{
				colaux = colaux->Arriba;
			}

			if (col->Atras != NULL)
			{
				while (prof != NULL)
				{
					if (prof->AVL!=NULL)
					{
						NodoArbol * aux = (objetoArbol->Buscar(prof->AVL, ident));
						NodoArbol * aux2 = objetoArbol->devolverAux();
						if ((aux2 !=NULL))
						{
							return prof;
							break;
						}
					}
					else
					{
						prof = prof->Atras;
					}
				}
			}
			else
			{
				if (col->AVL != NULL)
				{
					NodoArbol * aux = (objetoArbol->Buscar(prof->AVL, ident));
					NodoArbol * aux2 = objetoArbol->devolverAux();
					if ((aux2 != NULL))
					{
						return col;
						break;
					}
				}
				else
				{
					col = col->Siguiente;
				}
				col = col->Siguiente;
			}

		}

		fila = fila->Abajo;
	}
}
//Metodo para convertir de mayusculas a minusculas

string Matriz::comparar(string usuario)
{
	for_each(usuario.begin(), usuario.end(), [](char & c) {
		c = ::tolower(c);
	});

	return usuario;
}

//generar aleatoriamente strings

int Matriz::rangoaleatorio(int min, int max) {
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void Matriz::cadaleatoria(int Longitud, char *Destino) {
	char Muestra[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	for (int x = 0; x < Longitud; x++) {
		int indiceAleatorio = rangoaleatorio(0, (int)strlen(Muestra) - 1);
		Destino[x] = Muestra[indiceAleatorio];
	}
}