#include "mainwindow.h"
#include <QApplication>
#include "mylistview.h"
#include "filesystemwidget.h"
#include "sortview.h"
#include "currencymodel.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

/*
    QLabel *label=new QLabel;
    label->setFixedWidth(70);
    label->setText("Chrome");
    QListWidget *listWidget=new QListWidget;
    listWidget->setViewMode(QListWidget::IconMode);
    new QListWidgetItem(QIcon("fly1.png"),QObject::tr("Chrome"),listWidget);;
    new QListWidgetItem(QIcon("fly1.png"),QObject::tr("Firefox"),listWidget);
    listWidget->addItem(new QListWidgetItem(QIcon("fly1.png"),QObject::tr("IE")));
    listWidget->addItem(new QListWidgetItem(QIcon("fly1.png"),QObject::tr("Netscape")));
    listWidget->addItem(new QListWidgetItem(QIcon("fly1.png"),QObject::tr("Opera")));
    listWidget->addItem(new QListWidgetItem(QIcon("fly1.png"),QObject::tr("Safari")));
    listWidget->addItem(new QListWidgetItem(QIcon("fly1.png"),QObject::tr("Theworld")));
    listWidget->addItem(new QListWidgetItem(QIcon("fly1.png"),QObject::tr("Traveler")));

    QListWidgetItem *newItem=new QListWidgetItem;
    newItem->setIcon(QIcon("fly1.png"));
    newItem->setText("Maxthon");
    listWidget->insertItem(3,newItem);

    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(listWidget);


    QWidget *widget=new QWidget;
    widget->setLayout(layout);
    widget->show();
    //connect(listWidget,SIGNAL(currentTextChanged(QString)),
    //        label,SLOT(setText(QString)));

    QTreeWidget treeWidget;

    QStringList headers;
    headers<<"Name"<<"Number";
    treeWidget.setHeaderLabels(headers);

    QStringList rootTextList;
    rootTextList<<"Root"<<"0";

    QTreeWidgetItem *root=new QTreeWidgetItem(&treeWidget,rootTextList);
    new QTreeWidgetItem(root,QStringList()<<QString("leaf1")<<"1");
    QTreeWidgetItem *leaf2=new QTreeWidgetItem(root,QStringList()<<QString("leaf2")<<"2");
    leaf2->setCheckState(0,Qt::Checked);
    QList<QTreeWidgetItem *>rootlist;
    rootlist<<root;
    treeWidget.insertTopLevelItems(0,rootlist);
    treeWidget.show();

    QTableWidget tableWidget;
    tableWidget.setColumnCount(3);
    tableWidget.setRowCount(5);
    QStringList headers;
    headers<<"ID"<<"NAME"<<"AGE"<<"SEX";
    tableWidget.setHorizontalHeaderLabels(headers);

    tableWidget.setItem(0,0,new QTableWidgetItem(QString("0001")));
    tableWidget.setItem(1,0,new QTableWidgetItem(QString("0002")));
    tableWidget.setItem(2,0,new QTableWidgetItem(QString("0003")));
    tableWidget.setItem(3,0,new QTableWidgetItem(QString("0004")));
    tableWidget.setItem(4,0,new QTableWidgetItem(QString("0005")));
    tableWidget.setItem(0,1,new QTableWidgetItem(QString("112")));

    tableWidget.show();
    MyListView listView;
    listView.show();
    FileSystemWidget fileWidget;
    fileWidget.show();
    MyListView listView;
    listView.show();
    SortView sortView;
    sortView.show();*/
    QMap<QString,double> data;
    data["USD"]=1.0000;
    data["CNY"]=0.1628;
    data["GBP"]=1.5361;
    data["EUR"]=1.2992;
    data["HKD"]=0.1289;

    QTableView view;
    CurrencyModel *model=new CurrencyModel(&view);
    model->setCurrencyMap(data);//model连数据
    view.setModel(model);//视图连model
    view.resize(400,300);
    view.show();
    w.show();

    return a.exec();
}
