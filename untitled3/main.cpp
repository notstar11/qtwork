#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QMouseEvent>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include "custombutton.h"
#include "paintedwidget.h"

class EventLabel:public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};
void EventLabel::mouseMoveEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Move:(%1,%2)</h1></center>")
                  .arg(QString::number(event->x()),QString::number(event->y())));
}
void EventLabel::mousePressEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Press:(%1,%2)</h1></center>")
                  .arg(QString::number(event->x()),QString::number(event->y())));
}
void EventLabel::mouseReleaseEvent(QMouseEvent *event)
{
    QString msg;
    msg.sprintf("<center><h1>Release:(%d,%d)</h1></center>",
                event->x(),event->y());
    this->setText(msg);
}
class CustomWidget:public QWidget
{
protected:
    bool CustomWidget::event(QEvent *event);
};

bool CustomWidget::event(QEvent *event)
{

    if(event->type()==QEvent::KeyPress){
        QKeyEvent *keyEvent=static_cast<QKeyEvent *>(event);
        if(keyEvent->key()==Qt::Key_Tab){
            qDebug()<<"You press tab";
            return true;
        }
    }
    //return QWidget::event(event);
    return false;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   /* MainWindow w;
    EventLabel *label=new EventLabel;
    label->setWindowTitle("mouseEvent Demo");
    label->resize(300,200);
    label->setMouseTracking(true);
    label->show();
    //w.show();
    CustomButton btn;
    btn.setText("this is a button");
    btn.show();
    CustomWidget *cwidget=new CustomWidget;
    cwidget->show();
    MainWindow w;
    w.show();*/
    PaintedWidget *painted=new PaintedWidget;
    painted->show();
    return a.exec();
}
