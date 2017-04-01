#include <QtGui/QApplication>
#include "pixel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pixel w;
    w.show();
    
    return a.exec();
}
