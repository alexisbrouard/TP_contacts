#include <QtTest>
#include <QCoreApplication>

#include "contacts.h"

class TDD_contacts : public QObject
{
    Q_OBJECT
    Contacts obj;
public:
    TDD_contacts();
    ~TDD_contacts();

private slots:
    void test_delete();
    void test_addRow();
    void test_createDB();
    void test_updateRow();
};

TDD_contacts::TDD_contacts() {}

TDD_contacts::~TDD_contacts() {}

void TDD_contacts::test_updateRow()
{
    QStringList dataList = {"yolo", "yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","Facebook"};
    obj.addRow(dataList);
    QString company = "Facebook";
    QString companyUp = "BoringCompany";
    QCOMPARE(obj.updateRow(company, companyUp), true);
}

void TDD_contacts::test_createDB()
{
    QCOMPARE(obj.setupDB(), true);
}

void TDD_contacts::test_delete()
{
    QStringList dataList = {"yolo", "yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","Facebook"};
    obj.addRow(dataList);
    QString company = "Facebook";
    QCOMPARE(obj.deleteCompany(company), true);
}

void TDD_contacts::test_addRow()
{
    QStringList dataList = {"yolo", "yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","Facebook"};
    QCOMPARE(obj.addRow(dataList), true);
}

QTEST_MAIN(TDD_contacts)

#include "tst_tdd_contacts.moc"
