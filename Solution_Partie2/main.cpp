#include "Article.h"
#include "Vehicule.h"
#include "Ordinateur.h"
#include <iostream>

int main()
{
	//création d'un véhicule :
	CVehicule veh1(100, 12, "trotinette", 2, 0);

	//affichage du véhicule :
	std::cout << veh1;

	//création d'un ordinateur:
	COrdinateur ordi1(1200, 1, "Ordinateur de Carole", COrdinateur::Utilisation::Gaming);

	//affichage de l'ordinateur :
	std::cout << ordi1;
}