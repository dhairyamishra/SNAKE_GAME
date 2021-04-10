#include "twoplayer.h"
#include "ui_twoplayer.h"
#include "mainmenu.h"
#include "twoplayerslug.h"
#include "twoplayerworm.h"
#include "twoplayerpython.h"

TwoPlayer::TwoPlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TwoPlayer)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/futma/Desktop/Software Patterns and Teams/SnakeFinal/SnakePic.jpg");
    ui->label->setPixmap(pix.scaled(900,370,Qt::KeepAspectRatio));
    setFixedSize(900,400);
}

TwoPlayer::~TwoPlayer()
{
    delete ui;
}

void TwoPlayer::on_backButton_clicked()
{
    this->close();
    MainMenu mainmenu;
    mainmenu.exec();
}

void TwoPlayer::on_slugButton_clicked()
{
    //Start Two Player Snake on Easy Game Mode
    TwoPlayerSlug multislug;
    multislug.exec();
}

void TwoPlayer::on_wormButton_clicked()
{
    //Start Two Player Snake on Normal Game Mode
    TwoPlayerWorm multiworm;
    multiworm.exec();
}

void TwoPlayer::on_pythonButton_clicked()
{
    //Start Two Player Snake on Hard Game Mode
    TwoPlayerPython multipython;
    multipython.exec();
}
