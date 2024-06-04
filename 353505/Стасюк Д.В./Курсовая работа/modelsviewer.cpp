#include "modelsviewer.h"

modelsViewer::modelsViewer(QObject *parent)
    : QAbstractItemModel(parent)
{}

QVariant modelsViewer::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex modelsViewer::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex modelsViewer::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int modelsViewer::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int modelsViewer::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant modelsViewer::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
