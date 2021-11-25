#define INSERTS_COUNT 10000
#define DISPLAY_EVERY 1000
#define func_width    50

#include "contacts.h"

Contacts::Contacts()
{
    setupDB();
}

Contacts::~Contacts()
{

}


bool Contacts::addRow(QStringList dataList)
{
    QSqlQuery query;
    //QDate Date = QDate::fromString(dataList[9],"yyyy/MM/dd");

    query.prepare("INSERT INTO contacts(GUID, firstname, lastname, email, tel, category, city, birth_day, country, list, company)"
                  "VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    for (int i = 0; i <= 11; i++) {
        if (i == 0)
            continue;
        query.bindValue(i - 1, dataList[i]);
    }
    if(query.exec() == true)
    {
        return true;
    }
    if (query.lastError().isValid()) {
            qWarning() << query.lastError().text();
            return false;
    }
    return false;
}

bool Contacts::Delete_Company(QString &str)
{
    QSqlQuery query;
    query.prepare("DELETE FROM contacts WHERE company ='"+str+"';");
    if(query.exec() == true)
    {
        qDebug() << "Success Delete";
          return true;
    }
    if (query.lastError().isValid()) {
            qWarning() << query.lastError().text();
            return false;
     }
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
        //qWarning() << query.lastError().text();
        qWarning() << "Invalid Query";
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
