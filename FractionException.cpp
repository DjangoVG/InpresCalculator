#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "FractionException.h"
using namespace std;
const int FractionException::ERREUR_DENOMINATEUR_NUL(0) ;
const int FractionException::ERREUR_DIVISION_PAR_ZERO(1) ;

FractionException::FractionException():BaseException()
{
	setCode(2) ;
}
FractionException::FractionException(int iC,const char*iMess):BaseException(iMess)
{
	setCode(iC) ;
}
int FractionException::getCode() const
{
	return code ;
} 
void FractionException::setCode(int iC)
{
	code = iC ;
}
FractionException::~FractionException()
{
}
void FractionException::Affiche() const
{
	cout << "Code : " << code<< endl ;
	cout << "Message d'erreur : " << MessageErreur << endl ;
} 
