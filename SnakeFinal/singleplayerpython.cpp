#include "singleplayerpython.h"
#include "ui_singleplayerpython.h"

SinglePlayerPython::SinglePlayerPython(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SinglePlayerPython)
{
    ui->setupUi(this);

    leftDirection = false;
    rightDirection = true;
    upDirection = false;
    downDirection = false;
    inGame = true;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(timerEventS()));

    setFixedSize(B_WIDTH+1, B_HEIGHT+100);

    initGame();

}

SinglePlayerPython::~SinglePlayerPython()
{
    delete ui;
}



void SinglePlayerPython::initGame()
{

    dots = 3;

    for (int z = 0; z < dots; z++) {
        x[z] = 50 - z * 10;
        y[z] = 50;
    }
    locateApple();
    timer->start(DELAY-150);

}

void SinglePlayerPython::locateApple()
{

    int r =  (QRandomGenerator::global()->bounded(29)*10);
    apple_x = (r);

    r =  (QRandomGenerator::global()->bounded(29)*10);
    apple_y = (r);
}

void SinglePlayerPython::checkApple()
{
    if ((x[0] == apple_x) && (y[0] == apple_y)) {

            dots++;

            locateApple();
        }
}

void SinglePlayerPython::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    doDrawing();

}

void SinglePlayerPython::timerEventS()
{
    if (inGame) {
        checkApple();
        move();
        checkCollision();
    }
    repaint();
}

void SinglePlayerPython::checkScore(QPainter &qp)
{
    QFont font("Courier", 10, QFont::DemiBold, Qt::red);
    qp.setFont(font);

    qp.setPen(10);
    Score = dots*10 - 30;
    QString message = "Score: " + QString::number(Score);

    qp.drawText(0, 320, message);

}

void SinglePlayerPython::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();

    if ((key == Qt::Key_Left) && (!rightDirection)) {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Right) && (!leftDirection)) {
        rightDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Up) && (!downDirection)) {
        upDirection = true;
        rightDirection = false;
        leftDirection = false;
    }

    if ((key == Qt::Key_Down) && (!upDirection)) {
        downDirection = true;
        rightDirection = false;
        leftDirection = false;
    }

    QWidget::keyPressEvent(e);
    if(!inGame)
    {
        if(key == Qt::Key_R)
        {
          inGame = true;
          initGame();
        }
    }
}

void SinglePlayerPython::doDrawing()
{
    QPainter qp(this);
    qp.setPen(5);
    qp.drawRect(0,0,B_WIDTH,B_HEIGHT);

    if (inGame)
    {
        qp.setBrush(Qt::blue);
        qp.drawRect(apple_x, apple_y, DOT_SIZE,DOT_SIZE);

        for (int z = 0; z < dots; z++) {
            if (z == 0) {
                qp.setBrush(Qt::red);
                qp.drawEllipse(x[z], y[z], DOT_SIZE,DOT_SIZE);
            } else {
                qp.setBrush(Qt::green);
                qp.drawEllipse(x[z], y[z], DOT_SIZE,DOT_SIZE);
            }
        }
    checkScore(qp);
    } else {

        gameOver(qp);
    }
}

void SinglePlayerPython::gameOver(QPainter &qp)
{
    QString message = "Game over:";
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);

    QString message2 = "Score: " + QString::number(Score);

    QString message3 = "Press R to Retry";
    QString message4 = "Or click the X to";
    QString message5 = "choose a new";
    QString message6 = "game mode";

    qp.setFont(font);

    qp.drawText(10, 100, message);
    qp.drawText(10, 130, message3);
    qp.drawText(10, 170, message2);
    qp.drawText(10, 220, message4);
    qp.drawText(10, 250, message5);
    qp.drawText(10, 280, message6);
}

void SinglePlayerPython::move()
{

    for (int z = dots; z > 0; z--) {
        x[z] = x[(z - 1)];
        y[z] = y[(z - 1)];
    }

    if (leftDirection) {
        x[0] -= DOT_SIZE;
    }

    if (rightDirection) {
        x[0] += DOT_SIZE;
    }

    if (upDirection) {
        y[0] -= DOT_SIZE;
    }

    if (downDirection) {
        y[0] += DOT_SIZE;
    }
}


void SinglePlayerPython::checkCollision()
{

    for (int z = dots; z > 0; z--) {

        if ((z > 3) && (x[0] == x[z]) && (y[0] == y[z]))
        {
            inGame = false;
        }
    }

    if (y[0] >= B_HEIGHT) {
        inGame = false;
    }

    if (y[0] < 0) {
        inGame = false;
    }

    if (x[0] >= B_WIDTH) {
        inGame = false;
    }

    if (x[0] < 0) {
        inGame = false;
    }

}

