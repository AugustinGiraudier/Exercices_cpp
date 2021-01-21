#include "Magasin.h"

void CMagasin::AddArticle(std::shared_ptr<CArticle> pArticle)
{
	m_vecpArticles.push_back(pArticle);
}

void CMagasin::AfficherNbrArticlesDifférents()
{
	std::cout << "Nombre de types d'articles differents : " << GetArticles().size() << std::endl << std::endl;
}

void CMagasin::AfficherNbrTotalStock()
{
	int CompteTotalStock = 0;
	//on itere à travers tout le tableau d'articles.
	//ici, it est donc un pointeur vers un article (mais auto permet d'économiser du temps)
	for (auto it : GetArticles())
	{
		CompteTotalStock += it->GetStock();
		//on utilise le fleche car il s'agit d'un pointeur
		//RAPPEL : it->GetStock() est équivalent à : *(it).GetStock()
	}
	std::cout << "Nombre total des stocks : " << CompteTotalStock << std::endl << std::endl;
}

void CMagasin::AfficherPatrimoine()
{
	float CompteTotalArgent = 0;
	//on itere à travers tout le tableau d'articles.
	//ici, it est donc un pointeur vers un article (mais auto permet d'économiser du temps)
	for (auto it : GetArticles())
	{
		CompteTotalArgent += ((it->GetStock()) * (it->GetPrix()));
		//on utilise le fleche car il s'agit d'un pointeur
		//RAPPEL : it->GetStock() est équivalent à : *(it).GetStock()
	}
	std::cout << "Patrimoine : " << CompteTotalArgent << " euros" << std::endl << std::endl;
}

void CMagasin::Liquidation()
{
	//pour chaque type d'article :
	for (auto it : GetArticles())
	{
		//on fixe son prix à la moitié de son prix actuel
		it->SetPrix((it->GetPrix() / 2));
	}
	//et on effectue de la propagande dans la sortie standard :

	std::cout	<< "---------------------------------------------------------\n"
				<< "---------------------------------------------------------\n"
				<< "----------------------LIQUIDATION------------------------\n"
				<< "---------------------------------------------------------\n"
				<< "---------------------------------------------------------\n\n";
}
