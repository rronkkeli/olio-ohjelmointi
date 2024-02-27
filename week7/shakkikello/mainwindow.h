#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int time = 120000;

private slots:
    void on_btnStartStop_clicked();
    void updateClock();

    void on_btnChangePlayer_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int playerTime1, playerTime2;
    int currentPlayer = 0;
    bool gamestatus = false;
    void stopTheGame();
};
#endif // MAINWINDOW_H
