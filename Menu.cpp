#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "toucher.h"

using namespace sf;
using namespace std;


void menu(RenderWindow& window, string& Prenom, string& Prenom2, string& Nom, string& Age, string& Formation, string& Niveau, string& Endoscope, int& gamemode, int& ecran)
{
	Font font;
	if (!font.loadFromFile("Arimo-Regular.ttf"))
	{
	// erreur...
	}
	
	Text text, text2, text3, text4;
	
	text.setFont(font);
	text.setCharacterSize(24); // exprimée en pixels, pas en points !
	text.setFillColor(Color::White);
	
	text2.setFont(font);
	text2.setCharacterSize(24); // exprimée en pixels, pas en points !
	text2.setFillColor(Color::Red);
	text2.setPosition(10, 150);
	
	text3.setFont(font);
	text3.setString(L"Non défini");
	text3.setFillColor(Color::Black);
	text3.setCharacterSize(24);
	text3.setPosition(300,240);
	
	text4.setFont(font);
	text4.setString(L"Retour");
	text4.setFillColor(Color::Black);
	text4.setCharacterSize(24);
	text4.setPosition(80,240);
	
	Text text5;
	text5.setFont(font);
	text5.setString(L"Chirurgien");
	text5.setFillColor(Color::Black);
	text5.setCharacterSize(24);
	text5.setPosition(180,60);
	
	Text text6;
	text6.setFont(font);
	text6.setString(L"Expert");
	text6.setFillColor(Color::Black);
	text6.setPosition(205,180);
	text6.setCharacterSize(24);
	

	while (gamemode==0)
	{
	
		switch (ecran)
		{
		
		case 0:
		menu0( window, text, text2, ecran);
		
		case 1:
		text.setString(L"Bienvenue dans la simulation\nVeuillez entrer votre prénom (sans accents)");
		menuprenom( window, text, text2, text3, text4, Prenom, ecran);
		break;
		
		case 2:
		text.setString(L"Bienvenue dans la simulation\nVeuillez entrer votre deuxième prénom \n(sans accents)");
		menuprenom2(window, text, text2, text3, text4, Prenom2, ecran);
		
		case 3:
		menunom( window, text, text2, text3, text4, Nom, ecran);
		break;
		
		case 4:
		menu3( window, text, text2, text3, text4, Age, ecran);
		break;
		
		case 5:
		menu4( window, text, text2, text3, text4, text5, Formation, ecran);
		break;
		
		case 6:
		menu5( window, text, text2, text3, text4, text5, text6, Niveau, ecran);
		break;
		
		case 7:
		menu6( window, text, text2, text3, text4, text5, Endoscope, ecran);
		
		case 8:
		gamemode=1;
		break;
		
		case 10:
		gamemode=10;
		break;
		
		case 15:
		reglage(window, font, ecran);
		break;
		}
		
		
	}
}

/**********************************************************************************/

void menu0(RenderWindow& window, Text& text, Text& text2, int& ecran)
{
	
	Event event;
	
	text.setString(L"Débuter la simulation");
	text.setFillColor(Color::Black);
	text.setPosition(120,85);
	
	text2.setString(L"Réglage");
	text2.setPosition(195, 210);
	text2.setFillColor(Color::Black);
	
	
	RectangleShape rectangle1(Vector2f(300, 50));
	rectangle1.setPosition(90,75);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(300, 50));
	rectangle2.setPosition(90,200);
	rectangle2.setFillColor(Color::White);
	
	while (ecran==0)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					int x, y;
					Position_Curseur(x, y, window);
					if (x>90 and x<(90+300))
					{
						if (y>75 and y<(75+50))
						{
							ecran += 1;
						}
						
						if (y>200 and y<(200+50))
						{
							ecran = 15;
						}
					}
				
				
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
		
		}
	
	window.clear();
	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(text);
	window.draw(text2);
	window.display();
	}
}


/**********************************************************************************/

