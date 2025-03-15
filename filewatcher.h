#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QObject>
#include <QFileInfo>
#include <QTimer>

class FileWatcher : public QObject {
    Q_OBJECT

public:
    FileWatcher();

    QString filepath() const;
    void startWatching();

signals:
    void fileCreated(const QString& path, qint64 size);
    void fileModified(const QString& path, qint64 size);
    void fileDeleted(const QString& path);

private slots:
    void checkFile();

private:
    QString filepath_;
    bool lastExists;
    qint64 lastsize_;
    QTimer timer_;


};

#endif // FILEWATCHER_H
