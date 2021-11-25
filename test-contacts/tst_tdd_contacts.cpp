#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class TDD_contacts : public QObject
{
    Q_OBJECT

public:
    TDD_contacts();
    ~TDD_contacts();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

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

void TDD_contacts::cleanupTestCase()
{

}

void TDD_contacts::test_case1()
{

}

QTEST_MAIN(TDD_contacts)

#include "tst_tdd_contacts.moc"
