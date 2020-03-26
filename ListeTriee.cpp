#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "ListeTriee.h"
#include "PanneauImage.h"
#include "Fraction.h"
#include "BaseException.h"
using namespace std;

template<class T> 
ListeTriee<T>::ListeTriee():ListeBase<T>() 
{
}
 template<class T> 
ListeTriee<T>::~ListeTriee()
{
}
template<class T> 
void ListeTriee<T>::insere(const T &val)
{
	struct Cellule<T> *pNew,*pCur,*pPrec,*pTmp ;

	pNew = new struct Cellule<T>;
    	pNew->valeur = val ;
	pNew->suivant = NULL;

	if(ListeBase<T>::pTete==NULL)
	{
		ListeBase<T>::pTete=pNew ;
	}
	else
	{
		pPrec=NULL ;
		pTmp=ListeBase<T>::pTete ;
		while(pTmp!=NULL && pNew->valeur > pTmp->valeur)
		{
		 	pPrec=pTmp ;
		 	pTmp=pTmp->suivant ;
		}
		if(pPrec==NULL)
		{
		 	pNew->suivant=ListeBase<T>::pTete ;
		 	ListeBase<T>::pTete=pNew ;
		}
		else
		{
		 	pPrec->suivant=pNew ;
		 	pNew->suivant=pTmp ;
		}
	}
}

template class ListeTriee<int> ;
template class ListeTriee<Fraction> ;




