#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer;
    ui->progP1->setValue(100);
    ui->progP2->setValue(100);
    ui->victory->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}


void MainWindow::on_btnStartStop_clicked()
{
    if (this->gamestatus) {
        this->stopTheGame();
        ui->victory->setText("Voittaja on peliohjelmalle epäselvä.");

    } else {
        if (ui->t1->isChecked()) {
            this->time = 120;
        } else {
            this->time = 300;
        }

        ui->btnChangePlayer->setEnabled(true);
        ui->btnChangePlayer->setFocus();
        ui->t1->setEnabled(false);
        ui->t2->setEnabled(false);

        ui->progP1->setValue(100);
        ui->progP2->setValue(100);

        ui->btnStartStop->setText("Lopeta peli");

        connect(timer, SIGNAL(timeout()), this, SLOT(updateClock()), Qt::UniqueConnection);

        playerTime1 = playerTime2 = this->time;
        this->gamestatus = true;
        this->currentPlayer = 0;
        timer->start(1000);
        ui->victory->setText("Pelaajan 1 vuoro!");
    }
}

void MainWindow::updateClock()
{
    if (gamestatus) {
        if (this->currentPlayer == 0) {
            if (this->playerTime1 < 1) {
                this->stopTheGame();
                ui->victory->setText("Pelaaja 2 voitti!");
            }
            this->playerTime1--;
            ui->progP1->setValue(this->playerTime1 * 100 / this->time);
            qDebug() << "Aikaa jäljellä: " << this->playerTime1;
        } else {
            if (this->playerTime2 < 1) {
                this->stopTheGame();
                ui->victory->setText("Pelaaja 1 voitti!");
            }
            this->playerTime2--;
            ui->progP2->setValue(this->playerTime2 * 100 / this->time);
            qDebug() << "Aikaa jäljellä: " << this->playerTime2;
        }
    } else {
        this->stopTheGame();
        ui->victory->setText("Voittaja on peliohjelmalle epäselvä.");
    }
}


void MainWindow::on_btnChangePlayer_clicked()
{
    if (this->currentPlayer == 0) {
        this->currentPlayer = 1;
        ui->victory->setText("Pelaajan 2 vuoro!");
    } else {
        this->currentPlayer = 0;
        ui->victory->setText("Pelaajan 1 vuoro!");
    }
}

void MainWindow::stopTheGame()
{
    this->gamestatus = false;
    this->timer->stop();
    ui->btnChangePlayer->setEnabled(false);
    ui->btnStartStop->setText("Aloita peli");
    ui->t1->setEnabled(true);
    ui->t2->setEnabled(true);
}

