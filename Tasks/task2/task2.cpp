#include<iostream>
#include<graphics.h>
#include<math.h>
#include<conio.h>

using namespace std;

void draw(int x1, int y1, int x2, int y2){
	int lx, ly, dx, dy, p;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(x2>x1){
		lx=1;
	}
	else{
		lx=-1;
	}
	if(y2>y1){
		ly=1;
	}
	else{
		ly=-1;
	}
	putpixel (x1,y1,5);
	if(dx>dy){
		p=2*dy-dx;
		for(int i=0; i<dx;i++){
			if(p<0) {
			putpixel(x1,y1, 5);
			x1=x1+lx;
			p=p+2*dy;
			delay(100);
		     }
		    else{
			if(p<0){
				putpixel(x1, y1, 5);
				x1=x1+lx;
				p=p+2*dy;
				delay(100);
			}
			else{
				putpixel(x1, y1, 5);
				x1=x1+lx;
				y1=y1+ly;
				p=p+2*dy-2*dx;
				delay(100);
			}
		}
     }
	
}
	else{
		p=2*dx-dy;
		for(int i=0; i<dx;i++){
			if(p<0){
				putpixel(x1, y1, 5);
				x1=x1;
				y1=y1+ly;
				p=p+2*dx;
				delay(100);
			}
			else{
				putpixel(x1,y1, 5);
				x1=x1+lx;
				y1=y1+ly;
				p=p+2*dx-2*dy;
				delay(100);
			}
		}
	}
}

int main(){
	int x1,x2,y1,y2;

	cout<<"Enter the value of x1 and y1\n";
	cin>>x1>>y1;
	cout<<"Enter the value of x2 and y2\n";
	cin>>x2>>y2;
	initwindow(400,400,"BLA Algorithm");
	draw(x1,x2,y1,y2);
	
	getch();
	closegraph();
}
