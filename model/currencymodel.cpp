#include "currencymodel.h"

CurrencyModel::CurrencyModel(QObject *parent):
    QAbstractTableModel(parent)
{

}

//返回行数和列数  行数和列数都为货币种类
int CurrencyModel::rowCount(const QModelIndex &parent) const
{
    return currencyMap.count();
}
int CurrencyModel::columnCount(const QModelIndex &parent) const
{
    return currencyMap.count();
}
//判断角色是不是用来显示
//是：返回第section列的名字  否：返回空白的QVariant()
QVariant CurrencyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role!=Qt::DisplayRole){
        return QVariant();
    }
    return currencyAt(section);
}
//返回第offset列的关键字
QString CurrencyModel::currencyAt(int offset) const
{
    return (currencyMap.begin()+offset).key();
}
//ResetModel重置数据
void CurrencyModel::setCurrencyMap(const QMap<QString, double> &map)
{
    beginResetModel();
    currencyMap=map;
    endResetModel();
}
//返回单元格的数据
QVariant CurrencyModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }
    if(role==Qt::TextAlignmentRole){
        return int(Qt::AlignRight|Qt::AlignVCenter);
    }else if(role==Qt::DisplayRole||role==Qt::EditRole){
        QString rowCurrency=currencyAt(index.row());
        QString columnCurrency=currencyAt(index.column());
        if(currencyMap.value(rowCurrency)==0.0){
            return "###";
        }
        double amount=currencyMap.value(columnCurrency)
                                        /currencyMap.value(rowCurrency);
        return QString("%1").arg(amount,0,'f',4);
    }
    return QVariant();
}
//行列不同时才允许修改
Qt::ItemFlags CurrencyModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags=QAbstractItemModel::flags(index);
    if(index.row()!=index.column()){

        flags |=Qt::ItemIsEditable;
    }
    return flags;
}
//将委托获得的数据存入模型
bool CurrencyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid()&&index.row()!=index.column()
            &&role==Qt::EditRole){
        QString columCurrency=headerData(index.column(),
                                         Qt::Horizontal,Qt::DisplayRole).toString();
        QString rowCurrency=headerData(index.row(),Qt::Vertical,Qt::DisplayRole).toString();
        currencyMap.insert(columCurrency,value.toDouble()*currencyMap.value(rowCurrency));
        emit dataChanged(index,index);
        return true;
    }
    return false;
}











