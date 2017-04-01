#ifndef PIXEL_H
#define PIXEL_H

#include <QMainWindow>
#include<QPainter>
#include<QWidget>
#include<QImage>

namespace Ui {
class pixel;
}

class pixel : public QMainWindow
{
    Q_OBJECT
    int x1,x2,y1,y2,choice;
    
public:
    explicit pixel(QWidget *parent = 0);
    ~pixel();
    void paintEvent(QPaintEvent *);
    
private slots:
    void on_DDA_Button_clicked();

    void on_Bresenham_button_clicked();

private:
    Ui::pixel *ui;

public slots:
    void vDDA();
    void vBresenham();
};

#endif // PIXEL_H
