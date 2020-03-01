#include "addressbookcontroller.h"

AddressBookController::AddressBookController(AddressBook *addressBook, QObject *parent) : QObject(parent),
    addressBook(addressBook)
{
    Q_ASSERT(addressBook != nullptr);
}

AddressBookEntry *AddressBookController::createEntry()
{
    AddressBookEntry* result = addressBook->createEntry();
    if (result != nullptr)
    {
        result->setName("New"); // tr("New entry...") said granny boy
    }
    return result;
}

bool AddressBookController::deleteEntry(AddressBookEntry *entry)
{
    return addressBook->deleteEntry(entry);
}
