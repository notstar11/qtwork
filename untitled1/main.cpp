#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include "reader.h"
#include "newspaper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*QLabel label("hello");
    label.show();
    QPushButton button("quit");
    QObject::connect(&button,&QPushButton::clicked,&QApplication::quit);
    QObject::connect(&button,&QPushButton::clicked,[](bool){
        qDebug()<<"you clicked me!";
    });
    button.show();
    MainWindow w;
    w.show();
    Newspaper newspaper("newspaper A");
    Reader reader;
    QObject::connect(&newspaper,&Newspaper::newPaper,
                     &reader,&Reader::receiveNewspaper);
    newspaper.send();*/
    MainWindow win;
    win.show();

    return a.exec();
}
