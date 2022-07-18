#include "./qannotation_extended.h"
#include "./qannotation_util.h"

namespace QAnnotation {

class NotationExtendedPvt
{
public:
    QObject *parent = nullptr;
    Util notationUtil;
    bool notationUtilLoaded = false;

    //!
    //! \brief NotationExtendedPvt
    //! \param parent
    //!
    explicit NotationExtendedPvt(QObject *parent) : notationUtil{parent}
    {
        if (parent == nullptr)
            qFatal("invalid notation parent");
        this->parent = parent;
    }

    virtual ~NotationExtendedPvt() {}
};

Extended::Extended(QObject *parent)
{
    this->p = new NotationExtendedPvt(parent);
}

Extended::~Extended()
{
    delete p;
}

Util &Extended::notationUtil()
{
    return p->notationUtil;
}

QObject *Extended::parent()
{

    return p->parent;
}

Collection &Extended::notation() const
{

    return p->notationUtil.notation();
}

Collection &Extended::notation(const QMetaMethod &method) const
{

    return p->notationUtil.notation(method);
}

Collection &Extended::notation(const QByteArray &methodName) const
{

    return p->notationUtil.notation(methodName);
}

Collection &Extended::notationMethods() const
{

    return p->notationUtil.notationMethods();
}

} // namespace QAnnotation
