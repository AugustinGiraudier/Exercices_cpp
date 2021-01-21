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

void CMagasin::AfficherNbrOrdinateurs()
{
	int NbrOrdi = 0;
	//pour chaque article :
	for (auto it : GetArticles())
	{
		std::shared_ptr<COrdinateur> pOrdi; //on crée un pointeur destiné à recevoir un COrdinateur
		//on effectue une conversion dynamique de pointeur de CArticle vers COrdinateur :
		pOrdi = std::dynamic_pointer_cast<COrdinateur>(it);
		if (pOrdi != nullptr) //si la conversion n'a pas échouée :
		{
			//on ajoute le nombre d'ordinateur en stock au compteur :
			NbrOrdi += pOrdi->GetStock();
		}
	}
	//on affiche le résultat à la fin de la boucle :
	std::cout << "Nombre d'ordinateurs en stock : " << NbrOrdi << std::endl << std::endl;
}

std::array<std::vector<std::shared_ptr<CArticle>>, 2> CMagasin::TriArticles()
{
	//déclaration du tableau static que l'on retournera :
	std::array<std::vector<std::shared_ptr<CArticle>>, 2> ArrayARetourner;

	//déclaration des deux tableaux d'articles contenants les ordinateurs et les vehicules :
	std::vector<std::shared_ptr<CArticle>> VecOrdi;
	std::vector< std::shared_ptr<CArticle>> VecVehi;

	//pour chaque article du magasin :
	for (auto it : GetArticles())
	{
		std::shared_ptr<COrdinateur> pOrdi; //on crée un pointeur destiné à recevoir un COrdinateur

		//on effectue une conversion dynamique de pointeur de CArticle vers COrdinateur :
		pOrdi = std::dynamic_pointer_cast<COrdinateur>(it);

		if (pOrdi != nullptr) //si la conversion a réussie :
		{
			//il s'agit d'un ordinateur !
			//on ajoute le pointeur de type CArticle au vector des ordinateurs :
			VecOrdi.push_back(it);
		}
		else //sinon :
		{
			//il s'agit donc d'un véhicule !
			//on l'ajoute au vector des véhicules :
			VecVehi.push_back(it);
		}
	}
	//on ajoute les deux vectors au tableau static : 
	ArrayARetourner[0] = VecOrdi;
	ArrayARetourner[1] = VecVehi;

	//on le retourne :
	return ArrayARetourner;
}

void CMagasin::AfficherTableauVehicules(std::vector<std::shared_ptr<CArticle>> vec)
{
	//séparateur pour la console :
	std::cout << "---------------------Vehicules---------------------\n\n";

	//pour chaque élément du tableau :
	for (auto it : vec)
	{
		//on le convertit en pointeur de CVéhicule afin d'avoir accès à toutes ses données membres :
		//(on fait une conversion statique car on est sûr d'être en présence de CVehicules grace à notre tri)
		std::shared_ptr<CVehicule> pVeh = std::static_pointer_cast<CVehicule>(it);
		//on l'affiche par la sortie standard
		//pVeh est un pointeur, on le précède d'une étoile pour afficher l'objet qu'il pointe :
		std::cout << *pVeh;
	}
}

void CMagasin::AfficherTableauOrdinateurs(std::vector<std::shared_ptr<CArticle>> vec)
{
	//séparateur pour la console :
	std::cout << "--------------------Ordinateurs--------------------\n\n";

	//pour chaque élément du tableau :
	for (auto it : vec)
	{
		//on le convertit en pointeur de COrdinateur afin d'avoir accès à toutes ses données membres :
		//(on fait une conversion statique car on est sûr d'être en présence de COrdinateurs grace à notre tri)
		std::shared_ptr<COrdinateur> pOrdi = std::static_pointer_cast<COrdinateur>(it);

		//on l'affiche par la sortie standard
		//pOrdi est un pointeur, on le précède d'une étoile pour afficher l'objet qu'il pointe :
		std::cout << *pOrdi;
	}
}
