#ifndef Iterateur_h
#define Iterateur_h
#include "ListeBase.h"
#include "WindowSDL.h"
template <class T>
class Iterateur
{
  private :
	ListeBase<T>& lis;
	Cellule<T> *pCur;
  public :
	Iterateur(ListeBase<T>& l) ;
	bool end() const;
	void reset();
	char operator++();
	char operator++(int) ;
	operator T() const;
	T& operator &() const;
};
#endif
