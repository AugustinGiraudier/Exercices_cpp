#include "Article.h"
#include "Vehicule.h"
#include "Ordinateur.h"
#include "Magasin.h"
#include <iostream>

int main()
{
	//création d'un véhicule :
	CVehicule veh1(100, 30, "trotinette", 2, 0);

	//affichage du véhicule :
	//std::cout << veh1;

	//création d'un ordinateur:
	COrdinateur ordi1(1200, 1, "Ordinateur de Carole", COrdinateur::Utilisation::Gaming);

	//affichage de l'ordinateur :
	//std::cout << ordi1;

	//création d'un magasin :
	CMagasin magasin;

	//ajout d'un vehicule à la liste d'articles :
	magasin.AddArticle(std::make_shared<CVehicule>(veh1));

	//décompte des articles différents enregistrés :
	magasin.AfficherNbrArticlesDifférents();
	magasin.AfficherNbrTotalStock();
	magasin.AfficherPatrimoine();

	//ajout d'un ordinateur à la liste d'articles :
	magasin.AddArticle(std::make_shared<COrdinateur>(ordi1));

	//nouveau décompte :
	magasin.AfficherNbrArticlesDifférents();
	magasin.AfficherNbrTotalStock();
	magasin.AfficherPatrimoine();

	//Liquidation :
	magasin.Liquidation();

	//vérification du patrimoine :
	magasin.AfficherPatrimoine();
}