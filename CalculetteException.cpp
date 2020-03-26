#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "CalculetteException.h"
using namespace std;

CalculetteException::CalculetteException():BaseException()
{
}
CalculetteException::CalculetteException(const char *Mess):BaseException(Mess)
{
}
CalculetteException::~CalculetteException()
{
}
