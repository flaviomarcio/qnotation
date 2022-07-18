#pragma once

#include <QObject>
#include "./qannotation_global.h"
#include "./qannotation_extended.h"

namespace QAnnotation {

//!
//! \brief The ObjectNotation class
//!
template <class T=QObject>
class Object : public T, public Extended
{
public:

    //!
    //! \brief ObjectNotation
    //! \param parent
    //!
    Q_INVOKABLE explicit Object(QObject *parent = nullptr)
        :
          T{parent}, Extended{this}
    {
    }
};

}
