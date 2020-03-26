#ifndef Bouton_h
#define Bouton_h

#include "Panneau.h"
#include "Couleur.h"
#include "WindowSDL.h"
#include "Ecouteur.h"
class Bouton : public virtual Panneau
{
	protected :
		Ecouteur* ecouteur ;
	public :
		Bouton() ;
		Bouton(const char*cNom, int iX, int iY, int iLargeur, int iHauteur, const Couleur &c) ;
		Bouton(const char*cNom, int iX, int iY, int iLargeur, int iHauteur);
		Bouton(const Bouton &bouton);
		~Bouton();
		Bouton(const char*cNom, int iX, int iY);
		void setNom(const char*n) ;
		const char* getNom() const;
		static const char*type ;
		friend ostream& operator<<(ostream&s,const Bouton& c) ;
		friend istream& operator>>(istream&i,Bouton& c) ;
		Bouton& operator= (const Bouton& x);
		void clic(int x, int y) ;
		void Affiche() const ;
		const char* getType() const ;
		void setEcouteur(Ecouteur* ecouteurbouton) ;
		Ecouteur* getEcouteur() ;
};

#endif
