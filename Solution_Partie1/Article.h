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

	//enlève au stock le nombre indiqué (1 par défaut) :
	void Achat(int Decrement = 1);
	
	//ajoute au stock le nombre indiqué :
	void Restock(int Increment);

	/*------------------Opérateurs------------------*/

	//sortie vers flux :
	friend std::ostream& operator <<(std::ostream& out, const CArticle& art);
};