void menuprenom(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, string& Prenom, int& ecran)
{
	
	Event event;
	
	text.setCharacterSize(24); // exprimée en pixels, pas en points !
	text.setFillColor(Color::White);
	text.setPosition(0,0);
	
	text2.setCharacterSize(24); // exprimée en pixels, pas en points !
	text2.setFillColor(Color::Red);
	text2.setPosition(10, 150);
	
	text2.setString(Prenom);
	text2.setFillColor(Color::Red);
	text2.setPosition(10, 150);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(290,230);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(50,230);
	rectangle2.setFillColor(Color::White);
	
	while (ecran==1)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Prenom, ecran, "Non_defini", 290, 230, 140, 50);
					Retour(window, ecran, 50, 230);
				}
			}
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
			
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Return)
				{
					ecran+=1;
				}
			}
			
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode==8)
				{
					Prenom.erase(Prenom.size()-1,1);
				}
				else
				{
					Prenom+=event.text.unicode;
				}
			}
		}
	
	text2.setString(Prenom);
	
	window.clear();
	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.display();
	}
}
/**********************************************************************************/

void menuprenom2(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, string& Prenom, int& ecran)
{
	
	Event event;
	
	text.setCharacterSize(24); // exprimée en pixels, pas en points !
	text.setFillColor(Color::White);
	text.setPosition(0,0);
	
	text2.setCharacterSize(24); // exprimée en pixels, pas en points !
	text2.setFillColor(Color::Red);
	text2.setPosition(10, 150);
	
	text2.setString(Prenom);
	text2.setFillColor(Color::Red);
	text2.setPosition(10, 150);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(290,230);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(50,230);
	rectangle2.setFillColor(Color::White);
	
	while (ecran==2)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Prenom, ecran, "Non_defini", 290, 230, 140, 50);
					Retour(window, ecran, 50, 230);
				}
			}
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
			
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Return)
				{
					ecran+=1;
				}
			}
			
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode==8)
				{
					Prenom.erase(Prenom.size()-1,1);
				}
				else
				{
					Prenom+=event.text.unicode;
				}
			}
		}
	
	text2.setString(Prenom);
	
	window.clear();
	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.display();
	}
}

/**********************************************************************************/

void menunom(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, string& Nom, int& ecran)
{
	
	Event event;
	
	text.setString(L"Bienvenue dans la simulation\nVeuillez entrer votre nom (sans accents)");
	text.setCharacterSize(24); // exprimée en pixels, pas en points !
	text.setFillColor(Color::White);
	text.setPosition(0,0);
	
	text2.setCharacterSize(24); // exprimée en pixels, pas en points !
	text2.setFillColor(Color::Red);
	text2.setPosition(10, 150);
	
	text2.setString(Nom);
	text2.setFillColor(Color::Red);
	text2.setPosition(10, 150);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(290,230);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(50,230);
	rectangle2.setFillColor(Color::White);
	
	while (ecran==3)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Nom, ecran, "Non_defini", 290, 230, 140, 50);
					Retour(window, ecran, 50, 230);
				}
			}
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
			
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Return)
				{
					ecran=4;
				}
			}
			
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode==8)
				{
					Nom.erase(Nom.size()-1,1);
				}
				else
				{
					Nom+=event.text.unicode;
				}
			}
		}
	
	text2.setString(Nom);
	
	window.clear();
	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.display();
	}
}

/*****************************************************************************/

void menu3(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, string& Age, int& ecran)
{
	
	Event event;
	
	text.setString(L"Veuillez rentrer votre âge :");
	
	text2.setString(Age);
	text2.setFillColor(Color::Red);
	text2.setPosition(10, 150);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(290,230);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(50,230);
	rectangle2.setFillColor(Color::White);
	
	while (ecran==4)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Age, ecran, "Non_defini", 290, 230, 140, 50);
					Retour(window, ecran, 50, 230);
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
			
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Return)
				{
					ecran=5;
				}
			}
			
			if (event.type == sf::Event::TextEntered)
			{
				if (event.text.unicode==8)
				{
					Age.erase(Age.size()-1,1);
				}
				else
				{
					Age+=event.text.unicode;
				}
			}
		}
	
	text2.setString(Age);
	
	window.clear();
	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.display();
	}

}

