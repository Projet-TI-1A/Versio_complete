#include <SFML/Graphics.hpp>
#include <iostream>
#include "Fin.h"
#include "resultat.h"


using namespace sf;
using namespace std;


void affichage_fin(RenderWindow& window, int& gamemode, int erreurs, int points, int& n)
{
	
	Event event;
	while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				{window.close();}
			
			if (event.type == Event::KeyPressed)
			{
				if ((event.key.code == Keyboard::Q) or (event.key.code == Keyboard::N))
				{
					window.close();
				}
			}
		}
	affichage_erreur(points, erreurs, window, n);
}
