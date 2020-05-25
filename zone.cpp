#include <iostream>
#include "toucher.h"
#include "zone.h"


/************ce ficher comporte les fonction relatives au remplissage des zones à completer**********/

//verifie que le point (x,y) se situe dans la kème zone

int zone(int k,int x,int y,int a,int b,int r,int R, int e)
{
	//k va de 0 à nbzones
	int l, error=0;
	l=(a-x)*(a-x)+(b-y)*(b-y); //equation du cercle
	
	//verifie que le point est situé entre les deux lignes delimitant la zone ET appartient au cercle
	if ( (x>=a+r-(k+1)*e+R/2) && (x<=a+r-k*e-R/2) && (l<=r*r-R/2) )
		{
			error=1; //le point est dans la zone
		}
	
	if ( (x<=a+r-(k+1)*e-R/2) || (x>=a+r-k*e+R/2) || (l>r*r+R*R*R) )
		{
			error=2; //le point n'est pas dans la zone
		}
	return error;
}

/******************************************************************/

// remplissage du tableau de memes dimensions que la kème zone (un pixel= une case)
// la fonction ajoute un 1 dans la case de coordonnées (x,y) (et cases alentours) du tableau

void remplissage(int k,int x,int y,int xa,int ya,int r,int R, int e,int &aire, int **resul)
{
int i,j, boole=0;
int xp=x-(xa+r-e*(k+1)); //initialisation de x par rapport au tableau (xp origine du tableau, x origine de l'ecran)
i=xp-(R/2); j=y-(R/2);
while (i<xp+(R/2)+1)
		{ 
		while ((j<y+(R/2)+1) && (boole!=2))
			{
			if (zone(k,i+xa+r-e*(k+1),j,xa,ya,r,R,e)==1)
				{	
					boole=1;
					if (resul[i][j]!=1)
					{
						aire++;
						resul[i][j]=1;
					}	
				}
			if ((zone(k,i+xa+r-e*(k+1),j,xa,ya,r,R,e)!=1) && (boole==1))
				{
					boole=2;
				}
			j++;
			
			}
		i++;
		j=y-(R/2);
		}

}

/*******************************************************************/

//verifie que la zone est coloriée à 95% (pour changer de zone) ou 80% (pour faire apparaitre les pixels isolés en coloré)

int aire_completee(int aire,int airetotale, int condition80, int condition95)

{
	float pourcentage=((float)(aire)/(float)(airetotale))*100; //calcul  le pourcentage d'aire coloré
	
	if (pourcentage>condition95) {return 2;} 
	else if (pourcentage>condition80) {return 1;}
	else {return 0;}
}
