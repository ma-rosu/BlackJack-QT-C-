#include "menu.h"
#include "ui_menu.h"
#include <QPushButton>
#include <mainwindow.h>
#include <bits/stdc++.h>


using namespace std;

Menu::Menu(string selectedColorGiven, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    selectedColor = selectedColorGiven;
    ui->setupUi(this);

    setWindowTitle("Blackjack");
    this->setFixedSize(QSize(500, 400));
    setStyleSheet("background-color: " + QString::fromStdString(selectedColor));

    btnPlay = new QPushButton(this);
    btnPlay->setText("Play");
    btnPlay->setGeometry(150,75,200,60);
    connect(btnPlay, SIGNAL(clicked()), this, SLOT(play()));

    btnColor = new QPushButton(this);
    btnColor->setText("Change Color");
    btnColor->setGeometry(150,175,200,60);
    connect(btnColor, SIGNAL(clicked()), this, SLOT(selectColor()));

    btnExit = new QPushButton(this);
    btnExit->setText("Exit");
    btnExit->setGeometry(150,275,200,60);
    connect(btnExit, SIGNAL(clicked()), this, SLOT(exit()));


}

Menu::~Menu()
{
    delete ui;
}

int getIndex(vector<string> v, string K)
{
    auto it = find(v.begin(), v.end(), K);

    if (it != v.end())
    {
        int index = it - v.begin();
        return index;
    }
    else
    {
        return -1;
    }
}

void Menu::play()
{
    MainWindow *mainWindow = new MainWindow(selectedColor, this);
    this->hide();
    mainWindow->show();
}

void Menu::selectColor()
{
    int i = getIndex(colors, selectedColor);
    if(i<(int) colors.size()-1)
        selectedColor = colors[++i];
    else
        selectedColor = colors[0];
    setStyleSheet("background-color: " + QString::fromStdString(selectedColor));
}

void Menu::exit()
{
    this->close();
}
