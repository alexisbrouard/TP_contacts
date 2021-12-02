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

    //firstname
    if(ui->r_firstname->isChecked()){db_contacts.sqlToCSV("firstname");
    }
    //lastname
    if(ui->r_lastname->isChecked()){db_contacts.sqlToCSV("lastname");}
    //email
    if(ui->r_email->isChecked()){db_contacts.sqlToCSV("email");}
    //tel
    if(ui->r_phone->isChecked()){db_contacts.sqlToCSV("tel");}
    //category
    if(ui->r_category->isChecked()){db_contacts.sqlToCSV("category");}
    //city
    if(ui->r_city->isChecked()){db_contacts.sqlToCSV("city");}
    //birthday
    if(ui->r_birthday->isChecked()){db_contacts.sqlToCSV("birth_day");}
    //country
    if(ui->r_country->isChecked()){db_contacts.sqlToCSV("country");}
    //list
    if(ui->r_list->isChecked()){db_contacts.sqlToCSV("list");}
    //company
    if(ui->r_company->isChecked()){db_contacts.sqlToCSV("company");}
}

void MainWindow::on_del_button_clicked()
{
    if (!ui->l_company->text().isEmpty()) {
        QString str = ui->l_company->text();
        db_contacts.Delete_Company(str);
    }
}
