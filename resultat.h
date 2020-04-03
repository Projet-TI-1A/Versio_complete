#ifndef RESULTAT_H
#define RESULTAT_H
#include "toucher.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

void compt_erreur( int& points, int& erreurs,tabpoint tab, tabpoint erreur);
void affichage_erreur(int, int, RenderWindow&, int&);
void Envoi(String, int, int&);

#endif
