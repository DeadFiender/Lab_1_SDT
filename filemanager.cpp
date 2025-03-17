#include "FileManager.h"
#include <QDebug>

FileManager& FileManager::instance() {
    static FileManager instance;
    return instance;
}

// Конструктор, инициализация таймера
FileManager::FileManager(QObject* parent)
    : QObject(parent), logger_(nullptr) {
    connect(&timer_, &QTimer::timeout, this, &FileManager::checkFiles);
    timer_.setInterval(100);
}

// Установка логгера
void FileManager::setLogger(ILogger* logger) {
    logger_ = logger;
}

// Добавление файла в список отслеживания
void FileManager::addFile(const QString& filePath) {
    // Проверка того, есть ли уже файл в списке наблюдения


    auto* watcher = new FileWatcher(filePath, this);
    connect(watcher, &FileWatcher::fileCreated, this, &FileManager::onFileCreated);
    connect(watcher, &FileWatcher::fileModified, this, &FileManager::onFileModified);
    connect(watcher, &FileWatcher::fileDeleted, this, &FileManager::onFileDeleted);
    watchers_.append(watcher);
}

// Запуск мониторинга
void FileManager::startMonitoring() {
    checkFiles();
    timer_.start();
}

// Проверка всех файлов
void FileManager::checkFiles() {
    for (auto* watcher : watchers_) {
        watcher->checkFile();
    }
}

// Логирование событий
void FileManager::onFileCreated(const QString& filePath, qint64 size) {
    if (logger_) logger_->log(QString("Файл создан: %1 | Размер: %2").arg(filePath).arg(size));
}

void FileManager::onFileModified(const QString& filePath, qint64 newSize) {
    if (logger_) logger_->log(QString("Файл изменен: %1 | Новый размер: %2").arg(filePath).arg(newSize));
}

void FileManager::onFileDeleted(const QString& filePath) {
    if (logger_) logger_->log(QString("Файл удален: %1").arg(filePath));
}
