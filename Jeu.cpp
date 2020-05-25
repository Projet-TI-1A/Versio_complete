#include <SFML/Graphics.hpp>
#include <iostream>
#include "interface.h"
#include "toucher.h"
#include "zone.h"
#include "parametre.h"
#include "air.h"
#include <vector>
#include "ligne.h"
#include <math.h>
#include <unistd.h>
#include "resultat.h"
#include <fstream>
#include "Fin.h"
#include "Jeu.h"

#include <ctime>
#include <time.h>


using namespace std;
using namespace sf;

/**************Ce fichier contient le coeur de la simulation: la dissection de la tumeur à travers les différentes zones**************/

//simulation de la dissection

void simulation(RenderWindow& window,int& x,int& y,int& E,int& k,int& Dessin,int& e,int& ligneX,int& ligneY,int* airetotale,int& aire,int * points, int* erreurs, tabpoint& tab_point,tabpoint& tab_erreur,int** tab_pixel,Texture& texture,Sprite& sprite,point& p1, ligne& l1, ligne& l2, int& gamemode, time_t& chrono, int R, int condition80, int condition95, int nbzone)
{
		//initialisation des variables
		int H,m=0;
		time_t temps_debut, temps_debut_zone; 
		time(&temps_debut); 
		time(&temps_debut_zone);
		Event event;
		
		window.clear();
		window.draw(sprite);
		Grand_cercle(window);
		l1.Position_ligne(window);
		l2.Position_ligne(window);
		
		window.display();	
		
		

	while(k<nbzone and gamemode==1)//tant que toutes les zones ne sont pas complétées et que la simulation est en cours
	{
		
		
		if (window.pollEvent(event))
		{
			if (event.type == Event::Closed)//si l'on souhaite quitter le jeu
				{window.close();
				gamemode=10;}
			
			
			if (event.type == Event::KeyPressed)
			{
				if ((event.key.code == Keyboard::Q) || (event.key.code == Keyboard::N))
					{window.close();
					gamemode=10;}
				
				if (event.key.code == Keyboard::B)//on active le bistouri éléctrique
				{	
							

					Position_Curseur(x, y, window);//on place le curseur la où il y a contact avec un pixel
					p1.set(x,y); 
					if (zone(k, x, y, xcentre, ycentre, r, R, e)==1)//si celui-ci est dans la bonne zone
						{
						tab_point.append(p1);
						points[k]++;
						remplissage(k,x, y, xcentre,ycentre, r, R, e, aire, tab_pixel); 
						}
					if (zone(k, x, y, xcentre, ycentre, r, R, e)==2)//si celui-ci n'est pas dans la bonne zone
						{
						tab_erreur.append(p1);
						erreurs[k]++;
						}
					if (aire_completee(aire, airetotale[k], condition80, condition95)==2)//si la zone en cours de dissection est totalement completée
					{
						//on passe a la zone suivante (avec le k indice de la zone)
						k+=1;
						//réinitialisation des tableaux
						aire=0;
						m=0;
						tab_point.reset();
						tab_erreur.reset();
						for (int i = 0; i < e; i++)
						for(int j = 0; j < L; j++)
								{tab_pixel[i][j]=0;}
						//reinitialisation du chrono
						chrono[k]=chronosimul(temps_debut_zone);
						time(&temps_debut_zone);
						
						//déplacement des lignes délimitant la zone
						ligneX= xcentre +r-(k+1)*e;
						l1.set(xcentre+r-(k+1)*e, ligneY);
						l2.set(xcentre+r-(k+1)*e+e, ligneY);
						
						//affichage et mise à jour de la simulation
						window.clear();
						window.draw(sprite);
						Grand_cercle(window);
						l1.Position_ligne(window);
						l2.Position_ligne(window);
						ZoneFinie(window, k, e, xcentre, ycentre, r);
						window.display();
						sleep(1);
					}
					
					//si la zone est pratiquement completée, on affiche alors en vert les pixels restants afin qu'ils soient plus visibles
					if (aire_completee(aire, airetotale[k], condition80, condition95)==1  && m==0)
						{
							//reperage des pixels restants
							for (int i=0;i<e;i++){
								for (int y=0;y<l;y++)
								{
									if (tab_pixel[i][y]==0)

									{
										H=(xcentre-(i+(xcentre+r-e*(k+1))))*(xcentre-(i+(xcentre+r-e*(k+1))))+(ycentre-y)*(ycentre-y);
										if (i+(xcentre+r-e*(k+1)>=xcentre+r-(k+1)*e) && (i+(xcentre+r-e*(k+1))<=xcentre+r-k*e-R/2) && (H<=r*r-R/2))
										{
											//remplissage des pixels restants en une couleur différente
											Dessine_restant(k,i,y, e, r, R, xcentre, window);
										}	
									}
								}
							}
							m=1;
						}
					//on dessine les points corrects et les erreurs
					Dessine_plus_points(tab_point, tab_erreur, window, R);
					//actualisation de la fenetre
					window.display();
				}
				
				//on recommence la simulation
				if(event.key.code == Keyboard::Comma)
				{
					restart(tab_point, tab_erreur,k,temps_debut,l1, l2,aire,e,ligneX,ligneY,tab_pixel);
				}
					
			}
		
		}
	
	}
	//si on a completé toutes les zones, on arrete le chrono et on passe au mode suivant
	if (k>=nbzone) {  chrono[0]=chronosimul(temps_debut); gamemode=2;}	
}


