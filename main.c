#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "liste.h"
#include "outils.h"

int main ()
{
     printf("\t \t \t BIENVENUE \n");
    //Menu
    int choix =0;
    char mot[20];
    char mot1[20];
    char mot2[20];
    char*tmp0[20];
    int ordre;
    int ligne;
    int num_phrase;
    char rech[20];
    char*tmp[20];
    char filename[20];
    char* tmpf[20];
    int k=0;
    t_ArbreBR* arbre = NULL;
    t_NoeudABR* Noeud_rech = NULL ;
    t_NoeudABR* Noeud_tmp = NULL;
     while (choix<=0 || choix>9 )
    {
        printf("\n \n Veillez choisir SVP: \n");
        printf(" \t \t 1:  Creer Un arbre\n \n ");
        printf(" \t \t 2:  Charger un fichier dans l'ABR \n \n" );
        printf(" \t \t 3:  Caracteristiques de l'ABR \n \n");
        printf(" \t \t 4:  Afficher tous les mots distincts par ordre alphabétique\n \n ");
        printf(" \t \t 5:  Rechercher un mot \n \n");
        printf(" \t \t 6: Afficher les phrases contenant deux mots\n \n ");
        printf(" \t \t 8:   Quitter \n \n");
        printf("\t VOTRE CHOIX EST :");
        scanf("%d",&choix);
        printf("\n -------------------------------------------------------\n");

        switch(choix)
        {
        case 1:
                printf("\t \t CREER ABR \n");
                printf("\n -------------------------------------------------------\n");
                arbre= creer_abr();
                if (arbre == NULL)
                    printf("PAS OK choix 1");
                else
                    printf("OK choix 1 \n");
                printf(" \t ABR CREE\n");
                break;


        case 2:
                printf("\t \t CHARGER FICHIER \n");
                printf("\n -------------------------------------------------------\n");
                printf(" \t Insert : File Name \n");

                    fflush(stdin);
                    scanf("%s",filename);
                    strcpy(tmpf,filename);
                    charger_fichier(arbre,tmpf);
                    num_phrase++;
                    printf("File charged!\n");

                    printf("erreur chargement");


                break;

        case 3:
                printf("\t \t AFFICHER LES CARAcTERISTIQUES DE L'ABR \n");
                printf("\n -------------------------------------------------------\n");
                if (arbre == NULL)
                    printf("veuillez d'abord créer l'arbre");
                else {
                printf("\n Le nombre de mots diffèrents vaut : %d \n ",arbre->nb_mots_differents);
                printf("\n Le nombre de noeuds total vaut : %d \n",arbre->nb_mots_total);
                //printf("\n Le nombre de noeuds diffèrents vaut : %d \n",arbre->nb_mots_differents);
                int htr = hauteur(arbre->racine);
                if (htr==-1){
                    printf("l'arbre est vide ");
                }
                else
                    printf("\n Le hauteur de l'arbre vaut : %d \n",htr-1);

                if (estEquilibre(arbre->racine)==1){
                    printf(" \n L'abre est Equilibre  \n \n ");
                }
                else
                    printf("\n L'arbre n'est pas Equilibre  \n\n ");
                }

                break;


        case 4:
                printf("\t \t AFFICHER TOUS LES MOTS DISTINCTS PAR ORDRE ALPHABETIQUE \n");
                printf("\n -------------------------------------------------------\n");
                if (arbre != NULL)
                    afficher_arbre(arbre->racine);
                break;
        /*case 3:
                printf("\t \t AFFICHER ARBRE \n");
                printf("\n -------------------------------------------------------\n");
                if (arbre != NULL)
                    afficher_arbre(arbre->racine);
                break;*/

        case 5:
                 printf("\t \t RECHERHCER UN NOEUD \n");
                printf("\n -------------------------------------------------------\n");
                printf(" \t Insert : mot recherche \n");
                    fflush(stdin);
                    scanf("%s",rech);
                    strcpy(tmp,rech);
                    Noeud_rech = Rechercher_noeud(arbre->racine,tmp);
                    if (Noeud_rech != NULL){
                    printf("Noeud trouve a %s \n", Noeud_rech->mot);
                 Position *tmp = Noeud_rech->positions->debut;
                  while (tmp!= NULL){
                    printf("Le numéro de ligne vaut : %d \n",tmp->numero_ligne);
                    printf("Le numéro de phrase vaut : %d \n",tmp->numero_phrase);
                    printf("L'ordre vaut : %d \n",tmp->ordre);
                    tmp=tmp->suivant;
                    printf("\n \n");
                  }
                    }
                    else
                        printf("Noeud non présent");
                break;

        case 6:
                printf("\t \t AFFICHER TOUS LES PHRASES CONTENANT DEUX MOTS \n\n");
                printf("\n -------------------------------------------------------\n");
                printf(" \t Insert : mot1 \n");
                fflush(stdin);
                scanf("%s",mot1);
                printf("\t Insert : mot2 \n");
                fflush(stdin);
                scanf("%s", mot2);
                t_NoeudABR* Noeud_rech1 = NULL ;
                t_NoeudABR* Noeud_rech2 = NULL ;

                Noeud_rech1 = Rechercher_noeud(arbre->racine,mot1);

                Noeud_rech2 = Rechercher_noeud(arbre->racine,mot2);
                if (Noeud_rech1 != NULL & Noeud_rech2 != NULL){
                Position *tmp1 = Noeud_rech1->positions->debut;
                Position *tmp2 = Noeud_rech2->positions->debut;
                int nbElementListe=0;
                int list[20];
                  while (tmp1!= NULL){

                        while (tmp2!= NULL){

                    if (tmp1->numero_phrase==tmp2->numero_phrase){
                           int k = dejaTrouve(list,tmp2->numero_phrase);
                           if (k!= 0){
                                afficherPhrase2(arbre->racine, tmp1->numero_phrase);
                                list[nbElementListe]=tmp1->numero_phrase;
                                nbElementListe++;

                                printf("\n\n");
                           }

                    }
                    tmp2=tmp2->suivant;

                  }
                  tmp1=tmp1->suivant;
                  tmp2=Noeud_rech2->positions->debut;
                }
                }
                else
                    printf("Au moins l'un des mots n'est pas présent");


                break;

         case 8:
            if(arbre != NULL){

                vider(arbre->racine,arbre);


                //free(arbre);
                //free(arbre->racine);
            }
            printf("sortie");
                exit(1);
        default :
                 printf("veuillez entrer un chiffre coherent svp");

        }

    choix=0;
  }

return 0;
}

/*case 2 :
                  if (arbre == NULL)
                    printf("PAS OK choix 2");
                else
                    printf("OK choix 2");
                printf("\t \t INSERER UN MOT \n");
                printf("\n -------------------------------------------------------\n");

                printf(" \t Insert : nom \n");
                fflush(stdin);
                scanf("%s",mot);
                printf("\t Insert : Ligne \n");
                    fflush(stdin);
                    scanf("%d", &ligne);
                printf("\t Insert : Ordre \n");
                    fflush(stdin);
                    scanf("%d", &ordre);
                    printf("%s",mot);
                printf("\t Insert : Numero Phrase \n");
                    fflush(stdin);
                    scanf("%d", &num_phrase);
                    printf("%s",mot);
               ajouter_noeud(arbre,mot,ligne,ordre,num_phrase);
               break;*/

