#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    /*
    QHBoxLayout *layout=new QHBoxLayout(this);
    QWidget *centerWindow=new QWidget;
    this->setCentralWidget(centerWindow);
    QPushButton *btn=new QPushButton;
    btn->setText(QString("btn"));

    QTableWidget *tableWidget=new QTableWidget(8,4);
    QItemSelectionModel *selectionModel=tableWidget->selectionModel();
    //获取表格单元格 索引
    QModelIndex topLeft=tableWidget->model()->index(0,0,QModelIndex());
    QModelIndex bottomRight=tableWidget->model()->index(5,2,QModelIndex());
    //选择模型
    QItemSelection selection(topLeft,bottomRight);
    //第一个参数表示需要的选取，第二个参数是选区的标志位，Select表示选区中包含的单元格都会被选中
    selectionModel->select(selection,QItemSelectionModel::Toggle);
    QModelIndexList indexs=selectionModel->selectedIndexes();
    QModelIndex index;
    foreach (index, indexs) {
       QString text=QString("(%1,%2)").arg(index.row()).arg(index.column());

    }

    layout->addWidget(tableWidget);
    layout->addWidget(btn);
    centerWindow->setLayout(layout);*/
}

MainWindow::~MainWindow()
{

}
void MainWindow::changeCurrent(const QModelIndex &current, const QModelIndex &previous)
{
    statusBar()->showMessage(
                tr("move from (%1,%2) to (%3,%4)")
                .arg(previous.row()).arg(previous.column())
                .arg(current.row()).arg(current.column()));
}
