#ifndef TOUCHER_H
#define TOUCHER_H
#include <SFML/Graphics.hpp>
#include <ctime>
#include <time.h>

using namespace std;
using namespace sf;

/************ Ce fichier contient les fonction qui récupèrent et traitent les données récupérées de l'écran*************/

/*************************************Classe point******************************************/
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

};


/*************************************Classe tabpoint******************************************/

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

};

//Récupère la postion de la souris relative à la fenêtre
void Position_Curseur(int&, int& , RenderWindow&);

//Ajoute un point au tableau (qui collecte les points de l'écran touchés)
void Ajoute_point(vector<point>,int*, RenderWindow&);


#endif
