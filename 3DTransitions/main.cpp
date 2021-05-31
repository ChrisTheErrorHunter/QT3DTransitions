#include "qt3dtransitions.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QT3DTransitions w;
    w.show();
    return a.exec();
}
