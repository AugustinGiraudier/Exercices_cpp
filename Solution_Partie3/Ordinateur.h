#pragma once
#include "Article.h"
class COrdinateur :
    public CArticle
{
public:
	//initialisation de l'enum�ration
	//la diff�rence entre enum et enum class est tres faible (donc "class" non obligatoire ici)
	enum class Utilisation
	{
		Gaming,
		Bureautique
	};

private:
	Utilisation m_Utilisation;

public:
	/*------------------construct------------------*/
	COrdinateur(float Prix, int Stock, std::string Nom, Utilisation Util);

	/*------------------Getters------------------*/
	const Utilisation GetUtilisation() const { return m_Utilisation; }

	/*------------------Setters------------------*/
	void SetUtilisation(Utilisation NouvelleUtilisation) { m_Utilisation = NouvelleUtilisation; }

	/*------------------Autres Fonctions------------------*/

	//red�finition de la fonction afin de pr�ciser que cette classe n'est pas abstraite
	void Achat(int Decrement = 1) override;

	/*------------------Op�rateurs------------------*/

	//sortie vers flux :
	friend std::ostream& operator <<(std::ostream& out, const COrdinateur& ordi);
};

