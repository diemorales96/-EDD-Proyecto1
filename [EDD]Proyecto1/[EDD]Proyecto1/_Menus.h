#pragma once
#include <string>
using namespace std;
class _Menus
{
public:
	void MenuPrincipal();
	void MenuLogin();
	void Menuadmin();
	void MenuRegistro();
	string comparar(string);
	int rangoaleatorio(int min, int max);
	void cadaleatoria(int Longitud, char *Destino);
	void ReporteMDispersa();
	void MenuUsuario(string,string,string,string);
};

