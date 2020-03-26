#ifndef CALCULETTE_H
#define CALCULETTE_H

#include "Pile.h"
#include "Fraction.h"

class Calculette
{
	private :
		Pile<Fraction> pile;
		bool mode;
		char saisiecalculette[10];
		char chaine[30];
	
	public :
		Calculette(const Calculette &calculette);
		~Calculette();
		Calculette();
		void Affiche() ;
		void SaisirChiffre(unsigned int val);
		void ClearSaisie();
		void Enter();
		void Plus();
		void Moins();
		void Fois();
		void Divise();
		void PlusOuMoins();
		void Erase();
		bool ChangeMode();
		const char *getSaisie() const;
		char *getPile(int i);
		void Save(ofstream &fichier) const ;
		void Load(ifstream &fichier) ;
};

#endif
