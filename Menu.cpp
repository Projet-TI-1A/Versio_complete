#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"

using namespace sf;
using namespace std;


void menu(RenderWindow& window, Text& text, Text& text2, String& Nom, int& gamemode)
{
	
	Event event;
	Font font;
	if (!font.loadFromFile("Arimo-Regular.ttf"))
	{
	// erreur...
	}
	text.setFont(font);
	text.setString(L"Bienvenue dans la simulation\nVeuillez entrer votre nom et prénom");
	text.setCharacterSize(24); // exprimée en pixels, pas en points !
	text.setFillColor(Color::White);
	
	
	text2.setFont(font);
	text2.setCharacterSize(24); // exprimée en pixels, pas en points !
	text2.setFillColor(Color::Red);
	text2.setPosition(10, 150);
	 while (gamemode==0)
	 {
	if (window.pollEvent(event))
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
				if (event.text.unicode==8)
				{
					Nom.erase(Nom.getSize()-1,1);
				}
				else
				{
					Nom+=event.text.unicode;
				}
			}
		
		}
	
	text2.setString(Nom);
	window.draw(text);
	window.draw(text2);
	window.display();
	
}
}

/**********************************************************************************/













