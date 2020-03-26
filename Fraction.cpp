#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <fstream>
#include "Fraction.h"
#include "FractionException.h"
using namespace std;

const Fraction Fraction::UN(1,1,positif);
const Fraction Fraction::ZERO(0,1,positif);
void Fraction::simplifie()
{
	unsigned int diviseur ;
	diviseur = Fraction::PGCD(numerateur,denominateur) ;
	if (diviseur != 0)
	{
		numerateur = numerateur/diviseur;
		denominateur = denominateur/diviseur;
	}
}
unsigned int Fraction::PGCD(unsigned int a, unsigned int b)
{
	unsigned int quotient,reste ;
	if(a != 0 && b!=0)
	{
		while(b > 0)
		{
			reste = a % b;
			a = b ;
			b = reste ;
		}
		return a ;
	}
}
Fraction& Fraction::operator= (const Fraction& x)
{
	setNumerateur(x.getNumerateur());
	setDenominateur(x.getDenominateur());
	setSigne(x.getSigne()) ;
	
	return *this;
}
Fraction operator+(const Fraction& a,const Fraction& b)
{
	int num,den,newnuma,newnumb ;
	newnuma = (a.getSigne() * a.getNumerateur()*b.getDenominateur()) ;
	newnumb = (b.getSigne() * b.getNumerateur()*a.getDenominateur());
	
	num = newnuma + newnumb ;
	den = a.getDenominateur() * b.getDenominateur();

	Fraction f(num, den) ;
	f.simplifie();
	
	return f;
	
}
Fraction operator+(const Fraction& a, int b)
{
	int num,den,newnuma,newnumb ;

	
	newnumb = a.getDenominateur()*b;

	num = (a.getSigne()*a.getNumerateur()) + newnumb ;
	den = a.getDenominateur();

	Fraction f(num, den) ;
	f.simplifie();
	
	return f;
}
Fraction operator-(const Fraction& a, const Fraction& b)
{
	int num,den,newnuma,newnumb ;
	newnuma = (a.getSigne() * a.getNumerateur()*b.getDenominateur()) ;
	newnumb = (b.getSigne() * b.getNumerateur()*a.getDenominateur());
	
	num = newnuma - newnumb ;
	den = a.getDenominateur() * b.getDenominateur();

	Fraction f(num, den) ;
	f.simplifie();
	
	return f;	
}
Fraction operator*(const Fraction& a, const Fraction& b)
{
	int num,den ;
	num = ( (a.getSigne()*a.getNumerateur()) * (b.getSigne()*b.getNumerateur()) ) ;
	
	
	den = a.getDenominateur() * b.getDenominateur();

	Fraction f(num, den) ;
	f.simplifie();
	
	return f;
}
Fraction operator/(const Fraction& a, const Fraction& b)
{
	int num,den,newnuma,newnumb,newdenb ;
	if(b.estNul())
		throw FractionException(1,"Division par 0 !") ;
	else
	{

		newnuma = a.getSigne()*a.getNumerateur();
		newnumb = b.getSigne() * b.getDenominateur() ;
		newdenb = b.getNumerateur();
		
		num = newnuma * newnumb ;
		den = a.getDenominateur() * newdenb ;
	
		Fraction f(num, den) ;
		f.simplifie();
	
		return f;
	}
}
bool operator==(const Fraction& a, const Fraction& b)
{
	if(a.getSigne() != b.getSigne())
		return false ;
	else
	{
		if(a.getNumerateur() * b.getDenominateur() != b.getNumerateur() * a.getDenominateur())
			return false;
		else
			return true;
	}
}

