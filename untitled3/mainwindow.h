#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QTextEdit>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QWidget>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    bool eventFilter(QObject *obj,QEvent *event);

private:
    Ui::MainWindow *ui;
    QTextEdit *textEdit;
};

#endif // MAINWINDOW_H
