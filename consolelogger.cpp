#include "consolelogger.h"

//Реализация метода log(), который выводит сообщение в консоль
void ConsoleLogger::log(const QString& message) {
     qDebug() << "[LOG] " << message;
}
