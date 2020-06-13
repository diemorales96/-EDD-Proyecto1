#include "pch.h"
#include "Matriz.h"
#include "NodoMatriz.h"
#include <iostream>
#include <string>
using namespace std;

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
	fprintf(file,"\n}");
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
		colaux = cabecera->Siguiente;
		while (col != NULL) {
			group = colaux->nombre; 
			label += "N" + colaux->nombre + "_F" + filaaux->nombre + " [label = ";
			label += "\"" + col->nombre + "\" width = 1.5 group = " + group + " style = filled, fillcolor = lavenderblush1];\n";
			col = col->Siguiente;
			colaux = colaux->Siguiente;
		}
		fila = fila->Abajo;
		filaaux = filaaux->Abajo;
		label += "\n";
	}

	//NO TOCAR DE ACA PARA ARRIBA FUNCIONA BIEN

	clabel = label.c_str();
	fprintf(file, clabel);
}
