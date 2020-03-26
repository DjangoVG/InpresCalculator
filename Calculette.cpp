#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <strstream>
#include "Liste.h"
#include "Pile.h"
#include "ListeBase.h"
#include "Calculette.h"
#include "CalculetteException.h"
using namespace std;

Calculette::Calculette()
{
	cout << "Constructeur par defaut de la petite calculette" << endl;
	strcpy(saisiecalculette, "");
	mode= true;
}
Calculette::~Calculette()
{
	cout << "Destructeur de calculette" << endl;
}
Calculette::Calculette(const Calculette &calculette)
{
	cout << "Constructeur de copie de calculette" << endl;
	pile = calculette.pile;
	strcpy(saisiecalculette,calculette.getSaisie());
	mode = calculette.mode;
}
void Calculette::Affiche()
{
	if (mode == false) //Si on veut afficher en décimale
	{

		int compteur = 0;
		int n;
		n = pile.getNombreElements();
		if (n > 0)
		{
			Fraction tmp;
			while (compteur < n)
			{
				tmp = pile[compteur];
				cout << endl <<  "Element " << compteur+1 << " : " 
				<< tmp.getSigne()*(float)tmp.getNumerateur()/tmp.getDenominateur() << endl << endl;
				compteur++;
			}		
		}
		
	}
	else //Si on veut afficher en fraction
		pile.Affiche(); 

	cout << "----- Zone de saisie -----" << endl;
	cout << saisiecalculette << endl;
}
void Calculette::SaisirChiffre(unsigned int val)
{
	if(strlen(saisiecalculette) <10 )
	{
		char buff[10];
		sprintf (buff, "%d", val);
		strcat(saisiecalculette, buff);
	}
}
void Calculette::ClearSaisie()
{
	strcpy(saisiecalculette, "");
}
void Calculette::Enter()
{
	cout << "ENTER" << endl;
	if (strlen(saisiecalculette) > 0)
	{
		pile.push(Fraction(atoi(saisiecalculette)));
	}
	ClearSaisie();
}
void Calculette::Plus()
{
	cout << "PLUS" << endl;
	if (pile.getNombreElements() >= 2)
	{
		Fraction a = pile.pop() ;
		Fraction b = pile.pop() ;
		Fraction res = a + b ;
		pile.push(res) ;	
	}
	else
		throw CalculetteException("Pas assez de membres present!") ;
}
void Calculette::Moins()
{
	cout << "MOINS" << endl;
	if (pile.getNombreElements() >= 2)
	{
		Fraction a = pile.pop() ;
		Fraction b = pile.pop() ;
		Fraction res = a - b ;
		pile.push(res) ;	
	}
	else
		throw CalculetteException("Pas assez de membres present!") ;
}
void Calculette::Fois()
{
	cout << "FOIS" << endl;
	if (pile.getNombreElements() >= 2)
	{
		Fraction a = pile.pop() ;
		Fraction b = pile.pop() ;
		Fraction res = a * b ;
		pile.push(res) ;	
	}
	else
		throw CalculetteException("Pas assez de membres present!") ;
}
void Calculette::Divise()
{
	cout << "DIVISE" << endl;
	if (pile.getNombreElements() >= 2)
	{
		Fraction b = pile.pop() ;
		Fraction a = pile.pop() ;
		if(b.estNul())
		{
			pile.push(a) ;
			pile.push(b) ;
			throw CalculetteException("Denominateur Nul !") ;
			
		}
		else
		{
			Fraction res = a / b ;
			pile.push(res) ;
		}
	}
	else
		throw CalculetteException("Pas assez de membres present!") ;

}
void Calculette::PlusOuMoins()
{
	cout << "PLUSOUMOINS" << endl;
	if (pile.getNombreElements() >= 1)
	{
		Fraction a = pile.pop();
		if(a.getSigne()==Fraction::negatif)
			a.setSigne(Fraction::positif) ;
		else
			a.setSigne(Fraction::negatif) ;
		pile.push(a) ;
		cout << "Fraction : " << a << endl;
	}
	else
		throw CalculetteException("Pas assez de membres present!") ;
}
void Calculette::Erase()
{
	cout << "ERASE" << endl;
	int n;
	n = pile.getNombreElements();
	while (n != 0)
	{
		pile.pop();
		n--;
	}
}	
bool Calculette::ChangeMode()
{
	cout << "CHANGEMODE" << endl;
	if(mode == true)
		mode = false ;
	else
		mode = true ;

	return mode;
}
const char * Calculette::getSaisie() const
{
	return saisiecalculette;
}
char * Calculette::getPile(int i)
{
	int num, den;
	float resultat;
	Fraction tmp;
	int n;
	n = pile.getNombreElements();
	if (pile.getNombreElements() > 0 && n > i)
	{
		tmp = pile[i];
		if (mode == false) //Si en décimale
		{
			num = tmp.getNumerateur();
			den = tmp.getDenominateur();
			if (tmp.getSigne() == Fraction::negatif)
				resultat = -1 *((float)num/(float)den);
			else
				resultat = (float)num/(float)den;
			sprintf(chaine, "%.8f", resultat);
		}
		else //Si en fraction
		{
			ostrstream flux;
			flux << tmp << ends;
			strcpy(chaine, flux.str());
		}
	}
	else
	{
		strcpy(chaine, "");
	}
	return chaine;	
}
void Calculette::Save(ofstream &fichier) const  //Sauvegarder les différentes piles, saisie, mode et nbr d'éléments
{
	bool mod ;
	int n, i ;
	
	if(!fichier)
	{
		cout << "Ouverture impossible du fichier" << endl ;
	}
	else
	{
		n = strlen(saisiecalculette) +1 ;
		fichier.write((char *)&n, sizeof(int)) ;
		fichier.write((char *)saisiecalculette, n*sizeof(char)) ;
		
		mod = mode ;
		fichier.write((char *)&mod, sizeof(bool)) ;
		
		n = pile.getNombreElements() ;
		fichier.write((char *)&n, sizeof(int)) ;
		
		for(i=0;i<n;i++)
		{
			pile[i].Save(fichier) ;
		}
	}
}
void Calculette::Load(ifstream &fichier)  //Charger les différenes piles, saisie, mode et nbr d'éléments
{   
	bool mod ;
	int n, i ;
	char tmp[80] ;
	Fraction tmp1 ;
	Liste<Fraction> l ;
	
	if(!fichier)
	{
		cout << "Ouverture impossible du fichier" << endl ;
	}
	else
	{
		fichier.read((char*)&n, sizeof(int)) ;
		fichier.read((char*)&tmp, n*sizeof(char)) ;
		strcpy(saisiecalculette, tmp) ;
		
		fichier.read((char*)&mod, sizeof(bool)) ;
		mode = mod ;
		
		fichier.read((char*)&n, sizeof(int)) ;
		
		for(i = 0 ; i < n ; i++)
		{
			tmp1.Load(fichier) ;
			l.insere(tmp1) ;
		}
		for(i = n -1 ; i>=0 ; i--) //Parcourir la liste à l'envers car sauvegarder d'une pile (cf. save )
		{
			tmp1 = l[i] ;
			pile.push(tmp1) ;
		}
	}	
}
