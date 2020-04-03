#include <SFML/Graphics.hpp>
#include <iostream>
#include "resultat.h"
#include <fstream>

using namespace std;
using namespace sf;


void compt_erreur( int& points, int& erreurs,tabpoint tab, tabpoint erreur)
{
	points+=tab.gettaille();
	erreurs+=erreur.gettaille();
}

void affichage_erreur(int points, int erreurs, RenderWindow& window, int& n)
{
	//calcul le pourcentage d'incisions a l'interieur de la zone
	n=float(points/float(points+erreurs))*100;
	
	// Conversion de l'entier
	char nb[4];
 	sprintf(nb, "%d", n); 
 	Font font;//chargement de la police
	if (!font.loadFromFile("Arimo-Regular.ttf"))
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

/**************************************************************************/

void Envoi(String Nom, int chrono, int& n)
{
	ofstream Res ("RESULTAT.txt",ios::app);
	Nom.erase(Nom.getSize()-1,1);
	string text=Nom;
	
	if (Res)
	{
	Res << text << "	" << chrono << "s	" << n << "%" << endl;
	}
	
	else
	{
		cout << "impossibe d'ouvrir le fichers" << endl;
	}
}






















