#include "pixel.h"
#include "ui_pixel.h"
#include<QLabel>
#include<math.h>

pixel::pixel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pixel)
{
    ui->setupUi(this);
}
pixel::~pixel()
{
    delete ui;
}
void pixel::paintEvent(QPaintEvent *q)
{
    Q_UNUSED(q);
    QPainter z(this);

    QString a,b,c,d;

    a=this->ui->lineEdit->text();
    b=this->ui->lineEdit_2->text();
    c=this->ui->lineEdit_3->text();
    d=this->ui->lineEdit_4->text();
    x1=a.toInt();
    y1=b.toInt();
    x2=c.toInt();
    y2=d.toInt();

    if(choice==1)
    {
        float iLen,x,y,dx,dy;
        int sign1,sign2;
        if(abs(x2-x1)>=abs(y2-y1))
            iLen=abs(x2-x1);
        else
            iLen=abs(y2-y1);

        dx=(x2-x1)/iLen;
        dy=(y2-y1)/iLen;
        if(dx<0)
            sign1=-1;
        else if(dx>0)
            sign1=1;
        else
            sign1=0;
        if(dy<0)
            sign2=-1;
        else if(dy>0)
            sign2=1;
        else
            sign2=0;
        x=x1+0.5*sign1;
        y=y1+0.5*sign2;
        z.drawPoint(x+100,y+100);

        for(int i=1;i<=iLen;i++){
            x=x+dx;
            y=y+dy;
            z.drawPoint(x+100,y+100);
        }
    }
    if(choice==2)
    {
        int s1,s2,x,y,dx,dy,temp,interchange,p;
        if((x2-x1)<0)
            s1=-1;
        else if((x2-x1)>0)
            s1=1;
        else
            s1=0;
        if((y2-y1)<0)
            s2=-1;
        else if((y2-y1)>0)
            s2=1;
        else
            s2=0;
        x=x1;
        y=y1;
        dx=abs(x2-x1);
        dy=abs(y2-y1);

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
            z.drawPoint(x+100,y+100);
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

}
void pixel::vDDA()
{
    update();
}
void pixel::vBresenham()
{
    update();
}

void pixel::on_DDA_Button_clicked()
{
    choice=1;
    vDDA();
}
void pixel::on_Bresenham_button_clicked()
{
    choice=2;
    vBresenham();
}
