//Write C++ program to draw a line using DDA and bresenham algorithm
#include <graphics.h>
#include <iostream>
#include <math.h>

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
    void vDDA();
};
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

void cLine::vDDA()
{
    float iLength=0;
    if(abs(x2-x1)>=abs(y2-y1))
        iLength = abs(x2-x1);
    else
        iLength = abs(y2-y1);

    float dx = (x2-x1)/iLength;
    float dy = (y2-y1)/iLength;

    float x = x1 + 0.5f*iSign(dx);
    float y = y1 + 0.5f*iSign(dx);

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
    cLine drawLine;
    drawLine.vGetData();
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");
    drawLine.vDDA();
    line(100,100,200,400);
    delay(10000);
    closegraph();
    return 0;
}
