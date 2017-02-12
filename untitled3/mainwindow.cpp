#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    textEdit=new QTextEdit;
    setCentralWidget(textEdit);
    textEdit->setText("textEdit");
    textEdit->setWindowTitle("textEdit");

    textEdit->installEventFilter(this);
    textEdit->show();
    //ui->setupUi(this);
}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==textEdit){
        if(event->type()==QEvent::KeyPress){
            QKeyEvent *keyEvent=static_cast<QKeyEvent *>(event);
            qDebug()<<"ate key press"<<keyEvent->key();
            return true;
        }else
            return false;
    }else
        return QMainWindow::eventFilter(obj,event);
}
MainWindow::~MainWindow()
{
    //delete ui;
}
