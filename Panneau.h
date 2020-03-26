#ifndef Panneau_h
#define Panneau_h
#include "Couleur.h"
#include "WindowSDL.h"

class Panneau
{
	protected :
		int x,y ;
		int hauteur,largeur ;
		char*nom ;
		Couleur couleur;
	
	public :
		void setCouleur(const Couleur &c);
		void setCouleur(const Couleur& rouge,const Couleur& vert,const Couleur& bleu);
		Couleur getCouleur() const ;
		Panneau& operator= (const Panneau& x);
		friend ostream& operator<<(ostream&s,const Panneau& c) ;
		friend istream& operator>>(istream&i,Panneau& c) ;
		Panneau();
		Panneau(const char*cNom,int iX,int iY);
		static const char*type ;
		Panneau(const char*cNom,int iX,int iY,int iHauteur,int iLargeur);
		Panneau(int iX,int iY,int iHauteur,int iLargeur, Couleur c) ;
		Panneau(int iX,int iY,int iHauteur,int iLargeur) ;
		Panneau(const char*cNom,int iX,int iY,int iHauteur,int iLargeur, Couleur c);
		Panneau(const Panneau &panneau);
		~Panneau();
		void Affiche() const;
		void setX(int val);
		void setY(int val);
		void setHauteur(int val);
		void setLargeur(int val);
		virtual void setNom(const char*n);
		int getX() const;
		int getY() const;
		int getHauteur() const;
		int getLargeur() const;
		virtual void Dessine();
		const char* getNom() const;
		virtual const char* getType() const;
		
		void Save(ofstream &fichier) const ;
		void Load(ifstream &fichier) ;
};
#endif
