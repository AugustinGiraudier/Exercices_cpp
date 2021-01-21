#pragma once
#include <vector>
#include <memory>
#include <array>
#include "Article.h"
#include "Ordinateur.h"
#include "Vehicule.h"

class CMagasin
{
private :
	std::vector<std::shared_ptr<CArticle>> m_vecpArticles;

public:
	/*------------------Getters------------------*/
	const std::vector<std::shared_ptr<CArticle>> GetArticles() const { return m_vecpArticles; }

	/*------------------Setters------------------*/
	void AddArticle(std::shared_ptr<CArticle> pArticle);

	/*------------------Autres Fonctions------------------*/

	//affiche le nombre de types d'articles présent dans le magasin : 
	void AfficherNbrArticlesDifférents();

	//affiche le nombre total de Stocks tous articles confondus :
	void AfficherNbrTotalStock();

	//affiche le montant que représentent tous les articles du magasin :
	void AfficherPatrimoine();

	//diminue de moitié les prix de tous les articles et fait de la promotion dans la console :
	void Liquidation();

	//affiche le nombre d'ordinateurs en stock :
	void AfficherNbrOrdinateurs();

	//revoit un tableau avec :
	//tab[0] : le vector<CArticle> de tous les ordinateurs 
	//tab[1] : le vector<CArticle> de tous les véhicules 
	std::array<std::vector<std::shared_ptr<CArticle>>, 2> TriArticles();

	//fait l'affichage d'un tableau de vehicules :
	static void AfficherTableauVehicules(std::vector<std::shared_ptr<CArticle>> vec);

	//fait l'affichage d'un tableau d'ordinateurs :
	static void AfficherTableauOrdinateurs(std::vector<std::shared_ptr<CArticle>> vec);
};

