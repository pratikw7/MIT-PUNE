#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class transformations
{
	int x1,x2,x3,x4,y1,y2,y3,y4,tx,ty,poly[10],a[4][3],b[3][3],c[4][3],final[10];
	float theta,sx,sy,d[3][3];
	public:	transformations();
		void draw();
		void scaling();
		void translation();
		void rotation();
};
transformations::transformations()
{
	x1=x2=x3=x4=y1=y2=y3=y4=tx=ty=0;
	theta=sx=sy=0.0;
	int i,j;
	for(i=0;i<10;i++)
	{
		poly[i]=0;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][j]=0;
			b[i][i]=1;
			d[i][j]=0.0;
			d[i][i]=1.0;
		}
	}
}
void transformations::draw()
{
	int i,x,j,k=0;
	for(i=0;i<4;i++)
	{
		a[i][2]=1;
		for(j=0;j<2;j++)
		{
			cout<<"\n Enter the co-ordinate :" ;
			cin>>x;
			poly[k]=x;
			k++;
			a[i][j]=x;
		}
	}
	poly[8]=poly[0];
	poly[9]=poly[1];
	drawpoly(5,poly);
}
void transformations::scaling()
{
	int i,j=0,k,l,m=0;
	transformations();
	cout<<"\n Enter Sx and Sy factors:";
	cin>>sx>>sy;
	b[0][0]=sx;
	b[1][1]=sy;
	for(i=0;i<4;i++)
	{
		
		for(j=0;j<3;j++)
		{
			c[i][j]=0;
			for(k=0;k<3;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	for(i=0;i<4;i++)
	{	
		for(j=0;j<2;j++)
		{
			final[m]=c[i][j];
			m++;
		}
	}
	final[m]=final[0];
	m++;
	final[m]=final[1];
	drawpoly(5,final);
}	
void transformations::translation()
{
	int i,j=0,k,l,m=0;
	transformations();
	cout<<"\n Enter Tx and Ty factors:";
	cin>>tx>>ty;
	b[2][0]=tx;
	b[2][1]=ty;
	for(i=0;i<4;i++)
	{
		
		for(j=0;j<3;j++)
		{
			c[i][j]=0;
			for(k=0;k<3;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	for(i=0;i<4;i++)
	{	
		for(j=0;j<2;j++)
		{
			final[m]=c[i][j];
			m++;
		}
	}
	final[m]=final[0];
	m++;
	final[m]=final[1];
	drawpoly(5,final);
}
void transformations::rotation()
{
	int i,j,k,l,m=0;
	cout<<"\n Enter the angle theta for rotation:";
	cin>>theta;
	float e[4][3];
	d[0][0]=cos(theta);
	d[0][1]=sin(theta);
	d[1][0]=-sin(theta);
	d[1][1]=cos(theta);
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			e[i][j]=0.0;
			for(k=0;k<3;k++)
			{
				e[i][j]=e[i][j]+a[i][k]*d[k][j];
			}
		}
	}
	for(i=0;i<4;i++)
	{	
		for(j=0;j<2;j++)
		{
			final[m]=e[i][j];
			m++;
		}
	}
	final[m]=final[0];
	m++;
	final[m]=final[1];
	drawpoly(5,final);
}
int main()
{
	int m;
	char ans;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	transformations obj;
	do
	{
		cout<<"\n Enter the operation to be performed: \n 1.Draw \n 2.Scaling \n 3.Translation \n 4.Rotation";
		cin>>m;
		switch(m)
		{
			case 1:	obj.draw();
				delay(2000);
				break;
                case 2:	obj.scaling();
				delay(2000);
				break;
            case 3:	obj.translation();
				delay(2000);
				break;
			case 4:	obj.rotation();
				delay(2000);
				break;
		}
		cout<<"\n Do you want to continue?";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
	closegraph();
	return 0;
}
