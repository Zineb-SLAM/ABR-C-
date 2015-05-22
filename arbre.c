#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "liste.h"
#include "outils.h"

/*Changement*/
t_ArbreBR* creer_abr()
{
	t_ArbreBR* Arbre;
	Arbre=(t_ArbreBR*) malloc(sizeof(Arbre));
	if(Arbre!=NULL)
	{
		Arbre->racine=NULL;
		Arbre->nb_mots_differents=0;
		Arbre->nb_mots_total=0;
		return Arbre;
	}
	else{

     return NULL;
}
	}

int ajouter_noeud(t_ArbreBR *arbre, char *mot, int ligne, int ordre,int numero_phrase)
{
    printf("Le mot vaut %s \t",mot);
    printf("Le nombre de mots vaut: %d \n",arbre->nb_mots_total);
	if(arbre==NULL)
	{
            printf(" \t L'arbre n'existe pas , On le cree : \n ");
            arbre=creer_abr();
	}

    if (arbre->racine==NULL)
    {
        printf("Empty tree : ajout racine \n");
        t_NoeudABR* New =creer_noeud(mot,ligne,ordre,numero_phrase);
        arbre->racine=New;
        arbre->nb_mots_differents++;
        arbre->nb_mots_total++;
		return 1;
	}
	else
	{
        int comp=strcasecmp(arbre->racine->mot,mot);
        if(comp==0)
        {
            ajouter_position (arbre->racine->positions,ligne,ordre,numero_phrase);

            arbre->nb_mots_total++;
            return 1;
        }
		else if (comp>0)
		{
            //printf("in 1 \n");
            return ajout2(arbre->racine->filsGauche,arbre->racine,mot,ligne,ordre,arbre,numero_phrase);
		}

		else if (comp<0)
		{
            //printf("in 2 \n");

            return ajout2(arbre->racine->filsDroit,arbre->racine,mot,ligne,ordre,arbre,numero_phrase);

		}

    }
}

t_NoeudABR* Rechercher_noeud(t_NoeudABR* racine, char* mot)
{
	if (racine!=NULL && racine->mot != NULL)
	{

		int compar=strcasecmp(mot,racine->mot);

		if(compar==0)
        {
						printf(" \t \t FOUND!! \n");
                        return racine;
        }
		if (compar<0)
						return Rechercher_noeud(racine->filsGauche,mot);
		else
                        return Rechercher_noeud(racine->filsDroit,mot);
	}
	else
    {
        printf("\t NONEXISTANT or EMPTY ABR ! \n");
    	return NULL;
    }

}

void afficher_arbre(t_NoeudABR* racine)
{
       if (racine != NULL) {


        if(racine->filsGauche!=NULL)
           afficher_arbre(racine->filsGauche);
        if (racine != NULL)
             printf(" %s - ",racine->mot);
         if(racine->filsDroit!=NULL)
            afficher_arbre(racine->filsDroit);


       }
}
/*void vider_liste (Liste_pos* liste )
{
    Position* temp=liste->debut;
    While (temp!=NULL)
    {
        temp=liste->debut->suivant;
        free(liste->debut);
    }

}*/

void vider(t_NoeudABR* racine,t_ArbreBR* arbre){


   if (racine != NULL) {


        if(racine->filsGauche!=NULL){
            printf("allo \n");
           vider(racine->filsGauche,arbre);
        }

         if(racine->filsDroit!=NULL){
             printf("allo2 \n");
            vider(racine->filsDroit,arbre);
         }




        printf("\n ça plante après mot\n");
        if(racine->positions!=NULL){
            if(racine->positions != NULL){
         Position* temp= racine->positions->debut;
         Position * temp2 = temp->suivant;
         printf("ici");
             while(temp->suivant!=NULL)
            {
                printf("ici2");
                temp2=temp->suivant;
                free(temp);
                temp = temp2;

            }
            printf("sorti du while");
        }
        //free(racine->positions);
        }
/*
        if(racine->mot!=NULL){
            printf("Error au mot %s",racine->mot);
           // free(racine->mot);

        }
        */
        if (racine != NULL && racine != arbre->racine)
            free(racine);

           printf("On free2");


       }
}

int charger_fichier(t_ArbreBR *arbre, char *filename)
{

    printf("pas besoin de supprimer l'executable");
    if(arbre==NULL)
	{
            printf(" \t L'arbre n'existe pas , On le cree : \n ");
            arbre=creer_abr();
	}


    FILE* f= NULL;
    int ordre=1;
    int ligne=1;
    int num_phrase=1;
    char current;
    int i;

    if((f=fopen(filename,"r"))==NULL)
    {
            perror("fopen");
            printf("ERROR \n");
            exit(1);
    }

    current=fgetc(f);

    int k=1;
    do
    {
        char *mot_ajout=malloc(sizeof(char)*20);

        i=0;

            while(current)
            {

                if(current==' ' || current=='.' || current=='\n')
                    break;

                mot_ajout[i]=current;

                i++;
                current=fgetc(f);


            }
            mot_ajout[i]='\0';

        char * copy = malloc(sizeof(char)*(i+1));

        strcpy(copy,mot_ajout);
        if(i!=0)
        ajouter_noeud(arbre,copy,ligne,ordre,num_phrase);

        free(copy);
        ordre++;
        if(current=='\n') {
            printf("bordel");
            ligne++;
            }
        if(current=='.')
        {
            printf("hello");
            num_phrase++;
            ordre=0;
        }


        current=fgetc(f);
        free(mot_ajout);

    } while(!feof(f));
fclose(f);
printf("\t FILE CLOSED AND READY \n");
}







