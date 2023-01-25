// Objective: To be familiar with Fixed point scaling and Pivot point rotation.
// WAP to implement Fixed point scaling and Pivot point rotation of a triangle ABC
// with coordinates A (60,60), B (110,60) and C (70,100):

// For Fixed point scaling , move the specified point to the centre via inverse translation.
// then scale the points and then again translate the points to the original state.

#include <iostream>
#include <math.h>
#include <graphics.h>
#include <conio.h>

int X0, Y0;
int sx, sy;
int angle;
int choose;

using namespace std;

void plot(int x1, int y1, int x2, int y2, int x3, int y3)
{ // This function first moves to the point x1, y1 and then draws line to the corresponding points.
	moveto(x1, y1);
	lineto(x2, y2);
	lineto(x3, y3);
	lineto(x1, y1);
}

int centroid(int x1, int y1, int x2, int y2, int x3, int y3, const char *ch)
{

	int x0, y0, ret;
	x0 = (x1 + x2 + x3) / 3;
	y0 = (y1 + y2 + y3) / 3;

	if (*ch == 'x')
	{
		ret = x0;
	}

	else if (*ch == 'y')
	{
		ret = y0;
	}

	return ret;
}

void translation(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty)
{
	x1 = tx + x1;
	y1 = ty + y1;
	x2 = tx + x2;
	y2 = ty + y2;
	x3 = tx + x3;
	y3 = ty + y3;

	plot(x1, y1, x2, y2, x3, y3);
}

void scaling(int x1, int y1, int x2, int y2, int x3, int y3, int sx, int sy)
{
	x1 = sx * x1;
	y1 = sy * y1;
	x2 = sx * x2;
	y2 = sy * y2;
	x3 = sx * x3;
	y3 = sy * y3;

	translation(x1, y1, x2, y2, x3, y3, X0, Y0);
}

void rotation(int x1, int y1, int x2, int y2, int x3, int y3, int a)
{

	int xr1 = floor((x1 * cos(a * 3.14 / 180)) + (y1 * sin(a * 3.14 / 180)));
	int yr1 = floor((-x1 * sin(a * 3.14 / 180)) + (y1 * cos(a * 3.14 / 180)));

	int xr2 = floor((x2 * cos(a * 3.14 / 180)) + (y2 * sin(a * 3.14 / 180)));
	int yr2 = floor((-x2 * sin(a * 3.14 / 180)) + (y2 * cos(a * 3.14 / 180)));

	int xr3 = floor((x3 * cos(a * 3.14 / 180)) + (y3 * sin(a * 3.14 / 180)));
	int yr3 = floor((-x3 * sin(a * 3.14 / 180)) + (y3 * cos(a * 3.14 / 180)));

	translation(xr1, yr1, xr2, yr2, xr3, yr3, X0, Y0);
}

void inverse_translation(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty)
{ // Move the centroid to the origin
	tx = -tx;
	ty = -ty;
	x1 = tx + x1;
	y1 = ty + y1;
	x2 = tx + x2;
	y2 = ty + y2;
	x3 = tx + x3;
	y3 = ty + y3;

	if (choose == 1)
	{
		plot(x1, y1, x2, y2, x3, y3);
		scaling(x1, y1, x2, y2, x3, y3, sx, sy);
	}

	else if (choose == 2)
	{
		plot(x1, y1, x2, y2, x3, y3);
		rotation(x1, y1, x2, y2, x3, y3, angle);
	}
}

void fixedpointscaling(int x1, int y1, int x2, int y2, int x3, int y3)
{

	cout << "Enter the scaling factor: " << endl;
	cin >> sx >> sy;

	inverse_translation(x1, y1, x2, y2, x3, y3, X0, Y0);
}

void pivotpointrotation(int x1, int y1, int x2, int y2, int x3, int y3)
{

	cout << "Enter the rotation angle: " << endl;
	cin >> angle;

	inverse_translation(x1, y1, x2, y2, x3, y3, X0, Y0);
}

int main()
{

	int x1, x2, x3, y1, y2, y3;

	cout << "Enter the coordinates of the triangle: " << endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << endl;
	// x1=100;y1=100; x2=210;y2=100;x3=270;y3=300;

	initwindow(500, 500);
	plot(x1, y1, x2, y2, x3, y3);

	cout << "What do you want to perform ?" << endl;
	cout << "1. Fixed point scaling " << endl;
	cout << "2. Pivot point rotation " << endl;
	cin >> choose;

	X0 = centroid(x1, y1, x2, y2, x3, y3, "x");
	Y0 = centroid(x1, y1, x2, y2, x3, y3, "y");

	switch (choose)
	{
	case 1:
		fixedpointscaling(x1, y1, x2, y2, x3, y3);
		break;
	case 2:
		pivotpointrotation(x1, y1, x2, y2, x3, y3);
		break;
	default:
		cout << "Enter valid digit" << endl;
		exit(0);
		break;
	}

	getch();
	closegraph();
	return 0;
}
