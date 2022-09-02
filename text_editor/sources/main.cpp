#include <QApplication>

#include "headers/main_window.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;
    window.show();

    return a.exec();
}
