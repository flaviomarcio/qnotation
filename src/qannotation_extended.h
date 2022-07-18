#pragma once

#include "./qannotation_collection.h"
#include "./qannotation_global.h"
#include "./qannotation_util.h"
#include <QHash>
#include <QMetaMethod>
#include <QObject>

namespace QAnnotation {
class NotationExtendedPvt;
//!
//! \brief The NotationExtended class
//!
//! Notation Util
class Q_ANNOTATION_EXPORT Extended
{
public:
    enum Classification { Information, Documentation, Audit, Security, Operation };

    //!
    //! \brief NotationExtended
    //! \param parent
    //!
    explicit Extended(QObject *parent = nullptr);
    virtual ~Extended();

    //!
    //! \brief util
    //! \return
    //!
    virtual QAnnotation::Util &notationUtil();

    //!
    //! \brief parent
    //! \return
    //!
    virtual QObject *parent();

    //!
    //! \brief notation
    //!
    virtual Collection &notation() const;

    //!
    //! \brief notation
    //! \param method
    //! \return
    //!
    virtual Collection &notation(const QMetaMethod &method) const;
    virtual Collection &notation(const QByteArray &methodName) const;

    //!
    //! \brief notationMethods
    //! \return
    //!
    virtual Collection &notationMethods() const;

private:
    NotationExtendedPvt *p = nullptr;
};

} // namespace QAnnotation
