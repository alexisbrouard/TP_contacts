#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    Contacts db_contacts;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
