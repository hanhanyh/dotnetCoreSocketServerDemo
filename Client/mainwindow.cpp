#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QHostAddress>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket=new QTcpSocket();
    socket->connectToHost(QHostAddress("127.0.0.1"),13000);
   connect(socket,SIGNAL(connected()),this,SLOT(connsucc()));
   connect(socket,SIGNAL(readyRead()),this,SLOT(recv()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::connsucc()
{
    char d[1024]="你好我是数据ABCabc123...~";
    socket->write(d,strlen(d));
}
void MainWindow::recv()
{
   QString  data=   socket->readAll();
   QMessageBox::about(this,"收到的数据",data);
}
