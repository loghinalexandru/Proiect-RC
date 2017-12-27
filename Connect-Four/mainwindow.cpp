#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->end_game_box->setStyleSheet("background-color: #FFFFFF;");
    ui->end_game_box->hide();
    make_round_buttons(ui->p1_1);
    make_round_buttons(ui->p2_1);
    make_round_buttons(ui->p3_1);
    make_round_buttons(ui->p4_1);
    make_round_buttons(ui->p5_1);
    make_round_buttons(ui->p6_1);
    make_round_buttons(ui->p1_2);
    make_round_buttons(ui->p2_2);
    make_round_buttons(ui->p3_2);
    make_round_buttons(ui->p4_2);
    make_round_buttons(ui->p5_2);
    make_round_buttons(ui->p6_2);
    make_round_buttons(ui->p1_3);
    make_round_buttons(ui->p2_3);
    make_round_buttons(ui->p3_3);
    make_round_buttons(ui->p4_3);
    make_round_buttons(ui->p5_3);
    make_round_buttons(ui->p6_3);
    make_round_buttons(ui->p1_4);
    make_round_buttons(ui->p2_4);
    make_round_buttons(ui->p3_4);
    make_round_buttons(ui->p4_4);
    make_round_buttons(ui->p5_4);
    make_round_buttons(ui->p6_4);
    make_round_buttons(ui->p1_5);
    make_round_buttons(ui->p2_5);
    make_round_buttons(ui->p3_5);
    make_round_buttons(ui->p4_5);
    make_round_buttons(ui->p5_5);
    make_round_buttons(ui->p6_5);
    make_round_buttons(ui->p1_6);
    make_round_buttons(ui->p2_6);
    make_round_buttons(ui->p3_6);
    make_round_buttons(ui->p4_6);
    make_round_buttons(ui->p5_6);
    make_round_buttons(ui->p6_6);
    make_round_buttons(ui->p1_7);
    make_round_buttons(ui->p2_7);
    make_round_buttons(ui->p3_7);
    make_round_buttons(ui->p4_7);
    make_round_buttons(ui->p5_7);
    make_round_buttons(ui->p6_7);
    connect(ui->Back , SIGNAL(clicked(bool)) , this , SLOT(BackToMenu()));
    connect(ui->p1_1 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p2_1 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p3_1 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p4_1 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p5_1 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p6_1 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p1_2 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p2_2 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p3_2 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p4_2 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p5_2 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p6_2 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p1_3 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p2_3 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p3_3 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p4_3 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p5_3 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p6_3 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p1_4 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p2_4 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p3_4 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p4_4 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p5_4 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p6_4 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p1_5 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p2_5 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p3_5 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p4_5 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p5_5 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p6_5 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p1_6 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p2_6 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p3_6 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p4_6 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p5_6 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p6_6 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p1_7 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p2_7 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p3_7 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p4_7 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p5_7 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
    connect(ui->p6_7 , SIGNAL(clicked(bool)) , this , SLOT(click_wrapper()));
}


MainWindow::~MainWindow()
{
    delete ui;
    ::close(server);
}

void MainWindow::make_round_buttons(QPushButton *p){
    p->setFixedHeight(81);
    p->setFixedWidth(81);
    QRect *rect = new QRect(0,0,80,80);
    QRegion* region = new QRegion(*rect,QRegion::Ellipse);
    p->setMask(*region);
}

void MainWindow::BackToMenu()
{
    this->parentWidget()->show();
    this->~MainWindow();
}

void MainWindow::set_disc(bool is_clicked)
{
    char set_button[20];
    QPushButton * button_pressed = (QPushButton *)sender();
    this->hide();
    const char * button_object_name;
    button_object_name = button_pressed->objectName().toStdString().c_str();
    write(this->server , button_object_name , 20);
    read(this->server ,set_button , sizeof(set_button));
    this->set_current_player_choice(set_button);
    use_player_turn();

}

void MainWindow::set_color()
{
    qDebug() << (int) player_red << ' ' << (int)player_yellow;
    if(player_red == true){
         this->centralWidget()->setStyleSheet("QPushButton:hover {background-color: #FF2400;} QPushButton:disabled {background-color: #FF2400 ;} QPushButton {background-color: #FFFFFF; border: 1px solid black;border-radius: 5px;} ");
         return;
    }
    if(player_yellow == true){
         this->centralWidget()->setStyleSheet("QPushButton:hover {background-color: #FFFF00;} QPushButton:disabled {background-color: #FFFF00;} QPushButton {background-color: #FFFFFF; border: 1px solid black;border-radius: 5px;} ");
         return;
    }
}

