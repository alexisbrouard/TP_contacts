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
#include <QObject>
#include <QThreadPool>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include "contacts_global.h"

class CONTACTS_EXPORT Contacts : QObject
{
    Q_OBJECT
public:
    Contacts();
    ~Contacts();
    bool setupDB();
    bool insertAll();
    void cleanDb(QSqlDatabase &db);
    bool sqlToCSV(QString strExport);
    bool addRow(QStringList dataList);
    bool Delete_Company(QString &str);
    QString escapedCSV(QString unexc);

private:
    QSqlDatabase _db;
    QThreadPool _pool;
};

#endif // CONTACTS_H
