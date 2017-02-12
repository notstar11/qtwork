#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QTextEdit>
#include <QFileDialog>
#include <QIODevice>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle("Main Window");
    QAction *openAction=new QAction(tr("&Open..."),this);
    openAction->setStatusTip("open an existing file");

    QAction *saveAction=new QAction(tr("&save..."),this);
    saveAction->setStatusTip(tr("save a new file"));

    connect(openAction,&QAction::triggered,this,&MainWindow::openFile);
    connect(saveAction,&QAction::triggered,this,&MainWindow::saveFile);

    QMenu *file=menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolBar=addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    QTextEdit *textEdit=new QTextEdit(this);
    setCentralWidget(textEdit);
    //ui->setupUi(this);
    if(QMessageBox::Yes==QMessageBox::question(this,
                                               tr("question"),
                                               tr("are you ok?"),
                                               QMessageBox::Yes|QMessageBox::No,
                                               QMessageBox::Yes))
    {
        QMessageBox::information(this,tr("hmmm..."),tr("i am glad"));

    }
    else
        QMessageBox::information(this,tr("hmmm..."),tr("i am sorry"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openFile()
{
    QDialog dialog(this);
    dialog.setWindowTitle("hello");
    dialog.exec();
    qDebug()<<dialog.result();
}
void MainWindow::saveFile()
{
    QString path=QFileDialog::getSaveFileName(this,
                                              tr("open file"),
                                              ".",
                                              tr("Text Files(*.txt)"));
    if(!path.isEmpty()){
        QFile file(path);
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QMessageBox::warning(this,tr("write file"),

                                 tr("cannot open%1").arg(path));
            return;
        }
        QTextStream out(&file);
        //out<<textEdit->toPlainText();
        file.close();
    }else{
        QMessageBox::warning(this,tr("path"),tr("you did not select any file"));
    }
}
