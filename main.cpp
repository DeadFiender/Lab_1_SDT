#include <QCoreApplication>
#include "FileManager.h"
#include "ConsoleLogger.h"

using namespace std;

int main(int argc, char *argv[]){
    QCoreApplication app(argc, argv);

    ConsoleLogger logger;
    FileManager& manager = FileManager::instance();// Получаем экземпляр FileManager
    manager.setLogger(&logger);// Устанавливаем логгер для FileManager, чтобы он мог выводить сообщения

    //manager.addFile("C:/Users/bibek/Desktop/Test/a.txt");// Указываем путь к файлу
    //manager.addFile("C:/Users/bibek/Desktop/Test/b.txt");
    //manager.addFile("C:/Users/bibek/Desktop/Test/c.txt");
    //manager.addFile("C:/Users/bibek/Desktop/Test/c.txt");
    manager.addFile("H:/Desktop/Test/a.txt");
    manager.addFile("H:/Desktop/Test/b.txt");
    manager.addFile("H:/Desktop/Test/c.txt");
    manager.addFile("H:/Desktop/Test/c.txt");

    manager.startMonitoring();// Запуск наблюдения за файлом

    return app.exec();
}
