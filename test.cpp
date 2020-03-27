#include <iostream>
#define E 5
#define L 10




using namespace std;



int main()
{
	int** tab_pixel;
	tab_pixel = new int* [E];
	cout << "L=" << L << endl;
	cout << "E=" << E << endl;
	
		for (int i=0; i < E; i++)
		{
			tab_pixel[i] = new int[L];
		}
		
		
		for (int i=0; i < E; i++)
		{
			for (int j=0; j < L; j++)
			{
				tab_pixel[i][j]=0;
				cout << tab_pixel[i][j] ;
			}
			cout << endl;
		}
		
		
		for (int i = 0; i < E; i++)
		{
			delete [] tab_pixel[i];
		}
		delete [] tab_pixel;
		
	return 0;
}
