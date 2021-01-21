#pragma once
#include <string>
#include <iostream>

class CArticle
{
private:
	float m_fPrix;
	int m_nStock;
	std::string m_strNom;

public:

	/*------------------construct------------------*/
	CArticle(float Prix, int Stock, std::string Nom);

	/*------------------Getters------------------*/
	const float GetPrix() const { return m_fPrix; }
	const int GetStock() const { return m_nStock; }
	const std::string GetNom() const { return m_strNom; }

	/*------------------Setters------------------*/
	void SetPrix(float NouveauPrix) { m_fPrix = NouveauPrix; }
	void SetStock(int NouveauStock) { m_nStock = NouveauStock; }
	void SetNom(std::string NouveauNom) { m_strNom = NouveauNom; }

	/*------------------Autres Fonctions------------------*/

	//enl�ve au stock le nombre indiqu� (1 par d�faut) :
	virtual void Achat(int Decrement = 1)=0;

	//ajoute au stock le nombre indiqu� :
	void Restock(int Increment);

	/*------------------Op�rateurs------------------*/

	//sortie vers flux :
	friend std::ostream& operator <<(std::ostream& out, const CArticle& art);
};