/********************************************************************************/

void menu4(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, Text& text5, string& Formation, int& ecran)
{
	
	Event event;
	
	text.setString(L"Veuillez selectionner votre formation :");
	
	text2.setString(L"Endoscopiste");
	text2.setPosition(165, 160);
	text2.setFillColor(Color::Black);
	
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(290,230);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(50,230);
	rectangle2.setFillColor(Color::White);
	
	RectangleShape rectangle3(Vector2f(160, 50));
	rectangle3.setPosition(160,150);
	rectangle3.setFillColor(Color::White);
	
	RectangleShape rectangle4(Vector2f(160, 50));
	rectangle4.setPosition(160,50);
	rectangle4.setFillColor(Color::White);
	
	while (ecran==5)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Formation, ecran, "Non_defini", 290, 230, 140, 50);
					Button(window, Formation, ecran, "Chirurgien", 160,50, 160, 50);
					Button(window, Formation, ecran, "Endoscopiste", 160,150, 160, 50);
					Retour(window, ecran, 50, 230);
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
		
		}
	
	window.clear();

	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(rectangle4);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(text5);
	window.display();
	}
}


/*******************************************************************************/

void menu5(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, Text& text5,Text& text6, string& Niveau, int& ecran)
{
	Event event;
	
	text.setString(L"Veuillez selectionner votre formation :");
	
	text2.setString(L"Intermédiaire");
	text2.setPosition(165, 120);
	text2.setFillColor(Color::Black);
	
	text3.setPosition(300, 260);
	
	text4.setPosition(80, 260);
	
	text5.setString(L"Novice");
	text5.setPosition(205, 60);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(290,250);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(50,250);
	rectangle2.setFillColor(Color::White);
	
	RectangleShape rectangle3(Vector2f(160, 50));
	rectangle3.setPosition(160,170);
	rectangle3.setFillColor(Color::White);
	
	RectangleShape rectangle4(Vector2f(160, 50));
	rectangle4.setPosition(160,50);
	rectangle4.setFillColor(Color::White);
	
	RectangleShape rectangle5(Vector2f(160, 50));
	rectangle5.setPosition(160,110);
	rectangle5.setFillColor(Color::White);
	
	while (ecran==6)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Niveau, ecran, "Non_defini", 290, 250, 140, 50);
					Button(window, Niveau, ecran, "Novice", 160,50, 160, 50);
					Button(window, Niveau, ecran, "Intermediaire", 160,110, 160, 50);
					Button(window, Niveau, ecran, "Expert", 160,170, 160, 50);
					Retour(window, ecran, 50, 250);
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
		
		}
	
	window.clear();

	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(rectangle4);
	window.draw(rectangle5);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(text5);
	window.draw(text6);
	window.display();
	}
}
/********************************************************************************/

void menu6(RenderWindow& window, Text& text, Text& text2, Text& text3, Text& text4, Text& text5, string& Formation, int& ecran)
{
	
	Event event;
	
	text.setString(L"Veuillez selectionner le type\nd'endoscope utilisé :");
	
	text2.setString(L"Robot");
	text2.setPosition(205, 185);
	text2.setFillColor(Color::Black);
	
	
	text5.setString(L"Manuel");
	text5.setPosition(205,110);
	
	RectangleShape rectangle1(Vector2f(140, 50));
	rectangle1.setPosition(290,250);
	rectangle1.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(140, 50));
	rectangle2.setPosition(50,250);
	rectangle2.setFillColor(Color::White);
	
	RectangleShape rectangle3(Vector2f(160, 50));
	rectangle3.setPosition(160,175);
	rectangle3.setFillColor(Color::White);
	
	RectangleShape rectangle4(Vector2f(160, 50));
	rectangle4.setPosition(160,100);
	rectangle4.setFillColor(Color::White);
	
	while (ecran==7)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					Button(window, Formation, ecran, "Non_defini", 290, 250, 140, 50);
					Button(window, Formation, ecran, "Manuel", 160,100, 160, 50);
					Button(window, Formation, ecran, "Robot", 160,175, 160, 50);
					Retour(window, ecran, 50, 230);
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
		
		}
	
	window.clear();

	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(rectangle4);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(text5);
	window.display();
	}
}

