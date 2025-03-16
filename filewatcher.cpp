#include "FileWatcher.h"
#include <QDebug>

FileWatcher::FileWatcher(const QString& filePath, QObject* parent)
    : QObject(parent), filePath_(filePath), lastExists_(false), lastSize_(0) {}

// Проверка состояния файла
void FileWatcher::checkFile() {
    QFileInfo fileInfo(filePath_);
    fileInfo.refresh();  // Принудительно обновляем информацию о файле

    bool exists = fileInfo.exists();
    qint64 size = exists ? fileInfo.size() : 0;

    if (exists && !lastExists_) {
        emit fileCreated(filePath_, size);
    } else if (exists && lastExists_ && size != lastSize_) {
        emit fileModified(filePath_, size);
    } else if (!exists && lastExists_) {
        emit fileDeleted(filePath_);
    }

    lastExists_ = exists;
    lastSize_ = size;
}
