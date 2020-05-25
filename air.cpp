#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "interface.h"
#include "toucher.h"
#include "zone.h"
#include <vector>
#define nbzone 5

using namespace std;
using namespace sf;

/******************************calcul de l'aire d'une zone****************************/

/* On utilise un tableau "aire" de taille [diametre/nbzone] x largeurecran ce qui correspond au rectangle défini par les 2 lignes delimitant la zone*/
/* et on parcourt le tableau horizontalement on retire le nombre de pixels non compris dans le cercle*/


int calculaire(int k,int e,int largeur,int a,int b,int r, int R)
{
	int i,j,l,aire,sup,inf,diametre, compteur1=0, compteur2=0;
	aire=(e-R/2-R/2)*largeur;
	sup=a+r-k*e-R/2;  //borne sup de la zone (verticale)
	inf=a+r-(k+1)*e+R/2; //born inf de la zone (verticale)
	i=inf;
	while (i>=inf && i<sup) //on se situe entre les 2 lignes verticales
	{ 	j=0;
		l=largeur; 
		while(zone(k,i,j,a,b,r,R,e)!=1) 
		//on parcourt le tableau horizontalement par le haut
		//tant que le point n'appartient pas au cercle,
		{	
			j+=1;
			aire=aire-1;            //on le retire du calcul d'aire
		}  
		while (zone(k,i,l,a,b,r,R,e)!=1)
		//on parcourt le tableau horizontalement par le bas
		//tant que le point n'appartient pas au cercle,
		{
			l-=1;
			aire=aire-1; 
		}
		i+=1;
	}
	return aire;
}


