#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QTcpSocket>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTcpSocket *  socket;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void connsucc();
    void recv();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
