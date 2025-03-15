#include <QCoreApplication>
#include <QFileInfo>
#include <iostream>
#include "filemanager.h"

using namespace std;

int main(int argc, char *argv[]){


}

/*
{
    class FileManager
    {
    public:
        bool Add(параметры);
        bool Del();
        bool update();

    private:
        //Container-храним
        //push back
        //loger связь с update - вывод на экран когда что-то произошло
    };


    //QCoreApplication a(argc, argv);
    QFileInfo f_info("C:\\Desktop\\Test\\a.txt");
    cout<<f_info.exists()<<endl;
    cout<<f_info.size()<<endl;

    bool fileexist = f_info.exists();
    int fileCurrentsize = f_info.size();

    while(1){
        f_info.refresh();
        if(fileexist != f_info.exists()||fileCurrentsize!= f_info.size())
        {
            cout<<f_info.exists()<<endl;
            cout<<f_info.size()<<endl;
            fileexist = f_info.exists();
            fileCurrentsize = f_info.size();
        }
    }
    return 0;//a.exec();
}
*/
