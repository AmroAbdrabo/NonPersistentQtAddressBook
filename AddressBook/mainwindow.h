#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addressbookcontroller.h"
#include <QMainWindow>
#include <QHash>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(AddressBookController *controller, QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void createEntry();
    void deleteEntry();
    void editEntry();
    void discardEntry(); // dialog buttons
    void saveEntry();    // dialog buttons
    void resetEntry();   // dialog buttons

private:
    Ui::MainWindow *ui;
    AddressBookController *controller;
    QHash<QListWidgetItem*, AddressBookEntry*> entryMap;
    void setupConnection();
};
#endif // MAINWINDOW_H
