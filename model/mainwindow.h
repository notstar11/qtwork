#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QTableWidget>
#include <QStringListModel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QItemSelectionModel>
#include <QModelIndex>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changeCurrent(const QModelIndex &current,
                       const QModelIndex &previous);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