bool operator<(const Fraction& a, const Fraction& b) 
{
	float resa, resb ;
	resa = (a.getSigne() * (float)a.getNumerateur())/(float)a.getDenominateur() ;
	resb = (b.getSigne() * (float)b.getNumerateur())/(float)b.getDenominateur() ;
	if(resa < resb)
		return true ;
	else
		return false;
}
bool operator>(const Fraction& a, const Fraction& b)
{
	float resa, resb ;
	resa = (a.getSigne() * (float)a.getNumerateur())/(float)a.getDenominateur() ;
	resb = (b.getSigne() * (float)b.getNumerateur())/(float)b.getDenominateur() ;
	if(resa > resb)
		return true ;
	else
		return false;
}
Fraction Fraction::operator++()
{
	(*this) = (*this) + 1 ;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction temp(*this) ;
	(*this) = (*this) + 1 ;
	return temp;
}
ostream& operator<<(ostream&s,const Fraction& f)
{
	if (f.numerateur == 0)
	{
		s << "0" << endl;
	}
	else
	{
		if (f.denominateur == 1)
		{
			if (f.signe == Fraction::positif)
				s << f.numerateur << endl;
			else
				s << "-" << f.numerateur << endl;
		}
		else
		{
			if(f.signe == Fraction::positif)
				s << f.numerateur << "/" << f.denominateur << endl ;
			else
				s <<"-"<< f.numerateur << "/" << f.denominateur << endl ;
		}
	}
	return s;
}
istream& operator>>(istream&i,Fraction& f)
{
	int num,den ;
	i >> num >> den ;
	if(den==0)
		throw FractionException(0,"Denominateur Nul !") ;
	else	
		f=Fraction(num,den) ;
	return i;
}
Fraction::Fraction()
{
	//cout << "Passage dans le constructeur par défaut " << endl ;
	setNumerateur(1);
	setDenominateur(1);
	setSigne(positif);
	
}
Fraction::Fraction(unsigned int n,unsigned int d, Signe s)
{
	//cout << "Passage dans le constructeur par initialisation complet " << endl ;
	if(d==0)
		throw FractionException(0,"Denominateur Nul !") ;
	else
	{
		setNumerateur(n);
		setDenominateur(d);
		setSigne(s) ;
	}
}
Fraction::Fraction(int n, int d)
{
	//cout << "Passage dans le constructeur par initialisation partiel (n et d) " << endl ;
	if(d==0)
		throw FractionException(0,"Denominateur Nul !") ;
	else
	{
		setNumerateur(abs(n)) ;
		setDenominateur(abs(d)) ;
		if(n<0)
			setSigne(negatif) ;
		else
			setSigne(positif) ;
	}
}
Fraction::Fraction(int n)
{
	//cout << "Passage dans le constructeur par initialisation partiel (n) " << endl ;
	setNumerateur(abs(n)) ;
	setDenominateur(1) ;
	if(n<0)
		setSigne(negatif) ;
	else
		setSigne(positif) ;
}
Fraction::~Fraction()
{
	cout << "Destructeur" << endl;
}
Fraction::Fraction(const Fraction& f)
{
	//cout << "Passage dans le constructeur de copie" << endl ;
	setNumerateur(f.getNumerateur()) ;
	setDenominateur(f.getDenominateur());
	setSigne(f.getSigne()) ;
}
void Fraction::setNumerateur(unsigned int n)
{
	numerateur = n ;
}
void Fraction::setDenominateur(unsigned int d)
{
	if(d!=0)
		denominateur = d ;
	else
		throw FractionException(0,"Denominateur Nul !") ;
}
void Fraction::setSigne(const Signe& s)
{
	if(s == positif)
		signe = positif ;
	else
		signe = negatif ;
}
unsigned int Fraction::getNumerateur() const
{
	return numerateur;
}
unsigned int Fraction::getDenominateur() const
{
	return denominateur;
}
Fraction::Signe Fraction::getSigne() const
{
	return signe;
}
bool Fraction::estPositif() const 
{
	if(numerateur != 0 && signe==positif)
		return true;
	else
		return false;
}
bool Fraction::estNegatif() const 
{
	if(signe==negatif)
		return true;
	else
		return false;
}
bool Fraction::estNul() const
{
	if(numerateur==0)
		return true;
	else
		return false;
}

void Fraction::Save(ofstream &fichier) const 
{
	Signe s;
	unsigned int n;

	s = getSigne() ;
	fichier.write((char *)&s, sizeof(Signe)) ;
	
	n = getNumerateur() ;
	fichier.write((char*)&n, sizeof(unsigned int)) ;
	
	n = getDenominateur() ;
	fichier.write((char*)&n, sizeof(unsigned int)) ;
}
void Fraction::Load(ifstream &fichier)
{   
	Signe s;
	unsigned int n;

	fichier.read((char*)&s, sizeof(Signe));
	setSigne(s) ;

	fichier.read((char*)&n, sizeof(unsigned int));
	setNumerateur(n);
	
	fichier.read((char*)&n, sizeof(unsigned int));
	setDenominateur(n);
}
