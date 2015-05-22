typedef struct NoeudABR
{
    char* mot;
    struct Liste* positions;
    struct NoeudABR* filsGauche;
    struct NoeudABR* filsDroit;
}t_NoeudABR;

typedef struct ArbreBR
{
    struct NoeudABR* racine;
    int nb_mots_differents;
    int nb_mots_total;
}t_ArbreBR;

t_ArbreBR* creer_abr();

int ajouter_noeud(t_ArbreBR *arbre, char *mot, int ligne, int ordre,int numero_phrase);
int charger_fichier(t_ArbreBR *arbre, char *filename);
t_NoeudABR* Rechercher_noeud(t_NoeudABR* racine, char* mot);
void afficher_arbre(t_NoeudABR* racine);











