#ifndef Couleur_h
#define Couleur_h

#include <iostream>
using namespace std;

class Couleur
{
	private :
		int rouge,vert,bleu ;
		char *nom ;
	public :
		static const Couleur ARGENT ;
		static const Couleur BLEU ;
		static const Couleur GRIS ;
		Couleur& operator= (const Couleur& x);
		friend ostream& operator<<(ostream&s,const Couleur& c) ;
		friend istream& operator>>(istream&i,Couleur& c) ;
		Couleur();
		void Affiche() const ;
		~Couleur();
		Couleur(int iRouge, int iVert, int iBleu,const char*cNom);
		Couleur(int iRouge, int iVert, int iBleu);
		Couleur(int iCouleur);
		Couleur(const Couleur &couleur);
		void setRouge(int val);
		void setBleu(int val);
		void setVert(int val);
		void setNom(const char*n);
		void setGris(int val);
		int getRouge() const;
		int getBleu() const;
		int getVert() const;
		const char* getNom() const;
		void Save(ofstream &fichier) const ;
		void Load(ifstream &fichier) ;
};
#endif
