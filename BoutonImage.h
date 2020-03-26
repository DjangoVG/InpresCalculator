#ifndef BoutonImage_h
#define BoutonImage_h

#include "Panneau.h"
#include "Bouton.h"
#include "PanneauImage.h"
#include "WindowSDL.h"
class BoutonImage :public virtual Bouton,public virtual PanneauImage
{
	private :

	public :
		BoutonImage() ;
		BoutonImage(const char*cNom, int iX, int iY,const char*cFichier) ;
		BoutonImage(const BoutonImage &bouton);
		~BoutonImage();
		static const char*type ;
		void setNom(const char*n) ;
		const char* getNom() const;
		friend ostream& operator<<(ostream&s,const BoutonImage& c) ;
		friend istream& operator>>(istream&i,BoutonImage& c) ;
		Bouton& operator= (const BoutonImage& x);
		void Affiche() const ;
		const char* getType() const ;
		
};

#endif
