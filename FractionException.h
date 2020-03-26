#ifndef FractionException_h
#define FractionException_h
#include "BaseException.h"
class FractionException : public BaseException
{
	private :
		int code ;
	public :
		static const int  ERREUR_DENOMINATEUR_NUL ;
		static const int  ERREUR_DIVISION_PAR_ZERO ;
		FractionException() ;
		~FractionException() ;
		FractionException(int iC,const char*iMess) ;
		void setCode(int iC) ;
		int getCode() const ;
		void Affiche() const ;
};
#endif
