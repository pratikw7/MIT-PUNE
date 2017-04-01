#include "pixel.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pixel w;
    w.show();

    return a.exec();
}
