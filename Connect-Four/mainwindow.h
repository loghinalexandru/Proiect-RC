#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "mainmenu.h"
#include "mainwindow.h"
#define RED_PLAYER  2
#define YELLOW_PLAYER  3


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
    void set_other_player_choice(char * move);
    void set_current_player_choice(char * move);
    void other_player_left();
    void wait_turn_gui();
    void pass_turn_gui();
    ~MainWindow();


private slots:
    void BackToMenu();
    void set_disc(bool is_clicked);

private:
    Ui::MainWindow *ui;
    char player_yellow = 2;
    char player_red = 2;
    char my_turn = 2;
    int server;
};

#endif // MAINWINDOW_H
