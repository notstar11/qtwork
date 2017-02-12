#ifndef SORTVIEW_H
#define SORTVIEW_H
#include <QListView>
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
#include <QSortFilterProxyModel>
#include <QComboBox>
#include <QLineEdit>

class SortView:public QWidget
{
    Q_OBJECT
public:
    SortView();
private:
    QListView *view;
    QStringListModel *model;
    QSortFilterProxyModel *modelProxy;
    QComboBox *syntaxBox;
private slots:
    void filterChanged(const QString &text);
};




#endif // SORTVIEW_H
