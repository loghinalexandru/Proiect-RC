#include "mythread.h"
#include <QDebug>
#include <QObject>
#include <QMutex>
#include "mainwindow.h"

MyThread::MyThread(MainWindow * parent)
{
    qDebug() << "this";
    this->parent = parent;
    connect(this , SIGNAL(work_done()) , parent , SLOT(use_player_turn()) , Qt::DirectConnection);
}

void MyThread::run()
{
   qApp->processEvents();
   MainWindow * game;
   game = (MainWindow *) this->parent;
   ::read(game->server , &game->player_red , 1);
   ::read(game->server , &game->player_yellow , 1);
   qDebug() << parent->thread() << "parent thread " << this->currentThreadId() << "curent thread";
   game->set_color();
   qApp->processEvents();
   MainMenu * p = (MainMenu *) parent->parent();
   p->hide();
   qApp->processEvents();
   emit work_done();
   qApp->processEvents();
}


