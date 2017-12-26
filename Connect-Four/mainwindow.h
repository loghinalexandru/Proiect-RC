#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "mainmenu.h"
#include "mainwindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    friend class MainMenu;
    void make_round_buttons(QPushButton * p);
    void use_player_turn();
    void set_color();
    void set_server(int fd_server);


    ~MainWindow();


private slots:
    void BackToMenu();
    void set_disc(bool is_clicked);
    void click_wrapper();

private:
    Ui::MainWindow *ui;
    char player_yellow = 0;
    char player_red = 0;
    char my_turn = 2;
    int server;
    bool already_clicked = false;
};

#endif // MAINWINDOW_H
