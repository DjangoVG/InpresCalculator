#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "Panneau.h"
#include "BaseException.h"
using namespace std;
const char* Panneau::type("PANNEAU") ;
	
int x,y ;
int hauteur,largeur ;
char*nom ;
Panneau::Panneau()
{
	cout << "Passage Constructeur défaut Panneau" << endl ;
	nom=NULL ;
	setNom("P--") ;
	setX(0);
	setY(0) ;
	setHauteur(0);
	setLargeur(0) ;
}
void Panneau::Dessine()
{
	WindowSDL::fillRectangle(couleur.getRouge(),couleur.getVert(),couleur.getBleu(),getX(),getY(),getHauteur(),getLargeur());
}
Panneau::Panneau(const char*cNom,int iX,int iY,int iHauteur,int iLargeur)
{
	cout << "Passage Constructeur Panneau" << endl ;
	nom = NULL ;
	setNom(cNom) ;
	if(iX>=0) setX(iX) ; /*Et pareille pour les autres pour mettre que des appels au fonctions*/
	if(iY>=0) setY(iY) ;
	if(iHauteur>=0) setHauteur(iHauteur) ;
	if(iLargeur>=0) setLargeur(iLargeur);
}
Panneau::Panneau(int iX,int iY,int iHauteur,int iLargeur)
{
	cout << "Passage Constructeur Panneau" << endl ;

	if(iX>=0) setX(iX) ; /*Et pareille pour les autres pour mettre que des appels au fonctions*/
	if(iY>=0) setY(iY) ;
	if(iHauteur>=0) setHauteur(iHauteur) ;
	if(iLargeur>=0) setLargeur(iLargeur);
}
Panneau::Panneau(int iX,int iY,int iHauteur,int iLargeur, Couleur c)
{
	cout << "Passage Constructeur Panneau" << endl ;
	if(iX>=0) setX(iX) ; /*Et pareille pour les autres pour mettre que des appels au fonctions*/
	if(iY>=0) setY(iY) ;
	if(iHauteur>=0) setHauteur(iHauteur) ;
	if(iLargeur>=0) setLargeur(iLargeur);
	setCouleur(c);
}
Panneau::Panneau(const char*cNom,int iX,int iY,int iHauteur,int iLargeur, Couleur c)
{
	cout << "Passage Constructeur Panneau" << endl ;
	nom = NULL ;
	setNom(cNom) ;
	if(iX>=0) setX(iX) ; 
	if(iY>=0) setY(iY) ;
	if(iHauteur>=0) setHauteur(iHauteur) ;
	if(iLargeur>=0) setLargeur(iLargeur);
	setCouleur(c);
}
Panneau::Panneau(const char*cNom,int iX,int iY)
{
	cout << "Passage Constructeur Panneau" << endl ;
	nom = NULL ;
	setNom(cNom) ;
	if(iX>=0) setX(iX) ; 
	if(iY>=0) setY(iY) ;
	setLargeur(100);
	setHauteur(100);
	setCouleur(Couleur::GRIS);
}
Panneau::Panneau(const Panneau &panneau)
{
	cout << "Passage Constructeur copie Panneau" << endl ;
	nom = NULL ;
	setNom(panneau.getNom()) ;
	setX(panneau.getX()) ; 
	setY(panneau.getY()) ;
	setHauteur(panneau.getHauteur()) ;
	setLargeur(panneau.getLargeur());
	setCouleur(panneau.getCouleur());
}
Panneau::~Panneau()
{

	if(nom) delete nom;
	delete nom ;
}
Panneau& Panneau::operator=(const Panneau& x)
{
	setNom(x.getNom()) ;
	setX(x.getX());
	setY(x.getY()) ;
	setHauteur(x.getHauteur());
	setLargeur(x.getLargeur()) ;	
	setCouleur(x.getCouleur()) ;

	return *this;
}
ostream& operator<<(ostream& s,const Panneau& c)
{
	s << "X = " << c.x << endl ;
	s << "Y = " << c.y << endl ;
	s << "Hauteur = " << c.hauteur << endl ;
	s << "Largeur = " << c.largeur << endl ;
	s << "Nom = " << c.nom << endl;
	s << "Couleur( " << c.couleur.getRouge() << "," << c.couleur.getVert() << "," << c.couleur.getBleu() << ")" << endl;
	return s;
	return s;
}
istream& operator>>(istream& i,Panneau& c)
{
	i >> c.x >> c.y >> c.hauteur >> c.largeur >> c.hauteur >> c.nom;
	return i;

}
void Panneau::setCouleur(const Couleur&c)
{
	couleur.setRouge(c.getRouge());
	couleur.setBleu(c.getBleu());
	couleur.setVert(c.getVert());
	couleur.setNom(c.getNom());
}
void Panneau::setCouleur(const Couleur& rouge,const Couleur& vert,const Couleur& bleu)
{
	couleur.setRouge(rouge.getRouge());
	couleur.setBleu(vert.getBleu());
	couleur.setVert(bleu.getVert());
}

