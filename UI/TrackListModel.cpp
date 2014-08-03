/*
 * Copyright (c) 2014, Mikkel Kroman <mk@maero.dk>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "TrackListModel.h"

TrackListModel::TrackListModel(QObject* parent) :
    QAbstractItemModel(parent)
{
}

QModelIndex TrackListModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    if (row < 0 || row > tracks_.count() || column < 0 || column > 4)
        return QModelIndex();

    return createIndex(row, column);
}

QModelIndex TrackListModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);

    return QModelIndex();
}

int TrackListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return tracks_.count();
}

int TrackListModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return 3;
}

QVariant TrackListModel::data(const QModelIndex &index, int role) const
{
    int wantedData = index.column();

    switch (role) {
    case Qt::DisplayRole:
        switch (wantedData) {
        case 0:
            return tracks_[index.row()].title();
        case 1:
            return tracks_[index.row()].user().name();
        case 2:
            return QString::number(tracks_[index.row()].duration() * 1000);
        }
    }

    return QVariant();
}

QVariant TrackListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical)
        return QVariant();

    switch (role)
    {
    case Qt::DisplayRole:
        switch (section) {
        case 0:
            return QString("Title");
        case 1:
            return QString("Author");
        case 2:
            return QString("Duration");
        default:
            return QString::number(section);
        }
    }

    return QVariant();
}

void TrackListModel::onTrackSearchResults(Soundcloud::TrackList trackList)
{
    beginInsertRows(QModelIndex(), 0, trackList.count() - 1);

    tracks_ = trackList;

    endInsertRows();
}
