#include "Article.h"
#include <iostream>

int main()
{
	//cr�ation d'un article :
	CArticle article1 (10, 100, "Tablette de chocolat");

	//achat unique (par d�faut) :
	article1.Achat();
	
	//affichage :
	std::cout << article1 << std::endl;
	
	//achat group� :
	article1.Achat(3);
	
	//affichage :
	std::cout << article1 <<std::endl;
}