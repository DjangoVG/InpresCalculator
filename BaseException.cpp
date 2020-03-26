#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "BaseException.h"

using namespace std;

void BaseException::setMessageErreur(const char* n)
{
	if (strcmp(MessageErreur, "\0") != 0)
		strcpy(MessageErreur,"\0");
		
	strcpy(MessageErreur,n);
}
const char* BaseException::getMessageErreur() const 
{
	return MessageErreur ;
}
BaseException::BaseException()
{
	cout << "Passage Constructeur défaut BaseException" << endl ;
	strcpy(MessageErreur,"\0");
	setMessageErreur ("---");
}
BaseException::BaseException(const char* iMess)
{
	cout << "Passage Constructeur BaseException" << endl ;
	setMessageErreur(iMess) ;
}
BaseException::~BaseException()
{
}