/*******************************************************************************/

void Button(RenderWindow& window, string& text, int& ecran, string string,int coordx,int coordy,int taillex,int tailley)
{
	int x, y;
	Position_Curseur(x, y, window);
	if (x>coordx and x<(coordx+taillex))
	{
		if (y>coordy and y<(coordy+tailley))
		{
			text=string;
			ecran += 1;
		}
	}
}

/******************************************************************************/

void Retour(RenderWindow& window, int& ecran,int coordx,int coordy)
{
	int x, y;
	Position_Curseur(x, y, window);
	
	if (x>coordx and x<(coordx+140))
	{
		if (y>coordy and y<(coordy+50))
		{
			ecran -= 1;
		}
	}
}

/******************************************************************************/

bool Button(RenderWindow& window, int coordx, int coordy, int taillex,int tailley)
{
	int x, y;
	Position_Curseur(x, y, window);
	if (x>coordx and x<(coordx+taillex))
	{
		if (y>coordy and y<(coordy+tailley))
		{
			return(true);
		}
	}
	
	return(false);
}

/******************************************************************************/

void Champtxt(Event& event, String& string)
{
	if (event.text.unicode==8)
	{
		string.erase(string.getSize()-1,1);
	}
	else
	{
		string+=event.text.unicode;
	}
}

/******************************************************************************/

