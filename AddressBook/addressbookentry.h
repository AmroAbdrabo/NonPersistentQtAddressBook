#ifndef ADDRESSBOOKENTRY_H
#define ADDRESSBOOKENTRY_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QStringList>

class AddressBookEntry : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged) not sure if necessary for Qt 5+
    //Q_PROPERTY(QString address READ getAddress WRITE setAddress NOTIFY addressChanged)
    //Q_PROPERTY(QDate birthday READ getBirthday WRITE setBirthday NOTIFY birthdayChanged)
    //Q_PROPERTY(QStringList phoneNumbers READ getPhoneNumbers WRITE setPhoneNumbers NOTIFY phoneNumbersChanged)
public:
    explicit AddressBookEntry(QObject *parent = nullptr);

    QString getName() const;
    void setName(const QString &value);

    QString getAddress() const;
    void setAddress(const QString &value);

    QDate getBirthday() const;
    void setBirthday(const QDate &value);

    QStringList getPhoneNumbers() const;
    void setPhoneNumbers(const QStringList &value);

signals:

    void  nameChanged(); // don't provide implementations for signals since they override event raising mechanisms
    void addressChanged();
    void birthdayChanged();
    void phoneNumbersChanged();

public slots:

private:
    QString name;
    QString address;
    QDate birthday;
    QStringList phoneNumbers;

};

#endif // ADDRESSBOOKENTRY_H
