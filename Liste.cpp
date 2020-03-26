#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Liste.h"
#include "PanneauImage.h"
#include "BaseException.h"
#include "Bouton.h"
#include "Panneau.h"
#include "BoutonImage.h"
#include "Fraction.h"
using namespace std;

template<class T> 
Liste<T>::Liste():ListeBase<T>() 
{
}
 template<class T> 
Liste<T>::~Liste()
{
}
template<class T> 
void Liste<T>::insere(const T &val)
{
	struct Cellule<T> *pNew,*pCur ; 

	pNew = new struct Cellule<T> ;
	pNew->valeur = val ;
	
	pNew->suivant = NULL ;
	if(ListeBase<T>::pTete != NULL)
	{
		pCur = ListeBase<T>::pTete ;
		while(pCur->suivant !=NULL)
		{
			pCur = pCur->suivant ;
		}
		pCur->suivant = pNew ;
	}
	else
	{
		ListeBase<T>::pTete = pNew ;		
	}
}

template class Liste<int> ;
template class Liste<PanneauImage> ;
template class Liste<BoutonImage> ;
template class Liste<Panneau> ;
template class Liste<Fraction> ;




