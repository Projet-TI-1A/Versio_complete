#ifndef RESULTAT_H
#define RESULTAT_H
#include "toucher.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <time.h>

using namespace sf;
using namespace std;

/****Ce fichier traite les information récupéréees pendant la simulation et leur affichage****/

//affichage du pourcentage d'incisions dans la bonne zone et du temps total de la simulation
void affichage_erreur(int, int*, int*, RenderWindow&, int*, time_t*);

//calcule une durée (durée de la simulation totale ou zone par zone)
int chronosimul(time_t temps_debut);


#endif
