#include "diskmanager.h"
#include <algorithm>
#include <QMap>
#include <QMultiMap>

void DiskManager::sortByTitleWithinType() {
    QMultiMap<QString, Disk> sorted;
    for (const auto &disk : qAsConst(disks)) {
        sorted.insertMulti(disk.getType(), disk);
    }

    disks.clear();
    for (const auto &type : sorted.uniqueKeys()) {
        auto range = sorted.equal_range(type);
        std::vector<Disk> temp;
        for (auto it = range.first; it != range.second; ++it) {
            temp.push_back(it.value());
        }
        std::sort(temp.begin(), temp.end(), [](const Disk &a, const Disk &b) {
            return a.getTitle() < b.getTitle();
        });
        for (const auto &disk : temp) {
            disks.append(disk);
        }
    }
}

void DiskManager::sortByAuthorWithinType() {
    QMultiMap<QString, Disk> sorted;
    for (const auto &disk : qAsConst(disks)) {
        sorted.insertMulti(disk.getType(), disk);
    }

    disks.clear();
    for (const auto &type : sorted.uniqueKeys()) {
        auto range = sorted.equal_range(type);
        std::vector<Disk> temp;
        for (auto it = range.first; it != range.second; ++it) {
            temp.push_back(it.value());
        }
        std::sort(temp.begin(), temp.end(), [](const Disk &a, const Disk &b) {
            return a.getAuthor() < b.getAuthor();
        });
        for (const auto &disk : temp) {
            disks.append(disk);
        }
    }
}

QVector<Disk> DiskManager::getDisksByType(const QString &type) const {
    QVector<Disk> result;
    std::copy_if(disks.begin(), disks.end(), std::back_inserter(result), [&type](const Disk &disk) {
        return disk.getType() == type;
    });
    return result;
}

QVector<Disk> DiskManager::getDisksByTypeAndAuthor(const QString &type, const QString &author) const {
    QVector<Disk> result;
    std::copy_if(disks.begin(), disks.end(), std::back_inserter(result), [&type, &author](const Disk &disk) {
        return disk.getType() == type && disk.getAuthor() == author;
    });
    return result;
}
