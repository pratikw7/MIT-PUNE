#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;
class cPixel
{
public:
    void setPixel(int,int);
};

void cPixel::setPixel(int x, int y)
{
    putpixel(x,y,100);
}

class cLine:public cPixel
{
    int iSign(float);
    int x1,  y1,  x2,  y2;
public:
    void vGetData();
    void vDDA(int,int,int,int);
    void vBresenham(int x1, int y1,int raduis);
    void vDrawTriangle(int,int,int);
};
void cLine::vDrawTriangle(int x, int y, int radius)
{
    int x1,x2,x3,y1,y2,y3;
    y1 = y+0.866*radius;
    y2 = y+0.866*radius;
    y3 = y-0.866*radius;
    x1 = x-radius/2;
    x2 = x+radius/2;
    x3 = x;
    vDDA(x1,y1,x2,y2);
    vDDA(x2,y2,x3,y3);
    vDDA(x3,y3,x1,y2);

}

void cLine::vBresenham(int x1, int y1, int radius)
{

    int length = radius;
        int x = 0;
        int y = length;
        int e = 3-2*length;
        do
        {
            setPixel(x+x1,y+y1);
            setPixel(y+x1,x+y1);
            setPixel(y+x1,-x+y1);
            setPixel(x+x1,-y+y1);
            setPixel(-x+x1,-y+y1);
            setPixel(-y+x1,-x+y1);
            setPixel(-y+x1,x+y1);
            setPixel(-x+x1,y+y1);

            if(e<0)
            {
                e = e+4*x+6;
            }
            else
            {
                e = e+4*(x-y)+10;
                y--;

            }
            x++;
        }while(x<y);
}

void cLine::vGetData()
{
    std::cout<<"Enter the co-ordinates: ";
    std::cin>>x1>>y1>>x2>>y2;
}

int cLine::iSign(float n)
{
    if(n>0)
        return 1;
    else if(n<0)
        return -1;
    else
        return 0;
}

void cLine::vDDA(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y1 = y2;
    float iLength=0;
    if(abs(x2-x1)>=abs(y2-y1))
        iLength = abs(x2-x1);
    else
        iLength = abs(y2-y1);

    float dx = (x2-x1)/iLength;
    float dy = (y2-y1)/iLength;

    float x = x1 + 0.5f*iSign(dx);
    float y = y1 + 0.5f*iSign(dy);

    setPixel(floor(x),floor(y));
    int i=iLength;
    while(i--)
    {
        x = x + dx;
        y = y + dy;
        setPixel(floor(x),floor(y));
    }

}
int main()
{
    int x,y,radius;
    cLine objects;
    int gd=DETECT,gm;
    cout<<"Enter x coordinates of center: ";
    cin>>x;
    cout<<"Enter y coordinates of center: ";
    cin>>y;
    cout<<"Enter radius of center: ";
    cin>>radius;
    initgraph(&gd,&gm,"");
    objects.vBresenham(x,y,radius);
    objects.vDrawTriangle(x, y,  radius);
   // objects.vDDA(200,200,400,200);
    //objects.vDDA(200,200,300,26.8);
    //objects.vDDA(300,26.8,400,200);
    //objects.vBresenham(300,142,118);
    //objects.vBresenham(300,142,56);
    delay(7000);
    closegraph();
    return 0;
}
