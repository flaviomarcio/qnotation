#include "./qnotation_util.h"

namespace QNotation {

#define dPvt()\
auto&p = *reinterpret_cast<UtilPvt*>(this->p)


class UtilPvt{
public:
    bool inited=false;
    Util*util=nullptr;
    QObject*parent=nullptr;
    QHash<Util::Type, NotationCollection> notations;
    QHash<QByteArray, NotationCollection> notationsMethods;

    //!
    //! \brief UtilPvt
    //! \param parent
    //!
    explicit UtilPvt(Util*util, QObject*parent)
    {
        this->util=util;
        this->parent=parent;
    }

    virtual ~UtilPvt()
    {
    }

    //!
    //! \brief notationMaker
    //! \param notations
    //! \return
    //!
    NotationCollection notationMaker(const QVariant &notations)const
    {
        NotationCollection __return;
        QVariantList vList;

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
        int typeId=notations.typeId();
#else
        int typeId=notations.type();
#endif
        switch (typeId) {
        case QMetaType::QVariantList:
        case QMetaType::QStringList:
        case QMetaType::QVariantHash:
        case QMetaType::QVariantMap:
            vList=notations.toList();
            break;
        default:
            vList<<notations;
        }

        if(vList.isEmpty())
            return __return;

        for(auto&v:vList){
            Notation notation(v);

            if(!notation.isValid())
                continue;

            __return.insert(notation.name(), notation);
        }
        return __return;
    }

    //!
    //! \brief init
    //! \return
    //!
    auto&init()
    {
        if(this->inited)
            return*this;

        if(this->parent==nullptr)//check Object to extract notations
            return*this;

        this->inited=true;

        auto makeObject=this->parent;
        auto metaObject=makeObject->metaObject();
        auto notationRefereceClass=QByteArray(metaObject->className()).split(':').last().toLower();

        static const auto ___notation_declaration=QByteArrayLiteral("___notation_declare_x_not_x_");//start name of QNotation methods

        //class name

        NotationCollection vNotationsClass;
        NotationCollection vNotationsMethod;

        for (auto i = 0; i < metaObject->methodCount(); ++i) {
            auto method = metaObject->method(i);

            switch (method.methodType()) {
            case QMetaMethod::Method:
                break;
            default:
                continue;
            }

            if(method.parameterCount()>0)//ignore method with parameters
                continue;

            const QString methodName = method.name().toLower();
            if(!methodName.startsWith(___notation_declaration))//check method forma declaration for QNotation
                continue;

            const auto notationRefereceMethod=methodName.split("_x_not_x_").last().toUtf8();//extract method name at QNotation declaration

            NotationCollection vNotationsMethodExclusive;//exclusive list for methods

            QVariant returnVariant;//variable to invoke response
            auto argReturn=Q_RETURN_ARG(QVariant, returnVariant);

            //invoke QNotation method
            if(method.invoke(makeObject, Qt::DirectConnection, argReturn)){

                if(!returnVariant.isValid())
                    continue;

                auto notationList=notationMaker(returnVariant);

                if(notationList.isEmpty())//skip to empty values
                    continue;

                if(notationRefereceMethod==notationRefereceClass){//check notation is the scope class
                    for(auto&notation:notationList)
                        vNotationsClass.insert(notation.name(), notation);
                    continue;
                }

                {//notations at scope methods
                    for(auto&notation:notationList){
                        vNotationsMethod.insert(notation.name(), notation);
                        vNotationsMethodExclusive.insert(notation.name(), notation);
                    }
                    this->notationsMethods.insert(notationRefereceMethod, vNotationsMethodExclusive);
                }
            }
        }
        //persist notation class and methods
        this->notations={{Util::Class, vNotationsClass}, {Util::Method, vNotationsMethod}};
        return*this;
    }
};


Util::Util(QObject *parent)
{
    this->p=new UtilPvt(this, parent);
}

Util::~Util()
{
    dPvt();
    delete&p;
}

Util &Util::from(QObject *object)
{
    dPvt();
    p.parent=object;
    p.init();
    return*this;
}

bool Util::contains(const QByteArray &methodName, const QVariant &vNotation)const
{
    dPvt();
    NotationCollection &notations=p.init().notationsMethods[methodName.toLower()];
    const auto&notation=notations.find(vNotation);
    return notation.isValid();
}

QHash<Util::Type, NotationCollection> &Util::notations()const
{
    dPvt();
    return p.init().notations;
}

const NotationCollection &Util::notation()const
{
    dPvt();

    return p.init().notations[Util::Class];
}

const NotationCollection &Util::notation(const QMetaMethod &method) const
{
    dPvt();
    return p.init().notationsMethods[method.name()];
}

const NotationCollection &Util::notation(const QByteArray &methodName) const
{
    dPvt();
    return p.init().notationsMethods[methodName];
}

const NotationCollection &Util::notationMethods() const
{
    dPvt();
    return p.init().notations[Util::Method];
}

}
