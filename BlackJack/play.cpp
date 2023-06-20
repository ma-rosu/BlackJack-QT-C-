#include "play.h"
#include "ui_play.h"

Play::Play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Play)
{
    ui->setupUi(this);
}

Play::~Play()
{
    delete ui;
}
