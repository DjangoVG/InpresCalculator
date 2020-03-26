#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include "Controleur.h"
#include "CalculetteException.h"
using namespace std;

Controleur::Controleur()
{
	cout << "Constructeur par defaut de controleur" << endl;
	fenetre = NULL;
	calculette = NULL;
}
Controleur::Controleur(Calculette *calculettecontroleur, FenetreCalculette *fenetrecontroleur)
{
	cout << "Constructeur d'initialisation' de controleur" << endl;
	setCalculetteControleur(calculettecontroleur);
	setFenetreControleur(fenetrecontroleur);
}
Controleur::~Controleur()
{
	cout << "Destructeur" << endl;
}
void Controleur::setFenetreControleur(FenetreCalculette *fenetrecalculette)
{
	fenetre = fenetrecalculette;
}
void Controleur::setCalculetteControleur(Calculette *calculettes)
{
	calculette = calculettes;
}
FenetreCalculette* Controleur::getFenetreControleur() const
{
	return fenetre;
}
Calculette* Controleur::getCalculetteControleur() const
{
	return calculette;
}

void Controleur::ActionBouton(const char* nom) //Appeler les bonnes focntions quand on clic sur 1 des boutons
{
	try
	{
		if (strcmp(nom,"B_0") == 0) calculette->SaisirChiffre(0);
		if (strcmp(nom,"B_1") == 0) calculette->SaisirChiffre(1);
		if (strcmp(nom,"B_2") == 0) calculette->SaisirChiffre(2);
		if (strcmp(nom,"B_3") == 0) calculette->SaisirChiffre(3);
		if (strcmp(nom,"B_4") == 0) calculette->SaisirChiffre(4);
		if (strcmp(nom,"B_5") == 0) calculette->SaisirChiffre(5);
		if (strcmp(nom,"B_6") == 0) calculette->SaisirChiffre(6);
		if (strcmp(nom,"B_7") == 0) calculette->SaisirChiffre(7);
		if (strcmp(nom,"B_8") == 0) calculette->SaisirChiffre(8);
		if (strcmp(nom,"B_9") == 0) calculette->SaisirChiffre(9);
		if (strcmp(nom,"B_Enter") == 0) calculette->Enter();
		if (strcmp(nom,"B_Moins") == 0) calculette->Moins();
		if (strcmp(nom,"B_Plus") == 0) calculette->Plus();
		if (strcmp(nom,"B_Fois") == 0) calculette->Fois();
		if (strcmp(nom,"B_Divise") == 0) calculette->Divise();
		if (strcmp(nom,"B_Erase") == 0) calculette->Erase();
		if (strcmp(nom,"B_PlusOuMoins") == 0) calculette->PlusOuMoins();
		if (strcmp(nom,"B_Numerique") == 0) calculette->ChangeMode();
		if (strcmp(nom,"B_ClearSaisie") == 0) calculette->ClearSaisie();	
		if (strcmp(nom,"B_Config") == 0) ConfigCouleur();	//Focntions dans le controleur comme ça pas accès à la calculette
		
	}
	catch(CalculetteException e) { //Quand exception met les panneaux en rouge
		cout << "Erreur : " << e.getMessageErreur() << endl;
		ofstream fp1("Config.dat", ios::out) ;
		fenetre->Save(fp1) ;
		fp1.close() ;
		fenetre->setCouleurPanneauHaut(Couleur(255,0,0));
		fenetre->setCouleurPanneauMilieu(Couleur(255,0,0));
		fenetre->setCouleurPanneauBas(Couleur(255,0,0));
		fenetre->Dessine();
		sleep(1);
		
		ifstream fp2("Config.dat", ios::in) ;
		fenetre->Load(fp2) ;
		fp2.close() ;
		
		fenetre->Dessine();
		}
}
void Controleur::ConfigCouleur() //Menu pour modifier la couleur des différents panneaux
{
	bool fin = false ;
	char choix;
	Couleur CouleurConfig ;
	
	while(!fin)
	{
	
		cout << "****** MENU CONFIGURATION ******************************" << endl ;
		cout << "1) Changer la couleur du fond" << endl ;
		cout << "2) Changer la couleur du panneau du haut" << endl ;
		cout << "3) Changer la couleur du panneau du milieu" << endl ;
		cout << "4) Changer la couleur du panneau du bas" << endl ;
		cout << "q) Retour à la calculette" << endl ;
		cout << "********************************************************" << endl ;
		cout << "Choix "; 
		cin >> choix ;
		cout << endl ;
	
		switch(choix)
		{
			case '1' :
				cin >> CouleurConfig;
				fenetre->setCouleurFenetre(CouleurConfig) ;
				cout << endl ;
				cout << "Couleur du fond changee !" << endl ;
				cout << endl ;
				break;
			case '2' :
				cin >> CouleurConfig;
				fenetre->setCouleurPanneauHaut(CouleurConfig) ;
				cout << endl ;
				cout << "Couleur du fond changee !" << endl ;
				cout << endl ;
				break;
			case '3' :
				cin >> CouleurConfig;
				fenetre->setCouleurPanneauMilieu(CouleurConfig) ;
				cout << endl ;
				cout << "Couleur du fond changee !" << endl ;
				cout << endl ;
				break;
			case '4' :
				cin >> CouleurConfig;
				fenetre->setCouleurPanneauBas(CouleurConfig) ;
				cout << endl ;
				cout << "Couleur du fond changee !" << endl ;
				cout << endl ;
				break;
			case 'q' :
				fin = true ;
				break;
		}
		fenetre->Dessine() ;
	}
	
}






