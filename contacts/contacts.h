#ifndef CONTACTS_H
#define CONTACTS_H

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QtSql/QSqlDriver>
#include <QElapsedTimer>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QStandardPaths>
#include <iomanip>
#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QDate>
#include <QDirIterator>

#include "contacts_global.h"

class CONTACTS_EXPORT Contacts
{
public:
    Contacts();
    ~Contacts();
    bool setupDB(QSqlDatabase &db);
    void cleanDb(QSqlDatabase &db);
    bool sqlToCSV();
    bool addRow(QStringList dataList);
    QString escapedCSV(QString unexc);
private:
    QSqlDatabase _db;
};

#endif // CONTACTS_H