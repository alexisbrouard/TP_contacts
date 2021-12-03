#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList list = db_contacts.getData();
    QStringListModel* model = new QStringListModel(list);
    ui->listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_export_button_clicked()
{
    ui->l_error->setText("EN COURS");

    //firstname
    if(ui->r_firstname->isChecked()){db_contacts.sqlToCSV("firstname");}
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

    ui->l_error->setText("AUCUNE ACTION EN ATTENTE");
}

void MainWindow::on_del_button_clicked()
{
    QString field;
    if (!ui->l_firstname->text().isEmpty()) {
        QString str = ui->l_firstname->text();
        field = "firstname";
        db_contacts.deleteField(str,field);
    }
    if (!ui->l_lastname->text().isEmpty()) {
        QString str = ui->l_lastname->text();
        field = "lastname";
        db_contacts.deleteField(str,field);
    }
    if (!ui->l_email->text().isEmpty()) {
        QString str = ui->l_email->text();
        field = "email";
        db_contacts.deleteField(str,field);
    }
    if (!ui->l_category->text().isEmpty()) {
        QString str = ui->l_category->text();
        field = "category";
        db_contacts.deleteField(str,field);
    }
    if (!ui->l_country->text().isEmpty()) {
        QString str = ui->l_country->text();
        field = "country";
        db_contacts.deleteField(str,field);
    }
    if (!ui->l_company->text().isEmpty()) {
        QString str = ui->l_company->text();
        field = "company";
        db_contacts.deleteField(str,field);
    }
    if (!ui->l_birthday->text().isEmpty()) {
        QString str = ui->l_birthday->text();
        field = "birth_day";
        db_contacts.deleteField(str,field);
    }
    if (!ui->l_country->text().isEmpty()) {
        QString str = ui->l_country->text();
        field = "country";
        db_contacts.deleteField(str,field);
    }
    if (!ui->l_list->text().isEmpty()) {
        QString str = ui->l_list->text();
        field = "list";
        db_contacts.deleteField(str,field);
    }
    if (!ui->l_company->text().isEmpty()) {
        QString str = ui->l_company->text();
        field = "company";
        db_contacts.deleteField(str,field);
    }
}

void MainWindow::on_mod_button_clicked()
{
    // updates only the rows of the company because im lazy to do the full func
    QString field = "Company";
    if (!ui->l_company->text().isEmpty()) {
        QString str = ui->l_company->text();
        db_contacts.updateRow(field, str);
    }
}

void MainWindow::on_but_globalstats_clicked()
{
    QString stats;
    stats = db_contacts.globalStats();

    ui->l_stats->setText(stats);

}


void MainWindow::on_but_firstname_clicked()
{
    QString stats;
    stats = db_contacts.stats("firstname");

    ui->l_stats->setText(stats);
}


void MainWindow::on_but_lastname_clicked()
{
    QString stats;
    stats = db_contacts.stats("lastname");

    ui->l_stats->setText(stats);
}


void MainWindow::on_but_email_clicked()
{
    QString stats;
    stats = db_contacts.stats("email");

    ui->l_stats->setText(stats);
}


void MainWindow::on_but_phone_clicked()
{
    QString stats;
    stats = db_contacts.stats("tel");

    ui->l_stats->setText(stats);
}


void MainWindow::on_but_category_clicked()
{
    QString stats;
    stats = db_contacts.stats("category");

    ui->l_stats->setText(stats);
}


void MainWindow::on_but_city_clicked()
{
    QString stats;
    stats = db_contacts.stats("city");

    ui->l_stats->setText(stats);
}


void MainWindow::on_but_birthday_clicked()
{
    QString stats;
    stats = db_contacts.stats("birth_day");

    ui->l_stats->setText(stats);
}


void MainWindow::on_but_country_clicked()
{
    QString stats;
    stats = db_contacts.stats("country");

    ui->l_stats->setText(stats);
}


void MainWindow::on_but_list_clicked()
{
    QString stats;
    stats = db_contacts.stats("list");

    ui->l_stats->setText(stats);
}


void MainWindow::on_but_company_clicked()
{
    QString stats;
    stats = db_contacts.stats("company");

    ui->l_stats->setText(stats);
}

