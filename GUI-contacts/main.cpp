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


    /*Exporting Information Based on Company and Category*/
    /*db_contacts.sqlToCSV("company");
    db_contacts.sqlToCSV("category");*/

    return a.exec();
}
