#ifndef LOGMODELEXTENDED_H
#define LOGMODELEXTENDED_H

#include <QStandardItemModel>
#include <QObject>
#include <QDateTime>

// можно наверное отнаследоаться от QStandardItemModel, в реализации должно
// быть проще, смотри по ситуации
class LogModelExtended : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit LogModelExtended(QObject *parent = 0);
    //.....

    //.....

signals:

public slots:
    /**
     * @brief addStandardMessage
     * Добавляет стандартное сообщение в модель. Просто текст.
     * Всё, что не влезает в одну строку игрорируется
     * @param time
     * Время добавления
     * @param text
     * Сам текст сообщения
     * @param moduleType
     * Тип модуля (энумерация, смотри скриншот: AРМ, СЕТЬ, GSM...)
     * @param type
     * Тип сообщения - normal, warning, error
     */
    void addStandardMessage(const QDateTime &time, const QString &text, int moduleType, int type);

    /*
     * То же, что и предыдущий слот, только время по умолчанию ставиться текущее
     **/
    void addStandardMessage(const QString &text, int moduleType, int type);

    /**
     * @brief addInformMessage
     * Добавляет сообщение, требующее внимания диспетчера. Так же просто текст,
     * но тут условие: обязательно надо отобразить весь текст, причем он должен быть
     * обрамлён мигающей рамкой, до того, как пользователь не даблкликнет по этому
     * сообщению для подтверждения прочнетия. После этого сообщение мигать
     * перестаёт, и под ним появляется строка, со временем, когда пользователь
     * подтвердил прочтение.
     * @param time
     * Время
     * @param text
     * Текст
     */
    void addInformMessage(const QDateTime &time, const QString &text);

    void addInformMessage(const QString &text);

    /**
     * @brief createLogForIncomingFiles
     * Добавляет в лог строку с входящими файлами.
     * @param time
     * Время
     * @param description
     * Опсиания файлов
     * @param fileLogId
     * Идентификатор строки.
     */
    void createLogForIncomingFiles(const QDateTime &time, const QString &description, const QString &fileLogId);

    void createLogForIncomingFiles(const QString &description, const QString &fileLogId);

    /**
     * @brief addFileInLog
     * Добавляет
     * @param fileLogId
     * @param filePath
     */
    void addFileInLog(const QString &fileLogId, const QString &filePath);



};

#endif // LOGMODELEXTENDED_H
