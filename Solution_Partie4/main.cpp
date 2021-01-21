#include "Article.h"
#include "Vehicule.h"
#include "Ordinateur.h"
#include "Magasin.h"
#include <iostream>

int main()
{
	//création de véhicules :
	CVehicule veh1(100, 30, "trotinette", 2, 0);
	CVehicule veh2(115320, 2, "bus", 2, 20000);
	CVehicule veh3(12300, 3, "308", 2, 12000);
	CVehicule veh4(14500, 1, "mazda2", 2, 13000);
	
	//création d'ordinateurs:
	COrdinateur ordi1(1200, 1, "Ordinateur d'Augustin", COrdinateur::Utilisation::Gaming);
	COrdinateur ordi2(800, 1, "Ordinateur de Michel", COrdinateur::Utilisation::Bureautique);
	COrdinateur ordi3(25, 3, "Ordinateur de GrandMere", COrdinateur::Utilisation::Bureautique);
	COrdinateur ordi4(45000, 1, "Ordinateur quantique", COrdinateur::Utilisation::Gaming);
	COrdinateur ordi5(12, 20, "Ordinateur jouet", COrdinateur::Utilisation::Bureautique);
	
	//création d'un magasin :
	CMagasin magasin;
	
	//ajout des vehicules à la liste d'articles :
	magasin.AddArticle(std::make_shared<CVehicule>(veh1));
	magasin.AddArticle(std::make_shared<CVehicule>(veh2));
	magasin.AddArticle(std::make_shared<CVehicule>(veh3));
	magasin.AddArticle(std::make_shared<CVehicule>(veh4));
	
	//ajout des ordinateurs à la liste d'articles :
	magasin.AddArticle(std::make_shared<COrdinateur>(ordi1));
	magasin.AddArticle(std::make_shared<COrdinateur>(ordi2));
	magasin.AddArticle(std::make_shared<COrdinateur>(ordi3));
	magasin.AddArticle(std::make_shared<COrdinateur>(ordi4));
	magasin.AddArticle(std::make_shared<COrdinateur>(ordi5));
	
	//affichage du nombre d'ordinateurs en stock :
	magasin.AfficherNbrOrdinateurs();
	
	//tri en 2 vectors :
	std::array<std::vector<std::shared_ptr<CArticle>>, 2> tab = magasin.TriArticles();
	
	//affichage des deux tableaux : (tab[0] -> vector des ordinateurs / tab[1] -> vector des véhicules)
	CMagasin::AfficherTableauOrdinateurs(tab[0]);
	CMagasin::AfficherTableauVehicules(tab[1]);
}