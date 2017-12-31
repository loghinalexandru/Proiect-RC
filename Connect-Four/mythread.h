#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QObject>
#include <unistd.h>
#include "mainwindow.h"


class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(class MainWindow* parent);
    class MainWindow* parent;

public slots:
    void run();

signals:
        void work_done();
};

#endif // MYTHREAD_H
