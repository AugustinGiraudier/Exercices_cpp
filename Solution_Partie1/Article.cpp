#include "Article.h"

CArticle::CArticle(float Prix, int Stock, std::string Nom)
	//utilisation de la liste d'appel plus optimisée que dans le constructeur
	:m_fPrix(Prix)
	,m_nStock(Stock)
	,m_strNom(Nom)
{
}

void CArticle::Achat(int Decrement)
{
	//vérification du stock actuel
	if (GetStock() <= 0)
	{
		std::cout << "le stock ne permet pas l'achat de l'article " << GetNom()<<std::endl;
		return;//sortie de la fonction
	}
	if (Decrement <= 0)
	{
		std::cout << "Un achat doit obligatoirement soustraire le stock. erreur sur  l'article : " << GetNom() << std::endl;
		return;//sortie de la fonction
	}
	//décrémentation du stock
	SetStock(GetStock() - Decrement);
}

void CArticle::Restock(int Increment)
{
	if (Increment <= 0)
	{
		std::cout << "Un restock doit obligatoirement augmenter le stock. erreur sur  l'article : " << GetNom() << std::endl;
		return;//sortie de la fonction
	}
	//Incrémentation du stock
	SetStock(GetStock() + Increment);
}

std::ostream& operator<<(std::ostream& out, const CArticle& art)
{
	//affichage d'un Article :
	out << "Nom de l'article : " << art.GetNom() << std::endl
		<< "Prix a l'unite : " << art.GetPrix() << " euro(s)" << std::endl
		<< "Stock actuel : " << art.GetStock() << " article(s)" << std::endl;
	return out;
}
