#include "logmodelextended.h"

LogModelExtended::LogModelExtended(QObject *parent) :
    QStandardItemModel(parent)
{
}

void LogModelExtended::addStandardMessage(const QDateTime &time, const QString &text, int moduleType, int type)
{

    QStandardItem *item = new QStandardItem(time.toString("[dd.MM.yyyy hh:mm:ss]"));
    item->setEditable(false);
    QStandardItem *item2 = new QStandardItem(text);
    item2->setEditable(false);
    item2->setForeground(getColor(type));
    item2->setIcon(getIcon(type));
    item2->setData(moduleType, Qt::UserRole + 1);
    item2->setData(type, Qt::UserRole + 2);
    item2->setToolTip(QString("<table><tr><td>").append(text).append("</td></td></table>"));

    this->appendRow(QList<QStandardItem*>() << item << item2);
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

void LogModelExtended::createLogForIncomingFiles(const QString &description, const QString &fileLogId){
    createLogForIncomingFiles(QDateTime::currentDateTime(),description,fileLogId);
}

void LogModelExtended::addFileInLog(const QString &fileLogId, const QString &filePath){
    QMimeDatabase db;
    QMimeType mime = db.mimeTypeForFile(filePath);
    QFileIconProvider iconProvider;
    QIcon fileIcon = iconProvider.icon(filePath);
}

QIcon LogModelExtended::getIcon(int type){
    const static QIcon message(":/Icons/message_16.png");
    const static QIcon warning(":/Icons/warning_16.png");
    const static QIcon error(":/Icons/error_16.png");

    switch(type)
    {
    case 0:
    {
        return message;
        break;
    }
    case 1:
    {
        return warning;
        break;
    }
    case 2:
    {
        return error;
        break;
    }
    default:
        return message;
        break;
    }
}

QBrush LogModelExtended::getColor(int type) {
    if (type == 2) {
        return QBrush(Qt::red);
    }
    else if (type == 1) {
        return QBrush(QColor(0xda, 0xa5, 0x20));
    }
    return QBrush(Qt::black);
}

