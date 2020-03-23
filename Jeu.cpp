#include <SFML/Graphics.hpp>
#include <iostream>
#include "interface.h"
#include "toucher.h"
#include "zone.h"
#include "parametre.h"
#include "air.h"
#include <vector>
#include "ligne.h"

using namespace std;
using namespace sf;


void simulation(RenderWindow& window,int& x,int& y,int& E,int& k,int& Dessin,int& e,int& ligneX,int& ligneY,int* airetotale,int aire,tabpoint& tab_point,tabpoint& tab_erreur,int** tab_pixel,Texture& texture,Sprite& sprite,point& p1, ligne l1, ligne l2, int& gamemode)
{
		int temps_debut = clock();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::B)
				{
					Dessin = true;
				}
				
				if ((event.key.code == Keyboard::Q) or (event.key.code == Keyboard::N))
				{
					window.close();
				}
			}
			
			
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::B)
				{
					Dessin = false ;
				}
				
				if(event.key.code == Keyboard::Comma)
				{
					restart(tab_point, tab_erreur, k, temps_debut);
				}
			}
		}
		
			if (Dessin)
			{
				Position_Curseur(&x, &y, window);
				p1.set(x,y);
				cout << "okay2" << endl;
				if (zone(k, x, y, xcentre, ycentre, r, e))
					{
					cout << tab_point.gettaille() << endl;
					tab_point.append(p1);
					cout << tab_point.gettaille() << endl;
					//remplissage(k,x, y, xcentre,ycentre, r, R, e, aire, tab_pixel);
					cout << tab_point.gettaille() << endl;
					}
				else
					{
					tab_erreur.append(p1);
					cout << tab_erreur.gettaille() << endl;
					}
				
				
				switch (aire_completee(aire, airetotale[k], condition80, condition95) )
				//en fonction de l'aire on fait telle action mais on teste pas les autres
				{
					case 2: //95%
					cout << "bonjour" << endl;
					k+=1;
					//réinitialisation des tableaux
					aire=0;
					ligneX= xcentre +r-(k+1)*e;
					tab_point.reset();
					tab_erreur.reset();
					cout << "bonjour2" << endl;
					for (int i = 0; i < e; i++)
						for(int j = 0; j < L; j++)
							{tab_pixel[i][j]=0;}
					cout << "bonjour3" << endl;
					break;
					case 1 : //80%
					//mettre les carrés verts?
					break;
					
				}
			
			}
/*
		for (int i = 0; i < L; i++)
			{delete [] tab_pixel[i];
  			delete [] tab_pixel;}
		*/
		Grand_cercle(window);
		
		l1.set(xcentre+r-(k+1)*e, ligneY);
		l2.set(xcentre+r-(k+1)*e+e, ligneY);
		
		l1.Position_ligne(window);
		l2.Position_ligne(window);
		
		tab_point.Dessine_plus_points(window, R, 200,150,246);
		tab_erreur.Dessine_plus_points(window, R, 255,0,0);
		/*test_fin(aire_completee(aire,airetotale[nbzone],condition95,condition80),temps_debut);*/
	
}

/******************************************************************************/

void init_jeu(RenderWindow& window,int& x,int& y,int& E,int& k,int& Dessin,int& e,int& ligneX,int& ligneY,int* airetotale,int aire,int** tab_pixel,Texture& texture,Sprite& sprite,point& p1, ligne l1, ligne l2)

{
	Dessin = false;
	k=0;
	e=2*int(r/nbzone);
	ligneX= xcentre +r-(k+1)*e, ligneY=20;
	aire=0;
	E = e+1;
	tab_pixel = new int* [E];
	for (int i = 0; i < E; i++)
	{
		tab_pixel[i] = new int[L];
	}
	
	for (int i = 0; i < nbzone; i++)
	{
		airetotale[i] = calculaire(i,e,l,xcentre, ycentre, r, R);
	} 
	
	if (!texture.loadFromFile("background_im22.jpg", sf::IntRect(0,0,480,320)))
	{ /* Erreur*/ }
	
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(1.5f,1.5f));
	
	l1.set(ligneX, ligneY);
	l2.set(ligneX+e, ligneY);
}

/*********************************************************************************/




