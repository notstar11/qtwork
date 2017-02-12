#include "filesystemwidget.h"
FileSystemWidget::FileSystemWidget(QWidget *parent):
    QWidget(parent)
{
    model=new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    treeView=new QTreeView(this);

    treeView->setModel(model);
    treeView->setRootIndex(model->index(QDir::currentPath()));;
    QPushButton *mkdirButton=new QPushButton(tr("make dir"),this);
    QPushButton *rmButton=new QPushButton(tr("remove"),this);
    QHBoxLayout *buttonLayout=new QHBoxLayout;
    buttonLayout->addWidget(mkdirButton);
    buttonLayout->addWidget(rmButton);

    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(treeView);
    layout->addLayout(buttonLayout);

    setLayout(layout);
    setWindowTitle("file system model");

    connect(mkdirButton,SIGNAL(clicked()),this,SLOT(mkdir()));
    connect(rmButton,SIGNAL(clicked()),this,SLOT(rm()));
    QModelIndex parentIndex=model->index(QDir::currentPath());
    int numRows=model->rowCount(parentIndex);
    qDebug()<<numRows;
    for(int row=0;row<numRows;++row){
        QModelIndex index=model->index(row,0,parentIndex);
        QString text=model->data(index,Qt::DisplayRole).toString();
        qDebug()<<text;
        qDebug()<<"111";
    }
}
void FileSystemWidget::mkdir()
{
    QModelIndex index=treeView->currentIndex();
    if(!index.isValid()){
        return;
    }
    QString dirName=QInputDialog::getText(this,tr("create directory"),
                                          tr("directory name"));
    if(!dirName.isEmpty()){
        if(!model->mkdir(index,dirName).isValid()){
            QMessageBox::information(this,
                                     tr("create directory"),
                                     tr("failed to create"));
        }
    }
}
void FileSystemWidget::rm()
{
    QModelIndex index=treeView->currentIndex();
    if(!index.isValid())
    {
        return;
    }
    bool ok;
    if(model->fileInfo(index).isDir()){
        ok=model->rmdir(index);
    }else{
        ok=model->remove(index);
    }
    if(!ok){
        QMessageBox::information(this,
                                 tr("remove"),
                                 tr("fail to remove"));
    }
}
FileSystemWidget::~FileSystemWidget()
{}
