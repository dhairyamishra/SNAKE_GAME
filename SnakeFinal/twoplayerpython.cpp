#include "twoplayerpython.h"
#include "ui_twoplayerpython.h"

TwoPlayerPython::TwoPlayerPython(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TwoPlayerPython)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(timerEventS()));

    setFixedSize(B_WIDTH+1, B_HEIGHT+100);
    inGame = true;
    inGame2 = true;
    setup = true;
    gamemode = 2;

    initGame(gamemode);
}

TwoPlayerPython::~TwoPlayerPython()
{delete ui;}

void TwoPlayerPython::timerEventS()
{
    move();
    checkApple();
    checkCollision();
    repaint();
}
void TwoPlayerPython::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    doDrawing();
}
void TwoPlayerPython::doDrawing()
{
     QPainter qp(this);

    if ((setup == true) && (gamemode != 0) && (inGame || inGame2))
    {

        qp.setBrush(Qt::black);
        qp.drawRect(0,0,B_WIDTH,B_HEIGHT);
        qp.setBrush(Qt::yellow);
        qp.drawRect(apple_x, apple_y, DOT_SIZE,DOT_SIZE);
        if(inGame)
        {
            for (int z = 0; z < dots; z++)
            {
                if (z == 0) {

                    qp.setBrush(Qt::red);//draw head
                    qp.drawEllipse(x[z], y[z], DOT_SIZE,DOT_SIZE);
                }
                else
                {
                    qp.setBrush(Qt::green);//draw rest of body
                    qp.drawEllipse(x[z], y[z], DOT_SIZE,DOT_SIZE);
                }
            }
            checkScore(qp);
        }
        if(inGame2)
        {
            for (int zz = 0; zz < dots2; zz++)
            {
                if (zz == 0) {
                    qp.setBrush(Qt::magenta);
                    qp.drawEllipse(x2[zz], y2[zz], DOT_SIZE,DOT_SIZE);
                }
                else
                {
                    qp.setBrush(Qt::cyan);
                    qp.drawEllipse(x2[zz], y2[zz], DOT_SIZE,DOT_SIZE);
                }
            }
            checkScore(qp);
        }
    }
    if((setup == true)&& (!inGame && !inGame2))
    {
        gameOver(qp);
    }
}
void TwoPlayerPython::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();
    if(inGame)
    {
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
    }
    if(inGame2)
       {
        if ((key == Qt::Key_A) && (!rightDirection2)) {
            leftDirection2 = true;
            upDirection2 = false;
            downDirection2 = false;
        }
        if ((key == Qt::Key_D) && (!leftDirection2)) {
            rightDirection2 = true;
            upDirection2 = false;
            downDirection2 = false;
        }
        if ((key == Qt::Key_W) && (!downDirection2)) {
            upDirection2 = true;
            rightDirection2 = false;
            leftDirection2 = false;
        }
        if ((key == Qt::Key_S) && (!upDirection2)) {
            downDirection2 = true;
            rightDirection2 = false;
            leftDirection2 = false;
        }
    }
    if(key == Qt::Key_R)
    {
        setup = true;
        gamemode = 2;
        initGame(gamemode);
    }
}
void TwoPlayerPython::checkScore(QPainter &qp)
{
    QFont font("Courier", 10, QFont::DemiBold, Qt::red);
    qp.setFont(font);
    QString message =  "";
    QString message2 = "";

    qp.setPen(10);
    if(inGame && setup == true)
    {
        Score = dots*10 -30;
        message = "P1 Score:" + QString::number(Score);
        qp.drawText(0, 320, message);
    }
    if(inGame2 && setup == true)
    {
        Score2 = dots2*10 -30;
        message2 = "P2 Score:" + QString::number(Score2);
        qp.drawText(130, 320, message2);
    }
    if(!inGame && (gamemode ==1|| gamemode == 2))
    {
        message = "P1 DEAD:" + QString::number(Score);
        qp.drawText(0, 320, message);
    }

    if(!inGame2 && gamemode == 2)
    {
        message2 = "P2 DEAD:" + QString::number(Score2);
        qp.drawText(130, 320, message2);
    }

}

