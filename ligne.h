#ifndef LIGNE_H
#define LIGNE_H
#include <iostream>
#include "toucher.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

/***************************classe ligne*******************************/

class ligne : public point
{
	public :
	void Position_ligne(RenderWindow&);
	ligne(int x, int y);
};

#endif





