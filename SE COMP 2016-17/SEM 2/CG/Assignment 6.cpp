#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class cPixel{
	public:
	void vSetPixel(int,int);
};
void cPixel::vSetPixel(int x,int y){
	putpixel(x,y,60);
}

class cDrawPolygon:public cPixel{
	int x,y,l,b;
	public:
	cDrawPolygon();
	void vDDA(int,int,int,int);
	int iSign(int);
	void vDrawStruct();
};
cDrawPolygon::cDrawPolygon(){
	x=y=l=b=0;
}
int cDrawPolygon::iSign(int p){
	if(p>0) 
		return 1;
	else if(p<0)
		return -1;
	return 0;
}
void cDrawPolygon::vDDA(int x1,int y1,int x2,int y2){
	float iLen,x,y,dx,dy;

	if(abs(x2-x1)>=abs(y2-y1))
		iLen=abs(x2-x1);
	else
		iLen=abs(y2-y1);
	
	dx=(x2-x1)/iLen;
	dy=(y2-y1)/iLen;
	
	x=x1+0.5*iSign(dx);
	y=y1+0.5*iSign(dy);
	vSetPixel(int(x),int(y));
	
	for(int i=1;i<=iLen;i++){
		x=x+dx;
		y=y+dy;
		vSetPixel(int(x),int(y));
	}
}
void cDrawPolygon::vDrawStruct(){
	cout<<"\nEnter the starting co-ordinates(x,y) of the polygon:\t";
	cin>>x>>y;
	cout<<"\nEnter the length of the rectangle:\t";
	cin>>l;
	cout<<"\nEnter the breadth of the rectangle:\t";
	cin>>b;

	vDDA(x,y,x+l,y);
	vDDA(x+l,y,x+l,y+b);
	vDDA(x+l,y+b,x,y+b);
	vDDA(x,y+b,x,y);

	vDDA(x,(y+(b/2)),(x+(l/2)),(y+b));
	vDDA((x+(l/2)),(y+b),(x+l),(y+(b/2)));
	vDDA((x+l),(y+(b/2)),(x+(l/2)),y);
	vDDA((x+(l/2)),y,x,(y+(b/2)));

	vDDA(x+(l/4),y+(b/4),x+(3*l/4),y+(b/4));
	vDDA(x+(3*l/4),y+(b/4),x+(3*l/4),y+(3*b/4));
	vDDA(x+(3*l/4),y+(3*b/4),x+(l/4),y+(3*b/4));
	vDDA(x+(l/4),y+(3*b/4),x+(l/4),y+(b/4));
}
int main(){
	cDrawPolygon D;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	D.vDrawStruct();
	delay(5000);
	closegraph();
	return 0;
}

