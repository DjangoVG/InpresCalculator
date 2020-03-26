#ifndef FenetreCalculette_h
#define FenetreCalculette_h

#include "Couleur.h"
#include "Fenetre.h"
#include "PanneauImage.h"
#include "BoutonImage.h"
#include "Liste.h"
#include "Iterateur.h"
#include "Bouton.h"
#include "WindowSDL.h"
#include "BaseException.h"
#include "Ecouteur.h"
#include "Calculette.h"


class FenetreCalculette : public Fenetre //hérite de fenetre
{
	private :
		Liste<Panneau> listePanneaux ;
		Liste<BoutonImage> listeBoutons ;
		Bouton boutonClearSaisie ;
		PanneauImage affichage[4][10] ;
		PanneauImage saisie[6];
		Calculette * calculette; //pointeur vers l'objet calculette
		Couleur CouleurPanneauHaut;
		Couleur CouleurPanneauMilieu;
		Couleur CouleurPanneauBas;
	public :
		FenetreCalculette();
		~FenetreCalculette();
		virtual void Dessine();
		void setVisible(bool v);
		void setCouleurPanneauHaut(const Couleur &couleurhaut);
		void setCouleurPanneauMilieu(const Couleur &couleurmid);
		void setCouleurPanneauBas(const Couleur &couleurbas);
		Couleur getCouleurPanneauHaut();
		Couleur getCouleurPanneauMilieu();
		Couleur getCouleurPanneauBas();
		void setEcouteur(Ecouteur *ecouteurfenetrecalculette) ;
		void setCalculette(Calculette *calculettefenetrecalculette);
		Calculette * getCalculette();
		void clic(int x, int y);
		void Save(ofstream &fichier) const ;
		void Load(ifstream &fichier) ;
		
};
#endif
