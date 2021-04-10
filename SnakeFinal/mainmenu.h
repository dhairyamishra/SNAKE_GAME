#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_singlePlayerButton_clicked();

    void on_helpButton_clicked();

    void on_twoPlayerButton_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
