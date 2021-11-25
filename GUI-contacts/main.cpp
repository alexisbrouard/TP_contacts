#include "mainwindow.h"
#include "contacts.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Contacts db_contacts;
    return a.exec();
}
