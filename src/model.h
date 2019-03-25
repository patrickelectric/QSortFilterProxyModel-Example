#pragma once

#include <QAbstractListModel>
#include <QObject>

class Something : public QObject
{
    Q_OBJECT
public:
    Something(int number = 0, QObject* parent = nullptr)
    : QObject(parent)
    , _number(number) {};

    Something(const Something& something)
    : QObject(something.parent())
    , _number(something.foo()) {};

    ~Something() = default;

    Q_INVOKABLE int foo() const;

    Something& operator=(const Something& other) {
        _number = other.foo();
        return *this;
    }

private:
    int _number;
};

Q_DECLARE_METATYPE(Something)

class Model : public QAbstractListModel
{
    Q_OBJECT
public:
    Model(QObject* parent = nullptr);

    enum Roles {
        SomethingRole,
    };

    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE int rowCount(const QModelIndex& parent = QModelIndex()) const override
    {
        Q_UNUSED(parent);
        return _size;
    };

    void append(Something something);

signals:
    void countChanged();

private:
    Q_DISABLE_COPY(Model)
    Q_PROPERTY(int count READ rowCount NOTIFY countChanged)

    int _categories = 0;
    QVector<int> _roles;
    QHash<int, QByteArray> _roleNames{
        {{Model::SomethingRole}, {"something"}},
    };
    int _size = 0;
    QHash<int, QVector<QVariant>> _vectors;
};

Q_DECLARE_METATYPE(Model*)
