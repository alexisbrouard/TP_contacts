#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "contacts.h"

class TDD_contacts : public QObject
{
    Q_OBJECT
    Contacts obj;
public:
    TDD_contacts();
    ~TDD_contacts();

private slots:
    void initTestCase();
    void test_delete();
    void test_addRow();

};

TDD_contacts::TDD_contacts()
{

}

TDD_contacts::~TDD_contacts()
{

}

void TDD_contacts::initTestCase()
{

}

void TDD_contacts::test_delete()
{
    QStringList dataList = {"yolo", "yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","Facebook"};
    obj.addRow(dataList);
    QString company = "Facebook";
    QCOMPARE(obj.Delete_Company(company), true);
}

void TDD_contacts::test_addRow()
{
    QStringList dataList = {"yolo", "yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo","yolo"};
    QCOMPARE(obj.addRow(dataList), true);
}

QTEST_MAIN(TDD_contacts)

#include "tst_tdd_contacts.moc"
