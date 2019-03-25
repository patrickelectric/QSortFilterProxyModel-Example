#include "model.h"

#include <QDebug>
#include <QTimer>

Q_INVOKABLE int Something::foo() const
{
    qDebug() << "Foo!";
    return _number;
}

Model::Model(QObject* parent)
    : QAbstractListModel(parent)
{
    for(const auto& key : _roleNames.keys()) {
        _roles.append(key);
        _vectors.insert(key, {});
    }

    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]{
        static int i = 0;
        append(i);
        i++;
    });
    timer->start(100);
}

QVariant Model::data(const QModelIndex& index, int role) const
{
    const int indexRow = index.row();
    QVector<QVariant> vectorRole = _vectors[role];
    if(indexRow < 0 || vectorRole.size() <= indexRow) {
        return {"No valid data"};
    }
    return _vectors[role][indexRow];
}

void Model::append(Something something)
{
    const int line = rowCount();
    beginInsertRows(QModelIndex(), line, line);
    _vectors[Model::SomethingRole].append(QVariant::fromValue(something));
    _size++;
    const auto& indexRow = index(line);
    endInsertRows();
    emit dataChanged(indexRow, indexRow, _roles);
    emit countChanged();
}

QHash<int, QByteArray> Model::roleNames() const
{
    return _roleNames;
}
