#include "mainwindow.h"
#include "contacts.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Contacts db_contacts;


    /*QDirIterator it("/data", QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.fileName()
        while (!it.path.atEnd()) {
                    QByteArray line = file.readLine();
                    wordList.append(line.split(',').first());
                }
    }
    }
    QFile file("FlightParam.csv");
       if (!file.open(QIODevice::ReadOnly)) {
           qDebug() << file.errorString();
           return 1;
       }

       QStringList wordList;
       while (!file.atEnd()) {
           QByteArray line = file.readLine();
           wordList.append(line.split(',').first());
       }
    */
    return a.exec();
}
