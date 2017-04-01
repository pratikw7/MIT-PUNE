#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;

class cPixel{
	public:
	void vSetPixel(int,int);
	void vSetPixel(int,int,int);
};
void cPixel::vSetPixel(int x,int y){
	putpixel(x,y,60);
}
void cPixel::vSetPixel(int x,int y, int color){
	putpixel(x,y,color);
}
class cDDA:public cPixel{
	int x1,x2,y1,y2;
	public:
	cDDA();
	void vDDA();
	int iSign(int);
	
};
cDDA::cDDA(){
	x1=x2=y1=y2=0;
}
int cDDA::iSign(int p){
	if(p>0) 
		return 1;
	else if(p<0)
		return -1;
	return 0;
}
void cDDA::vDDA(){
	float iLen,x,y,dx,dy;
	cout<<"\nEnter co-ordinates of first point:\t";
	cin>>x1>>y1;
	cout<<"\nEnter co-ordinates of second point:\t";
	cin>>x2>>y2;
	
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
class cBresenhamAlgo:public cPixel{
	int x1,x2,y1,y2;
	public:
	cBresenhamAlgo();
	void vBresenham();
	int iSign(int);
	
};
cBresenhamAlgo::cBresenhamAlgo(){
	x1=x2=y1=y2=0;
}
int cBresenhamAlgo::iSign(int p){
	if(p>0) 
		return 1;
	else if(p<0)
		return -1;
	return 0;
}
void cBresenhamAlgo::vBresenham(){
	int s1,s2,x,y,dx,dy,temp,interchange,p;
	cout<<"\nEnter co-ordinates of first point:\t";
	cin>>x1>>y1;
	cout<<"\nEnter co-ordinates of last point:\t";
	cin>>x2>>y2;
	
	x=x1;
	y=y1;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	s1=iSign(x2-x1);
	s2=iSign(y2-y1);
	
	if(dy>dx){
		temp=dx;
		dx=dy;
		dy=temp;
		interchange=1;
	}	
	else	
		interchange=0;
		
	p=(2*dy)-dx;
	for(int i=1;i<=dx;i++){
		vSetPixel(x,y,3);
		while(p>=0){
			if(interchange==1)
				x=x+s1;
			else
				y=y+s2;
			p=p-(2*dx);
		}
		if(interchange==1)
			y=y+s2;
		else
			x=x+s1;
		p=p+(2*dy);
	}
}
main(){
	int gd=DETECT,gm;
	cDDA D;
	cBresenhamAlgo B;
	int ch;
	initgraph(&gd,&gm,"");
	do{
		cout<<"\nMENU:\n1.Digitsl Differential Algorithm\n2.Bresenham's Algorithm\nEnter choice:\t";
		cin>>ch;
		switch(ch){
			case 1:
				D.vDDA();
				delay(5000);
				break;
			case 2:
				B.vBresenham();
				delay(5000);
				break;
			default:
				cout<<"\nInvalid choice\t";
				break;
		}
		cout<<"\nEnter 1 to continue:\t";
		cin>>ch;
	}while(ch==1);
	closegraph();
}
