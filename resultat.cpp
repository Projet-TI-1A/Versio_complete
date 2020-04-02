#include <SFML/Graphics.hpp>
#include <iostream>
#include "resultat.h"


using namespace std;
using namespace sf;


void compt_erreur( int& points, int& erreurs,tabpoint tab, tabpoint erreur){
	points+=tab.gettaille();
	erreurs+=erreur.gettaille();
}

void affichage_erreur(int points, int erreurs, RenderWindow& window){
	//calcul le pourcentage d'incisions a l'interieur de la zone
	int n=points*100/float(points+erreurs);
	// Conversion de l'entier
	char nb[4];
 	sprintf(nb, "%d", n); 
 	Font font;//chargement de la police
	if (!font.loadFromFile("arial.ttf"))
		{cout<<"erreur chargement police"<<endl;}
	Text text;
	text.setFont(font);
	text.setString("Pourcentage d'incisions a l'interieur de la zone:");
	text.setCharacterSize(16);
	text.setFillColor(Color::White);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	window.draw(text);
	text.setString(nb);
	text.setPosition(390,0);
	window.draw(text);
	
}