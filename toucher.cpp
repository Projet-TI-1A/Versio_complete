#include <SFML/Graphics.hpp>
#include <iostream>
#include "toucher.h"
#include "interface.h"
#include <ctime>
#include <time.h>

using namespace std;
using namespace sf;

/************ Ce fichier contient les fonction qui récupèrent et traitent les données récupérées de l'écran*************/

//Récupère la postion de la souris relative à la fenêtre
void Position_Curseur(int& x, int& y, RenderWindow& window)
{
	Vector2i localPosition = Mouse::getPosition(window);
	x = localPosition.x;
	y = localPosition.y;
}

/*******************************************************************************/

//Ajoute un point au tableau qui collecte les points de l'écran touchés (tableau comptant les erreuurs ou les points corrects)

void Ajoute_point(vector<point> tab_point, int* taille, RenderWindow& window)
{
	int x, y;
	point p1;
	Position_Curseur(x, y, window);
	p1.set(x,y);
	
	tab_point.push_back(p1);
	*taille = *taille + 1 ;
	tab_point.push_back(p1);
}

/*******************fonctions de la classe point**************************************************************/

//constructeur
point::point(){}

point::point(int x, int y)
{
	this->x=x;
	this->y=y;
}

//implemente des valeurs à un point
void point::set(int x, int y)
{
	this->x=x;
	this->y=y;
}

//permet acceder aux coordonnées d'un point
void point::get(int& x, int& y)
{
	x=this->x;
	y=this->y;
}


/*************************fonction de la classe tabpoint (tableau comtenant des points)************************************/

//constructeur
tabpoint::tabpoint(){taille=0;}

//ajoute un point
void tabpoint::append(point& p)
{
	this->tab.push_back(p);
	taille++;
}

//donne acces au ième point du tableau
void tabpoint::get(point& p, int i)
{
	int x,y;
	tab[i].get(x, y);
	p.set(x, y);
}

//donne la taille du tableau
int tabpoint::gettaille()
{
	return(taille);
}

//réinitialise le tableau
void tabpoint::reset()
{
	this->tab.clear();
	this->taille=0;
}

/*******************************************************************************/
