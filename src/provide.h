#include "model.h"

#include <QSortFilterProxyModel>

class Provide : public QObject {
    Q_OBJECT
public:
    Provide() = default;
    ~Provide() = default;

    Q_PROPERTY(Model* model READ model CONSTANT)
    Model* model() { return &_model; };

private:
    Model _model;
};
