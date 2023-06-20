#include "mainwindow.h"
#include "ui_mainwindow.h"
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

using namespace std;

MainWindow::MainWindow(string selectedColorGiven, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    selectedColor = selectedColorGiven;

    ui->setupUi(this);
    setWindowTitle("Blackjack");
    this->setFixedSize(QSize(1150, 700));
    setStyleSheet("background-color: " + QString::fromStdString(selectedColor));

    lblPCScore = new QLabel("PC: 0",this);
    lblPCScore->setFont(QFont("Times", 20));
    lblPCScore->setGeometry(50,180,200,110);

    lblPlayerScore = new QLabel("YOU: 0",this);
    lblPlayerScore->setFont(QFont("Times", 20));
    lblPlayerScore->setGeometry(50,350,200,110);

    lblWin = new QLabel("",this);
    lblWin->setFont(QFont("Times", 70));
    lblWin->setGeometry(700,280,600,110);
    lblWin->hide();

    btnHit = new QPushButton(this);
    btnHit->setText("Start");
    btnHit->setGeometry(30,450,100,30);
    connect(btnHit, SIGNAL(clicked()), this, SLOT(addCard()));

    btnStay = new QPushButton(this);
    btnStay->setText("Stay");
    btnStay->setGeometry(160,450,100,30);
    connect(btnStay, SIGNAL(clicked()), this, SLOT(stayButton()));

    btnRestart = new QPushButton(this);
    btnRestart->setText("Restart");
    btnRestart->setGeometry(1000, 305, 100, 30);
    connect(btnRestart, SIGNAL(clicked()), this, SLOT(resetCards()));

    btnBack = new QPushButton(this);
    btnBack->setText("Menu");
    btnBack->setGeometry(1000, 340, 100, 30);
    connect(btnBack, SIGNAL(clicked()), this, SLOT(goBack()));


    cardPlayer1 = new QLabel(this);
    cardPlayer1->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer1->setGeometry(30, 510, 100, 160);

    cardPlayer2 = new QLabel(this);
    cardPlayer2->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer2->setGeometry(130, 510, 100, 160);

    cardPlayer3 = new QLabel(this);
    cardPlayer3->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer3->setGeometry(230, 510, 100, 160);

    cardPlayer4 = new QLabel(this);
    cardPlayer4->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer4->setGeometry(330, 510, 100, 160);

    cardPlayer5 = new QLabel(this);
    cardPlayer5->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer5->setGeometry(430, 510, 100, 160);

    cardPlayer6 = new QLabel(this);
    cardPlayer6->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer6->setGeometry(530, 510, 100, 160);

    cardPlayer7 = new QLabel(this);
    cardPlayer7->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer7->setGeometry(630, 510, 100, 160);

    cardPlayer8 = new QLabel(this);
    cardPlayer8->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer8->setGeometry(730, 510, 100, 160);

    cardPlayer9 = new QLabel(this);
    cardPlayer9->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer9->setGeometry(830, 510, 100, 160);

    cardPlayer10 = new QLabel(this);
    cardPlayer10->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer10->setGeometry(930, 510, 100, 160);

    cardPlayer11 = new QLabel(this);
    cardPlayer11->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer11->setGeometry(1030, 510, 100, 160);

    cardPC1 = new QLabel(this);
    cardPC1->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC1->setGeometry(30, 30, 100, 160);

    cardPC2 = new QLabel(this);
    cardPC2->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC2->setGeometry(130, 30, 100, 160);

    cardPC3 = new QLabel(this);
    cardPC3->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC3->setGeometry(230, 30, 100, 160);

    cardPC4 = new QLabel(this);
    cardPC4->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC4->setGeometry(330, 30, 100, 160);

    cardPC5 = new QLabel(this);
    cardPC5->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC5->setGeometry(430, 30, 100, 160);

    cardPC6 = new QLabel(this);
    cardPC6->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC6->setGeometry(530, 30, 100, 160);

    cardPC7 = new QLabel(this);
    cardPC7->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC7->setGeometry(630, 30, 100, 160);

    cardPC8 = new QLabel(this);
    cardPC8->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC8->setGeometry(730, 30, 100, 160);

    cardPC9 = new QLabel(this);
    cardPC9->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC9->setGeometry(830, 30, 100, 160);

    cardPC10 = new QLabel(this);
    cardPC10->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC10->setGeometry(930, 30, 100, 160);

    cardPC11 = new QLabel(this);
    cardPC11->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC11->setGeometry(1030, 30, 100, 160);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Functions implemented

string MainWindow::getRandomCard(vector<string>& cards, string who) {
    static mt19937 rng(time(nullptr));
    uniform_int_distribution<int> dist(0, cards.size() - 1);
    vector<string>::size_type index = dist(rng);
    while (cards.empty() || index < 0 || index >= cards.size())
    {
        static mt19937 rng(time(nullptr));
        index = dist(rng);
    }
    string selectedCard = cards[index];
    cards.erase(cards.begin() + index);
    size_t pos;
    if(who == "player")
    {
        if(selectedCard[0] == 'K' || selectedCard[0] == 'Q' || selectedCard[0] == 'J' || (selectedCard[0] == '1' && selectedCard[1] == '0'))
        {
            sPlayer += 10;
        }
        else
        {
            if(selectedCard[0] == '1')
            {
                if(sPlayer + 11 <= 21)
                {
                    sPlayer += 11;
                }
                else
                {
                    sPlayer += 1;
                }
            }
            else
            {
                sPlayer += stoi(selectedCard, &pos);
            }
        }
    }
    else
    {
        if(selectedCard[0] == 'K' || selectedCard[0] == 'Q' || selectedCard[0] == 'J' || (selectedCard[0] == '1' && selectedCard[1] == '0'))
        {
            sPC += 10;
        }
        else
        {
            if(selectedCard[0] == '1')
            {
                if(sPC + 11 <= 21)
                {
                    sPC += 11;
                }
                else
                {
                    sPC += 1;
                }
            }
            else
            {
                sPC += stoi(selectedCard, &pos);
            }
        }
        if(cp == 0)
            firstCard = sPC;
    }
    return selectedCard;
}

void MainWindow::stayButton()
{
    if(c>0)
    {
        playerStay = true;
        if(playerStay&&pcStay)
            checkWinner();
        else
        {
            while(sPC < 17)
            {
                timer = new QTimer(this);

                QEventLoop loop;
                QTimer::singleShot(500, &loop, &QEventLoop::quit);
                loop.exec();

                addCardPC();
                editScore();
                checkWinner();
            }

        }
    }

}

void MainWindow::addCard()
{
    if(!playerStay)
    {
        addCardPlayer();
    }
    if(!pcStay && !playerStay)
    {
        addCardPC();
    }
    editScore();
    checkWinner();
}

void MainWindow::addCardPlayer()
{
    std::string card = getRandomCard(cards, "player");
    c++;
    if(c > 0)
        btnHit->setText("Hit");
    if (c == 1)
        setImage(cardPlayer1, card);
    if (c == 2)
        setImage(cardPlayer2, card);
    if (c == 3)
        setImage(cardPlayer3, card);
    if (c == 4)
        setImage(cardPlayer4, card);
    if (c == 5)
        setImage(cardPlayer5, card);
    if (c == 6)
        setImage(cardPlayer6, card);
    if (c == 7)
        setImage(cardPlayer7, card);
    if (c == 8)
        setImage(cardPlayer8, card);
    if (c == 9)
        setImage(cardPlayer9, card);
    if (c == 10)
        setImage(cardPlayer10, card);
    if (c == 11)
        setImage(cardPlayer11, card);
}

void MainWindow::addCardPC()
{
    std::string card = getRandomCard(cards, "pc");
    cp++;
    if (cp == 1)
    {
        cardPC1->setPixmap(QPixmap(":/images/backOfCard.jpg"));
        setHiddenCard(card);
    }
    if (cp == 2)
        setImage(cardPC2, card);
    if (cp == 3)
        setImage(cardPC3, card);
    if (cp == 4)
        setImage(cardPC4, card);
    if (cp == 5)
        setImage(cardPC5, card);
    if (cp == 6)
        setImage(cardPC6, card);
    if (cp == 7)
        setImage(cardPC7, card);
    if (cp == 8)
        setImage(cardPC8, card);
    if (cp == 9)
        setImage(cardPC9, card);
    if (cp == 10)
        setImage(cardPC10, card);
    if (cp == 11)
        setImage(cardPC11, card);
    if(sPC >= 17)
        pcStay = true;
}

void MainWindow::setImage(QLabel* cardPlayer, string card)
{
    if (card == "1Hearts")
        cardPlayer->setPixmap(QPixmap(":/images/ASpades.jpg"));

    if (card == "1Diamonds")
        cardPlayer->setPixmap(QPixmap(":/images/ADiamonds.jpg"));

    if (card == "1Spades")
        cardPlayer->setPixmap(QPixmap(":/images/ASpades.jpg"));

    if (card == "1Clubs")
        cardPlayer->setPixmap(QPixmap(":/images/AClubs.jpg"));

    if (card == "2Hearts")
        cardPlayer->setPixmap(QPixmap(":/images/2Hearts.jpg"));

    if (card == "2Diamonds")
        cardPlayer->setPixmap(QPixmap(":/images/2Diamonds.jpg"));

    if (card == "2Spades")
        cardPlayer->setPixmap(QPixmap(":/images/2Spades.jpg"));

    if (card == "2Clubs")
        cardPlayer->setPixmap(QPixmap(":/images/2Clubs.jpg"));

    if (card == "3Hearts")
        cardPlayer->setPixmap(QPixmap(":/images/3Hearts.jpg"));

    if (card == "3Diamonds")
        cardPlayer->setPixmap(QPixmap(":/images/3Diamonds.jpg"));

    if (card == "3Spades")
        cardPlayer->setPixmap(QPixmap(":/images/3Diamonds.jpg"));

    if (card == "3Clubs")
        cardPlayer->setPixmap(QPixmap(":/images/3Diamonds.jpg"));

    if (card == "4Hearts")
        cardPlayer->setPixmap(QPixmap(":/images/4Hearts.jpg"));

    if (card == "4Diamonds")
        cardPlayer->setPixmap(QPixmap(":/images/4Diamonds.jpg"));

    if (card == "4Spades")
        cardPlayer->setPixmap(QPixmap(":/images/4Spades.jpg"));

    if (card == "4Clubs")
        cardPlayer->setPixmap(QPixmap(":/images/4Clubs.jpg"));

    if (card == "5Hearts")
        cardPlayer->setPixmap(QPixmap(":/images/5Hearts.jpg"));

    if (card == "5Diamonds")
        cardPlayer->setPixmap(QPixmap(":/images/5Diamonds.jpg"));

    if (card == "5Spades")
        cardPlayer->setPixmap(QPixmap(":/images/5Spades.jpg"));

    if (card == "5Clubs")
        cardPlayer->setPixmap(QPixmap(":/images/5Clubs.jpg"));

    if (card == "6Hearts")
        cardPlayer->setPixmap(QPixmap(":/images/6Hearts.jpg"));

    if (card == "6Diamonds")
        cardPlayer->setPixmap(QPixmap(":/images/6Diamonds.jpg"));

    if (card == "6Spades")
        cardPlayer->setPixmap(QPixmap(":/images/6Spades.jpg"));

    if (card == "6Clubs")
        cardPlayer->setPixmap(QPixmap(":/images/6Clubs.jpg"));

    if (card == "7Hearts")
        cardPlayer->setPixmap(QPixmap(":/images/7Hearts.jpg"));

    if (card == "7Diamonds")
        cardPlayer->setPixmap(QPixmap(":/images/7Diamonds.jpg"));

    if (card == "7Spades")
        cardPlayer->setPixmap(QPixmap(":/images/7Spades.jpg"));

    if (card == "7Clubs")
        cardPlayer->setPixmap(QPixmap(":/images/7Clubs.jpg"));

    if (card == "8Hearts")
        cardPlayer->setPixmap(QPixmap(":/images/8Hearts.jpg"));

    if (card == "8Diamonds")
        cardPlayer->setPixmap(QPixmap(":/images/8Diamonds.jpg"));

    if (card == "8Spades")
        cardPlayer->setPixmap(QPixmap(":/images/8Spades.jpg"));

    if (card == "8Clubs")
        cardPlayer->setPixmap(QPixmap(":/images/8Clubs.jpg"));

    if (card == "9Hearts")
        cardPlayer->setPixmap(QPixmap(":/images/9Hearts.jpg"));

    if (card == "9Diamonds")
        cardPlayer->setPixmap(QPixmap(":/images/9Diamonds.jpg"));

    if (card == "9Spades")
        cardPlayer->setPixmap(QPixmap(":/images/9Spades.jpg"));

    if (card == "9Clubs")
        cardPlayer->setPixmap(QPixmap(":/images/9Clubs.jpg"));

    if (card == "10Hearts")
        cardPlayer->setPixmap(QPixmap(":/images/10Hearts.jpg"));

    if (card == "10Diamonds")
        cardPlayer->setPixmap(QPixmap(":/images/10Diamonds.jpg"));

    if (card == "10Spades")
        cardPlayer->setPixmap(QPixmap(":/images/10Spades.jpg"));

    if (card == "10Clubs")
        cardPlayer->setPixmap(QPixmap(":/images/10Clubs.jpg"));

    if (card == "JHearts")
        cardPlayer->setPixmap(QPixmap(":/images/JHearts.jpg"));

    if (card == "JDiamonds")
        cardPlayer->setPixmap(QPixmap(":/images/JDiamonds.jpg"));

    if (card == "JSpades")
        cardPlayer->setPixmap(QPixmap(":/images/JSpades.jpg"));

    if (card == "JClubs")
        cardPlayer->setPixmap(QPixmap(":/images/JClubs.jpg"));

    if (card == "QHearts")
        cardPlayer->setPixmap(QPixmap(":/images/QHearts.jpg"));

    if (card == "QDiamonds")
        cardPlayer->setPixmap(QPixmap(":/images/QDiamonds.jpg"));

    if (card == "QSpades")
        cardPlayer->setPixmap(QPixmap(":/images/QSpades.jpg"));

    if (card == "QClubs")
        cardPlayer->setPixmap(QPixmap(":/images/QClubs.jpg"));

    if (card == "KHearts")
        cardPlayer->setPixmap(QPixmap(":/images/KHearts.jpg"));

    if (card == "KDiamonds")
        cardPlayer->setPixmap(QPixmap(":/images/KDiamonds.jpg"));

    if (card == "KSpades")
        cardPlayer->setPixmap(QPixmap(":/images/KSpades.jpg"));

    if (card == "KClubs")
        cardPlayer->setPixmap(QPixmap(":/images/KClubs.jpg"));
}

void MainWindow::editScore()
{
    lblPlayerScore->setText(QString::fromStdString(to_string(sPlayer)));
    lblPCScore->setText(QString::fromStdString("? + " + to_string(sPC-firstCard)));
}

void MainWindow::checkWinner()
{
    if(sPlayer > 21)
    {
        playerStay = true;
        lblWin->setText("YOU LOSE");
        lblPCScore->setText(QString::fromStdString(to_string(getFirstCard()) + " + " + to_string(sPC-firstCard) + " --> " + to_string(sPC)));
        setImage(cardPC1, getHiddenCard());
        lblWin->show();
        btnRestart->setGeometry(550, 305, 100, 30);
        btnBack->setGeometry(550, 340, 100, 30);
    }
    else
    {
        if(playerStay && pcStay)
        {
            if(sPC > 21)
            {
                lblWin->setText("YOU WIN");
                lblPCScore->setText(QString::fromStdString(to_string(getFirstCard()) + " + " + to_string(sPC-firstCard) + " --> " + to_string(sPC)));
                setImage(cardPC1, getHiddenCard());
                lblWin->show();
                btnRestart->setGeometry(550, 305, 100, 30);
                btnBack->setGeometry(550, 340, 100, 30);
            }
            else
            {
                if(sPlayer==sPC)
                {
                    lblWin->setText("IT'S A TIE");
                    lblPCScore->setText(QString::fromStdString(to_string(getFirstCard()) + " + " + to_string(sPC-firstCard) + " --> " + to_string(sPC)));
                    setImage(cardPC1, getHiddenCard());
                    lblWin->show();
                    btnRestart->setGeometry(550, 305, 100, 30);
                    btnBack->setGeometry(550, 340, 100, 30);
                }
                else
                {
                    if(sPlayer > sPC)
                    {
                        lblWin->setText("YOU WIN");
                        lblPCScore->setText(QString::fromStdString(to_string(getFirstCard()) + " + " + to_string(sPC-firstCard) + " --> " + to_string(sPC)));
                        setImage(cardPC1, getHiddenCard());
                        lblWin->show();
                        btnRestart->setGeometry(550, 305, 100, 30);
                        btnBack->setGeometry(550, 340, 100, 30);
                    }
                    else
                    {
                        lblWin->setText("YOU LOSE");
                        lblPCScore->setText(QString::fromStdString(to_string(getFirstCard()) + " + " + to_string(sPC-firstCard) + " --> " + to_string(sPC)));
                        setImage(cardPC1, getHiddenCard());
                        lblWin->show();
                        btnRestart->setGeometry(550, 305, 100, 30);
                        btnBack->setGeometry(550, 340, 100, 30);
                    }
                }
            }
        }
    }

}

int MainWindow::getFirstCard()
{
    return firstCard;
}

string MainWindow::getHiddenCard()
{
    return hiddenCard;
}

void MainWindow::setHiddenCard(string cardToSet)
{
    this->hiddenCard = cardToSet;
}

void MainWindow::resetCards()
{
    cards = cardsReset;
    sPlayer = 0;
    sPC = 0;
    firstCard = 0;
    c = 0;
    cp = 0;
    playerStay = false;
    pcStay = false;
    btnHit->setText("Start");
    cardPlayer1->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer2->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer3->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer4->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer5->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer6->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer7->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer8->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer9->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer10->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPlayer11->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC1->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC2->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC3->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC4->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC5->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC6->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC7->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC8->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC9->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC10->setPixmap(QPixmap(":/images/cardBG.png"));
    cardPC11->setPixmap(QPixmap(":/images/cardBG.png"));
    btnRestart->setGeometry(1000, 305, 100, 30);
    btnBack->setGeometry(1000, 340, 100, 30);
    lblWin->hide();
    editScore();
}

void MainWindow::goBack()
{
    Menu *menu = new Menu(selectedColor, this);
    this->close();
    menu->show();
//    menu = new Menu(this);
//    this->close();
//    menu->show();
}
