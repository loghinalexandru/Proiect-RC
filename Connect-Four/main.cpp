#include "mainwindow.h"
#include "mainmenu.h"
#include <QApplication>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu main_menu;
    main_menu.show();
    return a.exec();
}
