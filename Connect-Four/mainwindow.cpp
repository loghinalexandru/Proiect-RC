#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSplashScreen>
#include "ui_mainmenu.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) ,
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags( (windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowMaximizeButtonHint);
    this->setWindowTitle("PLAYER 2");
    ui->You->setText("<font color='white'>You: </font>");
    ui->You_actuall_number->hide();
    ui->You_actuall_number->setStyleSheet("QLabel { background-color : black; color : white;}");
    ui->Opponent->setText("<font color='white'>Opponent: </font>");
    ui->Opponent_actual_number->setStyleSheet("QLabel { background-color : black; color : white;}");
    ui->Opponent_actual_number->hide();
    ui->You->hide();
    ui->Opponent->hide();
    ui->end_game_box->setStyleSheet("background-color: #FFFFFF; font: 75 italic 30pt 'Noto Sans'; font: 30pt 'Noto Sans';");
    ui->end_game_box->hide();
    ui->Rematch->hide();
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
    connect(ui->Rematch , SIGNAL(clicked(bool)) , this , SLOT(Rematch()));
    connect(ui->p1_1 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p2_1 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p3_1 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p4_1 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p5_1 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p6_1 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p1_2 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p2_2 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p3_2 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p4_2 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p5_2 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p6_2 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p1_3 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p2_3 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p3_3 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p4_3 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p5_3 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p6_3 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p1_4 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p2_4 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p3_4 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p4_4 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p5_4 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p6_4 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p1_5 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p2_5 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p3_5 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p4_5 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p5_5 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p6_5 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p1_6 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p2_6 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p3_6 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p4_6 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p5_6 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p6_6 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p1_7 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p2_7 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p3_7 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p4_7 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p5_7 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
    connect(ui->p6_7 , SIGNAL(clicked(bool)) , this , SLOT(set_disc(bool)));
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
    MainMenu * p;
    char player_rematch = 0;
    write(this->server , &player_rematch , 1);
    p = (MainMenu* )this->parentWidget();
    ::close(p->server_descriptor);
    ::close(this->server);
    p->main_menu_gui();
    this->~MainWindow();
}

void MainWindow::Rematch()
{
    MainMenu *p = (MainMenu* )this->parentWidget();
    this->ui->Back->setEnabled(false);
    this->ui->Rematch->setEnabled(false);
    char player_rematch = 1;
    write(this->server , &player_rematch , 1);
    manual_event_loop();
    read(this->server , &player_rematch , 1);
    this->hide();
    if(player_rematch == 1){

        p->play_again();
    }
    else{
        BackToMenu();
    }
}

void MainWindow::set_disc(bool is_clicked)
{
    char set_button[20];
    QPushButton * button_pressed = (QPushButton *)sender();
    wait_turn_gui();
    qApp->processEvents();
    const char * button_object_name;
    button_object_name = button_pressed->objectName().toStdString().c_str();
    write(this->server , button_object_name , strlen(button_object_name));
    qDebug() << "Am trecut de write";
    read(this->server ,set_button , sizeof(set_button));
    this->set_current_player_choice(set_button);
    qApp->processEvents();
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
    QCoreApplication::processEvents();
    memset(other_player_move , 0 , sizeof(other_player_move));
    if(read(this->server , &my_turn , 1) == -1){
        qDebug() << "O CRAPAT";
        return;
    }
    qDebug() << "GO ? : " << (int)my_turn;
    if(this->my_turn == 1){
        qApp->processEvents();
        pass_turn_gui();
        this->show();
        this->setEnabled(true);
        qApp->processEvents();
    }
    if(my_turn == 0){
        qApp->processEvents();
        this->setEnabled(false);
        this->show();
        wait_turn_gui();
        manual_event_loop();
        qApp->processEvents();
        qDebug() << "ASTEPT SA IES DIN EVENT LOOP";
        read(this->server , other_player_move , sizeof(other_player_move));
        qDebug() << "AM IESIT DIN LOOP SI AM CITIT" << other_player_move;
        if(strlen(other_player_move) > 0){
            this->set_other_player_choice(other_player_move);
            qApp->processEvents();
            use_player_turn();
            return;
        }
        else{
            qDebug() << "LUNGIMEA" << strlen(other_player_move) << ':' << other_player_move << "\n";
            qApp->processEvents();
            other_player_left();
            my_turn = 0;
            return;
        }
    }
    if((my_turn == YELLOW_PLAYER && this->player_yellow == 1 ) || (my_turn == RED_PLAYER && this->player_red == 1)){
            this->show();
            this->setEnabled(true);
            this->ui->gridLayoutWidget->hide();
            this->ui->gridLayoutWidget_2->hide();
            this->ui->gridLayoutWidget_3->hide();
            this->ui->gridLayoutWidget_4->hide();
            this->ui->gridLayoutWidget_5->hide();
            this->ui->gridLayoutWidget_6->hide();
            this->ui->gridLayoutWidget_7->hide();
            this->ui->Back->blockSignals(false);
            this->ui->end_game_box->setText("YOU ARE THE WINNER");
            this->ui->end_game_box->show();
            this->ui->Rematch->show();
            qDebug() << "WIN AICI PRIMU IF";
            read(this->server , &this_player_score , sizeof(int));
            read(this->server   , &other_player_score , sizeof(int));
            ui->You->show();
            ui->You_actuall_number->show();
            ui->You_actuall_number->setText(QString::number(this_player_score));
            ui->Opponent->show();
            ui->Opponent_actual_number->show();
            ui->Opponent_actual_number->setText(QString::number(other_player_score));
            qDebug() << this_player_score << ":" << other_player_score;
            qApp->processEvents();

    }
    if((my_turn == YELLOW_PLAYER && this->player_yellow == 0) || (my_turn == RED_PLAYER && this->player_red == 0)){
        this->show();
        this->setEnabled(true);
        this->ui->gridLayoutWidget->hide();
        this->ui->gridLayoutWidget_2->hide();
        this->ui->gridLayoutWidget_3->hide();
        this->ui->gridLayoutWidget_4->hide();
        this->ui->gridLayoutWidget_5->hide();
        this->ui->gridLayoutWidget_6->hide();
        this->ui->gridLayoutWidget_7->hide();
        this->ui->Back->blockSignals(false);
        this->ui->end_game_box->setText("YOU HAVE BEEN DEFEATED");
        this->ui->end_game_box->show();
        this->ui->Rematch->show();
        qDebug() << "WIN AICI AL DOILEA IF";
        read(this->server , &this_player_score , sizeof(int));
        read(this->server   , &other_player_score , sizeof(int));
        qDebug() << "Blocat aici";
        ui->You->show();
        ui->You_actuall_number->show();
        ui->You_actuall_number->setText(QString::number(this_player_score));
        ui->Opponent->show();
        ui->Opponent_actual_number->show();
        ui->Opponent_actual_number->setText(QString::number(other_player_score));
        qDebug() << this_player_score << ":" << other_player_score;

    }
    if(my_turn == PLAYERS_DRAW){
        this->show();
        this->setEnabled(true);
        this->ui->gridLayoutWidget->hide();
        this->ui->gridLayoutWidget_2->hide();
        this->ui->gridLayoutWidget_3->hide();
        this->ui->gridLayoutWidget_4->hide();
        this->ui->gridLayoutWidget_5->hide();
        this->ui->gridLayoutWidget_6->hide();
        this->ui->gridLayoutWidget_7->hide();
        this->ui->Back->blockSignals(false);
        this->ui->end_game_box->setText("YOU MANAGED A DRAW");
        this->ui->end_game_box->show();
        this->ui->Rematch->show();
        qApp->processEvents();
        qDebug() << "WIN AICI AL TREILEA IF";
        read(this->server ,   &this_player_score ,  sizeof(int));
        read(this->server   , &other_player_score , sizeof(int));
        qDebug() << this_player_score << ":" << other_player_score;
        qApp->processEvents();
    }

}

void MainWindow::set_server(int fd_server)
{
    qApp->processEvents();
    this->server = fd_server;
}

void MainWindow::set_other_player_choice(char * move)
{
    QPushButton* button = this->findChild<QPushButton*>(move);
    if(button != NULL){
    button->setDisabled(true);
        if(this->player_red == 1){
            button->setStyleSheet("QPushButton:disabled {background-color: #FFFF00;}");
        }
        else{
            button->setStyleSheet("QPushButton:disabled {background-color: #FF2400;}");
        }
    }
}


void MainWindow::set_current_player_choice(char * move)
{
    QPushButton* button = this->findChild<QPushButton*>(move);
    if(button != NULL){
       button->setEnabled(false);
       qDebug() << "SUNT AICI";
    }
}


void MainWindow::wait_turn_gui()
{
    QCoreApplication::processEvents();
    this->ui->gridLayoutWidget->hide();
    this->ui->gridLayoutWidget_2->hide();
    this->ui->gridLayoutWidget_3->hide();
    this->ui->gridLayoutWidget_4->hide();
    this->ui->gridLayoutWidget_5->hide();
    this->ui->gridLayoutWidget_6->hide();
    this->ui->gridLayoutWidget_7->hide();
    this->ui->end_game_box->setText("WAIT YOUR TURN");
    this->ui->Back->blockSignals(true);
    this->ui->end_game_box->show();
    this->setEnabled(false);
    QCoreApplication::processEvents();
}

void MainWindow::pass_turn_gui()
{
    QCoreApplication::processEvents();
    this->ui->gridLayoutWidget->show();
    this->ui->gridLayoutWidget_2->show();
    this->ui->gridLayoutWidget_3->show();
    this->ui->gridLayoutWidget_4->show();
    this->ui->gridLayoutWidget_5->show();
    this->ui->gridLayoutWidget_6->show();
    this->ui->gridLayoutWidget_7->show();
    this->ui->Back->blockSignals(false);
    this->setEnabled(true);
    this->ui->end_game_box->hide();
    QCoreApplication::processEvents();
}

void MainWindow::manual_event_loop()
{
    int exit_value = 0;
    fd_set readfds;
    struct timeval waiting_time;
    while(exit_value == 0){
    FD_ZERO(&readfds);
    FD_SET(this->server , &readfds);
    waiting_time.tv_sec = 0;
    waiting_time.tv_usec = 10000;
    exit_value = select(this->server + 1 , &readfds , NULL , NULL  , &waiting_time);
     if(exit_value == -1){
        qDebug() << "FAILED";
        return;
     }
     qApp->processEvents();
    }
}

void MainWindow::closeEvent(QCloseEvent *bar){
    qDebug() << "AM AJUNS LA DESTRUCTOR";
    MainMenu * p = (MainMenu* )this->parent();
    p->~MainMenu();
    this->~MainWindow();
}

void MainWindow::other_player_left()
{
    this->show();
    this->setEnabled(true);
    this->ui->gridLayoutWidget->hide();
    this->ui->gridLayoutWidget_2->hide();
    this->ui->gridLayoutWidget_3->hide();
    this->ui->gridLayoutWidget_4->hide();
    this->ui->gridLayoutWidget_5->hide();
    this->ui->gridLayoutWidget_6->hide();
    this->ui->gridLayoutWidget_7->hide();
    this->ui->Back->blockSignals(false);
    this->ui->end_game_box->setText("OTHER PLAYER LEFT");
    this->ui->end_game_box->show();
}

