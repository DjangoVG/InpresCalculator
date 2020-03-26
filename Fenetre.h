#ifndef FENETRE_H
#define FENETRE_H

#include "Couleur.h"
#include "WindowSDL.h"


class Fenetre
{
	protected :
		int largeur, hauteur;
		Couleur couleurFond;
	
	public :
		Fenetre(const Fenetre &fenetre);
		~Fenetre();
		Fenetre();
		Fenetre(int largeur2, int hauteur2, Couleur couleur2);
		void setLargeurFenetre(int val);
		void setHauteurFenetre(int val);
		void setCouleurFenetre(const Couleur&c);
		int getLargeurFenetre() const;
		int getHauteurFenetre() const;
		Couleur getCouleurFenetre() const;
		void setVisible(bool v);
		virtual void Dessine();
		friend ostream& operator<<(ostream&s,const Fenetre& fenetre) ;
		
};

#endif
