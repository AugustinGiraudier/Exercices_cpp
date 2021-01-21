#include "Ordinateur.h"

COrdinateur::COrdinateur(float Prix, int Stock, std::string Nom, Utilisation Util)
	:CArticle(Prix,Stock,Nom) //passage au constructeur de la classe mère
	,m_Utilisation(Util)
{
}

void COrdinateur::Achat(int Decrement)
{
	//on ne souhaite pas réellement modifier la fonction,
	//on renvoit donc le parametre à la fonction de la classe mere
	CArticle::Achat(Decrement);
}

std::ostream& operator<<(std::ostream& out, const COrdinateur& ordi)
{
	//on conserve le nom de l'utilisation dans une variable string
	std::string util;
	switch (ordi.GetUtilisation())
	{
	case COrdinateur::Utilisation::Bureautique:
		util = "Bureautique";
		break;
	case COrdinateur::Utilisation::Gaming:
		util = "Gaming";
		break;
	}
	//affichage d'un ordinateur :
	out << "Nom de l'article : " << ordi.GetNom() << std::endl
		<< "Prix a l'unite : " << ordi.GetPrix() << " euro(s)" << std::endl
		<< "Stock actuel : " << ordi.GetStock() << " article(s)" << std::endl
		<< "Type d'utilisation : " << util << std::endl << std::endl;
	return out;
}
