#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QThread>
#include <QObject>
#include <string>
#include "mainmenu.h"
#include "mainwindow.h"
#define RED_PLAYER  2
#define YELLOW_PLAYER  3
#define PLAYERS_DRAW 5
#define PLAYER_DISCONNECT 9


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget * parent = 0);
    friend class MainMenu;
    void make_round_buttons(QPushButton * p);
    void set_server(int fd_server);
    void set_other_player_choice(char * move);
    void set_current_player_choice(char * move);
    void other_player_left();
    void wait_turn_gui();
    void pass_turn_gui();
    void manual_event_loop();
    void player_left_gui();
    void closeEvent(QCloseEvent * bar);
    ~MainWindow();



public slots:
    void BackToMenu();
    void Rematch();
    void set_disc(bool is_clicked);
    void use_player_turn();
    void set_color();

private:
    Ui::MainWindow *ui;
    char my_turn = 2;
    int server;
    char player_yellow = 2;
    char player_red = 2;
    int this_player_score = 0;
    int other_player_score = 0;
    char turn = 0;
    char action_made = 0;
};

#endif // MAINWINDOW_H
