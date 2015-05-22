t_NoeudABR* creer_noeud( char *mot, int ligne, int ordre, int numero_phrase);//Outils
int ajout2 (t_NoeudABR* arbre, t_NoeudABR* pere, char* mot, int ligne, int ordre, t_ArbreBR * abr,int numero_phrase);
int maxi(int a,int b);
int puissance (int x, int n);
int checkPositionList(t_NoeudABR* racine, int numPhrase,char ** file);
int afficherPhrase (t_NoeudABR* racine, int numPhrase,char ** file,int nb);
void afficherPhrase2(t_NoeudABR* racine, int numPhrase);
