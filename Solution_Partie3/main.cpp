#include "Article.h"
#include "Vehicule.h"
#include "Ordinateur.h"
#include "Magasin.h"
#include <iostream>

int main()
{
	//cr�ation d'un v�hicule :
	CVehicule veh1(100, 30, "trotinette", 2, 0);

	//affichage du v�hicule :
	//std::cout << veh1;

	//cr�ation d'un ordinateur:
	COrdinateur ordi1(1200, 1, "Ordinateur de Carole", COrdinateur::Utilisation::Gaming);

	//affichage de l'ordinateur :
	//std::cout << ordi1;

	//cr�ation d'un magasin :
	CMagasin magasin;

	//ajout d'un vehicule � la liste d'articles :
	magasin.AddArticle(std::make_shared<CVehicule>(veh1));

	//d�compte des articles diff�rents enregistr�s :
	magasin.AfficherNbrArticlesDiff�rents();
	magasin.AfficherNbrTotalStock();
	magasin.AfficherPatrimoine();

	//ajout d'un ordinateur � la liste d'articles :
	magasin.AddArticle(std::make_shared<COrdinateur>(ordi1));

	//nouveau d�compte :
	magasin.AfficherNbrArticlesDiff�rents();
	magasin.AfficherNbrTotalStock();
	magasin.AfficherPatrimoine();

	//Liquidation :
	magasin.Liquidation();

	//v�rification du patrimoine :
	magasin.AfficherPatrimoine();
}