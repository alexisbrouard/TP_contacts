#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_export_button_clicked()
{
    //birthday
    if (!ui->l_birthday->text().isEmpty()){db_contacts.sqlToCSV(ui->l_birthday->text());};
    //category
    if (!ui->l_category->text().isEmpty()){db_contacts.sqlToCSV(ui->l_category->text());};
    //city
    if (!ui->l_city->text().isEmpty()){db_contacts.sqlToCSV(ui->l_city->text());};
    //firstname
    if (!ui->l_firstname->text().isEmpty()){db_contacts.sqlToCSV(ui->l_firstname->text());};
    //lastname
    if (!ui->l_lastname->text().isEmpty()){db_contacts.sqlToCSV(ui->l_lastname->text());};
    //email
    if (!ui->l_email->text().isEmpty()){db_contacts.sqlToCSV(ui->l_email->text());};
    //list
    if (!ui->l_list->text().isEmpty()){db_contacts.sqlToCSV(ui->l_list->text());};
    //telephone
    if (!ui->l_phone->text().isEmpty()){db_contacts.sqlToCSV(ui->l_phone->text());};
    //country
    if (!ui->l_country->text().isEmpty()){db_contacts.sqlToCSV(ui->l_country->text());};
    //company
    if (!ui->l_company->text().isEmpty()){db_contacts.sqlToCSV(ui->l_company->text());};
}

