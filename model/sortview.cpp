#include "sortview.h"
SortView::SortView()
{
    //所有颜色的名字
    model=new QStringListModel(QColor::colorNames(),this);

    modelProxy=new QSortFilterProxyModel(this);
    modelProxy->setSourceModel(model);
    //对第一列进行过滤
    modelProxy->setFilterKeyColumn(0);

    view=new QListView(this);
    view->setModel(modelProxy);

    QLineEdit *filterInput=new QLineEdit;
    QLabel *filterLabel=new QLabel(tr("Filter"));
    QHBoxLayout *filterLayout=new QHBoxLayout;
    filterLayout->addWidget(filterLabel);
    filterLayout->addWidget(filterInput);

    //下拉框
    syntaxBox=new QComboBox;
    //QSizePolicy类是描述布局水平和垂直方向调整策略的属性
    syntaxBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    syntaxBox->addItem(tr("Regualr expression"),QRegExp::RegExp);
    syntaxBox->addItem(tr("Wildcard"),QRegExp::Wildcard);
    syntaxBox->addItem(tr("Fixed string"),QRegExp::FixedString);
    QLabel *syntaxLabel=new QLabel(tr("Syntax"));
    QHBoxLayout *syntaxLayout=new QHBoxLayout;
    syntaxLayout->addWidget(syntaxLabel);
    syntaxLayout->addWidget(syntaxBox);

    QVBoxLayout *layout=new QVBoxLayout(this);
    layout->addWidget(view);
    layout->addLayout(filterLayout);
    layout->addLayout(syntaxLayout);

    connect(filterInput,SIGNAL(textChanged(QString)),
            this,SLOT(filterChanged(QString)));
}
void SortView::filterChanged(const QString &text)
{
    QRegExp::PatternSyntax syntax=QRegExp::PatternSyntax(
                syntaxBox->itemData(syntaxBox->currentIndex()).toInt());
    //CaseInsensitive不区分大小
    QRegExp regExp(text,Qt::CaseInsensitive,syntax);
    modelProxy->setFilterRegExp(regExp);
}
