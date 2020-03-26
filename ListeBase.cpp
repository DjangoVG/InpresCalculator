#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "ListeBase.h"
#include "PanneauImage.h"
#include "Fraction.h"
#include "BaseException.h"
#include "BoutonImage.h"
#include "Panneau.h"
using namespace std;

template<class T> 
ListeBase<T>::ListeBase()
{
	pTete = NULL ;
}
template<class T> 
ListeBase<T>::ListeBase(const ListeBase &l1) 
{
	struct Cellule<T> *Tmp1,*pNew,*Tmp2 ;

	if(l1.pTete == NULL)
	{
		return ;
	}
	Tmp1 = l1.pTete ;
	pTete = NULL ;
	
	while(Tmp1 != NULL)
	{
		pNew = new struct Cellule<T> ;
		pNew->valeur = Tmp1->valeur ;
		pNew->suivant = NULL ;
		
		if(pTete == NULL)
		{
			pTete = pNew ;	
			Tmp2 = pTete ;
		}
		else
		{
			Tmp2->suivant = pNew ;
			Tmp2 = Tmp2->suivant ;	
		}
		Tmp1 = Tmp1->suivant ;
	}
}
template<class T> 
ListeBase<T>::~ListeBase()
{
	struct Cellule<T> *pCur, *pPrec;
	pCur = pTete;
	while (pCur != NULL)
	{
		pPrec = pCur; 
		pCur = pCur->suivant;
		delete pPrec;
	}
}
template<class T> 
bool ListeBase<T>::estVide()
{
	if(pTete==NULL)
		return true ;
	else
		return false ;
}
template<class T> 
int ListeBase<T>::getNombreElements() const
{
	int i=0 ;
	struct Cellule<T> *pCur ;
	pCur = pTete ;
	while(pCur != NULL)
	{
		i++ ;
		pCur = pCur->suivant ;	
	}
	return i ;
}
template<class T> 
void ListeBase<T>::Affiche() const 
{
	struct Cellule<T> *pCur, *pPrec;
	pCur = pTete;
	while (pCur != NULL)
	{
		pPrec = pCur; 
		cout << pPrec->valeur << endl ;
		pCur = pCur->suivant ;
	}
}
template<class T> 
ListeBase<T>& ListeBase<T>::operator=(const ListeBase<T>& l1) 
{
	/*DESTRUCTEUR*/
	struct Cellule<T> *pCur, *pPrec;
	pCur = pTete;
	while (pCur != NULL)
	{
		pPrec = pCur; 
		pCur = pCur->suivant;
		delete pPrec;
	}
	
	/*CONSTRUCTEUR*/
	struct Cellule<T> *Tmp1,*pNew,*Tmp2,TmpDel ;
	if(l1.pTete == NULL)
	{
		exit(0) ;
	}
	Tmp1 = l1.pTete ;
	pTete = NULL ;
	
	while(Tmp1 != NULL)
	{
		pNew = new struct Cellule<T> ;
		pNew->valeur = Tmp1->valeur ;
		pNew->suivant = NULL ;
		
		if(pTete == NULL)
		{
			pTete = pNew ;	
			Tmp2 = pTete ;
		}
		else
		{
			Tmp2->suivant = pNew ;
			Tmp2 = Tmp2->suivant ;	
		}
		Tmp1 = Tmp1->suivant ;
	}
}
template<class T> 
T ListeBase<T>::operator[](const int &indice) const
{
	struct Cellule<T> *pCur ;
	int i = indice ;
	pCur = pTete ;

	while(i > 0)
	{
		if(pCur!=NULL)
		{
			pCur = pCur->suivant ;
			i-- ;
		}	
	}
	
	return pCur->valeur ;

}
template class ListeBase<int>;
template class ListeBase<PanneauImage>;
template class ListeBase<Fraction>;
template class ListeBase<Panneau>;
template class ListeBase<Bouton>;
template class ListeBase<BoutonImage>;



