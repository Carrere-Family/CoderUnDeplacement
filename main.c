//----------------------------------------------------------------------------------------------------------------------
//!
//! \file     main.c
//! \author   Philippe Carrère
//! \date     2019-10-17T17:00:00
//!
//! \brief    main file, program entry point.
//!
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// I N C L U D E S
//----------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

//----------------------------------------------------------------------------------------------------------------------
// D E F I N E S   &   M A C R O
//----------------------------------------------------------------------------------------------------------------------

#define iFENETRE_TAILLE_X    ((int)1024)
#define iFENETRE_TAILLE_Y    ((int)768)
#define iFENETRE_PROFONDEUR  ((int)32)

#define sFENETRE_TITRE       "Coder un Deplacement"

//----------------------------------------------------------------------------------------------------------------------
// T Y P E D E F S
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// C O N S T A N T S
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// L O C A L   F U N C T I O N S   P R O T O T Y P E S
//----------------------------------------------------------------------------------------------------------------------

/*! \brief Mets le programme en pause (avant de quitter)*/
void vidPause(void);

//----------------------------------------------------------------------------------------------------------------------
// D A T A
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// F U N C T I O N S
//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
/*! \Details Mets le programme en pause en attendant un "event", dans notre cas la fermeture de la fenêtre SDL */
void vidPause(void)
{
  bool bIsWaiting = true;
  SDL_Event udtEvent;

  while (bIsWaiting)
  {
    SDL_WaitEvent(&udtEvent);
    switch(udtEvent.type)
    {
      case SDL_QUIT:
        bIsWaiting = false;
        break;

      default:
        break;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
/*! \Details Fonction "Main" */
int main(int argc, char *argv[])
{
  //SDL_Surface * pFenetre = (SDL_Surface*)NULL;

  if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
  {
    fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
    exit(EXIT_FAILURE); // On quitte le programme avec pertes et fracas.
  }

  SDL_SetVideoMode(iFENETRE_TAILLE_X, iFENETRE_TAILLE_Y, iFENETRE_PROFONDEUR, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption(sFENETRE_TITRE, (char*)NULL);

  vidPause(); // Mise en pause du programme

  SDL_Quit(); // Arrêt de la SDL

  return EXIT_SUCCESS; // Fermeture du programme
}
