#ifndef FILESYSTEMWIDGET_H
#define FILESYSTEMWIDGET_H
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
#include <QFileSystemModel>
#include <QDebug>

class FileSystemWidget:public QWidget
{
    Q_OBJECT
public:
    FileSystemWidget(QWidget *parent=0);
    ~FileSystemWidget();
private:
    QFileSystemModel *model;
    QTreeView *treeView;
public slots:
    void mkdir();
    void rm();
};

#endif // FILESYSTEMWIDGET_H
