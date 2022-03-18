#pragma once

#include <QObject>
#include <QVariantHash>
#include "./qnotation_global.h"
#include "./qnotation_macros.h"

namespace QNotation {

//!
//! \brief The Notation struct
//!
struct Q_NOTATION_EXPORT Notation
{
public:
    //!
    //! \brief Notation
    //!
    explicit Notation();

    //!
    //! \brief Notation
    //! \param value
    //!
    explicit Notation(const Notation &value);

    //!
    //! \brief Notation
    //! \param value
    //!
    explicit Notation(const QVariant &value);

    //!
    //! \brief name
    //! \return
    //!
    QByteArray name()const;

    //!
    //! \brief classification
    //! \return
    //!
    int classification()const;

    //!
    //! \brief value
    //! \return
    //!
    QVariant value()const;

    //!
    //! \brief isStatic
    //! \return
    //!
    bool isStatic()const;

    //!
    //! \brief toVariant
    //! \return
    //!
    QVariant toVariant()const;

    //!
    //! \brief toHash
    //! \return
    //!
    QVariantHash toHash()const;

    //!
    //! \brief toMap
    //! \return
    //!
    QVariantMap toMap()const;

    //!
    //! \brief operator =
    //! \param notation
    //! \return
    //!
    const Notation &operator=(const Notation &notation);

    //!
    //! \brief operator =
    //! \param value
    //! \return
    //!
    const Notation &operator=(const QVariant &value);

    //!
    //! \brief operator ==
    //! \param value
    //! \return
    //!
    bool operator==(const Notation &value)const;

    //!
    //! \brief operator ==
    //! \param value
    //! \return
    //!
    bool operator==(const QVariant &value)const;

    //!
    //! \brief from
    //! \param value
    //! \return
    //!
    const Notation &from(const Notation &value);

    //!
    //! \brief from
    //! \param value
    //! \return
    //!
    const Notation &from(const QVariant &value);

    //!
    //! \brief equal
    //! \param notation
    //! \return
    //!
    bool equal(const Notation&notation)const;

    //!
    //! \brief equal
    //! \param value
    //! \return
    //!
    bool equal(const QVariant&value)const;

    //!
    //! \brief isValid
    //! \return
    //!
    bool isValid()const;

    //!
    //! \brief clear
    //! \return
    //!
    const Notation &clear();
private:
    QByteArray _name;
    QVariant _value;
    int _classification=0;
    bool _isStatic=false;
};

}
