#include "menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w("#44B28A", nullptr);
    w.show();
    return a.exec();
}
