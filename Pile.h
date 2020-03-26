#ifndef Pile_h
#define Pile_h
#include "ListeBase.h"
template<class T> 
class Pile :public ListeBase<T>
{
	private :
	
	public :
		Pile() ;
		~Pile();
		void insere(const T &val) ;
		void push(const T &val) ;
		T pop() ;
		T top() ;
};
#endif

