#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Jeu.h"
#include "interface.h"
#include "toucher.h"
#include "zone.h"
#include "parametre.h"
#include "air.h"
#include "ligne.h"

using namespace std;
using namespace sf;

int main()
{
	int gamemode=1;
	int x, y, E, k, Dessin, e, ligneX, ligneY, airetotale[nbzone], aire;
	tabpoint tab_point;
	tabpoint tab_erreur;
	int **tab_pixel;
	ligne l1, l2;
	sf::Texture background;
	sf::Sprite sprite;
	
	point p1;
	
	RenderWindow window(VideoMode(480,320), "SFML works!"/*,Style::Fullscreen*/);
	
	init_jeu(window, x, y, E, k, Dessin, e, ligneX, ligneY, airetotale, aire, tab_pixel, background, sprite, p1, l1, l2);
	
	cout << "okay" << endl;
	
	while (window.isOpen()) //Boucle principale du programme
	{
		window.clear();
		switch(gamemode) //En fonction de gamemode, indique la phase du programme
		{
			case 0:
			//Menu	
			break;
			
			case 1:
			simulation(window, x, y, E, k, Dessin, e, ligneX, ligneY, airetotale, aire, tab_point, tab_erreur, tab_pixel, background, sprite, p1, l1, l2, gamemode);
			break;
			
			case 2:
			//Phase de fin/résutats
			break;
			
		}
		
		
		window.display();
	}
	return 0;
}
