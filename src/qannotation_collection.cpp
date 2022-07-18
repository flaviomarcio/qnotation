#include "./qannotation_collection.h"

namespace QAnnotation {

Collection::Collection()
    :
      QHash<QByteArray, Annotation>{}
{

}

Collection::Collection(const QHash<QByteArray, Annotation> &collection)
    :
      QHash<QByteArray, Annotation>{collection}
{

}

bool Collection::find(const QVariant &value, Annotation &notationOut) const
{
    const auto &notation = this->find(value);
    if (notation.isValid()) {
        notationOut = notation;
        return true;
    }

    notationOut.clear();
    return false;
}

const Annotation &Collection::find(const QVariant &value) const
{
    static Annotation defaultValue;

    Annotation notationIn(value);
    if (!notationIn.isValid())
        return defaultValue;

    QHashIterator<QByteArray, Annotation> i(*this);
    while (i.hasNext()) {
        i.next();
        auto &notation = i.value();
        if (notation.name() == notationIn.name())
            return notation;
    }
    return defaultValue;
}

bool Collection::contains(const QVariant &value) const
{
    const auto &vThis=*this;
    if(vThis.isEmpty())
        return {};

    QVariantList vList;

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    int typeId = value.typeId();
#else
    int typeId = value.type();
#endif
    switch (typeId) {
    case QMetaType::QVariantList:
    case QMetaType::QStringList:
        vList = value.toList();
        break;
    default:
        vList << value;
    }

    for(auto &v:vList){
        Annotation notationIn(v);
        if (!notationIn.isValid())
            return {};

        QHashIterator<QByteArray, Annotation> i(vThis);
        while (i.hasNext()) {
            i.next();
            auto &notation = i.value();
            if (notation.name() == notationIn.name())
                return true;
        }
    }
    return {};
}

bool Collection::containsClassification(int classification) const
{
    QHashIterator<QByteArray, Annotation> i(*this);
    while (i.hasNext()) {
        i.next();
        const auto &notation = i.value();
        if (notation.classification() == classification)
            return true;
    }
    return {};
}

} // namespace QAnnotation
