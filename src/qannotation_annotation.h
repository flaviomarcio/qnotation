#pragma once

#include <QObject>
#include <QVariantHash>
#include "./qannotation_global.h"

namespace QAnnotation {

//!
//! \brief The Notation struct
//!
struct Q_ANNOTATION_EXPORT Annotation
{
public:
    //!
    //! \brief Notation
    //!
    explicit Annotation();

    //!
    //! \brief Notation
    //! \param value
    //!
    explicit Annotation(const Annotation &value);

    //!
    //! \brief Notation
    //! \param value
    //!
    explicit Annotation(const QVariant &value);

    //!
    //! \brief isStatic
    //! \return
    //!
    bool isStatic()const;

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
    //! \brief toValueString
    //! \return
    //!
    QString toValueString()const;

    //!
    //! \brief toValueByteArray
    //! \return
    //!
    QByteArray toValueByteArray()const;

    //!
    //! \brief toValueStringVector
    //! \return
    //!
    QVector<QByteArray> toValueStringVector()const;

    //!
    //! \brief toValueList
    //! \return
    //!
    QVariantList toValueList()const;

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
    const Annotation &operator=(const Annotation &notation);

    //!
    //! \brief operator =
    //! \param value
    //! \return
    //!
    const Annotation &operator=(const QVariant &value);

    //!
    //! \brief operator ==
    //! \param value
    //! \return
    //!
    bool operator==(const Annotation &value)const;

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
    const Annotation &from(const Annotation &value);

    //!
    //! \brief from
    //! \param value
    //! \return
    //!
    const Annotation &from(const QVariant &value);

    //!
    //! \brief equal
    //! \param notation
    //! \return
    //!
    bool equal(const Annotation&notation)const;

    //!
    //! \brief equal
    //! \param value
    //! \return
    //!
    bool equal(const QVariant &value)const;

    //!
    //! \brief isValid
    //! \return
    //!
    bool isValid()const;

    //!
    //! \brief clear
    //! \return
    //!
    const Annotation &clear();
private:
    QByteArray _name;
    QVariant _value;
    int _classification=0;
    bool _isStatic=false;
};

}
