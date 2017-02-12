#include "mainwindow.h"
#include <QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;
    window.setWindowTitle("enter you age");
    QSpinBox *spinBox=new QSpinBox(&window);
    QSlider *slider=new QSlider(Qt::Horizontal,&window);
    spinBox->setRange(0,130);
    slider->setRange(0,130);

    QObject::connect(slider,&QSlider::valueChanged,
                     spinBox,&QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal)(int)=&QSpinBox::valueChanged;
    QObject::connect(spinBox,spinBoxSignal,slider,&QSlider::setValue);

    spinBox->setValue(35);

    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);

    window.setLayout(layout);
    window.show();
    MainWindow w;
    w.show();

    return a.exec();
}