/******************************************************************************/

//Initialisation des variables necessaires pour la simulation

void init_jeu(RenderWindow& window,int& x,int& y,int& E,int& k,int& Dessin,int& e,int& ligneX,int& ligneY,int* airetotale,int& aire,int * points, int* erreurs, Texture& texture,Sprite& sprite, ligne& l1, ligne& l2,time_t* chrono int nbzone, int& R)

{
	k=0;//indice de la zone dans laquelle on se trouve
	Dessin = false;
	
	e=2*int(r/nbzone);//epaisseur des zones
	ligneX= xcentre +r-(k+1)*e;
	ligneY=20;
	
	aire=0;
	E = e+1;
	
	for (int i = 0; i < nbzone; i++)
	{
	airetotale[i] = calculaire(i,e,l,xcentre, ycentre, r, R); //aire totale de chaque zone
	points[i]=0; //nombre de points corrects
	erreurs[i]=0;	//nombre d'erreurs
	chhrono[i]=0
	}
	
	
	l1.set(xcentre+r-(k+1)*e, ligneY);
	l2.set(xcentre+r-(k+1)*e+e, ligneY);
	
	if (!texture.loadFromFile("background_im2.jpg", sf::IntRect(0,0,490,340)))
	{ /* Erreur*/ }
	
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(1.5f,1.5f));
	sprite.setPosition(0,0);
	
}

/*********************************************************************************/

//fonction permettant de recomencer la simulation

void restart(tabpoint& t1, tabpoint& t2, int& k, time_t chrono, ligne& l1, ligne& l2,int& aire, int e, int ligneX, int ligneY, int** tab_pixel)
{
	k=0;
	time(&chrono);
	t1.reset();
	t2.reset();
	aire=0;
	l1.set(xcentre+r-(k+1)*e, ligneY);
	l2.set(xcentre+r-(k+1)*e+e, ligneY);
	for (int i = 0; i < e; i++)
		{ for(int j = 0; j < L; j++)
			{tab_pixel[i][j]=0;}
		}
}

/************************************************************************************/

//initialisation des paramètres réglables par l'utilisateur via le menu

void Initpara(int& nbzone, int& R, int& Condition80, int& Condition95, int& temps)
{
	ifstream Param("PARAMETRE.txt");
	
	if(Param)
	{
	//nbzone: nombre de zone 
	//R:taille du coté du curseur(carré)
	//Coondition95: condition à partir de laquelle on affiche les pixels restants isolés 
	//Condition95: pourcentage d'aire completée pour passer à la zone suivante 
	Param >> nbzone >> R >> Condition80 >> Condition95 >> temps;
	}
	
	else
	{
		cout << "Erreur, impossible d'ouvrir le fichier" << endl;
	}
}
