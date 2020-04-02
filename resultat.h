#ifndef RESULTAT_H
#define RESULTAT_H
#include "toucher.h"

using namespace sf;
using namespace std;

void compt_erreur( int& points, int& erreurs,tabpoint tab, tabpoint erreur);
void affichage_erreur(int points, int erreurs, RenderWindow& window);
#endif
