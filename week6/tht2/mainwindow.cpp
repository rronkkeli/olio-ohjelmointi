#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->num1->setFocus();

    connect(ui->btn0, SIGNAL(clicked(bool)), this, SLOT(numberPushHandler()), Qt::QueuedConnection);
    connect(ui->btn1, SIGNAL(clicked(bool)), this, SLOT(numberPushHandler()), Qt::QueuedConnection);
    connect(ui->btn2, SIGNAL(clicked(bool)), this, SLOT(numberPushHandler()), Qt::QueuedConnection);
    connect(ui->btn3, SIGNAL(clicked(bool)), this, SLOT(numberPushHandler()), Qt::QueuedConnection);
    connect(ui->btn4, SIGNAL(clicked(bool)), this, SLOT(numberPushHandler()), Qt::QueuedConnection);
    connect(ui->btn5, SIGNAL(clicked(bool)), this, SLOT(numberPushHandler()), Qt::QueuedConnection);
    connect(ui->btn6, SIGNAL(clicked(bool)), this, SLOT(numberPushHandler()), Qt::QueuedConnection);
    connect(ui->btn7, SIGNAL(clicked(bool)), this, SLOT(numberPushHandler()), Qt::QueuedConnection);
    connect(ui->btn8, SIGNAL(clicked(bool)), this, SLOT(numberPushHandler()), Qt::QueuedConnection);
    connect(ui->btn9, SIGNAL(clicked(bool)), this, SLOT(numberPushHandler()), Qt::QueuedConnection);

    connect(ui->btnMinus, SIGNAL(clicked(bool)), this, SLOT(operandPushHandler()), Qt::QueuedConnection);
    connect(ui->btnPlus, SIGNAL(clicked(bool)), this, SLOT(operandPushHandler()), Qt::QueuedConnection);
    connect(ui->btnMulti, SIGNAL(clicked(bool)), this, SLOT(operandPushHandler()), Qt::QueuedConnection);
    connect(ui->btnDivi, SIGNAL(clicked(bool)), this, SLOT(operandPushHandler()), Qt::QueuedConnection);

    connect(ui->btnEq, SIGNAL(clicked(bool)), this, SLOT(enterResetHandler()), Qt::QueuedConnection);
    connect(ui->btnEnter, SIGNAL(clicked(bool)), this, SLOT(enterResetHandler()), Qt::QueuedConnection);
    connect(ui->btnClear, SIGNAL(clicked(bool)), this, SLOT(enterResetHandler()), Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberPushHandler() {
    QPushButton* numberButton = qobject_cast<QPushButton*>(sender());
    QString name = numberButton->objectName();
    qDebug() << "Numeroa " << name << " painetiin.";


    if (this->select) {
        ui->num2->setText(
            ui->num2->text().append(name[3])
        );
    } else {
        ui->num1->setText(
            ui->num1->text().append(name[3])
        );
    }

}

void MainWindow::operandPushHandler() {
    QPushButton* operandButton = qobject_cast<QPushButton*>(sender());
    QString name = operandButton->objectName();
    qDebug() << "Operaattoria " << name << " painetiin.";

    if (operandButton == ui->btnMinus) {
        this->operand = 1;
    } else if (operandButton == ui->btnPlus) {
        this->operand = 2;
    } else if (operandButton == ui->btnMulti) {
        this->operand = 3;
    } else {
        this->operand = 4;
    }
}

void MainWindow::enterResetHandler() {
    QPushButton* execButton = qobject_cast<QPushButton*>(sender());
    QString name = execButton->objectName();
    qDebug() << "Valintaa " << name << " painetiin.";

    if (execButton == ui->btnEq) {
        this->x = ui->num1->text().toFloat();
        this->y = ui->num2->text().toFloat();

        qDebug() << "x is " << this->x;
        qDebug() << "y is " << this->y;

        switch (this->operand) {
            case 1:
                this->result = x - y;
                break;
            case 2:
                this->result = x + y;
                break;
            case 3:
                this->result = x * y;
                break;
            case 4:
                this->result = x / y;
                break;
            default:
                qDebug() << "Virheellinen laskutoimitus";
                break;
        }

        ui->result->setText(QString::number(this->result));

    } else if (execButton == ui->btnEnter) {
        if (this->select) {
            this->select = false;
            ui->num1->setFocus();
        } else {
            this->select = true;
            ui->num2->setFocus();
        }

    } else {
        ui->num1->clear();
        ui->num2->clear();
        ui->result->clear();
    }

}
