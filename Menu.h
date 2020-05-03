#include <SFML/Graphics.hpp>
#include <iostream>


#ifndef MENU_H
#define MENU_H

using namespace std;
using namespace sf;


void menu(RenderWindow&, String&, String&, String&, String&, String&, String&, String&, int&, int&);
void menu0(RenderWindow&, Text&, Text&, int&);
void menuprenom(RenderWindow&, Text&, Text&, Text&, Text&, String&, int&);
void menuprenom2(RenderWindow&, Text&, Text&, Text&, Text&, String&, int&);
void menunom(RenderWindow&, Text&, Text&, Text&, Text&, String&, int&);
void menu3(RenderWindow&, Text&, Text&, Text&, Text&, String&, int&);
void menu4(RenderWindow&, Text&, Text&, Text&, Text&, Text&, String&, int&);
void menu5(RenderWindow&, Text&, Text&, Text&, Text&, Text&, Text&, String&, int&);
void menu6(RenderWindow&, Text&, Text&, Text&, Text&, Text&, String&, int&);
void Button(RenderWindow& window, String& text, int& ecran, String ,int,int,int,int);
void Retour(RenderWindow&, int&, int, int);
bool Button(RenderWindow&, int, int, int,int);
void Champtxt(Event&, String&);
void reglage(RenderWindow&, Font, int&);
void Defaut(String&, String&, String&, String&);
void Enregistrer(String&, String&, String&, String&);
void Verif(bool&, int&, int&, int&, int&);

#endif
