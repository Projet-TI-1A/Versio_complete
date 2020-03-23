#ifndef TOUCHER_H
#define TOUCHER_H
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class point
{
private :
	int x;
	int y;

public :
	point();
	point(int, int);
	void set(int, int );
	void get(int&, int& );
	void Dessine_point(RenderWindow&, int,int , int , int );

};


class tabpoint
{
private:
	vector<point> tab;
	int taille;
public:
	tabpoint();
	void append(point&);/*Ajoute un objet en fin de tableau*/
	void get(point&, int); /*Recupere le point en position i*/
	int gettaille();
	void reset();
	void Dessine_plus_points(RenderWindow&,int, int, int, int);

};

void Position_Curseur(int*, int* , RenderWindow&);
void Ajoute_point(vector<point>,int*, RenderWindow&);

void restart(tabpoint&, tabpoint&, int&, int&);

#endif
