#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include <QDialog>

namespace Ui {
class GameOverDialog;
}

class GameOverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameOverDialog(int score, int hscore, QWidget *parent = nullptr);
    ~GameOverDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::GameOverDialog *ui;
    int currentScores;
    int highestScores;
};

#endif // GAMEOVERDIALOG_H
