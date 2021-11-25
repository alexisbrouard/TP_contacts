#define INSERTS_COUNT 10000
#define DISPLAY_EVERY 1000
#define func_width    50

#include "contacts.h"
#include "contacts.h"

Contacts::Contacts()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    setupDB(db);
}

Contacts::~Contacts()
{

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

bool Contacts::setupDB(QSqlDatabase &_db) {
    QString dbPath = "ContactsBDD.db";
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

bool Contacts::sqlToCSV()
{
    QSqlQuery query;
    QStringList companyList;

    query.prepare("SELECT company FROM contacts");
    if (!query.exec()){
            qDebug("failed to run query");
            return false;
    }

    while(query.next())
    {
        const QSqlRecord record = query.record();
        for(int i=0, recCount = record.count(); i < recCount; ++i)
        {
            companyList.append(record.value(i).toString());
        }
    }

    for(int i=0;i < companyList.size();i++)
    {

        QString csvName = "company-" + companyList[i] +".csv";
        QFile csvCompany(csvName);
        QString queryRequest = "SELECT * FROM contacts WHERE company='" + companyList[i] + "'";
        query.prepare(queryRequest);
        qDebug()<<queryRequest<< endl;
        if (!csvCompany.open(QFile::WriteOnly | QFile::Text)){
                qDebug("failed to open csv file");
                return false;
        }
        if (!query.exec()){
                qDebug("failed to run query");
                return false;
        }
        QTextStream outStream(&csvCompany);
        outStream.setCodec("UTF-8");
        while(query.next())
        {
            const QSqlRecord record = query.record();
            for(int i=0, recCount = record.count(); i<recCount; ++i)
            {
                if(i>0) { outStream << ','; }
                outStream << escapedCSV(record.value(i).toString());
            }
            outStream << '\n';
        }
        csvCompany.close();
    }
    return true;
}

QString Contacts::escapedCSV(QString unexc)
{
    if (!unexc.contains(QLatin1Char(',')))
        return unexc;
    return '\"' + unexc.replace(QLatin1Char('\"'), QStringLiteral("\"\"")) + '\"';
}
