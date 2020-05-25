#include <SFML/Graphics.hpp>
#include <iostream>
#include "Fin.h"
#include "resultat.h"


using namespace sf;
using namespace std;

/****** ce fichier contient les fonction permettant d'afficher les données a l'utilisateur à la fin de simulation****/

void affichage_fin(RenderWindow& window,int nbzone, int& gamemode, int* erreurs, int* points, int* n, time_t* temps)
{
	
	Event event;
	window.clear();
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
	affichage_erreur(nbzone, points, erreurs, window, n, temps);
}
