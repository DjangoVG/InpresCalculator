#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "Couleur.h"
using namespace std;

const Couleur Couleur::BLEU(0,0,255,"Bleu");
const Couleur Couleur::ARGENT(192,192,192,"Argent");
const Couleur Couleur::GRIS(128,128,128,"Gris");

Couleur& Couleur::operator=(const Couleur& x)
{
	setRouge(x.getRouge());
	setBleu(x.getBleu());
	setVert(x.getVert());
	setNom(x.getNom());

	return *this;
}
ostream& operator<<(ostream& s,const Couleur& c)
{
	s << "Rouge = " << c.rouge << endl ;
	s << "Vert = " << c.vert << endl ;
	s << "Bleu = " << c.bleu << endl ;
	s << "Nom = " << c.nom << endl ;

	return s;
}
istream& operator>>(istream& i,Couleur& c)
{
	cout << "Rouge = "; i >> c.rouge ; cout << endl ;
	cout << "Vert = " ; i >> c.vert ; cout << endl ;
	cout << "Bleu = " ; i >> c.bleu ; cout << endl ;
	cout << "Nom = "  ; i >> c.nom ; cout << endl ;
	return i;

}
Couleur::Couleur()
{
	//cout << endl << "Passage dans le constructeur" << endl ;
	nom = NULL;
	setRouge(0) ;
	setVert(0);
	setBleu(0);
	setNom("Noir");
}
void Couleur::Affiche() const
{
	cout << "Rouge = " << rouge << endl;
	cout << "Vert = " << vert << endl;
	cout << "Bleu = " << bleu << endl;
	cout << "Nom = " << nom << endl;
}
Couleur::~Couleur()
{
	//cout << endl << "Passage dans le destructeur" << endl ;
	if(nom)
		delete nom ;
}
Couleur::Couleur(int iRouge, int iVert, int iBleu,const char*cNom)
{
	//cout << endl << "Passage dans le constructeur d'initialisation" << endl ;
	nom = NULL ;
	setNom(cNom) ;
	if(iRouge >=0) setRouge(iRouge);
	if(iVert >=0) setVert(iVert) ;
	if(iBleu >=0) setBleu(iBleu) ;
	
}
Couleur::Couleur(int iRouge, int iVert, int iBleu)
{
	//cout << endl << "Passage dans le constructeur d'initialisation" << endl ;
	nom=NULL;
	setNom("NULL");
	if(iRouge >=0) setRouge(iRouge);
	if(iVert >=0) setVert(iVert) ;
	if(iBleu >=0) setBleu(iBleu) ;
	
}
Couleur::Couleur(int iCouleur)
{
	//cout << endl << "Passage dans le constructeur d'initialisation à 1 entree" << endl ;
	nom=NULL;
	if(iCouleur>=0 && iCouleur<=255) setGris(iCouleur) ;
}
Couleur::Couleur(const Couleur &couleur)
{
	//cout << endl << "Passage dans le constructeur de copie" << endl ;
	nom = NULL ;
	setNom(couleur.getNom()) ;
	setRouge(couleur.getRouge());
	setVert(couleur.getVert()) ;
	setBleu(couleur.getBleu()) ;

}
void Couleur::setRouge(int val)
{		
	if(val>=0 && val<=255)rouge=val;	
}
void Couleur::setBleu(int val)
{
	if(val>=0 && val<=255) bleu=val;
}
void Couleur::setVert(int val)
{
	if(val>=0 && val<=255) vert=val ;
}
void Couleur::setNom(const char*n)
{
	if(nom) delete nom;
	nom = new char[strlen(n)+1];
	strcpy(nom,n) ;
}
void Couleur::setGris(int val)
{
	setRouge(val);
	setBleu(val);
	setVert(val) ;
	setNom("Gris") ;	
}
int Couleur::getRouge() const
{
	return rouge;
}
int Couleur::getBleu() const
{
	return bleu;
}
int Couleur::getVert() const
{
	return vert ;
}
const char* Couleur::getNom() const
{
	 return nom ;
}
void Couleur::Save(ofstream &fichier) const 
{
	int n ;
	n = getRouge() ;
	fichier.write((char*)&n,sizeof(int)) ;
	n = getVert() ;
	fichier.write((char*)&n,sizeof(int)) ;
	n = getBleu() ;
	fichier.write((char*)&n,sizeof(int)) ;
	n =strlen(nom)+1 ;
	fichier.write((char*)&n,sizeof(int)) ;
	fichier.write((char*)nom,n*sizeof(char)) ;
}
void Couleur::Load(ifstream &fichier)
{   
	int n ;
	char tmp[80] ;
	
	fichier.read((char*)&n,sizeof(int)) ;
	setRouge(n) ;
	fichier.read((char*)&n,sizeof(int)) ;
	setVert(n) ;
	fichier.read((char*)&n,sizeof(int)) ;
	setBleu(n) ;
	fichier.read((char*)&n,sizeof(int)) ;
	fichier.read((char*)tmp,n*sizeof(int)) ;
	setNom(tmp) ;
}
