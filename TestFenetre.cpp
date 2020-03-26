#include <iostream>
using namespace std;

#include "Fenetre.h"
#include "Panneau.h"
#include "Bouton.h"
#include "PanneauImage.h"
#include "BoutonImage.h"

#include "WindowSDL.h" // pour waitClick

int main(int argc,char* argv[])
{
  Fenetre fenetre(600,400,Couleur(192));

  Panneau p1("P01",30,60,120,90,Couleur(255,0,0));
  Bouton  b1("B01",200,60,40,40,Couleur::BLEU);
  PanneauImage p2("P02",40,200,"images/Trois.bmp");
  BoutonImage b2("B02",210,170,"images/boutonEnter.bmp");

  fenetre.setVisible(true);
  fenetre.Dessine();
  p1.Dessine();
  b1.Dessine();
  p2.Dessine();
  b2.Dessine();
  cout << "Cliquez dans la fenetre..." << endl;
  WindowSDLclick clic = WindowSDL::waitClick();
  if (clic.getX() == -1) cout << "Clic sur croix de fenetre..." << endl;
  else
  { // A-t-on cliqué sur un bouton ?
    b1.clic(clic.getX(),clic.getY());
    b2.clic(clic.getX(),clic.getY());
  }

  fenetre.setVisible(false);

  return 0;
}


