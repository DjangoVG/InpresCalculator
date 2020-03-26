#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "Ecouteur.h"
#include "Calculette.h"
#include "FenetreCalculette.h"
#include "WindowSDL.h"

class Controleur : public Ecouteur
{
	private :
		Calculette * calculette; //accès à un objet calculette
		FenetreCalculette * fenetre; //accès à un objet fenetre
	
	public :
		void ActionBouton(const char* nom);
		Controleur();
		Controleur(Calculette* calculettecontroleur, FenetreCalculette* fenetrecontroleur);
		~Controleur();
		void setFenetreControleur(FenetreCalculette *fenetrecalculette);
		void setCalculetteControleur(Calculette *calculette);
		FenetreCalculette* getFenetreControleur() const;
		Calculette* getCalculetteControleur() const;
		void ConfigCouleur();
		
};

#endif
