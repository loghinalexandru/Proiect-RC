#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QApplication>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string>
#include <iostream>
#include <arpa/inet.h>
#include <fcntl.h>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = 0);
    friend class MainWindow;
    int get_server_descriptor();
    void main_menu_gui();
    ~MainMenu();

public slots:
    void PressPlay();
    void PressExit();
    void waiting_players_gui();



private:
    Ui::MainMenu *ui;
    int server_descriptor;
};

#endif // MAINMENU_H
