#ifndef TWOPLAYERPYTHON_H
#define TWOPLAYERPYTHON_H

#include <QDialog>
#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QTime>
#include <QRandomGenerator>
#include <QImage>
#include <QTimer>

namespace Ui {
class TwoPlayerPython;
}

class TwoPlayerPython : public QDialog
{
    Q_OBJECT

public:
    explicit TwoPlayerPython(QWidget *parent = nullptr);
    ~TwoPlayerPython();

private:
    Ui::TwoPlayerPython *ui;

    QTimer *timer;
    static const int B_WIDTH = 300;
    static const int B_HEIGHT = 300;
    static const int DOT_SIZE = 10;
    static const int ALL_DOTS = 900;
    static const int RAND_POS = 29;
    int DELAY = 200;

    int timerId;
    int Score = 0;
    int Score2 = 0;
    int dots;
    int dots2;
    int difficulty= 0;
    int speed;
    int gamemode = 0;

    int apple_x =0;
    int apple_y = 0;

    int x[ALL_DOTS];
    int y[ALL_DOTS];
    int x2[ALL_DOTS];
    int y2[ALL_DOTS];

    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;
    bool inGame;

    bool leftDirection2;
    bool rightDirection2;
    bool upDirection2;
    bool downDirection2;
    bool inGame2;

    bool setup;

    void checkScore(QPainter &qp);
    void initGame(int mode);
    void locateApple();
    void checkApple();
    void checkCollision();
    void move();
    void doDrawing();
    void gameOver(QPainter &);

protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *e);
private slots:
    void timerEventS();

};

#endif // TWOPLAYERPYTHON_H
