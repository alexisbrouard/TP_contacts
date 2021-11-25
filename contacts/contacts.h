#ifndef CONTACTS_H
#define CONTACTS_H

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QtSql/QSqlDriver>
#include <QElapsedTimer>
#include <QtSql/QSqlQuery>
#include <QStandardPaths>
#include <iomanip>
#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDate>
#include <QDirIterator>

#include "contacts_global.h"

class CONTACTS_EXPORT Contacts
{
public:
    Contacts();
    bool setupDB();
    void cleanDb(QSqlDatabase &db);
    bool addRow(QStringList dataList);
private:
    QSqlDatabase _db;
};

#endif // CONTACTS_H
