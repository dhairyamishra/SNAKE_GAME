#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QTime>
#include <QRandomGenerator>
#include <QImage>
#include <QTimer>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_singlePlayerButton_clicked();

    void on_twoPlayerButton_clicked();

    void on_helpButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
