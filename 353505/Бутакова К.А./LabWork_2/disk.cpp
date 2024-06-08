#include "disk.h"

Disk::Disk(const QString &type, const QString &title, const QString &author, double price, const QString &note)
    : type(type), title(title), author(author), price(price), note(note) {}

QString Disk::getType() const { return type; }
QString Disk::getTitle() const { return title; }
QString Disk::getAuthor() const { return author; }
double Disk::getPrice() const { return price; }
QString Disk::getNote() const { return note; }
