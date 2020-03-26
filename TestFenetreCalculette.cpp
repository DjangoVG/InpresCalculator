#include <iostream>
using namespace std;

#include "FenetreCalculette.h"
#include "WindowSDL.h"

//************************************************************************************************
int main(int argc,char* argv[])
{
  FenetreCalculette fenetre;
  fenetre.setVisible(true);
  fenetre.FenetreCalculette::Dessine();
  WindowSDL::waitClick();
  fenetre.setVisible(false);

  return 0;
}

