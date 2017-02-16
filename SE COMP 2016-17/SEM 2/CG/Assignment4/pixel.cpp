#include "pixel.h"
#include "ui_pixel.h"
#include <QLabel>
#include "math.h"

Pixel::Pixel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pixel)
{
    ui->setupUi(this);
    x1=x2=x3=x4=y1=y2=y3=y4=Sx=Sy=Theta=Tx=Ty=0;
    ch=-1;
}

Pixel::~Pixel()
{
    delete ui;
}
void Pixel::Translate()
{
    update();
}
void Pixel::Rotate()
{
update();
}
void Pixel::Scale()
{
update();
}
void Pixel::Draw()
{
    update();
}
void Pixel::paintEvent(QPaintEvent *q)
{
    Q_UNUSED(q);
       QPainter z(this);
       QPen p(Qt::black,1,Qt::SolidLine);
       z.setPen(p);

       const QPointF points[4]={
          QPointF(x1,y1),
          QPointF(x2,y2),
          QPointF(x3,y3),
          QPointF(x4,y4),
      };
    x1=this->ui->x1->text().toFloat();
    x2=this->ui->x2->text().toFloat();
    x3=this->ui->x3->text().toFloat();
    x4=this->ui->x4->text().toFloat();
    y1=this->ui->y1->text().toFloat();
    y2=this->ui->y2->text().toFloat();
    y3=this->ui->y3->text().toFloat();
    y4=this->ui->y4->text().toFloat();
    Tx=this->ui->Tx->text().toFloat();
    Ty=this->ui->Ty->text().toFloat();
    Sx=this->ui->Sx->text().toFloat();
    Sy=this->ui->Sy->text().toFloat();
    Theta=this->ui->Theta->text().toFloat();


    if(ch==0)
        z.drawPolygon(points,4);
    else if(ch==1)
    {
        x1+=Tx;x2+=Tx;x3+=Tx;x4+=Tx;
        y1+=Ty;y2+=Ty;y3+=Ty;y4+=Ty;
        const QPointF points[4]={
           QPointF(x1,y1),
           QPointF(x2,y2),
           QPointF(x3,y3),
           QPointF(x4,y4),
       };
        z.drawPolygon(points,4);
    }
    else if(ch==2)
        ;
    else if(ch==3)
    {
        x1*=Sx;x2*=Sx;x3*=Sx;x4*=Sx;
        y1*=Sy;y2*=Sy;y3*=Sy;y4*=Sy;
        const QPointF points[4]={
           QPointF(x1,y1),
           QPointF(x2,y2),
           QPointF(x3,y3),
           QPointF(x4,y4),
       };
        z.drawPolygon(points,4);
    }

}

void Pixel::on_Appl_Trans_clicked()
{
    ch=1;
    Translate();

}

void Pixel::on_Appl_Rot_clicked()
{
    ch=2;
    Rotate();
}

void Pixel::on_Appl_Scal_clicked()
{
    ch=3;
    Scale();
}

void Pixel::on_Show_orig_clicked()
{
ch=0;
Draw();
}

