#pragma once

#include <QObject>
#include <QMetaMethod>
#include <QHash>
#include "./qannotation_global.h"
#include "./qannotation_annotation.h"

namespace QAnnotation {

//!
//! \brief NotationCollection
//!
class Q_ANNOTATION_EXPORT Collection:public QHash<QByteArray, Annotation>{
public:
    //!
    //! \brief NotationCollection
    //!
    explicit Collection();

    //!
    //! \brief NotationCollection
    //! \param collection
    //!
    explicit Collection(const QHash<QByteArray, Annotation> &collection);

    //!
    //! \brief find
    //! \param value
    //! \return
    //!
    bool find(const QVariant &value, Annotation &notationOut)const;

    //!
    //! \brief find
    //! \param value
    //! \return
    //!
    const Annotation &find(const QVariant &value)const;

    //!
    //! \brief contains
    //! \param value
    //! \return
    //!
    bool contains(const QVariant &value) const;

    //!
    //! \brief containsClassification
    //! \param classification
    //! \return
    //!
    bool containsClassification(int classification)const;

};

}
