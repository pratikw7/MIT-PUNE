#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

void koch(int x1,int y1, int x2, int y2,int n){
    int xa,ya,xb,yb,xc,yc;
    xa = (x2+(2*x1))/3;
    ya = (y2+(2*y1))/3;
    xc = (x1+(2*x2))/3;
    yc = (y1+(2*y2))/3;
    xb = ((xc-xa)*(cos(1.0472)))+((yc-ya)*(sin(1.0472)))+xa;
    yb = -((xc-xa)*(sin(1.0472)))+((yc-ya)*(cos(1.0472)))+ya;
    if(n>0){
        koch(x1,y1,xa,ya,n-1);
        koch(xa,ya,xb,yb,n-1);
        koch(xb,yb,xc,yc,n-1);
        koch(xc,yc,x2,y2,n-1);
    }
    if(n==0){
        line(x1,y1,xa,ya);
        line(xa,ya,xb,yb);
        line(xb,yb,xc,yc);
        line(xc,yc,x2,y2);
    }
}


int main(){
int n;
int x,y,side;double angle;
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
cout<<"\n Enter the order, the x and y coordinates, the length of the side, and the angle :";
cin>>n>>x>>y>>side>>angle;
    angle *= 3.14/180 ;
    koch(x,y,(side*cos(angle))+x,(-side*sin(angle))+y,n);
delay(7000);
closegraph();
return 0;
}
