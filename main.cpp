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

#include "Fin.h"
#include <ctime>
#include <time.h>
#include <unistd.h>

#include "basededonnees.h"
#include <sqlite3.h> 

using namespace std;
using namespace sf;

int main()
{
	//on crée toutes les varibles necéssaires aux fonction
	int gamemode=0;
	int points[nbzonemax], erreurs[nbzonemax];
	int x, y,E,k, Dessin;
	tabpoint tab_point;
	tabpoint tab_erreur;
	int e;
	int ligneX, ligneY;
	int* airetotale;
	int aire;
	sf::Texture background;
	sf::Sprite sprite;
	point p1;
	ligne l1(0,0), l2(0,0);
	string Nom, Age, Formation, Niveau, Prenom, Prenom2, Endoscope;
	string temps;
	string erreurstr[nbzonemax];
	time_t temps_simul[nbzonemax];
	int n[nbzonemax];
	int ind=1;
	int R, condition80, condition95, nbzone,/*a ajouter pour le tempsmax*/ tempsmax;

	SQLBASE objet1;
	SQLBASE2 objet2;
	
	
	
	//on crée la fenetre
	RenderWindow window(VideoMode(L,l), "SFML works!"/*,Style::Fullscreen*/);
	
	//Boucle principale
	int i=0;
	if (window.isOpen())
	{
	
		window.clear();
		
		//selon la valeur de gamemode, on change de phase de jeu
		if (gamemode==0)
		{
			menu(window, Prenom, Prenom2, Nom, Age, Formation, Niveau, Endoscope, gamemode, ind);
			
			
			//initialisation de la base de données
			objet1.SQLinitialisation(Nom,Prenom,Prenom2);
			objet2.SQLinitialisation2(Age,Formation,Niveau,Endoscope);
		}
		if (gamemode==1)	
		{
			//on initialise les variables liées a la parties simulation
			
			Initpara(nbzone, R, condition80, condition95,/*a ajouter pour le tempsmax*/ tempsmax);
			
			/******************/
			airetotale= new int[nbzone];
			/*****************/
			
			init_jeu( window, x, y, E, k, Dessin, e, ligneX, ligneY, airetotale, aire, points, erreurs, background, sprite, l1, l2,temps_simul, nbzone, R);
			
			/*********************************/
			int **tab_pixel = new int* [E];
			for (int i = 0; i < E; i++)
			{tab_pixel[i] = new int[L];}
			/*********************************/
			
			simulation(window,x,y,E,k,Dessin,e,ligneX,ligneY, airetotale, aire, points, erreurs, tab_point, tab_erreur, tab_pixel, background, sprite, p1, l1, l2, gamemode, temps_simul, R, condition80, condition95, nbzone);
		}
		
		 if (gamemode==2)	
		{
			affichage_fin(window, nbzone, gamemode, erreurs, points, n, temps_simul);

			//remplissage des résultats et des incrémentations de test de la base de données
			objet1.SQLcompteur(ind);
			objet1.SQLrequete(ind);
		

			objet2.SQLrecupererResults(temps,erreurstr[0],"fini");
			objet2.SQLrecupererid(objet1);
			objet2.SQLrecupererCompteur(ind,objet1);
			objet2.SQLrequete2();
		}
		
		if (gamemode==10)
		{return 0;}
		
		window.display();
		sleep(10);
		
	}
	return 0;
}
