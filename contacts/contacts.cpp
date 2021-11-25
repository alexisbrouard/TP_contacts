#define INSERTS_COUNT 10000
#define DISPLAY_EVERY 1000
#define func_width    50

#include "contacts.h"

Contacts::Contacts()
{
    setupDB();
}

bool Contacts::addRow(QStringList dataList)
{
    QSqlQuery query;
    QDate Date = QDate::fromString( dataList[8],"yyyy/MM/dd");

    query.prepare("INSERT INTO files(GUID, firstname, lastname, email, tel, category, city, birth-date, country, list, company) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, dataList[0]);
    query.bindValue(1, dataList[0]);
    query.bindValue(2, dataList[0]);
    query.bindValue(3, dataList[0]);
    query.bindValue(4, dataList[0]);
    query.bindValue(5, dataList[0]);
    query.bindValue(6, dataList[0]);
    query.bindValue(7, dataList[0]);
    query.bindValue(8, Date);
    query.bindValue(9, dataList[0]);
    query.bindValue(10, dataList[0]);
    query.bindValue(11, dataList[0]);

    if(query.exec())
    {
          return true;
    }
    qDebug() << "Error:" << query.lastError();
    return false;
}

bool Contacts::setupDB() {
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = "C:\\Users\\Cameron Gassedat\\source\\repos\\TP_contacts\\BDD\\ContactsBDD.db";
    _db.setDatabaseName(dbPath);

    if (_db.open() == false) {
        qWarning() << "Unable to open db" << dbPath;
        return false;
    }
    qDebug() << __FUNCTION__ << __LINE__ << "creating table 'contacts'";

    //id,GUID,firstname,lastname,email,tel,category,city,birth_day,country,list,company
    QString tblFilesCreate = "CREATE TABLE IF NOT EXISTS contacts ("
                             "id            INTEGER PRIMARY KEY AUTOINCREMENT, "
                             "GUID          STRING,"
                             "firstname     STRING,"
                             "lastname      STRING,"
                             "email         STRING,"
                             "tel           STRING,"
                             "category      STRING,"
                             "city          STRING,"
                             "birth_day     QDATE,"
                             "country       STRING,"
                             "list          STRING,"
                             "company       STRING"
                             ")";
    QSqlQuery query;
    query.exec(tblFilesCreate);
    if (query.lastError().isValid()) {
        qWarning() << query.lastError().text();
        return false;
    }
    return true;
}

void Contacts::cleanDb(QSqlDatabase &db) {

    QSqlQuery query;
    query.exec("DROP TABLE contacts");
    if (query.lastError().isValid()) {
        qWarning() << "DROP TABLE" << query.lastError().text();
    }
    db.commit();
    db.close();
}
