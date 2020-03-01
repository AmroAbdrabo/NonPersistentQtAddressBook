#include "addressbook.h"

AddressBook::AddressBook(QObject *parent) : QObject(parent)
{

}

Entries AddressBook::getEntries() const
{
    return entries;
}

AddressBookEntry *AddressBook::createEntry()
{
    AddressBookEntry* result = new AddressBookEntry(this);
    // this, of type AddressBook, is the parent of the new address book entry to be created
    // children are garbage collected whenever their parent are garbage collected
    if (result != nullptr)
    {
        entries.append(result);
        emit entryAdded(result);
    }
    return result;
}

bool AddressBook::deleteEntry(AddressBookEntry *entry)
{
    if(entries.contains(entry))
    {
        entries.removeOne(entry);
        delete entry;
        emit entryRemoved(entry);
        return true;
    }
    return false;
}

