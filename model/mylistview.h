#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QTableWidget>
#include <QStringListModel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QListView>

class MyListView:public QWidget{
    Q_OBJECT
public:
    MyListView();
private:
    QStringListModel *model;
    QListView *listView;
public slots:
    void insertData();
    void deleteData();
    void showData();
};


#endif // MYLISTVIEW_H
