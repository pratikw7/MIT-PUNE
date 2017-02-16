#include "pixel.h"
#include "ui_pixel.h"
#include<QLabel>
#include<math.h>

Pixel::Pixel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pixel)
{
    ui->setupUi(this);
    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(DrawCircle()));
    x=y=x1=y1=x2=y2=length=0;
}

Pixel::~Pixel()
{
    delete ui;
}
void Pixel::DrawCircle(){
    update();
}
int Pixel::getLength(){
    return (sqrt(pow((x2-x1),2)+pow((y2-y1),2)));
}

void Pixel::paintEvent(QPaintEvent *q){
    Q_UNUSED(q);
    QPainter z(this);
    QPen p(Qt::black,1,Qt::SolidLine);
    z.setPen(p);

    QString a,b,c,d;
    a=this->ui->lineEdit->text();
    b=this->ui->lineEdit_2->text();
    c=this->ui->lineEdit_3->text();
    d=this->ui->lineEdit_4->text();

    x1=a.toInt();
    y1=b.toInt();
    x2=c.toInt();
    y2=d.toInt();
    z.drawLine(320,0,320,480);
    z.drawLine(0,240,640,240);
    length = getLength();
    x=0;
    y=length;
    e=3-(2*length);
    do{
    z.drawPoint(x+320,y+240);
    z.drawPoint(-x+320,-y+240);
    z.drawPoint(x+320,-y+240);
    z.drawPoint(-x+320,y+240);
    z.drawPoint(y+320,x+240);
    z.drawPoint(-y+320,-x+240);
    z.drawPoint(y+320,-x+240);
    z.drawPoint(-y+320,x+240);

        if(e<0)
            e=e+(4*x)+6;
        else{
            e=e+(4*(x-y))+10;
            y=y-1;
        }
        x=x+1;
    }while(x<y);
}
