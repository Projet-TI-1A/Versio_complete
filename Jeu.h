#include <SFML/Graphics.hpp>
#include <iostream>
#include "parametre.h"
#include "toucher.h"
#include "zone.h"
#include <vector>
#include "ligne.h"

#ifndef JEU_H
#define JEU_H

void init_jeu(RenderWindow&, int& ,int& ,int& ,int& ,int& ,int& ,int& ,int& ,int* ,int& ,int& ,int& ,Texture& ,Sprite& ,ligne& ,ligne& );
void simulation(RenderWindow&, int&, int&, int&, int&, int&, int&, int&, int&, int*, int&, int&,int&, tabpoint&, tabpoint&, int**, Texture&, Sprite&, point&, ligne& , ligne& , int&);

#endif
