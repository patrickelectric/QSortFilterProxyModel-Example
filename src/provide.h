#include "model.h"

#include <QSortFilterProxyModel>

class Provide : public QObject {
    Q_OBJECT
public:
    Provide() {
        _filter.setSourceModel(&_model);
        _filter.setFilterRole(Model::Roles::Display);
        _filter.setFilterWildcard("*0");
    };
    ~Provide() = default;

    Q_PROPERTY(Model* model READ model CONSTANT)
    Model* model() { return &_model; };

    Q_PROPERTY(QSortFilterProxyModel* filteredModel READ filteredModel CONSTANT)
    QSortFilterProxyModel* filteredModel() { return &_filter; };

private:
    Model _model;
    QSortFilterProxyModel _filter;
};

Q_DECLARE_METATYPE(QSortFilterProxyModel*)