void MainWindow::use_player_turn()
{
    char other_player_move[20];
    memset(other_player_move , 0 , sizeof(other_player_move));
    //qDebug() <<"SUNT AICI";
    if(read(this->server , &my_turn , 1) == -1){
        qDebug() << "O CRAPAT";
        return;
    }
    this->already_clicked = false;
    qDebug() << (int)this->my_turn;
    if(this->my_turn == 1){
        this->show();
        this->setEnabled(true);
    }
    if(my_turn == 0){
        this->setEnabled(false);
        read(this->server , other_player_move , sizeof(other_player_move));
        qDebug() << "CRAPA LA READ";
        qDebug() << other_player_move;
        if(strlen(other_player_move) > 0){
           this->set_other_player_choice(other_player_move);
        }
        else{
            read(this->server , &my_turn , 1);
        }
        use_player_turn();
    }
    if(my_turn == YELLOW_PLAYER && this->player_yellow == 1){
            this->show();
            this->setEnabled(true);
            this->ui->gridLayoutWidget->hide();
            this->ui->gridLayoutWidget_2->hide();
            this->ui->gridLayoutWidget_3->hide();
            this->ui->gridLayoutWidget_4->hide();
            this->ui->gridLayoutWidget_5->hide();
            this->ui->gridLayoutWidget_6->hide();
            this->ui->gridLayoutWidget_7->hide();
            this->ui->end_game_box->setText("YOU ARE THE WINNER");
            this->ui->end_game_box->show();
    }
    if(my_turn == YELLOW_PLAYER && this->player_yellow == 0){
        this->show();
        this->setEnabled(true);
        this->ui->gridLayoutWidget->hide();
        this->ui->gridLayoutWidget_2->hide();
        this->ui->gridLayoutWidget_3->hide();
        this->ui->gridLayoutWidget_4->hide();
        this->ui->gridLayoutWidget_5->hide();
        this->ui->gridLayoutWidget_6->hide();
        this->ui->gridLayoutWidget_7->hide();
        this->ui->end_game_box->setText("YOU HAVE BEEN DEFEATED");
        this->ui->end_game_box->show();
    }
    if(my_turn == RED_PLAYER && this->player_red == 1){
        this->show();
        this->setEnabled(true);
        this->ui->gridLayoutWidget->hide();
        this->ui->gridLayoutWidget_2->hide();
        this->ui->gridLayoutWidget_3->hide();
        this->ui->gridLayoutWidget_4->hide();
        this->ui->gridLayoutWidget_5->hide();
        this->ui->gridLayoutWidget_6->hide();
        this->ui->gridLayoutWidget_7->hide();
        this->ui->end_game_box->setText("YOU ARE THE WINNER");
        this->ui->end_game_box->show();
    }
    if(my_turn == RED_PLAYER && this->player_red == 0){
        this->show();
        this->setEnabled(true);
        this->ui->gridLayoutWidget->hide();
        this->ui->gridLayoutWidget_2->hide();
        this->ui->gridLayoutWidget_3->hide();
        this->ui->gridLayoutWidget_4->hide();
        this->ui->gridLayoutWidget_5->hide();
        this->ui->gridLayoutWidget_6->hide();
        this->ui->gridLayoutWidget_7->hide();
        this->ui->end_game_box->setText("YOU HAVE BEEN DEFEATED");
        this->ui->end_game_box->show();
    }
}

void MainWindow::set_server(int fd_server)
{
    this->server = fd_server;
}

void MainWindow::click_wrapper()
{
    if(this->already_clicked == false){
        this->already_clicked = true;
        set_disc(true);
    }
    return;
}


void MainWindow::set_other_player_choice(char * move)
{
    QPushButton* button = this->findChild<QPushButton*>(move);
    button->setDisabled(true);
    if(this->player_red == 1){
        button->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
    }
    else{
        button->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
    }
}


void MainWindow::set_current_player_choice(char * move)
{
    QPushButton* button = this->findChild<QPushButton*>(move);
    button->setEnabled(false);
}

void other_player_left()
{

}