Couleur Panneau::getCouleur() const
{
	return couleur;
}
void Panneau::Affiche() const
{
	cout << endl << "X= " <<x<< endl ;
	cout << endl << "Y= " <<y<< endl ;
	cout << endl << "Largeur= " <<largeur<< endl ;
	cout << endl << "Hauteur= " <<hauteur<< endl ;
	cout << endl << "Nom= " <<nom<< endl ;
	cout << endl << "Couleur( " << couleur.getRouge() << "," << couleur.getVert() << "," << couleur.getBleu()  << "," << couleur.getNom() << ")" << endl;
}

void Panneau::setX(int val)
{
	if(val >=0)
		x = val ;
}
void Panneau::setY(int val)
{
	if(val >=0)
		y = val ;
}
void Panneau::setHauteur(int val)
{
	if(val >=0)
		hauteur = val ;
}
void Panneau::setLargeur(int val)
{
	if(val >=0)
		largeur = val ;
}
void Panneau::setNom(const char*n)
{
	const char * pch1,*pch2 ;
	pch1 = strchr(n,'P') ;
	if(n!=NULL)
	{
		if( pch1!=NULL && strlen(n) >2 )
		{
			if(nom) delete nom;
			nom = new char[strlen(n)+1] ;
			strcpy(nom,n) ;
		}
		else
			throw BaseException("Nom Invalide") ;
	}
	
}
int Panneau::getX() const
{
	return x ;
}
int Panneau::getY() const
{
	return y ;
}
int Panneau::getHauteur() const
{
	return hauteur ;
}
int Panneau::getLargeur() const
{
	return largeur ;
}
const char* Panneau::getNom() const
{
	return nom ;
}
const char* Panneau::getType() const
{
	return type ;
}
void Panneau::Save(ofstream &fichier) const 
{
	int n;

	n = strlen(nom)+1;
	fichier.write((char *)&n, sizeof(int));
	fichier.write((char *)nom, n*sizeof(char));

	n = getX();
	fichier.write((char*)&n, sizeof(int));
	n = getY();
	fichier.write((char*)&n, sizeof(int));

	n = getLargeur();
	fichier.write((char*)&n, sizeof(int));
	n = getHauteur();
	fichier.write((char*)&n, sizeof(int));
}
void Panneau::Load(ifstream &fichier)
{   
	int n;
	char tmp[80];

	fichier.read((char*)&n, sizeof(int));
	fichier.read((char*)tmp, n*sizeof(char));
	setNom(tmp);

	fichier.read((char*)&n, sizeof(int));
	setX(n);
	fichier.read((char*)&n, sizeof(int));
	setY(n);

	fichier.read((char*)&n, sizeof(int));
	setLargeur(n);
	fichier.read((char*)&n, sizeof(int));
	setHauteur(n);
}
