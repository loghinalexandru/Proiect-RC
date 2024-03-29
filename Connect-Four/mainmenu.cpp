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
    this->setWindowTitle("ConnectFour");
    this->setWindowFlags(Qt::Dialog);
    this->setFixedSize(779 , 384);
    this->setStyleSheet("QMainWindow {background-color : black;} QPushButton:hover{background-color: red;}");
    QPixmap pixmap("connect-four-wide.png");
    this->ui->Title->setPixmap(pixmap);
    this->ui->Title->show();
    this->ui->Title->setScaledContents(true);
    connect(ui->Play , SIGNAL(released()) , this , SLOT(waiting_players_gui()));
    connect(ui->Exit , SIGNAL(released()) , this , SLOT(PressExit()));
}

MainMenu::~MainMenu()
{
    ::close(this->server_descriptor);
    delete ui;
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
        server_not_online_gui();
        return;
    }
    the_game = new class MainWindow(this);
    the_game->setAttribute(Qt::WA_DeleteOnClose);
    the_game->wait_turn_gui();
    the_game->set_server(server_descriptor);
    if(the_game->manual_event_loop() == -1){
        qDebug() << "SERVER";
        return;
    }
    if(read(the_game->server , &the_game->player_red , 1) <= 0){
        server_not_online_gui();
    }
    if(read(the_game->server , &the_game->player_yellow , 1) <= 0){
        server_not_online_gui();
    }
    this->hide();
    the_game->set_color();
    the_game->use_player_turn();

}

void MainMenu::PressExit()
{
    this->close();
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
    delete the_game;
    this->show();
    this->ui->Play->show();
    this->ui->Exit->show();
    this->ui->label->hide();
    qApp->processEvents();
}


void MainMenu::play_again()
{
    delete the_game;
    the_game = new class MainWindow(this);
    the_game->wait_turn_gui();
    the_game->set_server(server_descriptor);
    ::read(the_game->server , &the_game->player_red , 1);
    ::read(the_game->server , &the_game->player_yellow , 1);
    this->hide();
    the_game->set_color();
    the_game->use_player_turn();
    qApp->processEvents();

}

void MainMenu::server_not_online_gui()
{
    this->show();
    this->ui->Play->hide();
    this->ui->Exit->hide();
    this->ui->label->show();
    this->ui->label->setText("SERVER OFFLINE");
}
