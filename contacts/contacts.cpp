#define INSERTS_COUNT 10000
#define DISPLAY_EVERY 1000
#define func_width    50

#include "contacts.h"
#include "contacts.h"

Contacts::Contacts()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    setupDB();
}

Contacts::~Contacts()
{

}


bool Contacts::addRow(QStringList dataList)
{
    QSqlQuery query;
    dataList[11].replace(QString("\r\n"), QString(""));
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
    query.prepare("DROP * FROM contacts WHERE company ='"+str+"';");
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
    QString dbPath = "ContactsBDD.db";
    _db.setDatabaseName(dbPath);

    if (_db.open() == false) {
        qWarning() << "Unable to open db" << dbPath;
        return false;
    }
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
        qWarning() << "Invalid Query";
        return false;
    }
    return true;
}

void Contacts::cleanDb(QSqlDatabase &db)
{
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
