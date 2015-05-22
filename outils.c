#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "liste.h"
#include "outils.h"

t_NoeudABR* creer_noeud( char *mot, int ligne, int ordre,int numero_phrase)
{
    t_NoeudABR* New= (t_NoeudABR*)malloc(sizeof(t_NoeudABR));
            New->mot=malloc(sizeof(strlen(mot)+1));
            strcpy(New->mot,mot);
            Liste_pos *New_liste= creerListePositions();
            ajouter_position (New_liste,ligne,ordre,numero_phrase);
            New->positions= New_liste;
            New->filsGauche=NULL;
            New->filsDroit=NULL;
    return New;
}


int ajout2 (t_NoeudABR* arbre, t_NoeudABR* pere, char* mot, int ligne, int ordre,t_ArbreBR *abr,int numero_phrase)
{

    int compar;

    if(arbre==NULL)
    {
             printf("Creation du nouveau noeud \n");
            t_NoeudABR* New =creer_noeud(mot,ligne,ordre,numero_phrase);
            compar=strcasecmp(pere->mot, mot);
            if(compar<0){

                pere->filsDroit=New;
            }
            else if(compar>0){

                pere->filsGauche=New;
            }

                abr->nb_mots_differents++;
                abr->nb_mots_total++;

            return 1;
    }
    else
    {
         compar=strcasecmp(arbre->mot,mot);
         if(compar<0)
            {
                //printf("out 1 \n");
                ajout2(arbre->filsDroit,arbre,mot,ligne,ordre,abr,numero_phrase);
            }
        if(compar>0)
            {
                //printf("out 2 \n");
                ajout2(arbre->filsGauche,arbre,mot, ligne,ordre,abr,numero_phrase);
            }
        if(compar==0)
            {
            ajouter_position(arbre->positions, ligne, ordre,numero_phrase);
            printf("Ajout position \n");

            abr->nb_mots_total++;
            return 1;
            }
    }
}


int maxi(int a,int b)
{
	return (a>b)? a : b ;
}

int hauteur (t_NoeudABR* racine )
{
	if ( racine == NULL ){
        return -1;
	}
    else{
       return (1 + maxi( hauteur(racine->filsDroit) , hauteur(racine->filsGauche) ));
    }

}

int puissance (int x, int n)
{
if (n==0)
    return 1;
else
    return (x*puissance(x,n-1));
}


int estEquilibre(t_NoeudABR* racine){

 if (racine != NULL){
    if(((hauteur(racine->filsGauche)-hauteur(racine->filsDroit)) >= -1) && ((hauteur(racine->filsGauche)-hauteur(racine->filsDroit)) <= 1)){
        if (estEquilibre(racine->filsGauche) && estEquilibre(racine->filsDroit)){
                return 1;

        }
        else
            return 0;




    }
    else
        return 0;


 }
 else
    return 1;
}




int checkPositionList(t_NoeudABR* racine, int numPhrase,char ** file)
{
    int nb=0;
    if (racine != NULL){
//printf("in check PositionList");
  Position *tmp = racine->positions->debut;

                  while (tmp!= NULL){
                    if (tmp->numero_phrase==numPhrase)
                    {
                        nb = nb +1;
                        strcpy(file[tmp->ordre],racine->mot);
                        tmp=tmp->suivant;
                    }
                    else
                        tmp=tmp->suivant;
                  }
    }
return nb;

}
int afficherPhrase (t_NoeudABR* racine, int numPhrase,char ** file,int nb)
{


    if (racine != NULL){
     nb = nb +  checkPositionList(racine,numPhrase,file);
        if (racine->filsGauche != NULL )
           nb =  afficherPhrase(racine->filsGauche,numPhrase,file,nb);
        if (racine->filsDroit != NULL)
            nb =  afficherPhrase(racine->filsDroit,numPhrase,file,nb);
    }



    return nb;

}


void afficherPhrase2(t_NoeudABR* racine, int numPhrase)
{

printf("Numphrase vaut %d \n ",numPhrase);
char ** file ;
           file = malloc(50*sizeof(char*));
                    int i= 0;
                    if (file != NULL) {
                    for(i=0 ; i < 50 ; i++){
                        file[i] = malloc(20 * sizeof(char**) );
                        if(file[i] != NULL){

                        }
                    }
                    }

                //printf("avant afficher phrase");


            int nb=0;
                    nb=      afficherPhrase(racine,numPhrase,file,nb);
                     printf("LA PHRASE EST:\t");

                    for(i=1 ; i < nb +1 ; i++){
                        printf(" %s ",file[i]);
                    }

}


int dejaTrouve(int list [],int k){

int i =0;
for (i=0;i<20;i++){
 if (list[i] == k)
        return 0;


}
return 1;
}







/* typedef struct cel
{
    char* mot;
    struct cellule* next;
}cellule;

typedef struct f
{
    struct cellule* head;
    struct cellule* tail;
} file;

void creer_file(file* f)
{
    f=(file*)malloc(sizeof(file));
        f->head= NULL;
        f->tail= NULL;
    return ;
}

int filevide(file* f)
{
        return ((f->head==f)&&(f->tail==NULL));
}
void enfiler(file* f, char* mot)
{
       if(f!=NULL)
       {
            cellule* new=(cellule*)malloc(sizeof(cellule));
            new->mot=NULL;
            strcpy(new->mot,mot);
            new->next=NULL;
            if(filevide(f))
            {
                f->head=new;
                f->tail=new;
            }
            else
            {
                f->tail->next= new;
                f->tail=new;
            }
       }

}

void defiler (file* f)
{
        if(f==NULL || filevide(f))
            return ;
        else
        {
                struct cellule*temp=f->head;
                f->head=f->head->next;
                free(temp);
                return ;

        }
}*/


