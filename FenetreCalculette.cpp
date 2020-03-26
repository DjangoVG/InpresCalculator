#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "FenetreCalculette.h"
using namespace std;

FenetreCalculette::FenetreCalculette()
{
	cout << "Constructeur par defaut" << endl;

	int i=0,j=0, x, y = 170;
	setLargeurFenetre(440);
	setHauteurFenetre(470);
	setCouleurFenetre(Couleur(128));
	
	setCouleurPanneauHaut(Couleur::ARGENT);
	setCouleurPanneauMilieu(Couleur::ARGENT);
	setCouleurPanneauBas(Couleur::ARGENT);

	
	boutonClearSaisie.setNom("B_ClearSaisie");
	boutonClearSaisie.setX(330);
	boutonClearSaisie.setY(240);
	boutonClearSaisie.setHauteur(90);
	boutonClearSaisie.setLargeur(40);
	boutonClearSaisie.setCouleur(Couleur(255,0,0));
	while (i<4)
	{
		x = 20;
		while (j<10)
		{
			affichage[i][j] = PanneauImage("P00",x,y,"images/Vide.bmp"); //crée 40 panneauimages vides (zone au dessus de la zone de saisie)
			x = x+40;
			j++;
		}
		y = y-50;
		i++;
		j=0;
	}
	i=0;
	x=20;
	y=240;
	while (i<6)
	{
		saisie[i] = PanneauImage("P00",x,y,"images/Vide.bmp"); //crée 6 panneau iamge vide (saisie)
		x = x +40;
		i++;
	}
	
	ifstream fp1("images/boutons.csv", ios::in) ; //descripteur de flux ouvert en input (accéder aux données)
	
	if(!fp1)
	{
		ofstream fp2("images/boutons.csv", ios::out); //descripteur de flux ouvert en output (écrire les boutons sur le flux)
		
		fp2 << "B_0" << " " << 20 << " " << 310 << " " << "images/boutonZero.bmp" << endl ;
		fp2 << "B_1" << " " << 70 << " " << 310 << " " << "images/boutonUn.bmp" << endl ;
		fp2 << "B_2" << " " << 120 << " " << 310 << " " << "images/boutonDeux.bmp" << endl ;
		fp2 << "B_3" << " " << 170 << " " << 310 << " " << "images/boutonTrois.bmp" << endl ;
		fp2 << "B_4" << " " << 220 << " " << 310 << " " << "images/boutonQuatre.bmp" << endl ;
		fp2 << "B_5" << " " << 20 << " " << 360 << " " << "images/boutonCinq.bmp" << endl ;
		fp2 << "B_6" << " " << 70 << " " << 360 << " " << "images/boutonSix.bmp" << endl ;
		fp2 << "B_7" << " " << 120 << " " << 360 << " " << "images/boutonSept.bmp" << endl ;
		fp2 << "B_8" << " " << 170 << " " << 360 << " " << "images/boutonHuit.bmp" << endl ;
		fp2 << "B_9" << " " << 220 << " " << 360 << " " << "images/boutonNeuf.bmp" << endl ;
		fp2 << "B_Erase" << " " << 20 << " " << 410 << " " << "images/boutonErase.bmp" << endl ;
		fp2 << "B_Enter" << " " << 145 << " " << 410 << " " << "images/boutonEnter.bmp" << endl ;
		fp2 << "B_Plus" << " " << 330 << " " << 310 << " " << "images/boutonPlus.bmp" << endl ;
		fp2 << "B_Moins" << " " << 380 << " " << 310 << " " << "images/boutonMoins.bmp" << endl ;
		fp2 << "B_Fois" << " " << 330 << " " << 360 << " " << "images/boutonFois.bmp" << endl ;
		fp2 << "B_Divise" << " " << 380 << " " << 360 << " " << "images/boutonDivise.bmp" << endl ;
		fp2 << "B_PlusOuMoins" << " " << 380 << " " << 410 << " " << "images/boutonPlusOuMoins.bmp" << endl ;
		fp2 << "B_Numerique" << " " << 330 << " " << 410 << " " << "images/boutonNumerique.bmp" << endl ;
		fp2 << "B_Config" << " " << 275 << " " << 410 << " " << "images/boutonConfig.bmp" << endl ;
		fp2.close() ;
	}
	ifstream fp3("images/boutons.csv", ios::in) ;
	int l = 0 ;
	while(l<19)
	{
		int a,b ;
		char tmp1[20], tmp2[50] ;
		
		fp3 >> tmp1 >> a >> b >> tmp2 ; //reprend les données des boutons dans les différentes varaibles
		
		listeBoutons.insere(BoutonImage(tmp1,a,b,tmp2)) ; //insérer les différents boutons dans la liste
		l++ ;
	}
	fp3.close() ;
	fp1.close() ;
	/*listeBoutons.insere(BoutonImage("B_0",20,310,"images/boutonZero.bmp"));
	listeBoutons.insere(BoutonImage("B_1",70,310,"images/boutonUn.bmp"));
	listeBoutons.insere(BoutonImage("B_2",120,310,"images/boutonDeux.bmp"));
	listeBoutons.insere(BoutonImage("B_3",170,310,"images/boutonTrois.bmp"));
	listeBoutons.insere(BoutonImage("B_4",220,310,"images/boutonQuatre.bmp"));
	listeBoutons.insere(BoutonImage("B_5",20,360,"images/boutonCinq.bmp"));
	listeBoutons.insere(BoutonImage("B_6",70,360,"images/boutonSix.bmp"));
	listeBoutons.insere(BoutonImage("B_7",120,360,"images/boutonSept.bmp"));
	listeBoutons.insere(BoutonImage("B_8",170,360,"images/boutonHuit.bmp"));
	listeBoutons.insere(BoutonImage("B_9",220,360,"images/boutonNeuf.bmp"));
	listeBoutons.insere(BoutonImage("B_Erase",20,410,"images/boutonErase.bmp"));
	listeBoutons.insere(BoutonImage("B_Enter",145,410,"images/boutonEnter.bmp"));
	listeBoutons.insere(BoutonImage("B_Plus",330,310,"images/boutonPlus.bmp"));
	listeBoutons.insere(BoutonImage("B_Moins",380,310,"images/boutonMoins.bmp"));
	listeBoutons.insere(BoutonImage("B_Fois",330,360,"images/boutonFois.bmp"));
	listeBoutons.insere(BoutonImage("B_Divise",380,360,"images/boutonDivise.bmp"));
	listeBoutons.insere(BoutonImage("B_PlusOuMoins",380,410,"images/boutonPlusOuMoins.bmp"));
	listeBoutons.insere(BoutonImage("B_Numerique",330,410,"images/boutonNumerique.bmp"));
	listeBoutons.insere(BoutonImage("B_Config",275,410,"images/boutonConfig.bmp"));*/
}
FenetreCalculette::~FenetreCalculette()
{
	cout << "Destructeur de fenetrecalculette" << endl;
}
void FenetreCalculette::Dessine()
{
	int i,j, x=20, y=240;
	char buff[30], damn[1];
	char buffpile[30];
	Fenetre::Dessine();
	Iterateur<Panneau> it(listePanneaux);
	Iterateur<BoutonImage> ib(listeBoutons);
	
	for (it.reset() ; !it.end(); it++) //Parcour de la liste des panneaux et les dessine
	{
		((Panneau)it).Dessine();
	}
	for (ib.reset() ; !ib.end() ; ib++) //Parcour de la liste des boutonsImage et les dessine
	{
    		((BoutonImage)ib).Dessine();
	}
	boutonClearSaisie.Dessine(); //Dessine le bouton ClearSaisie
	for (i=0; i<4; i++)
	{
		for (j=0;j<10;j++) //Parcours la liste des 40 panneaux d'affichage et les dessine
		{
			affichage[i][j].Dessine();	
		}
	}
	
	// Update de l'affichage de la zone de saisie 
	
	sprintf(buff, "%s", calculette->getSaisie());
	cout << "SAISIE : " << calculette->getSaisie() << endl;
	i = 0;
	if (strcmp(buff,"\0") != 0) //vérifie qu'on a bien qql chose dans la saisie 
	{
		while (i<6)
		{
			switch (buff[i]) //met à jour les différents affichages selon le buff
			{
				case '0':
					saisie[i].setFichier("images/Zero.bmp");
					break;
				case '1':
					saisie[i].setFichier("images/Un.bmp");
					break;
				case '2':
					saisie[i].setFichier("images/Deux.bmp");
					break;
				case '3':
					saisie[i].setFichier("images/Trois.bmp");
					break;
				case '4':
					saisie[i].setFichier("images/Quatre.bmp");
					break;
				case '5':
					saisie[i].setFichier("images/Cinq.bmp");
					break;
				case '6':
					saisie[i].setFichier("images/Six.bmp");
					break;
				case '7':
					saisie[i].setFichier("images/Sept.bmp");
					break;
				case '8':
					saisie[i].setFichier("images/Huit.bmp");
					break;
				case '9':
					saisie[i].setFichier("images/Neuf.bmp");
					break;
				default : 
					saisie[i].setFichier("images/Vide.bmp");
					break;
			}
			saisie[i].Dessine();
			i++;
		}
	}
	else
	{
		i=0;
		while (i<6)
		{
			saisie[i].setFichier("images/Vide.bmp");
			saisie[i].Dessine();
			i++;
		}
	}
	// Update de l'affichage de la pile
	for (i=0;i<4;i++)
	{
		sprintf(buffpile, "%s", calculette->getPile(i));
		if (strcmp(buffpile,"\0") != 0)
		{
			j=0;
			int k=0;
			while (j<10)
			{
				cout << "BUFFER : " << buffpile[k] << endl;
				switch (buffpile[k])
				{
					case '0':
						affichage[i][j].setFichier("images/Zero.bmp");
						break;
					case '1':
						if (buffpile[k-1] == '/' && buffpile[k+1] == ' ')
							affichage[i][j].setFichier("images/Vide.bmp");
						else
							affichage[i][j].setFichier("images/Un.bmp");
						break;
					case '2':
						affichage[i][j].setFichier("images/Deux.bmp");
						break;
					case '3':
						affichage[i][j].setFichier("images/Trois.bmp");
						break;
					case '4':
						affichage[i][j].setFichier("images/Quatre.bmp");
						break;
					case '5':
						affichage[i][j].setFichier("images/Cinq.bmp");
						break;
					case '6':
						affichage[i][j].setFichier("images/Six.bmp");
						break;
					case '7':
						affichage[i][j].setFichier("images/Sept.bmp");
						break;
					case '8':
						affichage[i][j].setFichier("images/Huit.bmp");
						break;
					case '9':
						affichage[i][j].setFichier("images/Neuf.bmp");
						break;
					case '/':
						if (buffpile[k+1] == '1' && buffpile[k+2] == ' ')
							affichage[i][j].setFichier("images/Vide.bmp");
						else
							affichage[i][j].setFichier("images/BarreFraction.bmp");
						break;
					case '-':
						affichage[i][j].setFichier("images/Moins.bmp");
						break;
					case '.':
						affichage[i][j].setFichier("images/Virgule.bmp");
						break;
					default : 
						affichage[i][j].setFichier("images/Vide.bmp");
						break;
				}
				affichage[i][j].Dessine();
				k++;
				j++;
			}
		}
		else
		{
			j=0;
			while (j<10)
			{
				affichage[i][j].setFichier("images/Vide.bmp");
				affichage[i][j].Dessine();
				j++;			
			}

		}
	}	

}
void FenetreCalculette::setVisible(bool v)
{
	Fenetre::setVisible(v);
}
void FenetreCalculette::setCouleurPanneauHaut(const Couleur &c1) 
{
	CouleurPanneauHaut.setRouge(c1.getRouge());
	CouleurPanneauHaut.setBleu(c1.getBleu());
	CouleurPanneauHaut.setVert(c1.getVert());
	CouleurPanneauHaut.setNom(c1.getNom());
	listePanneaux.insere(Panneau("P_Haut",10,10,420,210,CouleurPanneauHaut));
}
void FenetreCalculette::setCouleurPanneauMilieu(const Couleur &c2)
{
	CouleurPanneauMilieu.setRouge(c2.getRouge());
	CouleurPanneauMilieu.setBleu(c2.getBleu());
	CouleurPanneauMilieu.setVert(c2.getVert());
	CouleurPanneauMilieu.setNom(c2.getNom());
	listePanneaux.insere(Panneau("P_Milieu",10,230,420,60,CouleurPanneauMilieu));
}
void FenetreCalculette::setCouleurPanneauBas(const Couleur &c3)
{
	CouleurPanneauBas.setRouge(c3.getRouge());
	CouleurPanneauBas.setBleu(c3.getBleu());
	CouleurPanneauBas.setVert(c3.getVert());
	CouleurPanneauBas.setNom(c3.getNom());
	listePanneaux.insere(Panneau("P_Bas",10,300,420,160,CouleurPanneauBas));
}
Couleur FenetreCalculette::getCouleurPanneauHaut()
{
	return 	listePanneaux[0].getCouleur();
}
Couleur FenetreCalculette::getCouleurPanneauMilieu()
{	
	return 	listePanneaux[1].getCouleur();
}
Couleur FenetreCalculette::getCouleurPanneauBas()
{
	return 	listePanneaux[2].getCouleur();
}
void FenetreCalculette::setEcouteur(Ecouteur *ecouteurfenetrecalculette) //setEcouteur pour chaque bouton de la liste
{
	Iterateur<BoutonImage> ib(listeBoutons);
	boutonClearSaisie.setEcouteur(ecouteurfenetrecalculette);
	for(ib.reset(); !ib.end(); ib++)
	{
		(&ib).setEcouteur(ecouteurfenetrecalculette);
	}
	
}
void FenetreCalculette::setCalculette(Calculette *calculettefenetrecalculette)
{
	calculette = calculettefenetrecalculette;
}
Calculette * FenetreCalculette::getCalculette()
{
	return calculette;
}
void FenetreCalculette::clic(int x, int y)
{
	Iterateur<BoutonImage> ib(listeBoutons);
	boutonClearSaisie.clic(x,y);
	for(ib.reset(); !ib.end(); ib++)
	{ 
		(&ib).clic(x,y);
	}	
}
void FenetreCalculette::Save(ofstream &fichier) const //sauvegarder la couleur des différents panneaux
{
	int n ;
	char tmp[80] ;
	Couleur c ;
	
	if(!fichier)
	{
		cout << "Ouverture impossible du fichier" << endl ;
	}
	else
	{
		n = couleurFond.getRouge() ;
		fichier.write((char*)&n,sizeof(int)) ;
		n = couleurFond.getVert() ;
		fichier.write((char*)&n,sizeof(int)) ;
		n = couleurFond.getBleu() ;
		fichier.write((char*)&n,sizeof(int)) ;
		
		n = CouleurPanneauHaut.getRouge() ;
		fichier.write((char*)&n,sizeof(int)) ;
		n = CouleurPanneauHaut.getVert() ;
		fichier.write((char*)&n,sizeof(int)) ;
		n = CouleurPanneauHaut.getBleu() ;
		fichier.write((char*)&n,sizeof(int)) ;
		
		n = CouleurPanneauMilieu.getRouge() ;
		fichier.write((char*)&n,sizeof(int)) ;
		n = CouleurPanneauMilieu.getVert() ;
		fichier.write((char*)&n,sizeof(int)) ;
		n = CouleurPanneauMilieu.getBleu() ;
		fichier.write((char*)&n,sizeof(int)) ;
		
		n = CouleurPanneauBas.getRouge() ;
		fichier.write((char*)&n,sizeof(int)) ;
		n = CouleurPanneauBas.getVert() ;
		fichier.write((char*)&n,sizeof(int)) ;
		n = CouleurPanneauBas.getBleu() ;
		fichier.write((char*)&n,sizeof(int)) ;
	}
}
void FenetreCalculette::Load(ifstream &fichier) //charger les différentes couleurs des panneaux
{   
	int r,v,b ;
	char tmp[80] ;
	Couleur c ;
	
	if(!fichier)
	{
		cout << "Ouverture impossible du fichier" << endl ;
	}
	else
	{
		fichier.read((char*)&r, sizeof(int)) ;
		cout << r << endl ;
		couleurFond.setRouge(r) ;
		fichier.read((char*)&v, sizeof(int)) ;
		cout << v << endl ;
		couleurFond.setVert(v) ;
		fichier.read((char*)&b, sizeof(int)) ;
		cout << b << endl ;
		couleurFond.setBleu(b) ;
		
		fichier.read((char*)&r, sizeof(int)) ;
		cout << r << endl ;
		CouleurPanneauHaut.setRouge(r) ;
		fichier.read((char*)&v, sizeof(int)) ;
		cout << v << endl ;
		CouleurPanneauHaut.setVert(v) ;
		fichier.read((char*)&b, sizeof(int)) ;
		cout << b << endl ;
		CouleurPanneauHaut.setBleu(b) ;
		setCouleurPanneauHaut(CouleurPanneauHaut) ;
		
		fichier.read((char*)&r, sizeof(int)) ;
		cout << r << endl ;
		CouleurPanneauMilieu.setRouge(r) ;
		fichier.read((char*)&v, sizeof(int)) ;
		cout << v << endl ;
		CouleurPanneauMilieu.setVert(v) ;
		fichier.read((char*)&b, sizeof(int)) ;
		cout << b << endl ;
		CouleurPanneauMilieu.setBleu(b) ;
		setCouleurPanneauMilieu(CouleurPanneauMilieu) ;
		
		fichier.read((char*)&r, sizeof(int)) ;
		cout << r << endl ;
		CouleurPanneauBas.setRouge(r) ;
		fichier.read((char*)&v, sizeof(int)) ;
		cout << v << endl ;
		CouleurPanneauBas.setVert(v) ;
		fichier.read((char*)&b, sizeof(int)) ;
		cout << b << endl ;
		CouleurPanneauBas.setBleu(b) ;
		setCouleurPanneauBas(CouleurPanneauBas) ;
	}	
}
