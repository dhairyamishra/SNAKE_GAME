#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "singleplayer.h"
#include "twoplayer.h"
#include "helpwindow.h"

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/futma/Desktop/Software Patterns and Teams/SnakeFinal/SnakePic.jpg");
    ui->label->setPixmap(pix.scaled(900,370,Qt::KeepAspectRatio));
    setFixedSize(900,400);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_singlePlayerButton_clicked()
{
    this->close();
    SinglePlayer singleplayer;
    singleplayer.exec();
}

void MainMenu::on_twoPlayerButton_clicked()
{
    this->close();
    TwoPlayer twoplayer;
    twoplayer.exec();
}

void MainMenu::on_helpButton_clicked()
{
    HelpWindow helpwindow;
    helpwindow.setModal(true);
    helpwindow.exec();
}


