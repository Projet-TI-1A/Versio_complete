#include <SFML/Graphics.hpp>
#include <iostream>


#ifndef MENU_H
#define MENU_H

using namespace std;
using namespace sf;


void menu(RenderWindow&, string&, string&, string&, string&, string&, string&, string&, int&, int&);
void menu0(RenderWindow&, Text&, Text&, int&);
void menuprenom(RenderWindow&, Text&, Text&, Text&, Text&, string&, int&);
void menuprenom2(RenderWindow&, Text&, Text&, Text&, Text&, string&, int&);
void menunom(RenderWindow&, Text&, Text&, Text&, Text&, string&, int&);
void menu3(RenderWindow&, Text&, Text&, Text&, Text&, string&, int&);
void menu4(RenderWindow&, Text&, Text&, Text&, Text&, Text&, string&, int&);
void menu5(RenderWindow&, Text&, Text&, Text&, Text&, Text&, Text&, string&, int&);
void menu6(RenderWindow&, Text&, Text&, Text&, Text&, Text&, string&, int&);
void Button(RenderWindow& window, string& text, int& ecran, string ,int,int,int,int);
void Retour(RenderWindow&, int&, int, int);
bool Button(RenderWindow&, int, int, int,int);
void Champtxt(Event&, string&);
void reglage(RenderWindow&, Font, int&);
void Defaut(String&, String&, String&, String&);
void Enregistrer(String&, String&, String&, String&);
void Verif(int&, int&, int&, int&, int&);

#endif
