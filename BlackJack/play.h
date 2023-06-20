#ifndef PLAY_H
#define PLAY_H

#include <QDialog>

namespace Ui {
class Play;
}

class Play : public QDialog
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = nullptr);
    ~Play();

private:
    Ui::Play *ui;
};

#endif // PLAY_H
