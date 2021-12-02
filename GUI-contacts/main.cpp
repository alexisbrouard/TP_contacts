#include "mainwindow.h"
#include "contacts.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*Deleting Rows with facebook company*/
    /* QString company = "Facebook";
    db_contacts.Delete_Company(company);*/

    /* initial Insert of all data*/

    return a.exec();
}
