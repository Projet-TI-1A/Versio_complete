#include "ligne.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

/*****************fonctions de la classe ligne***********************/

//Permet d'afficher la ligne à la position (x,y)
void ligne::Position_ligne(RenderWindow& window)

{
	int x, y;
	get(x,y);
	RectangleShape line(Vector2f(450,5));
	line.rotate(90);
	line.setPosition(x,y);
	line.setFillColor(Color::Red);
	window.draw(line);
}

//Permet regler les coordonées de la ligne
ligne::ligne(int x, int y)
{
	set(x,y);
}
