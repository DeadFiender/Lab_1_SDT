#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QFileInfo>

class FileWatcher : public QObject {
    Q_OBJECT

public:
    explicit FileWatcher(const QString& filePath, QObject* perent = nullptr);

    void checkFile();// Проверка состояния файла
signals:
    void fileCreated(const QString& filePath, qint64 size);
    void fileModified(const QString& filePath, qint64 newsize);
    void fileDeleted(const QString& filePath);

private:
    QString filePath_;// Путь к файлу
    bool lastExists_;// Был ли файл в предыдущую проверку
    qint64 lastSize_;// Размер файла при последней проверке
};

#endif // FILEWATCHER_H
