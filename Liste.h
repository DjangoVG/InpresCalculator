#ifndef Liste_h
#define Liste_h
#include "ListeBase.h"
template<class T> 
class Liste :public ListeBase<T>
{
	private :
	
	public :
		Liste() ;
		~Liste();
		void insere(const T &val) ;
};
#endif
