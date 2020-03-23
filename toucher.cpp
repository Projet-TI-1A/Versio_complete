#include <SFML/Graphics.hpp>
#include <iostream>
#include "toucher.h"
#include "interface.h"


using namespace std;
using namespace sf;

void Position_Curseur(int *x, int *y, RenderWindow& window)
//Récupère la postion de la souris relative à la fenêtre
{
	Vector2i localPosition = Mouse::getPosition(window);
	*x = localPosition.x;
	*y = localPosition.y;
}

/*******************************************************************************/

void Ajoute_point(vector<point> tab_point, int* taille, RenderWindow& window)
{
	int x, y;
	point p1;
	Position_Curseur(&x, &y, window);
	p1.set(x,y);
	
	tab_point.push_back(p1);
	*taille = *taille + 1 ;
	tab_point.push_back(p1);
}

/*********************************************************************************/

void point::set(int x, int y)
{
	this->x=x;
	this->y=y;
}

void point::get(int& x, int& y)
{
	x=this->x;
	y=this->y;
}

point::point(){}

point::point(int x, int y)
{
	this->x=x;
	this->y=y;
}

void point::Dessine_point(RenderWindow& window, int cote,int Red, int Green, int Blue)
//Dessine un point de taille Rpx à la position (x,y)
{
	RectangleShape carre(Vector2f(cote, cote));
	carre.setFillColor(Color(Red, Green, Blue));
	carre.setPosition(x-int(cote/2),y-int(cote/2));
	window.draw(carre);

}
/*******************************************************************************/

tabpoint::tabpoint(){taille=0;}

void tabpoint::append(point& p)
{
	this->tab.push_back(p);
	taille++;
}

void tabpoint::get(point& p, int i)
{
	int x,y;
	tab[i].get(x, y);
	p.set(x, y);
}

int tabpoint::gettaille()
{
	return(taille);
}


void tabpoint::reset()
{
	this->tab.clear();
	this->taille=0;
}

void tabpoint::Dessine_plus_points(RenderWindow& window,int cote, int Red, int Green, int Blue)
{
	point p1;
	int i;
	
	for (i=0; i<this->taille; i++)
	{
		tab[i].Dessine_point(window, cote, Red, Green, Blue);
	}
}
/********************************************************************************/

void restart(tabpoint& t1, tabpoint& t2, int& k, int& chrono)
{
	k=0;
	chrono=0;
	t1.reset();
	t2.reset();
	
}












