#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste.h"

/*Cette fonction crée une liste de positions et renvoie null si échec */
Liste_pos * creerListePositions()
{


    Liste_pos* listeP=(Liste_pos*) malloc(sizeof(Liste_pos));
    if(listeP!=NULL)
    {
        listeP->debut=NULL;
        listeP->nb_elements=0;
        return listeP;
    }
    else
        return NULL;
}

// Correction : listeP->nb_elements++;
int ajouter_position (Liste_pos *listeP, int ligne, int ordre,int numero_phrase)
{
    Position *pos =(Position*)malloc(sizeof(Position));
    Position* temp= listeP->debut;
    //Position *temp_prev=NULL;
    if(pos!=NULL)
    {
        pos->numero_ligne=ligne;
        pos->ordre=ordre;
        pos->numero_phrase=numero_phrase;
        pos->suivant=NULL;
        if (listeP->nb_elements==0) // liste vide ajout au debut
        {
            listeP->debut=pos;
            listeP->nb_elements++;
        }
        else
        {

            while(temp->suivant!=NULL)
            {
                temp=temp->suivant;
            }
            temp->suivant=pos;
            listeP->nb_elements++;
            }
    return 1;
    }
    else
    {
        return 0;
    }

}