void reglage(RenderWindow& window, Font font,int& ecran)
{
	int var=-1;
	
	String Nbzones, R, Condition80, Condition95;
	
	Event event;
	
	Text text, text2, text3, text4, text5, text6, text7, text8, text9, text10, text11, text12;
	
	text.setFont(font);
	text.setCharacterSize(15);
	text.setFillColor(Color::White);
	text.setString(L"Appuyer sur le rectangle blanc correspondant au\nparamètre à changer, puis taper au clavier.");
	
	text2.setFont(font);
	text2.setCharacterSize(15);
	text2.setFillColor(Color::White);
	text2.setString(L"Nombre de zones :");
	text2.setPosition(20,50);
	
	text3.setFont(font);
	text3.setCharacterSize(15);
	text3.setFillColor(Color::White);
	text3.setString(L"Taille du pixel de\ncoloriage :");
	text3.setPosition(20,130);
	
	text4.setFont(font);
	text4.setCharacterSize(15);
	text4.setFillColor(Color::White);
	text4.setString(L"% de la zone\ndevant être coloriée\navant de passer à\nla zone suivante :");
	text4.setPosition(280,50);
	
	text5.setFont(font);
	text5.setCharacterSize(15);
	text5.setFillColor(Color::White);
	text5.setString(L"% de la zone\ndevant être coloriée\navant d'afficher\nles pixels restants:");
	text5.setPosition(280,190);
	
	text6.setFont(font);
	text6.setCharacterSize(20);
	text6.setFillColor(Color::Black);
	text6.setString(L"Annuler");
	text6.setPosition(30,233);
	
	text7.setFont(font);
	text7.setCharacterSize(20);
	text7.setFillColor(Color::Black);
	text7.setString(L"Enregistrer");
	text7.setPosition(132,233);
	
	text8.setFont(font);
	text8.setCharacterSize(20);
	text8.setFillColor(Color::Black);
	text8.setString(L"Par défaut");
	text8.setPosition(25,273);
	
	text9.setFont(font);
	text9.setCharacterSize(20);
	text9.setFillColor(Color::Red);
	text9.setString(Nbzones);
	text9.setPosition(70,80);
	
	text10.setFont(font);
	text10.setCharacterSize(20);
	text10.setFillColor(Color::Red);
	text10.setString(R);
	text10.setPosition(70,180);
	
	text11.setFont(font);
	text11.setCharacterSize(20);
	text11.setFillColor(Color::Red);
	text11.setString(Condition95);
	text11.setPosition(330,140);
	
	text12.setFont(font);
	text12.setCharacterSize(20);
	text12.setFillColor(Color::Red);
	text12.setString(Condition95);
	text12.setPosition(330,280);
	
	RectangleShape rectangle(Vector2f(50,40));
	rectangle.setPosition(60,70);
	rectangle.setFillColor(Color::White);
	
	RectangleShape rectangle2(Vector2f(50,40));
	rectangle2.setPosition(60,170);
	rectangle2.setFillColor(Color::White);
	
	RectangleShape rectangle3(Vector2f(50,40));
	rectangle3.setPosition(290+30,130);
	rectangle3.setFillColor(Color::White);
	
	RectangleShape rectangle4(Vector2f(50,40));
	rectangle4.setPosition(290+30,270);
	rectangle4.setFillColor(Color::White);
	
	RectangleShape rectangle5(Vector2f(100,30));
	rectangle5.setPosition(20, 230);
	rectangle5.setFillColor(Color::White);
	
	RectangleShape rectangle6(Vector2f(100,30));
	rectangle6.setPosition(20, 270);
	rectangle6.setFillColor(Color::White);
	
	RectangleShape rectangle7(Vector2f(105,30));
	rectangle7.setPosition(130, 230);
	rectangle7.setFillColor(Color::White);
	
	while (ecran==15)
	{
		if (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					if (Button(window, 20, 230, 100, 30))
					{
						ecran=0;
					}
					
					if (Button(window, 60, 70, 50, 40))
					{
						var=1;
					}
					
					if (Button(window, 60, 170, 50, 40))
					{
						var=2;
					}
					
					if (Button(window, 320, 130, 50, 40))
					{
						var=3;
					}
					
					if (Button(window, 320, 270, 50, 40))
					{
						var=4;
					}
					
					if (Button(window, 20, 270, 100, 30))
					{
						Defaut(Nbzones, R, Condition80, Condition95);
						Enregistrer(Nbzones, R, Condition80, Condition95);
						ecran=0;
					}
					
					if (Button(window, 130, 230, 105, 30))
					{
						Enregistrer(Nbzones, R, Condition80, Condition95);
						ecran=0;
					}
				}
			}
			
			if (event.type == sf::Event::TextEntered)
			{
				switch (var)
				{
					case 1:
					Champtxt(event, Nbzones);
					break;
					
					case 2:
					Champtxt(event, R);
					break;
					
					case 3:
					Champtxt(event, Condition95);
					break;
					
					case 4:
					Champtxt(event, Condition80);
					break;
				}
			}
			
			
			if (event.type == Event::Closed)
			{
				window.close();
				ecran=10;
			}
		
		}
	
	text9.setString(Nbzones);
	text10.setString(R);
	text11.setString(Condition95);
	text12.setString(Condition80);
	
	window.clear();
	window.draw(rectangle);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(rectangle4);
	window.draw(rectangle5);
	window.draw(rectangle6);
	window.draw(rectangle7);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
	window.draw(text4);
	window.draw(text5);
	window.draw(text6);
	window.draw(text7);
	window.draw(text8);
	window.draw(text9);
	window.draw(text10);
	window.draw(text11);
	window.draw(text12);
	window.display();
	
	}
}


/************************************************************************************/
void Defaut(String& Nbzones, String& R, String& Condition80, String& Condition95)
{
	Nbzones="5";
	R="20";
	Condition80="80";
	Condition95="95";
}

/************************************************************************************/

void Enregistrer(String& Nbzones, String& R, String& Condition80, String& Condition95)
{
	ofstream Res("PARAMETRE.txt");
	
	string Nb=Nbzones, r=R, c80=Condition80, c95=Condition95;
	if (Res)
	{
	Res << Nb << " " << r << " " << c80 << " " << c95 << endl;
	}
}


/***********************************************************************************/

void Verif(int& ind, int& nbzone, int& R, int& condition80, int& condition95)
{
	if ( nbzone==5 and R==20 and condition80==80 and condition95==95 )
	{
		ind = 2;
	}
	
	else 
	{
		ind = 1;
	}
	
}




























