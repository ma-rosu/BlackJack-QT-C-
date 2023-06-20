#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
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
#include "menu.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(string selectedColor, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel* lblPCScore;
    QLabel* lblPlayerScore;
    QLabel* lblWin;
    QPushButton* btnHit;
    QPushButton* btnStay;
    QPushButton* btnRestart;
    QPushButton* btnBack;
    QLabel* cardPlayer1;
    QLabel* cardPlayer2;
    QLabel* cardPlayer3;
    QLabel* cardPlayer4;
    QLabel* cardPlayer5;
    QLabel* cardPlayer6;
    QLabel* cardPlayer7;
    QLabel* cardPlayer8;
    QLabel* cardPlayer9;
    QLabel* cardPlayer10;
    QLabel* cardPlayer11;
    QLabel* cardPC1;
    QLabel* cardPC2;
    QLabel* cardPC3;
    QLabel* cardPC4;
    QLabel* cardPC5;
    QLabel* cardPC6;
    QLabel* cardPC7;
    QLabel* cardPC8;
    QLabel* cardPC9;
    QLabel* cardPC10;
    QLabel* cardPC11;
    QTimer* timer;
    vector<string> cards = {"1Hearts", "1Diamonds", "1Spades", "1Clubs", "2Hearts", "2Diamonds", "2Spades", "2Clubs", "3Hearts", "3Diamonds", "3Spades", "3Clubs", "4Hearts", "4Diamonds", "4Spades", "4Clubs", "5Hearts", "5Diamonds", "5Spades", "5Clubs", "6Hearts", "6Diamonds", "6Spades", "6Clubs", "7Hearts", "7Diamonds", "7Spades", "7Clubs", "8Hearts", "8Diamonds", "8Spades", "8Clubs", "9Hearts", "9Diamonds", "9Spades", "9Clubs", "10Hearts", "10Diamonds", "10Spades", "10Clubs", "JHearts", "JDiamonds", "JSpades", "JClubs", "QHearts", "QDiamonds", "QSpades", "QClubs", "KHearts", "KDiamonds", "KSpades", "KClubs"};
    const vector<string> cardsReset = cards;
    int sPlayer = 0;
    int sPC = 0, firstCard;
    int c = 0;
    int cp = 0;
    bool playerStay = false, pcStay = false;
    string hiddenCard;
    string selectedColor;



public slots:
    void addCard();
    void stayButton();
    void addCardPlayer();
    void addCardPC();
    string getRandomCard(vector<string>& cards, string who);
    void setImage(QLabel* cardPlayer, string card);
    void editScore();
    void checkWinner();
    int getFirstCard();
    string getHiddenCard();
    void setHiddenCard(string cardToSet);
    void resetCards();
    void goBack();
};

#endif // MAINWINDOW_H
