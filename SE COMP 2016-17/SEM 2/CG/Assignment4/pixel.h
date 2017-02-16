#ifndef PIXEL_H
#define PIXEL_H

#include<QWidget>
#include<QImage>
#include<QPainter>
#include <QMainWindow>

namespace Ui {
class Pixel;
}

class Pixel : public QMainWindow
{
    Q_OBJECT
    float x1,x2,x3,x4,y1,y2,y3,y4;
    float Sx,Sy;
    float Tx,Ty;
    float Theta;
    int ch;
    void paintEvent(QPaintEvent *);
public:
    explicit Pixel(QWidget *parent = 0);

    ~Pixel();

    
private slots:
    void Scale();
    void Translate();
    void Rotate();
    void Draw();
    void on_Appl_Trans_clicked();

    void on_Appl_Scal_clicked();

    void on_Appl_Rot_clicked();

    void on_Show_orig_clicked();

private:
    Ui::Pixel *ui;
public slots:

};

#endif // PIXEL_H
