#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QMap>
#include "filewatcher.h"

class FileManager : public QObject {
    Q_OBJECT

public:
    FileManager();

    void addFile(const QString& path);
    void removeFile(const QString& path);
    void startMonitoring();

private slots:
    void onFileCreated(const QString& path, qint64 size);
    void onFileModified(const QString& path, qint64 size);
    void onFileDeleted(const QString& path);

private:


};

#endif // FILEMANAGER_H
