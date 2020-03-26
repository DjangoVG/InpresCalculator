#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "PanneauImage.h"
#include <fstream>
#include "BaseException.h"
using namespace std;
const char* PanneauImage::type("PANNEAU_IMAGE") ;

PanneauImage::PanneauImage():Panneau()
{
	cout << "Constructeur PanneauImage" << endl ;
	fichier = NULL;
	image = NULL;
	setFichier("--") ;
}
PanneauImage::PanneauImage(const char*cNom,int iX,int iY,const char*cFichier):Panneau(cNom,iX,iY,0,0)
{
	cout << "Constructeur PanneauImage" << endl ;
	fichier = NULL ;
	image = NULL;
	setFichier(cFichier) ;
	
}
PanneauImage::PanneauImage(int iX,int iY,const char*cFichier):Panneau(iX,iY,0,0)
{
	cout << "Constructeur PanneauImage" << endl ;
	fichier = NULL ;
	image = NULL;
	setFichier(cFichier) ;
}
PanneauImage::PanneauImage(const PanneauImage &panneauimage):Panneau(panneauimage)
{
	cout << "Constructeur copie PanneauImage" << endl ;
	fichier = NULL ;
	image = NULL;
	setFichier(panneauimage.getFichier()) ;
}
PanneauImage::~PanneauImage()
{
	if(fichier) delete fichier;
	delete fichier ;
}
void PanneauImage::Dessine()
{
	WindowSDL::drawImage(getFichier(),getX(),getY());
}
ostream& operator<<(ostream&s,const PanneauImage& c)
{	
	s << "Fichier = " << c.fichier << endl ;
	s << "X = " << c.x << endl ;
	s << "Y = " << c.y << endl ;
	s << "Nom = " << c.nom << endl ;
	return s;
}
void PanneauImage::setNom(const char*n)
{
	const char * pch1 ;
	pch1 = strchr(n,'P') ;
	
	if( pch1!=NULL && strlen(n) >2 )
	{
		if(nom) delete nom;
		nom = new char[strlen(n)+1] ;
		strcpy(nom,n) ;
	}
	else
		throw BaseException("Nom Invalide") ;
	
}
const char* PanneauImage::getNom() const
{
	return nom ;
}
istream& operator>>(istream&i,PanneauImage& c)
{
	char tmp[20] ;
	int tmp2 ;
	cout << "Fichier : " << endl;
	i >> tmp;
	c.setFichier(tmp) ;
	cout << "Nom : " << endl;
	i >> tmp;
	c.setNom(tmp) ;
	cout << "X : " << endl;
	i >> tmp2 ;
	c.setX(tmp2) ;
	cout << "Y : " << endl;
	i >> tmp2 ;
	c.setY(tmp2) ;
	return i;
}
PanneauImage& PanneauImage::operator= (const PanneauImage& x)
{
	Panneau::operator=(x) ;
	setFichier(x.getFichier()) ;
	return *this;
}
void PanneauImage::setFichier(const char*n)
{
	if(fichier) delete fichier;
	fichier = new char[strlen(n)+1] ;
	strcpy(fichier,n) ;
	if(image) delete image;
	try
	{
		image = new WindowSDLimage(fichier);
	}
	catch(WindowSDLexception e)
	{
		e.getMessage();
		image = NULL;
		return;
	}
	setLargeur(image->getWidth());
	setHauteur(image->getHeight());
}
const char* PanneauImage::getFichier() const
{
	return fichier ;
}
void PanneauImage::Affiche() const
{
	cout << endl << "Position : ( "<< x << ", " << y << " )" << endl ; 
	cout << endl << "Fichier = " << fichier << endl ;
}
const char* PanneauImage::getType() const
{
	return type ;
}

void PanneauImage::Save(ofstream & Fichier) const
{
	int n;

	n = strlen(nom)+1;
	Fichier.write((char *)&n, sizeof(int));
	Fichier.write((char *)nom, n*sizeof(char));
	n = strlen(fichier)+1;
	Fichier.write((char *)&n, sizeof(int));
	Fichier.write((char *)fichier, n*sizeof(char));
	n = getX();
	Fichier.write((char*)&n, sizeof(int));
	n = getY();
	Fichier.write((char*)&n, sizeof(int));
}
void PanneauImage::Load(ifstream &Fichier)
{
	int n;
	char tmp[80];

	Fichier.read((char*)&n, sizeof(int));
	Fichier.read((char*)tmp, n*sizeof(char));
	setNom(tmp);
	Fichier.read((char*)&n, sizeof(int));
	Fichier.read((char*)tmp, n*sizeof(char));
	setFichier(tmp);
	Fichier.read((char*)&n, sizeof(int));
	setX(n);
	Fichier.read((char*)&n, sizeof(int));
	setY(n);
}












