#ifndef ListeTriee_h
#define ListeTriee_h
#include "ListeBase.h"

template<class T> 
class ListeTriee :public ListeBase<T>
{
	private :
	
	public : 
		ListeTriee() ;
		~ListeTriee();
		void insere(const T &val) ;
};

#endif
