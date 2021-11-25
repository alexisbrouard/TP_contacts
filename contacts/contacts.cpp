#define INSERTS_COUNT 10000
#define DISPLAY_EVERY 1000
#define func_width    50

#include "contacts.h"

Contacts::Contacts()
{
    setupDB();
}

bool Contacts::addRow()
{}


bool Contacts::setupDB() {
    QSqlDatabase db                      = QSqlDatabase::addDatabase("ContactsBDD");
    QString dbPath = "C:\\Users\\Cameron Gassedat\\source\\repos\\TP_contacts\\BDD\\ContactsBDD.db";
    db.setDatabaseName(dbPath);

    if (db.open() == false) {
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
