#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialogButtonBox>
#include <QtWidgets>

MainWindow::MainWindow(AddressBookController *controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      controller(controller)
{
    Q_ASSERT(controller != nullptr);
    ui->setupUi(this);
    setupConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createEntry()
{
    AddressBookEntry* entry = controller->createEntry();
    if (entry)
    {
        ui->listWidget->addItem(entry->getName());
        auto listItem = ui->listWidget->item(ui->listWidget->count()-1);
        entryMap.insert(listItem, entry);
    }
}

void MainWindow::deleteEntry()
{
    QListWidgetItem* listItem = ui->listWidget->currentItem();
    if (listItem)
    {
        auto entry = entryMap.value(listItem);
        if (entry)
        {
            if (controller->deleteEntry(entry))
            {
                entryMap.remove(listItem);
                delete listItem;
            }
        }
    }
}

void MainWindow::editEntry()
{
    auto listItem = ui->listWidget->currentItem();
    if (listItem)
    {
        auto entry = entryMap.value(listItem);
        if (entry)
        {
            ui->stackedWidget->setCurrentWidget(ui->detailPage);
            ui->menuEntries->setEnabled(false);
            //ui->nameEdit->setText(entry->getName());
            //ui->birthdayEdit->setDate(entry->getBirthday());
            //ui->addressEdit->setPlainText(entry->getAddress());
            //ui->phoneNumbersEdit->setPlainText(entry->getPhoneNumbers().join("\n"));
            resetEntry();
        }
    }

}

void MainWindow::discardEntry()
{
    ui->stackedWidget->setCurrentWidget(ui->listPage);
    ui->menuEntries->setEnabled(true);
}

void MainWindow::saveEntry()
{
    auto listItem = ui->listWidget->currentItem();
    if (listItem)
    {
        auto entry = entryMap.value(listItem);
        if (entry)
        {
            entry->setName(ui->nameEdit->text());
            entry->setBirthday(ui->birthdayEdit->date());
            entry->setAddress(ui->addressEdit->toPlainText());
            entry->setPhoneNumbers(ui->phoneNumbersEdit->toPlainText().split("\n"));
            listItem->setText(entry->getName());
            discardEntry(); // switch to the list page and re-enable dropdown menu entries

        }
    }
}

void MainWindow::resetEntry()
{
    auto listItem = ui->listWidget->currentItem();
    if (listItem)
    {
        auto entry = entryMap.value(listItem);
        if (entry)
        {
            ui->stackedWidget->setCurrentWidget(ui->detailPage);
            ui->menuEntries->setEnabled(false);
            ui->nameEdit->setText(entry->getName());
            ui->birthdayEdit->setDate(entry->getBirthday());
            ui->addressEdit->setPlainText(entry->getAddress());
            ui->phoneNumbersEdit->setPlainText(entry->getPhoneNumbers().join("\n"));
        }
    }
}

void MainWindow::setupConnection()
{
    // Syntax for connect: SENDER, SENT SIGNAL, RECEIVER, RECEIVE_ACTION
    connect(ui->actionAdd, SIGNAL(triggered(bool)), this, SLOT(createEntry()));
    connect(ui->actionRemove, SIGNAL(triggered()), this, SLOT(deleteEntry())); // can also do &QAction::triggered instead of SIGNAL(triggered) and &MainWindow::deleteEntry
    connect(ui->actionEdit, SIGNAL(triggered()), this, SLOT(editEntry()));

    // for the dialog buttons
    connect(ui->buttonBox->button(QDialogButtonBox::Save), SIGNAL(clicked()), this, SLOT(saveEntry()));
    connect(ui->buttonBox->button(QDialogButtonBox::Discard), SIGNAL(clicked()), this, SLOT(discardEntry()));
    connect(ui->buttonBox->button(QDialogButtonBox::Reset), SIGNAL(clicked()), this, SLOT(resetEntry()));

}

