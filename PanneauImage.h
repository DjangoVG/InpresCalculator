#ifndef PanneauImage_h
#define PanneauImage_h

#include "Panneau.h"
#include "WindowSDL.h"
class PanneauImage : public virtual Panneau
{
	protected :
		char *fichier ;
		WindowSDLimage * image;
	
	public :
		void setFichier(const char*n);
		const char* getFichier() const;
		void Affiche() const;
		PanneauImage();
		static const char*type ;
		PanneauImage(const char*cNom,int iX,int iY,const char*cFichier) ;
		PanneauImage(int iX,int iY,const char*cFichier) ;
		PanneauImage(const PanneauImage &panneauimage) ;
		~PanneauImage() ;
		void setNom(const char*n) ;
		virtual void Dessine();
		const char* getNom() const;
		friend ostream& operator<<(ostream&s,const PanneauImage& c) ;
		friend istream& operator>>(istream&i,PanneauImage& c) ;
		PanneauImage& operator= (const PanneauImage& x);
		const char* getType() const ;
		void Save(ofstream & Fichier) const;
		void Load(ifstream & Fichier);
};
#endif
