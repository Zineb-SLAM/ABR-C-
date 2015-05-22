typedef struct  Pos
{
    int numero_ligne;
    int ordre;
    int numero_phrase;
    struct Pos* suivant;
} Position;

typedef struct Liste
{
    struct Pos * debut;
    int nb_elements;
}Liste_pos;

Liste_pos * creerListePositions();
int ajouter_position (Liste_pos *listeP, int ligne, int ordre, int numero_phrase);
