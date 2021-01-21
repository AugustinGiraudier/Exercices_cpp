#pragma once
#include "Article.h"

class CVehicule :
    public CArticle
{
private :
    int m_nRoues;
    int m_nCylindree;

public:
    /*------------------construct------------------*/
    CVehicule(float Prix, int Stock, std::string Nom, int NbrRoues, int Cylindree);

    /*------------------Getters------------------*/
    const int GetNbrRoues() const { return m_nRoues; }
    const int GetCylindree() const { return m_nCylindree; }

    /*------------------Setters------------------*/
    void SetNbrRoues(int NouveauNbrRoues) { m_nRoues = NouveauNbrRoues; }
    void SetCylindree(int NouvelleCylindree) { m_nCylindree = NouvelleCylindree; }

    /*------------------Autres Fonctions------------------*/

    //red�finition de la fonction afin de pr�ciser que cette classe n'est pas abstraite
    void Achat(int Decrement = 1) override;

    /*------------------Op�rateurs------------------*/

    //sortie vers flux :
    friend std::ostream& operator <<(std::ostream& out, const CVehicule& Veh);
};

