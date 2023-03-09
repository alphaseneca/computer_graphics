//  To be familiar with Shear.
// WAP to implement Shear of a square ABCD whose coordinates are A (0,0), 
// B (0,100), C (100,100) and D (100,0). 


#include <iostream>
#include <math.h>
#include <graphics.h>
#include <conio.h>

using namespace std;

void graph(){
	// Makes a graph in the window. i.e divides the window in four quadrants
	moveto(0,300);
	lineto(600,300);
	moveto(300,0);
	lineto(300,600);
}

void plot(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{ // This function first moves to the point x1, y1 and then draws line to the corresponding points.
	moveto(300+x1,300-y1);
	lineto(300+x2,300-y2);
	lineto(300+x3,300-y3);
	lineto(300+x4,300-y4);
	lineto(300+x1,300-y1);
}


void Xref(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int xref,shy;
	cout<<"enter xref and shy:"<<endl;
	cin>>xref>>shy;
	
	y1+=shy*(x1-xref);
	y2+=shy*(x2-xref);
	y3+=shy*(x3-xref);
	y4+=shy*(x4-xref);
	setcolor(5);
	plot(x1, y1, x2, y2, x3, y3, x4, y4);
	
}

void Yref(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int yref,shx;
	cout<<"enter yref and shx:"<<endl;
	cin>>yref>>shx;
	
	x1+=shx*(y1-yref);
	x2+=shx*(y2-yref);
	x3+=shx*(y3-yref);
	x4+=shx*(y4-yref);
	setcolor(10);
	plot(x1, y1, x2, y2, x3, y3, x4, y4);

}

int main(){
	
	int x1, x2, x3, y1, y2, y3, x4, y4;
	int choice;

	//cout << "Enter the coordinates of the square: " << endl;
	//cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	//cout << endl;
	
	x1 = 0; y1= 0; x2= 0; y2= 100; x3 = 100; y3 = 100; x4 = 100; y4 = 0;
// x1=200;y1=200; x2=300;y2=200;x3=300 ;y3=300; x4=200; y4=300;
	initwindow(600,600);
	graph();
	setcolor(1);
	plot(x1, y1, x2, y2, x3, y3, x4, y4); 
	cout<<"Shearing with respect to:"<<endl;
	cout<<"1.x reference line\n2.y refence line\n3.Exit"<<endl;
	cin>>choice;
		switch(choice){
			case 1:
				Xref( x1, y1, x2, y2, x3, y3, x4, y4);
				break;
			case 2:
				Yref( x1, y1, x2, y2, x3, y3, x4, y4);
				break;
			case 3:
				exit(0);
				break;
			default:
				cout<<"Enter according to option";
		}
	getch();
	closegraph();
	return 0;
}

