#ifndef ILOGGER_H
#define ILOGGER_H

#include <QString>

class ILogger {
public:
    virtual ~ILogger() = default;// Виртуальный деструктор (обеспечивает корректное удаление наследников)
    virtual void log(const QString& message) = 0;
};

#endif // ILOGGER_H
