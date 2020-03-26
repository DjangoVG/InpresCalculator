#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "Liste.h"
#include "PanneauImage.h"
#include "Fraction.h"
#include "Pile.h"
#include "BaseException.h"
using namespace std;
 
template<class T> 
Pile<T>::Pile():ListeBase<T>()
{
}
template<class T> 
Pile<T>::~Pile()
{
}
template<class T> 
void Pile<T>::insere(const T &val)
{
	struct Cellule<T> *pNew,*pCur ;

	pNew = new struct Cellule<T>;
  	
	pNew->valeur = val ;
	pNew->suivant=ListeBase<T>::pTete ;
	ListeBase<T>::pTete = pNew ;
}
template<class T> 
void Pile<T>::push(const T &val)
{
	insere(val) ;
}
template<class T>  
T Pile<T>::pop()
{
	struct Cellule<T> *pCur,*pTeteRenvoi,*pPrec ;

	pTeteRenvoi = ListeBase<T>::pTete ;
	pCur = ListeBase<T>::pTete ;
	ListeBase<T>::pTete = pCur->suivant ;
	
	return pTeteRenvoi->valeur ;
}
template<class T>  
T Pile<T>::top()
{
	struct Cellule<T> *pCur ;
	pCur = ListeBase<T>::pTete ;
	
	return pCur->valeur ;
}

template class Pile<int>;
template class Pile<PanneauImage>;
template class Pile<Fraction>;
