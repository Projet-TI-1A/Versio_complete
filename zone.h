#ifndef ZONE_H
#define ZONE_H

//verifie que le point (x,y) se situe dans la kème zone
int zone(int ,int ,int ,int ,int ,int ,int , int );

// remplissage du tableau de memes dimensions que la kème zone (un pixel= une case)
// la fonction ajoute un 1 dans la case de coordonnées (x,y) (et cases alentours) du tableau
void remplissage(int ,int ,int ,int ,int ,int ,int , int ,int& , int** );

//verifie que la zone est coloriée à 95% (pour changer de zone) ou 80% (pour faire apparaitre les pixels isolés en coloré)
int aire_completee(int,int, int, int);

#endif
