#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "PanneauImage.h"
#include "Fraction.h"
#include "BoutonImage.h"
#include "Bouton.h"
#include "BaseException.h"
#include "Iterateur.h"
#include "WindowSDL.h"
using namespace std;

template <class T>
Iterateur<T>::Iterateur(ListeBase<T>& l1):lis(l1),pCur(l1.pTete) 
{
}
template <class T>
bool Iterateur<T>::end() const
{
	if(pCur == NULL)
		return true ;
	else
		return false ;
}
template <class T>
void Iterateur<T>::reset()
{
	pCur = lis.pTete ;
}
template <class T>
char Iterateur<T>::operator++()
{
	if(pCur != NULL)
		pCur = pCur->suivant ;
	else
	{
		return '0';
	}
}	
template <class T>
char Iterateur<T>::operator++(int)
{
	return operator++();
}
template <class T>
Iterateur<T>::operator T() const
{
	return pCur->valeur ;
}
template <class T>
T& Iterateur<T>::operator &() const
{
	return pCur->valeur;
}

template class Iterateur<int>;
template class Iterateur<PanneauImage>;
template class Iterateur<Panneau>;
template class Iterateur<BoutonImage>;
template class Iterateur<Fraction>;
