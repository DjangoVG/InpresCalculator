#include "WindowSDLimage.h"

//***************************************************************************
//********** Constructeurs **************************************************
//***************************************************************************
WindowSDLimage::WindowSDLimage(void)
{
  surface = NULL;
}

WindowSDLimage::WindowSDLimage(const char* nf) throw (WindowSDLexception)
{
  surface = chargeSurface(nf);
}

WindowSDLimage::WindowSDLimage(const WindowSDLimage &i)
{
  if (i.surface != NULL) surface = copieSurface(i.surface);
  else surface = NULL;
}

//***************************************************************************
//********** Desctructeur ***************************************************
//***************************************************************************
WindowSDLimage::~WindowSDLimage() 
{ 
  // On libere la memoire de l'image
  SDL_FreeSurface(surface); 
}

//***************************************************************************
//********** SETTERS ********************************************************
//***************************************************************************

//***************************************************************************
//********** GETTERS ********************************************************
//***************************************************************************
int WindowSDLimage::getWidth() const { return surface->w; }
int WindowSDLimage::getHeight() const { return surface->h; }

//***************************************************************************
//********** Methodes d'instance ********************************************
//***************************************************************************
void WindowSDLimage::load(const char* nf) throw (WindowSDLexception)
{
  SDL_Surface* tmp = chargeSurface(nf);
  SDL_FreeSurface(surface);
  surface = tmp;
}

//***************************************************************************
SDL_Surface* WindowSDLimage::chargeSurface(const char *nf) throw (WindowSDLexception)
{
  // Surface tampon qui nous servira pour charger l'image 
  SDL_Surface* loadedImage = NULL; 

  // L'image optimisee qu'on va utiliser 
  SDL_Surface* optimizedImage = NULL;

  // Chargement de l'image
  loadedImage = SDL_LoadBMP(nf);

  // Si le chargement se passe bien
  if(loadedImage != NULL)
  { 
    return loadedImage;

    // Création de l'image optimisée 
    optimizedImage = SDL_DisplayFormat(loadedImage); // BUG...

    // Libération de l'ancienne image
    SDL_FreeSurface(loadedImage); 
  }
  else throw WindowSDLexception("Nom de fichier image BMP incorrect !");
	
  // On retourne l'image optimisée 
  return optimizedImage; 
}

//***************************************************************************
SDL_Surface* WindowSDLimage::copieSurface(SDL_Surface *surf)
{
  SDL_Surface *res;
  res = SDL_CreateRGBSurface(surf->flags, surf->w, surf->h, 
                      surf->format->BitsPerPixel, surf->format->Rmask,
                      surf->format->Gmask, surf->format->Bmask,
                      surf->format->Amask);
  if(res != NULL) 
     SDL_BlitSurface(surf, NULL, res, NULL);
  
  return res;
}

//***************************************************************************
//********** Surcharges d'operateurs ****************************************
//***************************************************************************
WindowSDLimage& WindowSDLimage::operator=(const WindowSDLimage& i)
{
  // On libere la memoire de l'image
  SDL_FreeSurface(surface); 

  // copie de l'image
  if (i.surface != NULL) surface = copieSurface(i.surface);
  else surface = NULL;  

  return *this;
}

