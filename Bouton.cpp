#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Bouton.h"
#include "BaseException.h"
using namespace std;
const char* Bouton::type("BOUTON") ;

Bouton::Bouton():Panneau()
{
	cout << "Constructeur Bouton" << endl ;
	ecouteur = NULL ;
}
Bouton::~Bouton()
{
	
}
Bouton::Bouton(const char*cNom, int iX, int iY, int iLargeur, int iHauteur, const Couleur &c):Panneau(iX,iY,iLargeur,iHauteur,c) 
{
	cout << "Constructeur Bouton" << endl ;
	nom = NULL ;
	setNom(cNom) ;
}
Bouton::Bouton(const char*cNom, int iX, int iY):Panneau(NULL,iX,iY) 
{
	cout << "Constructeur Bouton" << endl ;
	nom = NULL ;
	setNom(cNom) ;
}
Bouton::Bouton(const char*cNom, int iX, int iY, int iLargeur, int iHauteur):Panneau(cNom,iX,iY,iLargeur,iHauteur) 
{
	cout << "Constructeur Bouton" << endl ;
}
Bouton::Bouton(const Bouton &bouton):Panneau(bouton)
{
	cout << "Constructeur de copie Bouton" << endl ;
}
void Bouton::setNom(const char*n)
{
	const char * pch1 ;
	pch1 = strchr(n,'B') ;
	
	if( pch1!=NULL && strlen(n) >2 )
	{
		if(nom) delete nom;
		nom = new char[strlen(n)+1] ;
		strcpy(nom,n) ;
	}
	else
		throw BaseException("Nom Invalide") ;
	
}
const char* Bouton::getNom() const
{
	return nom ;
}
ostream& operator<<(ostream&s,const Bouton& c)
{
	s << "X = " << c.x << endl ;
	s << "Y = " << c.y << endl ;
	s << "Hauteur = " << c.hauteur << endl ;
	s << "Largeur = " << c.largeur << endl ;
	s << "Nom = " << c.nom << endl;
	s << "Couleur( " << c.couleur.getRouge() << "," << c.couleur.getVert() << "," << c.couleur.getBleu() << ")" << endl;
	return s;
}
Bouton& Bouton::operator= (const Bouton& x)
{
	Panneau::operator=(x) ;
}
istream& operator>>(istream&i,Bouton& c)
{
	char tmp[20] ;
	int tmp2 ;

	cout << "Nom : " << endl;
	i >> tmp;
	c.setNom(tmp) ;
	cout << "X : " << endl;
	i >> tmp2 ;
	c.setX(tmp2) ;
	cout << "Y : " << endl;
	i >> tmp2 ;
	c.setY(tmp2) ;
	cout << "Largeur : " << endl;
	i >> tmp2 ;
	c.setLargeur(tmp2) ;
	cout << "Hauteur : " << endl;
	i >> tmp2 ;
	c.setHauteur(tmp2) ;
	return i;
}
void Bouton::clic(int X, int Y)
{
	if (ecouteur== NULL)
	{
		cout << "pointeur nul" << endl;
	}
	if (X <= x + largeur && X >= x && Y >= y && Y <= y +hauteur)
		ecouteur->ActionBouton(nom) ;
}
void Bouton::Affiche() const
{
	cout << endl << "Position : ( "<< x << ", " << y << " )" << endl ; 
	cout << endl << "Largeur = " << largeur << endl ;
	cout << endl << "Hauteur = " << hauteur << endl ;
	cout << endl << "Couleur( " << couleur.getRouge() << "," << couleur.getVert() << "," << couleur.getBleu()  << ")";
}
const char* Bouton::getType() const
{
	/*Que mettre return type ;*/
	return type ;
}
void Bouton::setEcouteur(Ecouteur* ecouteurbouton) 
{
	ecouteur = ecouteurbouton ;
}
Ecouteur* Bouton::getEcouteur() 
{
	return ecouteur ;
}


