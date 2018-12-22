#pragma once

#include <QAbstractListModel>

class Model : public QAbstractListModel
{
    Q_OBJECT
public:
    Model(QObject* parent = nullptr);

    enum Roles {
        Display,
    };

    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE int rowCount(const QModelIndex& parent = QModelIndex()) const override
    {
        Q_UNUSED(parent);
        return _size;
    };

    void append(const QString& text);

signals:
    void countChanged();

private:
    Q_DISABLE_COPY(Model)
    Q_PROPERTY(int count READ rowCount NOTIFY countChanged)

    int _categories = 0;
    QVector<int> _roles;
    QHash<int, QByteArray> _roleNames{
        {{Model::Display}, {"display"}},
    };
    int _size = 0;
    QHash<int, QVector<QVariant>> _vectors;
};

Q_DECLARE_METATYPE(Model*)
