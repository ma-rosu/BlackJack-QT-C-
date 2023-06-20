#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <map>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include<thread>
#include<QTimer>
#include <QEventLoop>
#include <mainwindow.h>
#include <QMediaPlayer>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(string selectedColorGiven, QWidget *parent = nullptr);
    ~Menu();
    string getColor();

private:
    Ui::Menu *ui;
    QPushButton* btnPlay;
    QPushButton* btnColor;
    QPushButton* btnExit;
    vector<string> colors = {"#44B28A", "#4A9743", "#368BC1", "#6AE1E3", "#C24641", "#FA8686", "#FA86F7", "#EBB9EA" };
    string selectedColor;


public slots:
    void play();
    void exit();
    void selectColor();


};
#endif // MENU_H
