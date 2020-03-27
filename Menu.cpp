#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"

using namespace sf;
using namespace std;


void menu(RenderWindow& window, Text& text, Text& text2, string& Nom, int& gamemode)
{
	Event event;
	Font font;
	if (!font.loadFromFile("Arimo-Regular.ttf"))
	{
	// erreur...
	}
	text.setFont(font);
	text.setString("Bienvenue dans la simulation\nVeuillez entrer votre nom et prenom");
	text.setCharacterSize(24); // exprimée en pixels, pas en points !
	text.setFillColor(Color::White);
	
	char lettre;
	
	text2.setFont(font);
	text2.setCharacterSize(24); // exprimée en pixels, pas en points !
	text2.setFillColor(Color::Red);
	text2.setPosition(10, 150);
	
	while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Return)
				{
					gamemode=1;
				}
			}
			
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode < 128)
				{
					lettre=event.text.unicode;
					Entreetext(Nom, lettre);
				}
			}
		}
	text2.setString(Nom);
	window.draw(text);
	window.draw(text2);
}

/**********************************************************************************/

void Entreetext(string& Nom, char lettre)
{
	Nom.push_back(lettre);

}











