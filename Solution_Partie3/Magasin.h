#pragma once
#include <vector>
#include <memory>
#include "Article.h"

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

	//affiche le nombre de types d'articles pr�sent dans le magasin : 
	void AfficherNbrArticlesDiff�rents();

	//affiche le nombre total de Stocks tous articles confondus :
	void AfficherNbrTotalStock();

	//affiche le montant que repr�sentent tous les articles du magasin :
	void AfficherPatrimoine();

	//diminue de moiti� les prix de tous les articles et fait de la promotion dans la console :
	void Liquidation();
};

