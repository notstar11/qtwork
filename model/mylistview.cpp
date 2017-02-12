#include "mylistview.h"
#include "spinboxdelegate.h"
MyListView::MyListView()
{
    QStringList data;
    data<<"Letter A"<<"Letter B"<<"Letter C";
    model=new QStringListModel(this);
    model->setStringList(data);

    listView=new QListView(this);
    listView->setModel(model);
    listView->setItemDelegate(new SpinBoxDelegate(listView));

    QHBoxLayout *btnLayout=new QHBoxLayout;
    QPushButton *insertBtn=new QPushButton(tr("insert"),this);
    connect(insertBtn,SIGNAL(clicked()),this,SLOT(insertData()));
    QPushButton *delBtn=new QPushButton(tr("delete"),this);
    connect(delBtn,SIGNAL(clicked()),this,SLOT(deleteData()));
    QPushButton *showBtn=new QPushButton(tr("show"),this);
    connect(showBtn,SIGNAL(clicked()),this,SLOT(showData()));

    btnLayout->addWidget(insertBtn);
    btnLayout->addWidget(delBtn);
    btnLayout->addWidget(showBtn);

    QVBoxLayout *mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(listView);
    mainLayout->addLayout(btnLayout);
    this->setLayout(mainLayout);
}
void MyListView::insertData()
{
    bool isOK;
    QString text=QInputDialog::getText(this,"insert",
                                       "Please input new data:",
                                       QLineEdit::Normal,
                                       "you are inserting new data",
                                       &isOK);
    if(isOK){
        QModelIndex currIndex=listView->currentIndex();
        model->insertRows(currIndex.row(),1);
        model->setData(currIndex,text);
        listView->edit(currIndex);
    }
}
void MyListView::deleteData()
{
    if(model->rowCount()>1){
        model->removeRows(listView->currentIndex().row(),1);
    }
}
void MyListView::showData()
{
    QStringList data=model->stringList();
    QString str;
    foreach(QString s,data){
        str+=s+"\n";
    }
    QMessageBox::information(this,"Data",str);
}
