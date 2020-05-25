#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <ctime>
#include "resultat.h"

using namespace std;
using namespace sf;

/****Ce fichier traite les information récupéréees pendant la simulation et leur affichage****/

void affichage_erreur(int nbzones, int* points, int* erreurs, RenderWindow& window, int* n, time_t* temps)
{
	//calcul le pourcentage d'incisions a l'interieur de la zone
	int erreurstot=0,pointstot=0;
		
	for(int i=0;i<nbzones;i++)
		{
		n[i+1]=100*float((points[i]-erreurs[i])/float(points[i]+erreurs[i]));
		erreurstot+=erreurs[i];
		pointstot+=points[i];
		}
	
	n[0]=100*abs(float(pointstot-erreurstot)/float(pointstot+erreurstot));
	
	// Conversion de l'entier
	char nb[4], tps[4];
	sprintf(tps, "%ld", temps[0]); 
 	
 	//chargement de la police
 	Font font;
	if (!font.loadFromFile("Arimo-Regular.ttf"))
		{cout<<"erreur chargement police"<<endl;}
	
	Text text;
	Text text2;
	
	//affichage du pourcentage d'erreur totale
	text.setFont(font);
	text.setString("Pourcentage d'incisions a l'interieur de la zone : ");
	text.setCharacterSize(16);
	text.setFillColor(Color::White);
	text.setPosition(0,0);
	window.draw(text);
	
	sprintf(nb, "%d", n[0]);
	text.setString(nb);
	text.setPosition(340,0);
	window.draw(text);
	text.setString("%");
	text.setPosition(360,0);
	window.draw(text);
	
	//affichage du pourcentage d'erreur zone par zone
	/*for(int i=1;i<nbzones;i++)
	{
	text.setFont(font);
	text.setString("Pourcentage d'incisions a l'interieur de la zone ");
	text.setCharacterSize(16);
	text.setFillColor(Color::White);
	text.setPosition(0,i*20);
	window.draw(text);
	
	sprintf(nb, "%d", i+1);
	text.setString(nb);
	text.setPosition(360,i*20);
	window.draw(text);
	
	sprintf(nb, "%d", n[i]);
	text.setString(nb);
	text.setPosition(390,i*20);
	window.draw(text);}*/
	
	//affichage du temps de simulation
	text2.setFont(font);
	text2.setString("Temps de simulation:");
	text2.setCharacterSize(16);
	text2.setFillColor(Color::White);
	text2.setPosition(0,60);
	window.draw(text2);
	text2.setString(tps);
	text2.setPosition(150,60);
	window.draw(text2);
	text2.setString("secondes");
	text2.setPosition(180,60);
	window.draw(text2);
}

/****************************************************************************************/

//calcule une durée (durée de la simulation totale ou zone par zone)

int chronosimul(time_t temps_debut)
{
	//temps en secondes
	time_t temps_fin;
	time_t temps_operation;  
	
	time(&temps_fin); 
	temps_operation = temps_fin-temps_debut;

	return temps_operation;
}
