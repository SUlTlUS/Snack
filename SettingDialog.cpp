#include "settingsDialog.h"
#include <QWidget>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}