void TwoPlayerPython::gameOver(QPainter &qp)
{
    QFont font("Courier", 15, QFont::DemiBold);
    qp.setFont(font);
    QString message = "Game over:";
    QString message2 = "";
    QString message3 = "";
    QString message4 = "Press R to Retry";
    QString message5 = "Or click the X to";
    QString message6 = "choose a new ";
    QString message7 = "game mode";

    qp.drawText(10,100, message);
    qp.drawText(10,130, message4);
    qp.drawText(10,230, message5);
    qp.drawText(10,260, message6);
    qp.drawText(10,290, message7);
    if(gamemode == 1 || gamemode ==2)
    {
        message2 = "P1 Score:" + QString::number(Score);
        qp.drawText(10, 170, message2);
    }
    if(gamemode == 2)
    {
        message3 = "P2 Score:" + QString::number(Score2);
        qp.drawText(10, 190, message3);
    }
}

void TwoPlayerPython::locateApple()
{

    int r =  (QRandomGenerator::global()->bounded(RAND_POS)*10);
    apple_x = (r);

    r =  (QRandomGenerator::global()->bounded(RAND_POS)*10);
    apple_y = (r);
}

void TwoPlayerPython::checkApple()
{
    if ((x[0] == apple_x) && (y[0] == apple_y)) {
            dots++;
            locateApple();
        }
    if ((x2[0] == apple_x) && (y2[0] == apple_y)) {
            dots2++;
            locateApple();
        }

}

void TwoPlayerPython::initGame(int mode)
{
    timer->start(DELAY - 150);
    if(mode == 1 && setup == true)
    {
        inGame = true;
        dots = 3;
        for (int z = 0; z < dots; z++)
        {
            x[z] = z * 10;
            y[z] = 50;
        }
        leftDirection = false;
        rightDirection = true;
        upDirection = false;
        downDirection = false;
        locateApple();
    }
    if(mode == 2 && setup == true)
    {
        dots = 3;
        dots2 = 3;
        inGame =true;
        inGame2  = true;

        leftDirection = false;
        rightDirection = true;
        upDirection = false;
        downDirection = false;

        leftDirection2 = true;
        rightDirection2 = false;
        upDirection2 = false;
        downDirection2 = false;
        for (int z = 0; z < dots; z++)
            {
                x[z] = z * 10 + 10;
                y[z] = 50;
                x2[z] = 250 + z*10;
                y2[z] = 70;
            }
        locateApple();
    }
}

void TwoPlayerPython::checkCollision()
{
    if(inGame)
    {
        for (int z = dots; z > 0; z--)
        {
            if (((z > 3) && (x[0] == x[z]) && (y[0] == y[z])) || ((x2[0] == x[z]) && (y2[0] == y[z])))
            {
                inGame = false;
                leftDirection = false;
                rightDirection = false;
                upDirection = false;
                downDirection = false;
                x[0] = 310;
                y[0] = 310;
            }
        }
        if (y[0] >= B_HEIGHT || (y[0] < 0) || (x[0] >= B_WIDTH)|| (x[0] < 0))
        {
            inGame = false;
            leftDirection = false;
            rightDirection = false;
            upDirection = false;
            downDirection = false;
            x[0] = 310;
            y[0] = 310;
        }
    }
    if(inGame2)
    {
        for (int zz = dots2; zz > 0; zz--)
        {
            if (((zz > 3) && (x2[0] == x2[zz]) && (y2[0] == y2[zz])) || ((x[0] == x2[zz]) && (y[0] == y2[zz])) )
            {
                inGame2 = false;
                leftDirection2 = false;
                rightDirection2 = false;
                upDirection2 = false;
                downDirection2 = false;
                x2[0] = 320;
                y2[0] = 320;
            }
        }
        if (y2[0] >= B_HEIGHT || (y2[0] < 0) || (x2[0] >= B_WIDTH)|| (x2[0] < 0))
        {
            inGame2 = false;
            leftDirection2 = false;
            rightDirection2 = false;
            upDirection2 = false;
            downDirection2 = false;
            x2[0] = 320;
            y2[0] = 320;
        }
    }


}
void TwoPlayerPython::move()
{
    if(inGame)
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
    ////////////p2
    if(inGame2)
    {
        for (int q = dots2; q > 0; q--) {
            x2[q] = x2[(q - 1)];
            y2[q] = y2[(q - 1)];
        }

        if (leftDirection2) {
            x2[0] -= DOT_SIZE;
        }

        if (rightDirection2) {
            x2[0] += DOT_SIZE;
        }

        if (upDirection2) {
            y2[0] -= DOT_SIZE;
        }

        if (downDirection2) {
            y2[0] += DOT_SIZE;
        }

    }
}

