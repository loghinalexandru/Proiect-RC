#include "mainwindow.h"
#include "mainmenu.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(true);
    QSplashScreen * intro = new QSplashScreen;
    MainMenu *main_menu = new MainMenu();
    main_menu->setAttribute(Qt::WA_DeleteOnClose);
    intro->setPixmap(QPixmap("./connectfour_intro.jpg"));
    intro->show();
    QGraphicsOpacityEffect *opacity;
    opacity = new QGraphicsOpacityEffect(intro);
    intro->setGraphicsEffect(opacity);
    QPropertyAnimation *anim = new QPropertyAnimation(opacity, "opacity");
    anim->setEasingCurve(QEasingCurve::OutQuad);
    anim->setStartValue(0.01);
    anim->setEndValue(0.85);
    anim->setDuration(30000);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
    QTimer::singleShot(2000 , intro , SLOT(close()));
    QTimer::singleShot(2000 , main_menu , SLOT(show()));
    return a.exec();
}

