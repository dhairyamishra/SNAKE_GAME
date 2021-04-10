#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "singleplayer.h"
#include "twoplayer.h"
#include "helpwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/futma/Desktop/Software Patterns and Teams/SnakeFinal/SnakePic.jpg");
    ui->label->setPixmap(pix.scaled(900,370,Qt::KeepAspectRatio));
    setFixedSize(900,400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_singlePlayerButton_clicked()
{
    this->close();
    SinglePlayer singleplayer;
    singleplayer.exec();
}

void MainWindow::on_twoPlayerButton_clicked()
{
    this->close();
    TwoPlayer twoplayer;
    twoplayer.exec();
}

void MainWindow::on_helpButton_clicked()
{
    HelpWindow helpwindow;
    helpwindow.setModal(true);
    helpwindow.exec();
}
