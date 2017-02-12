#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QLabel>
#include <QMouseEvent>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
//class CustomButton
class CustomButton:public QPushButton
{
    Q_OBJECT
public:
    CustomButton(QWidget *parent=0);
private:
    void onButtonClicked();
protected:
    void mousePressEvent(QMouseEvent *event);
};
#endif // CUSTOMBUTTON_H
