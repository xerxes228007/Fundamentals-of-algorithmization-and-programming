#ifndef DISK_H
#define DISK_H

#include <QString>

class Disk {
public:
    Disk(const QString &type, const QString &title, const QString &author, double price, const QString &note);
    QString getType() const;
    QString getTitle() const;
    QString getAuthor() const;
    double getPrice() const;
    QString getNote() const;

private:
    QString type;
    QString title;
    QString author;
    double price;
    QString note;
};

#endif // DISK_H
