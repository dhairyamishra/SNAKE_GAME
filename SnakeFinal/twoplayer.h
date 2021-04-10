#ifndef TWOPLAYER_H
#define TWOPLAYER_H

#include <QDialog>

namespace Ui {
class TwoPlayer;
}

class TwoPlayer : public QDialog
{
    Q_OBJECT

public:
    explicit TwoPlayer(QWidget *parent = nullptr);
    ~TwoPlayer();

private slots:
    void on_backButton_clicked();

    void on_slugButton_clicked();

    void on_wormButton_clicked();

    void on_pythonButton_clicked();

private:
    Ui::TwoPlayer *ui;
};

#endif // TWOPLAYER_H
