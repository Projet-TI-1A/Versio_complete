#include <SFML/Graphics.hpp>
#include <iostream>
#include "resultat.h"

#include <fstream>

#include <ctime>


using namespace std;
using namespace sf;


void compt_erreur( int& points, int& erreurs,tabpoint tab, tabpoint erreur)
{
	points+=tab.gettaille();
	erreurs+=erreur.gettaille();
}

void affichage_erreur(int points, int erreurs, RenderWindow& window, int& n, time_t& temps)
{
	//calcul le pourcentage d'incisions a l'interieur de la zone
	n=float(points/float(points+erreurs))*100;
	
	// Conversion de l'entier
	char nb[4], tps[4];
 	sprintf(nb, "%d", n);
	sprintf(tps, "%ld", temps); 
 	Font font;//chargement de la police
	if (!font.loadFromFile("Arimo-Regular.ttf"))
		{cout<<"erreur chargement police"<<endl;}
	Text text,text2;
	text.setFont(font);
	text.setString("Pourcentage d'incisions a l'interieur de la zone:");
	text.setCharacterSize(16);
	text.setFillColor(Color::White);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	window.draw(text);
	text.setString(nb);
	text.setPosition(390,0);
	window.draw(text);

	text2.setFont(font);
	text2.setString("temps de simulation");
	text2.setCharacterSize(16);
	text2.setFillColor(Color::White);
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text2.setPosition(0,50);
	window.draw(text2);
	text2.setString(tps);
	text2.setPosition(390,50);
	window.draw(text2);
}

/**************************************************************************/

void Envoi(String Nom, String Age, String Formation, String Niveau, time_t& chrono, int& n)
{
	ofstream Res ("RESULTAT.txt",ios::app);
	//Nom.erase(Nom.getSize()-1,1);
	//Age.erase(Age.getSize()-1,1);
	
	string text=Nom, age=Age, formation=Formation, niveau=Niveau;
	if (Res)
	{
	Res << text << "	" << age << "	" << formation << "	" << niveau <<"	" << chrono << "s	" << n << "%" << endl;
	}
	
	else
	{
		cout << "impossibe d'ouvrir le fichers" << endl;
	}
}




 

int chronosimul(time_t temps_debut)
{
//temps en secondes
time_t temps_fin; 
time_t temps_operation;  

time(&temps_fin); 
temps_operation = temps_fin-temps_debut;


return temps_operation;
}



