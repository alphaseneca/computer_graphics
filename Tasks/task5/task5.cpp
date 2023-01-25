// To be familiar with Basic Transformation.
// WAP to implement Basic transformation of a triangle ABC with coordinates
// A (60,60), B (110,60) and C (70,100):

#include <iostream>
#include <cmath>
#include <graphics.h>
#include <conio.h>
using namespace std;

void plot(int x1, int y1, int x2, int y2, int x3, int y3)
{
	moveto(x1, y1);
	lineto(x2, y2);
	lineto(x3, y3);
	lineto(x1, y1);
}

void Rotation(int x1, int y1, int x2, int y2, int x3, int y3)
{

	float a;
	cout << "Enter the rotation angle" << endl;
	cin >> a;
	int xr1 = floor((x1 * cos(a * 3.14 / 180)) + (y1 * sin(a * 3.14 / 180)));
	int yr1 = floor((-x1 * sin(a * 3.14 / 180)) + (y1 * cos(a * 3.14 / 180)));

	int xr2 = floor((x2 * cos(a * 3.14 / 180)) + (y2 * sin(a * 3.14 / 180)));
	int yr2 = floor((-x2 * sin(a * 3.14 / 180)) + (y2 * cos(a * 3.14 / 180)));

	int xr3 = floor((x3 * cos(a * 3.14 / 180)) + (y3 * sin(a * 3.14 / 180)));
	int yr3 = floor((-x3 * sin(a * 3.14 / 180)) + (y3 * cos(a * 3.14 / 180)));
	plot(xr1, yr1, xr2, yr2, xr3, yr3);
}

void Translation(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int tx, ty;
	cout << "Enter the translation point" << endl;
	cin >> tx >> ty;
	tx = -tx;
	ty = -ty;
	x1 = tx + x1;
	y1 = ty + y1;
	x2 = tx + x2;
	y2 = ty + y2;
	x3 = tx + x3;
	y3 = ty + y3;
	plot(x1, y1, x2, y2, x3, y3);
}

void Scaling(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int sx, sy;
	cout << "Enter the scaling point" << endl;
	cin >> sx >> sy;
	x1 = sx * x1;
	y1 = sy * y1;
	x2 = sx * x2;
	y2 = sy * y2;
	x3 = sx * x3;
	y3 = sy * y3;
	plot(x1, y1, x2, y2, x3, y3);
}
int main()
{
	int choose;
	int x1, x2, x3, y1, y2, y3;
	cout << "Enter the coordinates of the triangle: " << endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << endl
		 << "1. Translation";
	cout << endl
		 << "2. Rotation";
	cout << endl
		 << "3. Scaling" << endl;
	cin >> choose;

	initwindow(400, 400);
	plot(x1, y1, x2, y2, x3, y3);
	switch (choose)
	{
	case 1:
		Translation(x1, y1, x2, y2, x3, y3);
		break;
	case 2:
		Rotation(x1, y1, x2, y2, x3, y3);
		break;
	case 3:
		Scaling(x1, y1, x2, y2, x3, y3);
		break;
	default:
		cout << "Enter valid digit.";
		break;
	}

	getch();
	closegraph();
	return 0;
}
