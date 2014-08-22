#include "logmodelextended.h"

LogModelExtended::LogModelExtended(QObject *parent) :
    QStandardItemModel(parent)
{
}

void LogModelExtended::addStandardMessage(const QDateTime &time, const QString &text, int moduleType, int type)
{

    QStandardItem *__item = new QStandardItem(time.toString("[dd.MM.yyyy hh:mm:ss]"));
    __item->setEditable(false);
    QStandardItem *__item2 = new QStandardItem(text);
    __item2->setEditable(false);
    __item2->setData(moduleType, Qt::UserRole + 1);
    __item2->setData(type, Qt::UserRole + 2);
    __item2->setToolTip(QString("<table><tr><td>").append(text).append("</td></td></table>"));

    this->appendRow(QList<QStandardItem*>() << __item << __item2);
}

void LogModelExtended::addStandardMessage(const QString &text, int moduleType, int type)
{
    addStandardMessage(QDateTime::currentDateTime(), text, moduleType, type);
}

void LogModelExtended::addInformMessage(const QDateTime &time, const QString &text){}

void LogModelExtended::addInformMessage(const QString &text){
    addInformMessage(QDateTime::currentDateTime(), text);
}

void LogModelExtended::createLogForIncomingFiles(const QDateTime &time, const QString &description, const QString &fileLogId){}

void LogModelExtended::createLogForIncomingFiles(const QString &description, const QString &fileLogId){}

void LogModelExtended::addFileInLog(const QString &fileLogId, const QString &filePath){}
