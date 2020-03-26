#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "BoutonImage.h"
#include "BaseException.h"
using namespace std;
const char* BoutonImage::type("BOUTON_IMAGE") ;

BoutonImage::BoutonImage():Panneau(),Bouton(),PanneauImage()
{
	cout << "Constructeur BoutonImage" << endl ;
}

BoutonImage::~BoutonImage()
{
	cout << "Constructeur BoutonImage" << endl ;
}
BoutonImage::BoutonImage(const char*cNom, int iX, int iY,const char*cFichier):Panneau("P01",iX,iY),PanneauImage("P01",iX,iY,cFichier),Bouton(cNom,iX,iY)
{
	cout << "Constructeur BoutonImage" << endl ;
	setX(iX);
	setY(iY);
}
BoutonImage::BoutonImage(const BoutonImage &boutonimage):PanneauImage(boutonimage)
{
	cout << "Constructeur copie BoutonImage" << endl ;
	setX(boutonimage.getX());
	setY(boutonimage.getY());

}
void BoutonImage::setNom(const char*n)
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
const char* BoutonImage::getNom() const
{
	return nom ;
}
ostream& operator<<(ostream&s,const BoutonImage& c) 
{
	s << "X = " << c.x << endl ;
	s << "Y = " << c.y << endl ;
	s << "Hauteur = " << c.hauteur << endl ;
	s << "Largeur = " << c.largeur << endl ;
	s << "Nom = " << c.nom << endl;
	s << "Fichier = " << c.fichier << endl ;
	return s;
}
istream& operator>>(istream&i,BoutonImage& c) 
{
	char tmp[20] ;
	int tmp2 ;

	cout << "Nom : " << endl;
	i >> tmp;
	c.setNom(tmp) ;
	cout << "Fichier : " << endl;
	i >> tmp;
	c.setFichier(tmp) ;
	cout << "X : " << endl;
	i >> tmp2 ;
	c.setX(tmp2) ;
	cout << "Y : " << endl;
	i >> tmp2 ;
	c.setY(tmp2) ;
	return i;
}
Bouton& BoutonImage::operator= (const BoutonImage& x)
{
	PanneauImage::operator=(x) ;
}

void BoutonImage::Affiche() const
{
	cout << endl << endl << "Bouton_Image : " << nom ;
	cout << "Position( " <<x<< "," << y << ")" ;
	cout << "Fichier : " << fichier ; 
}
const char* BoutonImage::getType() const
{
	return type ;
}

