#include "paintedwidget.h"
PaintedWidget::PaintedWidget(QWidget *parent):
    QWidget(parent)
{
    resize(800,600);
    setWindowTitle("Paint Window");
}
void PaintedWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    /*
    painter.drawLine(80,100,650,500);
    painter.setPen(Qt::red);
    painter.drawRect(10,10,100,400);
    painter.setPen(QPen(Qt::green,5));
    //painter.setBrush(Qt::blue);
    QRadialGradient gradient(50,50,50,50,50);
    gradient.setColorAt(0,QColor::fromRgbF(0,1,0,1));
    gradient.setColorAt(1,QColor::fromRgbF(0,0,0,0));
    QBrush brush(gradient);
    painter.setBrush(brush);
    painter.drawEllipse(50,150,400,200);

    QPen pen;
    QVector<qreal>dashes;
    qreal space=4;
    dashes<<1<<space<<3<<space<<9<<space;
    pen.setDashPattern(dashes);
    painter.setPen(pen);
    painter.drawEllipse(50,150,400,200);

    painter.setRenderHint(QPainter::Antialiasing,true);
    //start:Point(x,y) end:Point(x,y)
    QLinearGradient linearGradient(60,50,200,200);
    linearGradient.setColorAt(0.2,Qt::white);
    linearGradient.setColorAt(0.6,Qt::green);
    linearGradient.setColorAt(1.0,Qt::black);
    painter.setBrush(QBrush(linearGradient));
    painter.drawEllipse(50,50,200,150);*/

    QPixmap pixmap(":/images/test.PNG");
    QBitmap bitmap("E:/qt_test/untitled3/test.png");
    painter.drawPixmap(10,10,181,138,pixmap);
    painter.drawPixmap(270,10,181,138,bitmap);

}
