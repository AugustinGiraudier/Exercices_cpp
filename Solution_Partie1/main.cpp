#include "Article.h"
#include <iostream>

int main()
{
	//création d'un article :
	CArticle article1 (10, 100, "Tablette de chocolat");

	//achat unique (par défaut) :
	article1.Achat();
	
	//affichage :
	std::cout << article1 << std::endl;
	
	//achat groupé :
	article1.Achat(3);
	
	//affichage :
	std::cout << article1 <<std::endl;
}