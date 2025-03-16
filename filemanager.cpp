#include "filemanager.h"
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

