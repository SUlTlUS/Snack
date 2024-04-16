#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QString>
#include <QLineEdit>
#include <SnakeGame.h>

settingsDialog::settingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::settingsDialog)
{
    ui->setupUi(this);
}

settingsDialog::~settingsDialog()
{
    delete ui;
}

void settingsDialog::on_moveDelayEdit_textChanged()
{
    QLineEdit *lineEdit = qobject_cast<QLineEdit*>(sender());
    if (lineEdit) {
        bool ok;
        int newMoveDelay = lineEdit->text().toInt(&ok);
        if (ok && newMoveDelay > 0) {
            SnakeGame::instance()->setMoveDelay(newMoveDelay);
        } else {
            // 处理无效输入
        }
    }
}

