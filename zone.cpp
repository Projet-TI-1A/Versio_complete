#include <iostream>
#include "toucher.h"
#include "zone.h"


/******************************************************************/
/*verifie que le point (x,y) dans la kè zone*/
int zone(int k,int x,int y,int a,int b,int rayon, int e)
{
	//attention penser aux effets de bords erreurs de segmentation
	//k va de 0 à 4
	int l, error=0;
	l=(a-x)*(a-x)+(b-y)*(b-y);
	
	if ( (x>=a+rayon-(k+1)*e) && (x<=a+rayon-k*e) && (l<=rayon*rayon) )
	/*if (  (x>=180) && (x<310) && (l<=rayon*rayon) )*/
		{
			error=1;
		}
	else 
		{
			error=0;
		}
	return error;
}

/******************************************************************/
/*ajoutes un 1 dans la case (x,y) et alentours du tableau de la taille de la kè zone */
void remplissage(int k,int x,int y,int xa,int ya,int rayon,int cote, int e,int &aire, int **resul)
{
int i,j, boole=0;
int xp=x-(xa+rayon-e*(k+1)); //initialisation de x par rapport au tableau
i=xp-(cote/2); j=y-(cote/2);
while (i<xp+(cote/2)+1)
		{ 
		while ((j<y+(cote/2)+1) && (boole!=2))
			{
			if (zone(k,i+xa+rayon-e*(k+1),j,xa,ya,rayon,e))
				{	
					boole=1;
					if (resul[i][j]!=1)
					{
						aire++;
						resul[i][j]=1;
					}	
				}
			if ((zone(k,i+xa+rayon-e*(k+1),j,xa,ya,rayon,e)==0) && (boole==1))
				{
					boole=2;
				}
			j++;
			
			}
		i++;
		j=y-(cote/2);
		}

}

/*******************************************************************/
/*verifie que la zone est coloriée à 95% ou 80% pour fair apparaitre les pixel isolés en coloré*/






int aire_completee(int aire,int airetotale, int condition80, int condition95)

{
	float pourcentage=((float)(aire)/(float)(airetotale))*100;
	
	if (pourcentage>condition95) {return 2;}
	else if (pourcentage>condition80) {return 1;}
	else {return 0;}
}


