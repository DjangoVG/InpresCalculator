#ifndef ListeBase_h
#define ListeBase_h

template<class T>
struct Cellule
{
		T valeur ;
		Cellule<T> *suivant ;
};


template <class T> class Iterateur;

template<class T> 
class ListeBase
{
	protected :
		Cellule<T> *pTete ;
	public :
		ListeBase() ;
		ListeBase(const ListeBase &listebase) ;
		~ListeBase() ;
		bool estVide() ;
		int getNombreElements() const ; 
		void Affiche() const ;
		virtual void insere(const T &val) = 0 ;
		ListeBase& operator=(const ListeBase& l) ;
		T operator[](const int &indice) const ;
		friend class Iterateur<T>;
		
};
#endif

