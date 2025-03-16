#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QTimer>
#include "ILogger.h"
#include "FileWatcher.h"

class FileManager : public QObject {
    Q_OBJECT

public:
    static FileManager& instance();

    void setLogger(ILogger* logger);// Установка логгера
    void addFile(const QString& filepath);// Добавление файла для мониторинга
    void startMonitoring();// Запуск мониторинга

private slots:
    void onFileCreated(const QString& filePath, qint64 size);//
    void onFileModified(const QString& filePath, qint64 size);//
    void onFileDeleted(const QString& filePath);//
    void checkFiles();// Проверка всех файлов

private:
    explicit FileManager(QObject* parent = nullptr);
    ILogger* logger_;// Указатель на логгер
    QTimer timer_;// Таймер для периодической проверки
    QList<FileWatcher*> watchers_;// Список наблюдателей за файлами
};

#endif // FILEMANAGER_H
