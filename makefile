CO=g++ -m64 -Wno-deprecated

Calculatrice:	Calculatrice.cpp Couleur.o Panneau.o Fraction.o PanneauImage.o Bouton.o BoutonImage.o BaseException.o FractionException.o ListeBase.o Liste.o Iterateur.o Pile.o ListeTriee.o Calculette.o CalculetteException.o Fenetre.o WindowSDL.o WindowSDLexception.o WindowSDLimage.o WindowSDLclick.o FenetreCalculette.o Controleur.o
	$(CO) Calculatrice.cpp Couleur.o Panneau.o Fraction.o PanneauImage.o Bouton.o BoutonImage.o BaseException.o FractionException.o ListeBase.o Liste.o Iterateur.o Pile.o ListeTriee.o Calculette.o CalculetteException.o Fenetre.o WindowSDL.o WindowSDLexception.o WindowSDLimage.o WindowSDLclick.o FenetreCalculette.o Controleur.o -o Calculatrice -lpthread -lSDL

Couleur.o:	Couleur.cpp Couleur.h
		$(CO) Couleur.cpp -c

Panneau.o:	Panneau.cpp Panneau.h Couleur.h
		$(CO) Panneau.cpp -c

Fraction.o :	Fraction.cpp Fraction.h
		$(CO) Fraction.cpp -c

PanneauImage.o :	PanneauImage.cpp PanneauImage.h 
		$(CO) PanneauImage.cpp -c	

Bouton.o :	Bouton.cpp Bouton.h 
		$(CO) Bouton.cpp -c

BoutonImage.o : BoutonImage.cpp BoutonImage.h 
		$(CO) BoutonImage.cpp -c

BaseException.o :	BaseException.cpp BaseException.h
		$(CO) BaseException.cpp -c

FractionException.o :	FractionException.cpp FractionException.h
		$(CO) FractionException.cpp -c 

ListeBase.o:	ListeBase.cpp	ListeBase.h
		$(CO)	ListeBase.cpp -c

Liste.o:	Liste.cpp	Liste.h
		$(CO)	Liste.cpp -c

Iterateur.o:	Iterateur.cpp	Iterateur.h
		$(CO)	Iterateur.cpp -c

Pile.o:	Pile.cpp	Pile.h
		$(CO)	Pile.cpp -c

ListeTriee.o:	ListeTriee.cpp	ListeTriee.h
		$(CO)	ListeTriee.cpp -c

Calculette.o:	Calculette.cpp Calculette.h
		$(CO)	Calculette.cpp -c

CalculetteException.o:	CalculetteException.cpp CalculetteException.h
		$(CO)	CalculetteException.cpp -c

FenetreCalculette.o:	FenetreCalculette.cpp FenetreCalculette.h
		$(CO)	FenetreCalculette.cpp -c

Fenetre.o:	Fenetre.cpp Fenetre.h
		$(CO)	Fenetre.cpp -c

WindowSDL.o:	WindowSDL.cpp WindowSDL.h
		echo Creation de WindowSDL.o ...
		$(CO) -c WindowSDL.cpp

WindowSDLexception.o:	WindowSDLexception.cpp WindowSDLexception.h
		echo Creation de WindowSDLexception.o ...
		$(CO) -c WindowSDLexception.cpp

WindowSDLclick.o:	WindowSDLclick.cpp WindowSDLclick.h
		echo Creation de WindowSDLclick.o ...
		$(CO) -c WindowSDLclick.cpp

WindowSDLimage.o:	WindowSDLimage.cpp WindowSDLimage.h
		echo Creation de WindowSDLimage.o ...
		$(CO) -c WindowSDLimage.cpp
		
Controleur.o:	Controleur.cpp Controleur.h
		echo Creation de Controleur.o ...
		$(CO) -c Controleur.cpp

clean:
	@rm -f $(OBJS) core

clobber:	clean
	@rm -f tags $(PROGRAMS)
