#include "consolelogger.h"

void ConsoleLogger::log(const QString& message) {
    qDebug() << message;
}
