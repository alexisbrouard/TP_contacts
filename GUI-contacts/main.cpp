#include "mainwindow.h"
#include "contacts.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Contacts db_contacts;

    /*Deleting Rows with facebook company*/
    /* QString company = "Facebook";
    db_contacts.Delete_Company(company);*/

    /* initial Insert of all data*/
    QStringList wordList;
    QString data;
    QStringList appDataLocation = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
    QDir    dir(appDataLocation[0]);

    QDirIterator iterator(dir);
    while (iterator.hasNext()) {
        QFile file(iterator.next());
        if ( file.open( QIODevice::ReadOnly ) ) {
            qDebug() << "Opened:" << file.fileName() << endl;
            while (!file.atEnd()) {
                   data = file.readLine();
                   wordList = data.split(",");
                   db_contacts.addRow(wordList);
                   wordList.empty();
            }
        }
    }

    /*Exporting Information Based on Company and Category*/
    /*db_contacts.sqlToCSV("company");
    db_contacts.sqlToCSV("category");*/

    return a.exec();
}
