#include "addressbookentry.h"

AddressBookEntry::AddressBookEntry(QObject *parent) : QObject(parent)
{

}

QString AddressBookEntry::getName() const
{
    return name;
}

void AddressBookEntry::setName(const QString &value)
{
    if (name != value)
    {
        name = value;
        emit nameChanged(); // nameChanged event is emitted
    }
}

QString AddressBookEntry::getAddress() const
{
    return address;
}

void AddressBookEntry::setAddress(const QString &value)
{
    if (address != value)
    {
        address = value;
        emit addressChanged();
    }
}

QDate AddressBookEntry::getBirthday() const
{
    return birthday;
}

void AddressBookEntry::setBirthday(const QDate &value)
{
    if (birthday != value)
    {
        birthday = value;
        emit birthdayChanged();
    }
}

QStringList AddressBookEntry::getPhoneNumbers() const
{
    return phoneNumbers;
}

void AddressBookEntry::setPhoneNumbers(const QStringList &value)
{
    if (phoneNumbers != value)
    {
        phoneNumbers = value;
        emit phoneNumbersChanged();
    }
}
