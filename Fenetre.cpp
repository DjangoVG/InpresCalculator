#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <strstream>
#include "Fenetre.h"
using namespace std;
	
Fenetre::Fenetre(const Fenetre &fenetre)
{
	setLargeurFenetre(fenetre.getLargeurFenetre());
	setHauteurFenetre(fenetre.getHauteurFenetre());
	setCouleurFenetre(fenetre.getCouleurFenetre());
}
Fenetre::~Fenetre()
{
	cout << "Destructeur" << endl;
}
Fenetre::Fenetre()
{
	cout << "Constructeur par defaut" << endl;
	setLargeurFenetre(0);
	setHauteurFenetre(0);
	setCouleurFenetre(Couleur(0,0,0));
}
Fenetre::Fenetre(int largeur2, int hauteur2, Couleur couleur2)
{
	setLargeurFenetre(largeur2);
	setHauteurFenetre(hauteur2);
	setCouleurFenetre(couleur2);
}
void Fenetre::setLargeurFenetre(int val)
{
	if(val >=0)
		largeur = val ;
}
void Fenetre::setHauteurFenetre(int val)
{
	if(val >=0)
		hauteur = val ;
}
void Fenetre::setCouleurFenetre(const Couleur&c)
{
	couleurFond.setRouge(c.getRouge());
	couleurFond.setBleu(c.getBleu());
	couleurFond.setVert(c.getVert());
}
int Fenetre::getLargeurFenetre() const
{
	return largeur;
}
int Fenetre::getHauteurFenetre() const
{
	return hauteur;
}
Couleur Fenetre::getCouleurFenetre() const
{
	return couleurFond;
}
void Fenetre::setVisible(bool v)
{
	if(v == true)
	{
		WindowSDL::open(getLargeurFenetre(),getHauteurFenetre()) ;
	}
	else
	{
		WindowSDL::close() ;
	}
}
void Fenetre::Dessine()
{
	WindowSDL::setBackground(couleurFond.getRouge(),couleurFond.getVert(),couleurFond.getBleu());
}
ostream& operator<<(ostream& s,const Fenetre& fenetre)
{
	s << "Largeur = " << fenetre.largeur << endl ;
	s << "Hauteur = " << fenetre.hauteur << endl ;
	s << "Couleur( " << fenetre.couleurFond.getRouge() << "," << fenetre.couleurFond.getVert() << "," << fenetre.couleurFond.getBleu() << ")" << endl;

	return s;
}











