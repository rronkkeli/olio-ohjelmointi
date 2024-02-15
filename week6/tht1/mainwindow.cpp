#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPlus_clicked()
{
    int x = ui->lineEdit->text().toInt() + 1;
    ui->lineEdit->setText(QString::number(x));
}

void MainWindow::on_btnReset_clicked()
{
    ui->lineEdit->setText("0");
}

