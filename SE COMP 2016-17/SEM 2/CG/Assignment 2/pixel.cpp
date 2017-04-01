#include "pixel.h"
#include "ui_pixel.h"
#include <math.h>
pixel::pixel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pixel)
{
    ui->setupUi(this);
    connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(drawLine()));
    this->ui->radioButton->setChecked(true);
}

pixel::~pixel()
{
    delete ui;
}

void pixel::drawLine(){
    update();
}

int sign(double a){
    if(a>0)
        return 1;
    if(a<0)
        return -1;
    return 0;
}

void pixel::paintEvent(QPaintEvent *q){
    Q_UNUSED(q);
    QPainter z(this);
    QPen p(Qt::blue,1,Qt::SolidLine);
    z.setPen(p);

    QString a,b,c,d;
    a=this->ui->lineEdit->text();
    b=this->ui->lineEdit_2->text();
    c=this->ui->lineEdit_3->text();
    d=this->ui->lineEdit_4->text();
    thickness = this->ui->thicknessLabel->text().toInt();

    x1=a.toInt();
    y1=b.toInt();
    x2=c.toInt();
    y2=d.toInt();
    int type;
    if(this->ui->radioButton->isChecked()){
        type = 1;
    }else{
        if(this->ui->radioButton_2->isChecked()){
            type = 2;
        }else{
            if(this->ui->radioButton_3->isChecked()){
               type = 3;
            }else{
                if(this->ui->radioButton_4->isChecked()){
                  type = 4;
                }else{
                   type = 5;
                }
            }
        }
    }

               // Bresenham's Line Drawing Algorithm
            int w=thickness;
        int wy = ((w-1)/2)*(sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)))/abs(x2-x1));
        x = x1;
        y = y1;
        z.drawPoint(x,y);
        int dx = abs(x2-x1);
        int dy = abs(y2-y1);
        int s1 = sign(x2-x1);
        int s2 = sign(y2-y1);
        int interchange = 0;
        if(dx > dy){
        int temp = dx;
        dx = dy;
        dy = temp;
        interchange = 1;
        }else interchange = 0;

        int e = (2*dx)-dy;

        for(int i=1 ; i<dx;i++){
            if(type==1)
            z.drawPoint(x,y);
            if(i%15==0 && type == 2)
            z.drawPoint(x,y);
            if(i%15>0 && i%20<20 && type ==3)
            z.drawPoint(x,y);
            if((i%20<5 ||i%10==0)&&type == 4){
            z.drawPoint(x,y);}
        if(type == 5){
        for(int j=-wy ; j<=wy;j++){
            z.drawPoint(x,y+j);
            }
        }
            while(e>=0){
                if(interchange == 1)
                    x +=s1;
                else
                    y +=s2;
                e-=2*dx;
            }

            if(interchange == 1)
                y+=s2;
            else
                x+=s1;
            e+=2*dy;
        }


}
