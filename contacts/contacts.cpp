#define INSERTS_COUNT 10000
#define DISPLAY_EVERY 1000
#define func_width    50

#include "contacts.h"

Contacts::Contacts()
{


    _pool.setMaxThreadCount(1);
    _db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = "ContactsBDD.db";
    _db.setDatabaseName(dbPath);

    if (_db.open() == false) {
        qWarning() << "Unable to open db" << dbPath;
    }
    else {
        setupDB();
        if(globalStats().toInt()<=0)
        {
            qDebug() <<"On est dedans !";
            insertAll();
        }
    }
}

Contacts::~Contacts() {}

bool Contacts::insertAll()
{
    QStringList wordList;
    QString data;
    QStringList appDataLocation = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
    QDir    dir(appDataLocation[0]);

    QDirIterator iterator(dir);
    while (iterator.hasNext()) {
        QFile file(iterator.next());
        if ( file.open( QIODevice::ReadOnly ) ) {
            qDebug() << "Opened:" << file.fileName() << endl;
            while (!file.atEnd()) {
                   data = file.readLine();
                   wordList = data.split(",");
                   wordList[11].replace("\r\n", "");
                   addRow(wordList);
                   wordList.empty();
            }
        }
    }

    qDebug() << "Exiting Function Insert";
    return true;
}


bool Contacts::addRow(QStringList dataList)
{
    return QtConcurrent::run(&_pool, [this, dataList]() {
    QSqlQuery query(_db);

    query.exec("pragma temp_store = memory");
    query.exec("PRAGMA synchronous = normal");
    query.exec("pragma mmap_size = 30000000000");
    query.exec("PRAGMA journal_mode = wal");
    query.prepare("INSERT INTO contacts(GUID, firstname, lastname, email, tel, category, city, birth_day, country, list, company)"
                  "VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    for (int i = 1; i < dataList.size(); i++) {
        query.bindValue(i - 1, dataList[i]);
    }
    if (query.exec() == true)
    {
        return true;
    }
    if (query.lastError().isValid()) {
        qWarning() << query.lastError().text();
    }
    return false;
    });
}

bool Contacts::updateRow(QString &field, QString &elem)
{
    return QtConcurrent::run(&_pool, [this, field, elem]() {
        QSqlQuery query(_db);
        query.prepare("UPDATE contacts"
                      " SET company = " + elem);
        if (query.exec() == true)
        {
            qDebug() << "Update Success";
            return true;
        }
        if (query.lastError().isValid()) {
                qWarning() << query.lastError().text();
                return false;
         }
        return false;
    });
}

bool Contacts::deleteField(QString &str, QString &field)
{
    return QtConcurrent::run(&_pool, [this, str, field]() {
        QSqlQuery query(_db);
        query.prepare("DELETE FROM contacts WHERE " + field + "='" + str + "'");
        if(query.exec())
        {
            qDebug() << "Success Delete";
            return true;
        }
        if (query.lastError().isValid()) {
                qWarning() << query.lastError().text();
                return false;
         }
        return false;
    });
}

bool Contacts::setupDB()
{
    QString tblFilesCreate = "CREATE TABLE IF NOT EXISTS contacts ("
                             "id            INTEGER PRIMARY KEY AUTOINCREMENT,"
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
     qDebug() << __FUNCTION__ << __LINE__ << "Databse connected / created";
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

bool Contacts::sqlToCSV(QString strExport)
{
    return QtConcurrent::run(&_pool, [this, strExport]() {
        QSqlQuery query(_db);

        QStringList exportList ={""};
        QString exportString;
        exportString = "SELECT " + strExport + " FROM contacts";
        query.prepare(exportString);
        if (!query.exec()){
                qDebug("failed to run query");
                return false;
        }

        while(query.next())
        {
            const QSqlRecord record = query.record();
            for(int i=0, recCount = record.count(); i < recCount; ++i)
            {
                if(!exportList.contains(record.value(i).toString()))
                {
                    exportList.append(record.value(i).toString());
                }
            }
        }
        qDebug() << "La liste d'export est : " << exportList.size();

        for(int i = 0;i < exportList.size();i++)
        {
            QString csvName;
            if(exportList[i].isEmpty())
            {
                csvName = strExport + "-empty.csv";
            }
            else {
                csvName = strExport + "-" + exportList[i] +".csv";
            }

            QFile csvCompany(csvName);
            QString queryRequest = "SELECT * FROM contacts WHERE "+ strExport + "='" + exportList[i] + "'";
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
                for(int j=0, recCount = record.count(); j<recCount; ++j)
                {
                    if(j>0) { outStream << ','; }
                    outStream << escapedCSV(record.value(j).toString());
                }
                outStream << '\n';
            }
            csvCompany.close();
        }
        qDebug() << "Sortie de boucle for";
        return true;
    });
}

QString Contacts::escapedCSV(QString unexc)
{
    if (!unexc.contains(QLatin1Char(',')))
        return unexc;
    return '\"' + unexc.replace(QLatin1Char('\"'), QStringLiteral("\"\"")) + '\"';
}

QString Contacts::globalStats()
{
    QString stats;

    QSqlQuery query;

    query.prepare("SELECT COUNT(*) FROM contacts");
    if (!query.exec()){
        qDebug("failed to run query");
    }

    query.first();
    stats = query.value(0).toString();

    return stats;
}

QString Contacts::stats(QString s_stats)
{
    QString stats;
    QSqlQuery query;

    QString s_query = "SELECT COUNT(DISTINCT " + s_stats + ") FROM contacts";

    query.prepare(s_query);

    if (!query.exec()) {
            qDebug("failed to run query");
    }

    query.first();
    stats = query.value(0).toString();
    return stats;

}
