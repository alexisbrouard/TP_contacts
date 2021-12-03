#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFuture>
#include <QtConcurrent>
#include <QObject>
#include "contacts.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_export_button_clicked();

    void on_del_button_clicked();

    void on_mod_button_clicked();

    void on_but_globalstats_clicked();

    void on_but_firstname_clicked();

    void on_but_lastname_clicked();

    void on_but_email_clicked();

    void on_but_phone_clicked();

    void on_but_category_clicked();

    void on_but_city_clicked();

    void on_but_birthday_clicked();

    void on_but_country_clicked();

    void on_but_list_clicked();

    void on_but_company_clicked();


private:
    Contacts db_contacts;
    QString s_working;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
