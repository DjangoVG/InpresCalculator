#include <iostream>
using namespace std;

class Fraction
{			
	public : 
		static const Fraction UN ;
		static const Fraction ZERO ;
		static unsigned int PGCD(unsigned int a, unsigned int b);
		void simplifie();
		friend ostream& operator<<(ostream&s,const Fraction& f) ;
		friend istream& operator>>(istream&i,Fraction& f) ;
		Fraction& operator= (const Fraction& x);
		friend Fraction operator+(const Fraction& a, const Fraction& b) ;
		friend Fraction operator+(const Fraction& a, int b) ;
		friend Fraction operator-(const Fraction& a, const Fraction& b) ;
		friend Fraction operator*(const Fraction& a, const Fraction& b) ;
		friend Fraction operator/(const Fraction& a, const Fraction& b) ;
		friend bool operator==(const Fraction& a, const Fraction& b) ;
		friend bool operator<(const Fraction& a, const Fraction& b) ;
		friend bool operator>(const Fraction& a, const Fraction& b) ;
		Fraction operator++();
		Fraction operator++(int);
		enum Signe { positif = +1, negatif = -1 } ;
		Fraction();
		Fraction(unsigned int n,unsigned int d, Signe s) ;
		Fraction(int n, int d);
		Fraction(int n);
		~Fraction();
		Fraction(const Fraction& fraction);
		void setNumerateur(unsigned int n);
		void setDenominateur(unsigned int d);
		void setSigne(const Signe& s);
		unsigned int getNumerateur() const;
		unsigned int getDenominateur() const;
		Signe getSigne() const;
		bool estPositif() const ; 
		bool estNegatif() const ;
		bool estNul() const ;
		void Save(ofstream &fichier) const ;
		void Load(ifstream &fichier) ;
	private : 
		unsigned int numerateur,denominateur;
		Signe signe;
};
