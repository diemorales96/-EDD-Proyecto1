#include "pch.h"
#include "Matriz.h"
#include "NodoMatriz.h"
#include <iostream>

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

