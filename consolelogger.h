#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "ILogger.h"
#include <QDebug>// Для вывода сообщений в консоль

class ConsoleLogger : public ILogger {// Класс логирования в консоль, реализует интерфейс ILogger
public:
    void log(const QString& message) override;// Реализация метода log() из интерфейса ILogger
};

#endif // CONSOLELOGGER_H
