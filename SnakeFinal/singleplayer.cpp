#include "singleplayer.h"
#include "ui_singleplayer.h"
#include "mainmenu.h"
#include "singleplayerslug.h"
#include "singleplayerworm.h"
#include "singleplayerpython.h"

SinglePlayer::SinglePlayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SinglePlayer)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/futma/Desktop/Software Patterns and Teams/SnakeFinal/SnakePic.jpg");
    ui->label->setPixmap(pix.scaled(900,370,Qt::KeepAspectRatio));
    setFixedSize(900,400);
}

SinglePlayer::~SinglePlayer()
{
    delete ui;
}

void SinglePlayer::on_backButton_clicked()
{
    this->close();
    MainMenu mainmenu;
    mainmenu.exec();
}

void SinglePlayer::on_slugButton_clicked()
{
    //Start Single Player Snake on Normal Game Mode
    SinglePlayerSlug sluggame;
    sluggame.exec();
}

void SinglePlayer::on_wormButton_clicked()
{
    //Start Single Player Snake on Normal Game Mode
    SinglePlayerWorm wormgame;
    wormgame.exec();
}

void SinglePlayer::on_pythonButton_clicked()
{
    //Start Single Player Snake on Hard Game Mode
    SinglePlayerPython pythongame;
    pythongame.exec();
}
