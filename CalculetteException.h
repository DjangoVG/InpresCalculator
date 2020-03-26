#include <iostream>
#include <string.h>
using namespace std;
#include "BaseException.h"
#ifndef CALCULETTEEXCEPTION_H
#define CALCULETTEEXCEPTION_H


class CalculetteException : public BaseException
{
	private : 

	public : 
		void Affiche() const;
		CalculetteException();
		CalculetteException(const char *Mess);
		~CalculetteException();
};

#endif
