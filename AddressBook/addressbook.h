#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "addressbookentry.h"

#include <QObject>
#include <QList> // provides linked list implementation
typedef QList<AddressBookEntry*> Entries;
class AddressBook : public QObject
{
    Q_OBJECT
public:


    explicit AddressBook(QObject *parent = nullptr);

    Entries getEntries() const;

    AddressBookEntry* createEntry();
    bool deleteEntry(AddressBookEntry *entry);

signals:

    void entryAdded(AddressBookEntry *entry);
    void entryRemoved(AddressBookEntry *entry);

public slots:

private:
    Entries entries;
};

#endif // ADDRESSBOOK_H
