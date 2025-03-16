#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "ILogger.h"
#include <QDebug>

class ConsoleLogger : public ILogger {
public:
    void log(const QString& message) override;
};

#endif // CONSOLELOGGER_H
