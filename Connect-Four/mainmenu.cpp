#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include <QDebug>
#define DEFAULT_PORT 2024
#define DEFAULT_SERVER "127.0.0.1"


MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)

{
    ui->setupUi(this);
    this->ui->label->hide();
    connect(ui->Play , SIGNAL(released()) , this , SLOT(waiting_players_gui()));
    connect(ui->Exit , SIGNAL(released()) , this , SLOT(PressExit()));
}

MainMenu::~MainMenu()
{
    delete ui;
    ::close(this->server_descriptor);
    delete(the_game);
}

void MainMenu::PressPlay()
{

    sockaddr_in server;
    server_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(server_descriptor == - 1){
        qDebug() << "ERROR ON SOCKET CREATION";
        exit(0);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(DEFAULT_SERVER);
    server.sin_port = htons(DEFAULT_PORT);
    if(::connect(this->server_descriptor , (sockaddr*)&server , sizeof(sockaddr)) == -1){
        qDebug() << "ERROR ON CONNECT";
        exit(1);
    }
    the_game = new class MainWindow(this);
    the_game->wait_turn_gui();
    the_game->set_server(server_descriptor);
    the_game->manual_event_loop();
    ::read(the_game->server , &the_game->player_red , 1);
    ::read(the_game->server , &the_game->player_yellow , 1);
    this->hide();
    the_game->set_color();
    the_game->use_player_turn();

}

void MainMenu::PressExit()
{
    close();
}

int MainMenu::get_server_descriptor()
{
    return this->server_descriptor;
}


void MainMenu::waiting_players_gui()
{
    this->ui->Play->hide();
    this->ui->Exit->hide();
    this->ui->label->show();
    qApp->processEvents();
    this->PressPlay();
}


void MainMenu::main_menu_gui()
{
    this->show();
    this->ui->Play->show();
    this->ui->Exit->show();
    this->ui->label->hide();
    qApp->processEvents();
}


void MainMenu::play_again()
{
    the_game = new class MainWindow(this);
    the_game->wait_turn_gui();
    the_game->set_server(server_descriptor);
    ::read(the_game->server , &the_game->player_red , 1);
    ::read(the_game->server , &the_game->player_yellow , 1);
    this->hide();
    the_game->set_color();
    the_game->use_player_turn();
    qApp->processEvents();
    //make_thread();

}
