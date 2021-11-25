#include "mainwindow.h"
#include "contacts.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Contacts db_contacts;
    QString company = "Facebook";
    db_contacts.Delete_Company(company);
    // initial Insert of all data
    QStringList wordList;
    QString data;

       QString appDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/data_qt";

       QDir    dir(appDataLocation);
       qDebug() << appDataLocation;
       if (!dir.exists()) {
           dir.mkdir(appDataLocation);
           qDebug() << __FUNCTION__ << __LINE__ << "mkdir" << appDataLocation;
       }

    QDirIterator iterator(dir);
    while (iterator.hasNext()) {
        QFile file(iterator.next());
        if ( file.open( QIODevice::ReadOnly ) ) {
            qDebug() << "Opened:" << file.fileName() << endl;
            while (!file.atEnd()) {
                   data = file.readLine();
                   //qDebug() << "Data: "<< data;
                   wordList = data.split(",");
                   db_contacts.addRow(wordList);
                   wordList.empty();
                    }
        }
        else
            qDebug() << "Can't open " << file.fileName() << file.errorString() << endl;
    }

    db_contacts.sqlToCSV();


    return a.exec();
}
