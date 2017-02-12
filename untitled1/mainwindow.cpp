#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowTitle("Main Window");

    openAction=new QAction(this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("open an existing file"));
    connect(openAction,&QAction::triggered,this,&MainWindow::open);
    QMenu *file=menuBar()->addMenu((tr("&File")));
    file->addAction(openAction);
    QToolBar *toolBar=addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    statusBar();
    //ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::open()
{
    QMessageBox::information(this,tr("Information"),tr("Open"));
}
