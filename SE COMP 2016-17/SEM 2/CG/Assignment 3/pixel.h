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
    int x,y,x1,y1,x2,y2,length;
    double e;
    void paintEvent(QPaintEvent*);
    int getLength();
    
public:
    explicit Pixel(QWidget *parent = 0);
    ~Pixel();
    
private:
    Ui::Pixel *ui;
public slots:
    void DrawCircle();
};

#endif // PIXEL_H
