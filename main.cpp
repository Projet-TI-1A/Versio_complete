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
#include <math.h>
#include "Menu.h"
#include "resultat.h"

using namespace std;
using namespace sf;

int main()
{
	//on crée toutes les varibles necéssaires aux fonction
	int gamemode=0;
	int points, erreurs;
	int x, y,E,k, Dessin;
	tabpoint tab_point;
	tabpoint tab_erreur;
	int e=2*int(r/nbzone);
	int ligneX, ligneY;
	int airetotale[nbzone];
	int aire;
	sf::Texture background;
	sf::Sprite sprite;
	point p1;
	ligne l1(0,0), l2(0,0);
	Text text, text2;
	String Nom;
	int chrono = 0;
	//on crée la fenetre
	RenderWindow window(VideoMode(480,320), "SFML works!"/*,Style::Fullscreen*/);
	
	//on initialise les variables liées a la parties simulation
	init_jeu( window, x, y, E, k, Dessin, e, ligneX, ligneY, airetotale, aire, points, erreurs, background, sprite, l1, l2);
	
	
	//sauf celle ci qu'on initialise ici sinon ca marche pas
	int **tab_pixel = new int* [E];
	for (int i = 0; i < E; i++)
	{tab_pixel[i] = new int[L];}
	
	//Boucle principale
	
	while (window.isOpen())
	{
		window.clear();
		
		//selon la valeur de gamemode, on change de phase de jeu
		switch(gamemode)
		{
			case 0:
			menu(window, text, text2, Nom, gamemode);
			break;
			
			case 1:
			simulation(window,x,y,E,k,Dessin,e,ligneX,ligneY, airetotale, aire, points, erreurs, tab_point, tab_erreur, tab_pixel, background, sprite, p1, l1, l2, gamemode, chrono);
			break;
			
		}
		
		window.display();
	}
	return 0;
}
