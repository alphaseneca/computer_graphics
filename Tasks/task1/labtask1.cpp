#include <graphics.h>
#include <iostream>
#include <cmath>
#include <direct.h>
#define Round(p) (p + 0.5)

using namespace std;

int main()
{
    float x, y, x1, y1, x2, y2, dx, dy, step, xincr, yincr;
    initwindow(400, 400, "DDA Line Drawing Algorithm");
    cout << "Enter the value of x1 and y1 "<<endl;
    cin >> x1 >> y1;
    cout << "Enter the value of x2 and y2 "<<endl;
    cin >> x2 >> y2;
    x = x1;
    y = y1;
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
    {
        step = abs(dy);
    }

    xincr = dx / (float)step;
    yincr = dy / (float)step;
    putpixel(Round(x), Round(y), 5);
    int i = 1;
    while (i <= step)
    {
        x = x + xincr;
        y = y + yincr;
        i++;
        delay(100);
        putpixel(Round(x), Round(y), 5);
    }
    getch();
    closegraph();
}
