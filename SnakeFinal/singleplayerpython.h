#ifndef SINGLEPLAYERPYTHON_H
#define SINGLEPLAYERPYTHON_H

#include <QDialog>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QTime>
#include <QRandomGenerator>
#include <QImage>
#include <QTimer>

namespace Ui {
class SinglePlayerPython;
}

class SinglePlayerPython : public QDialog
{
    Q_OBJECT

public:
    explicit SinglePlayerPython(QWidget *parent = nullptr);
    ~SinglePlayerPython();

private slots:
    void timerEventS();

private:
    Ui::SinglePlayerPython *ui;

    QTimer *timer;

    QRectF bodyCirc;
    QRectF headRec;
    QRectF AppleCirc;



    static const int B_WIDTH = 300;
    static const int B_HEIGHT = 300;
    static const int DOT_SIZE = 10;
    static const int ALL_DOTS = 900;
    static const int RAND_POS = 29;
    static const int DELAY = 200;

    int timerId;
    int Score = 0;
    int dots;
    int apple_x =0;
    int apple_y = 0;
    int x[ALL_DOTS];
    int y[ALL_DOTS];

    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;
    bool inGame;

    void checkScore(QPainter &qp);
    void initGame();
    void locateApple();
    void checkApple();
    void checkCollision();
    void move();
    void doDrawing();
    void gameOver(QPainter &);

protected:
    void paintEvent(QPaintEvent *);

    void keyPressEvent(QKeyEvent *e);
};

#endif // SINGLEPLAYERPYTHON_H
