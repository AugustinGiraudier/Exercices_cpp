#include "Vehicule.h"

CVehicule::CVehicule(float Prix, int Stock, std::string Nom, int NbrRoues, int Cylindree)
	:CArticle(Prix,Stock, Nom)	//passage au constructeur de la classe mère
	,m_nCylindree(Cylindree)
	,m_nRoues(NbrRoues)
{
}

void CVehicule::Achat(int Decrement)
{
	//on ne souhaite pas réellement modifier la fonction,
	//on renvoit donc le parametre à la fonction de la classe mere
	CArticle::Achat(Decrement);
}

std::ostream& operator<<(std::ostream& out, const CVehicule& Veh)
{
	//affichage d'un vehicule :
	out << "Nom de l'article : " << Veh.GetNom() << std::endl
		<< "Prix a l'unite : " << Veh.GetPrix() << " euro(s)" << std::endl
		<< "Stock actuel : " << Veh.GetStock() << " article(s)" << std::endl
		<< "Nombre de roue(s) : " << Veh.GetNbrRoues() << std::endl
		<< "Cylindree : " << Veh.GetCylindree() << std::endl << std::endl;
	return out;
}
