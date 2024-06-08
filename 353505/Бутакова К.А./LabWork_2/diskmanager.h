#ifndef DISKMANAGER_H
#define DISKMANAGER_H

#include "disk.h"
#include <QVector>

class DiskManager {
public:
    void addDisk(const Disk &disk);
    void removeDisk(const QString &title);
    QVector<Disk> getDisksByAuthor(const QString &author) const;
    QVector<Disk> getDisksByTitle(const QString &title) const;
    void sortByTitle();
    void sortByAuthor();
    void sortByAuthorWithinType();
    QVector<Disk> getDisksByType(const QString &type) const;
    QVector<Disk> getDisksByTypeAndAuthor(const QString &type, const QString &author) const;

private:
    QVector<Disk> disks;
};

#endif // DISKMANAGER_H

