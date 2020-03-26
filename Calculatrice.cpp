#include <iostream>
#include <unistd.h>
#include <fstream>
using namespace std;

#include "Controleur.h"
#include "WindowSDL.h"
#include "FenetreCalculette.h"
#include "Calculette.h"
#include "Bouton.h"


int main()
{
	bool temporaire = true;
	Calculette calculette ;
	FenetreCalculette fenetre ;
	Controleur controleur(&calculette,&fenetre) ;
	fenetre.setEcouteur(&controleur); // qui relie chaque bouton au contrôleur
	fenetre.setCalculette(&calculette) ; // qui relie la fenêtre à la calculette
	
	ifstream fp1("Config.dat", ios::in) ;
	if(fp1)
	{
		calculette.Load(fp1) ; //charger les différentes piles/listes
		fenetre.Load(fp1) ; //charger les couleurs des panneaux
	}
	fp1.close() ;
	
	fenetre.setVisible(true);
	while(temporaire == true) // on appelle cette boucle la boucle des « événements »
	{
		fenetre.Dessine();
		WindowSDLclick clic = WindowSDL::waitClick() ;
		fenetre.clic(clic.getX(),clic.getY());
		
		if (clic.getX() == -1)
		{
			ofstream fp2("Config.dat", ios::out);
			calculette.Save(fp2) ; //sauvegarder les différenes piles/listes
			fenetre.Save(fp2) ; //sauvegarder les couleurs des panneaux
			fp2.close() ;
			fenetre.setVisible(false);
			temporaire = false;
		}
	}
}
