#ifndef SINGLEPLAYER_H
#define SINGLEPLAYER_H

#include <QDialog>

namespace Ui {
class SinglePlayer;
}

class SinglePlayer : public QDialog
{
    Q_OBJECT

public:
    explicit SinglePlayer(QWidget *parent = nullptr);
    ~SinglePlayer();

private slots:
    void on_backButton_clicked();

    void on_slugButton_clicked();

    void on_wormButton_clicked();

    void on_pythonButton_clicked();

private:
    Ui::SinglePlayer *ui;
};

#endif // SINGLEPLAYER_H
