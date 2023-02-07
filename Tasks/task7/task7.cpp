//  To be familiar with Shear.
// WAP to implement Shear of a square ABCD whose coordinates are A (0,0), 
// B (0,100), C (100,100) and D (100,0). 


#include <iostream>
#include <math.h>
#include <graphics.h>
#include <conio.h>

using namespace std;

void plot(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{ // This function first moves to the point x1, y1 and then draws line to the corresponding points.
	moveto(x1, y1);
	lineto(x2, y2);
	lineto(x3, y3);
	lineto(x4, y4);
	lineto(x1, y1);
}

void shear (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	
	float shx, shy;
	cout<<"Shx: ";cin>>shx;
	cout<<"Shy: ";cin>>shy;
	
	
	int shr_x1 = x1 + (shx*y1);
	int shr_y1 = y1 + (shy*x1);
	int shr_x2 = x2 + (shx*y2);
	int shr_y2 = y2 + (shy*x2);
	int shr_x3 = x3 + (shx*y3);
	int shr_y3 = y3 + (shy*x3);
	int shr_x4 = x4 + (shx*y4);
	int shr_y4 = y4 + (shy*x4);

	plot(shr_x1, shr_y1, shr_x2, shr_y2, shr_x3, shr_y3, shr_x4, shr_y4); 
	
}


int main(){
	
	int x1, x2, x3, y1, y2, y3, x4, y4;

/*out << "Enter the coordinates of the square: " << endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	cout << endl;
	*/
// x1=200;y1=200; x2=300;y2=200;x3=300 ;y3=300; x4=200; y4=300;
 x1=0;y1=0; x2=0;y2=100;x3=100 ;y3=100; x4=100; y4=0;
 


	initwindow(500, 500);
	plot(x1, y1, x2, y2, x3, y3, x4, y4); 
	shear(x1, y1, x2, y2, x3, y3, x4, y4);
	getch();
	closegraph();
	return 0;
}

