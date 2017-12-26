#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    this->hide();
}

void MainWindow::set_disc(bool is_clicked)
{
    char set_button[20];
    QPushButton * button_pressed = (QPushButton *)sender();
    this->hide();
    const char * t;
    t = button_pressed->objectName().toStdString().c_str();
    //qDebug() << "AM FOST APELAT" ;
    write(this->server , t , 20);
    read(this->server ,set_button , sizeof(set_button));
    this->set_current_player_choice(set_button);
    use_player_turn();

}

void MainWindow::set_color()
{
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
        return;
    }
    this->already_clicked = false;
    //qDebug() << (int)this->my_turn;
    if(this->my_turn > 0){
        this->show();
        this->setEnabled(true);
    }
    else{
        this->setEnabled(false);
        read(this->server , other_player_move , sizeof(other_player_move));
        this->set_other_player_choice(other_player_move);
        use_player_turn();
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
    if(strcmp(move , "p1_1") == 0){
        ui->p1_1->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p1_1->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p1_1->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p2_1") == 0){
        ui->p2_1->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p2_1->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p2_1->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p3_1") == 0){
        ui->p3_1->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p3_1->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p3_1->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p4_1") == 0){
        ui->p4_1->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p4_1->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p4_1->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p5_1") == 0){
        ui->p5_1->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p5_1->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p5_1->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p6_1") == 0){
        ui->p6_1->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p6_1->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p6_1->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p1_2") == 0){
        ui->p1_2->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p1_2->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p1_2->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p2_2") == 0){
        ui->p2_2->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p2_2->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p2_2->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p3_2") == 0){
        ui->p3_2->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p3_2->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p3_2->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p4_2") == 0){
        ui->p4_2->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p4_2->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p4_2->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p5_2") == 0){
        ui->p5_2->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p5_2->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p5_2->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p6_2") == 0){
        ui->p6_2->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p6_2->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p6_2->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p1_3") == 0){
        ui->p1_3->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p1_3->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p1_3->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p2_3") == 0){
        ui->p2_3->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p2_3->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p2_3->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p3_3") == 0){
        ui->p3_3->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p3_3->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p3_3->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p4_3") == 0){
        ui->p4_3->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p4_3->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p4_3->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p5_3") == 0){
        ui->p5_3->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p5_3->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p5_3->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p6_3") == 0){
        ui->p6_3->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p6_3->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p6_3->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p1_4") == 0){
        ui->p1_4->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p1_4->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p1_4->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p2_4") == 0){
        ui->p2_4->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p2_4->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p2_4->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p3_4") == 0){
        ui->p3_4->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p3_4->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p3_4->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p4_4") == 0){
        ui->p4_4->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p4_4->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p4_4->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p5_4") == 0){
        ui->p5_4->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p5_4->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p5_4->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p6_4") == 0){
        ui->p6_4->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p6_4->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p6_4->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p1_5") == 0){
        ui->p1_5->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p1_5->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p1_5->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p2_5") == 0){
        ui->p2_5->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p2_5->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p2_5->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p3_5") == 0){
        ui->p3_5->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p3_5->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p3_5->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p4_5") == 0){
        ui->p4_5->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p4_5->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p4_5->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p5_5") == 0){
        ui->p5_5->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p5_5->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p5_5->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p6_5") == 0){
        ui->p6_5->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p6_5->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p6_5->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p1_6") == 0){
        ui->p1_6->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p1_6->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p1_6->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p2_6") == 0){
        ui->p2_6->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p2_6->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p2_6->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p3_6") == 0){
        ui->p3_6->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p3_6->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p3_6->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p4_6") == 0){
        ui->p4_6->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p4_6->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p4_6->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p5_6") == 0){
        ui->p5_6->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p5_6->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p5_6->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p6_6") == 0){
        ui->p6_6->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p6_6->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p6_6->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p1_7") == 0){
        ui->p1_7->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p1_7->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p1_7->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p2_7") == 0){
        ui->p2_7->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p2_7->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p2_7->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p3_7") == 0){
        ui->p3_7->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p3_7->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p3_7->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p4_7") == 0){
        ui->p4_7->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p4_7->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p4_7->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p5_7") == 0){
        ui->p5_7->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p5_7->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p5_7->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
    if(strcmp(move , "p6_7") == 0){
        ui->p6_7->setDisabled(true);
        if(this->player_yellow == 1){
            ui->p6_7->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
        if(this->player_red == 1){
            ui->p6_7->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        return;
    }
}


void MainWindow::set_current_player_choice(char * move){
    if(strcmp(move , "p1_1") == 0){
        ui->p1_1->setDisabled(true);
    }
    if(strcmp(move , "p2_1") == 0){
        ui->p2_1->setDisabled(true);

    }
    if(strcmp(move , "p3_1") == 0){
        ui->p3_1->setDisabled(true);

    }
    if(strcmp(move , "p4_1") == 0){
        ui->p4_1->setDisabled(true);

    }
    if(strcmp(move , "p5_1") == 0){
        ui->p5_1->setDisabled(true);

    }
    if(strcmp(move , "p6_1") == 0){
        ui->p6_1->setDisabled(true);

    }
    if(strcmp(move , "p1_2") == 0){
        ui->p1_2->setDisabled(true);

    }
    if(strcmp(move , "p2_2") == 0){
        ui->p2_2->setDisabled(true);

    }
    if(strcmp(move , "p3_2") == 0){
        ui->p3_2->setDisabled(true);

    }
    if(strcmp(move , "p4_2") == 0){
        ui->p4_2->setDisabled(true);

    }
    if(strcmp(move , "p5_2") == 0){
        ui->p5_2->setDisabled(true);

    }
    if(strcmp(move , "p6_2") == 0){
        ui->p6_2->setDisabled(true);

    }
    if(strcmp(move , "p1_3") == 0){
        ui->p1_3->setDisabled(true);

    }
    if(strcmp(move , "p2_3") == 0){
        ui->p2_3->setDisabled(true);

    }
    if(strcmp(move , "p3_3") == 0){
        ui->p3_3->setDisabled(true);

    }
    if(strcmp(move , "p4_3") == 0){
        ui->p4_3->setDisabled(true);

    }
    if(strcmp(move , "p5_3") == 0){
        ui->p5_3->setDisabled(true);

    }
    if(strcmp(move , "p6_3") == 0){
        ui->p6_3->setDisabled(true);

    }
    if(strcmp(move , "p1_4") == 0){
        ui->p1_4->setDisabled(true);

    }
    if(strcmp(move , "p2_4") == 0){
        ui->p2_4->setDisabled(true);

    }
    if(strcmp(move , "p3_4") == 0){
        ui->p3_4->setDisabled(true);

    }
    if(strcmp(move , "p4_4") == 0){
        ui->p4_4->setDisabled(true);

    }
    if(strcmp(move , "p5_4") == 0){
        ui->p5_4->setDisabled(true);

    }
    if(strcmp(move , "p6_4") == 0){
        ui->p6_4->setDisabled(true);

    }
    if(strcmp(move , "p1_5") == 0){
        ui->p1_5->setDisabled(true);

    }
    if(strcmp(move , "p2_5") == 0){
        ui->p2_5->setDisabled(true);

    }
    if(strcmp(move , "p3_5") == 0){
        ui->p3_5->setDisabled(true);

    }
    if(strcmp(move , "p4_5") == 0){
        ui->p4_5->setDisabled(true);

    }
    if(strcmp(move , "p5_5") == 0){
        ui->p5_5->setDisabled(true);

    }
    if(strcmp(move , "p6_5") == 0){
        ui->p6_5->setDisabled(true);

    }
    if(strcmp(move , "p1_6") == 0){
        ui->p1_6->setDisabled(true);

    }
    if(strcmp(move , "p2_6") == 0){
        ui->p2_6->setDisabled(true);

    }
    if(strcmp(move , "p3_6") == 0){
        ui->p3_6->setDisabled(true);

    }
    if(strcmp(move , "p4_6") == 0){
        ui->p4_6->setDisabled(true);

    }
    if(strcmp(move , "p5_6") == 0){
        ui->p5_6->setDisabled(true);

    }
    if(strcmp(move , "p6_6") == 0){
        ui->p6_6->setDisabled(true);

    }
    if(strcmp(move , "p1_7") == 0){
        ui->p1_7->setDisabled(true);

    }
    if(strcmp(move , "p2_7") == 0){
        ui->p2_7->setDisabled(true);

    }
    if(strcmp(move , "p3_7") == 0){
        ui->p3_7->setDisabled(true);

    }
    if(strcmp(move , "p4_7") == 0){
        ui->p4_7->setDisabled(true);

    }
    if(strcmp(move , "p5_7") == 0){
        ui->p5_7->setDisabled(true);

    }
    if(strcmp(move , "p6_7") == 0){
        ui->p6_7->setDisabled(true);

    }
}
