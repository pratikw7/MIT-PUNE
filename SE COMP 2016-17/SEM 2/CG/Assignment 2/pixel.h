#ifndef PIXEL_H
#define PIXEL_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QImage>

namespace Ui {
class pixel;
}

class pixel : public QMainWindow
{
    Q_OBJECT
    int x,y,x1,y1,x2,y2,thickness;

public:
    explicit pixel(QWidget *parent = 0);
    ~pixel();
    void paintEvent(QPaintEvent *);

private:
    Ui::pixel *ui;

public slots:
    void drawLine();
};

#endif // PIXEL_H
