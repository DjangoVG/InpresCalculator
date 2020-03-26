#ifndef WINDOW_SDL_IMAGE_H
#define WINDOW_SDL_IMAGE_H

#include <SDL/SDL.h>
#include "WindowSDLexception.h"

class WindowSDL;

class WindowSDLimage
{
  private :
    SDL_Surface   *surface;

    SDL_Surface*  chargeSurface(const char *nomfichier) throw (WindowSDLexception);
    SDL_Surface*  copieSurface(SDL_Surface *surf);
    
  public:
    WindowSDLimage(void);
    WindowSDLimage(const char* nomFichier) throw (WindowSDLexception);
    WindowSDLimage(const WindowSDLimage &c);
    ~WindowSDLimage();

    void load(const char* nomFichier) throw (WindowSDLexception);

    int  getWidth() const;    // Largeur en pixels de l'image
    int  getHeight() const;   // Hauteur en pixels de l'image

    WindowSDLimage& operator=(const WindowSDLimage& i);

    friend class WindowSDL;
};

#endif
