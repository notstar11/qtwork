#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QIODevice>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QDataStream>
#include <QTextStream>
#include <QList>

struct Movie
{
    int id;
    QString title;
    QDate releaseDate;
};
QDataStream &operator<<(QDataStream &out,const Movie &movie)
{
    out<<(quint32)movie.id<<movie.title<<movie.releaseDate;
    return out;
}
QDataStream &operator>>(QDataStream &in,Movie &movie)
{
    quint32 id;
    QDate date;
    in>>id>>movie.title>>date;
    movie.id=(int)id;
    movie.releaseDate=date;
    return in;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*QFile file("in.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"open file failed";
        return -1;
    }else{
        while(!file.atEnd()){

            qDebug()<<file.readLine();
        }
    }
    QFileInfo info(file);
    qDebug()<<info.isDir();
    qDebug()<<info.isExecutable();
    qDebug()<<info.baseName();
    qDebug()<<info.completeBaseName();
    qDebug()<<info.suffix();
    qDebug()<<info.completeSuffix();
    qDebug()<<QDir::currentPath();

    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out<<QString("the answer is");
    out<<(qint32)42;

   // MainWindow w;
   // w.show();
    file.close();
    QFile f1("file.dat");

    f1.open(QIODevice::ReadOnly);
    QDataStream in(&f1);
    QString str;
    qint32 ia;
    in>>str>>ia;

    QFile data("file.txt");
    if(data.open(QFile::WriteOnly|QIODevice::Truncate))
    {
        QTextStream out(&data);
        out<<"the answer is"<<42;
    }
    QFile data("file.txt");
    if(data.open(QFile::ReadOnly)){
        QTextStream in(&data);
        QString str;
        int ans=0;
        in>>str>>ans;
        qDebug()<<str<<ans;
    }

    QList<Movies>movs;

    QListIterator<QString> i(list);
    while(i.hasNext()){

        qDebug()<<i.next();
    }*/
    QList<QString>list;
    list<<"A"<<"B"<<"C"<<"D";
    QList<QString>::iterator i;
    for(i=list.begin();i!=list.end();++i){
        *i=(*i).toLower();
    }

    return a.exec();
}
