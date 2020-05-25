#include <SFML/Graphics.hpp>
#include <iostream>
#include "parametre.h"
#include "toucher.h"
#include "zone.h"
#include <vector>
#include "ligne.h"
#include <ctime>
#include <time.h>


#ifndef JEU_H
#define JEU_H

/**************Ce fichier contient le coeur de la simulation: la dissection de la tumeur à travers les différentes zones**************/

//simulation de la dissection
void init_jeu(RenderWindow&, int& ,int& ,int& ,int& ,int& ,int& ,int& ,int& ,int* ,int& , int*, int*,Texture& ,Sprite& ,ligne& ,ligne& ,time_t*, int, int&);

//Initialisation des variables necessaires pour la simulation
void simulation(RenderWindow&, int&, int&, int&, int&, int&, int&, int&, int&, int*, int&, int*,int*, tabpoint&, tabpoint&, int**, Texture&, Sprite&, point&, ligne& , ligne& , int&, time_t*, int, int, int, int);

//fonction permettant de recomencer la simulation
void restart(tabpoint&, tabpoint&, int&, time_t, ligne&, ligne&,time_t* ,int&, int, int, int , int**);

//initialisation des paramètres réglables par l'utilisateur via le menu
void Initpara(int&, int&, int&, int&, int&);

#endif
