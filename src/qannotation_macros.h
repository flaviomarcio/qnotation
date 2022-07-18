#pragma once

#include <QVariantHash>

#define nl QVariantList

#define Q_ANNOTATION_UTIL auto &nUtil = this->notationUtil()

#define Q_ANNOTATION(notationReference, notations) \
public: \
    Q_INVOKABLE QVariant ___notation_declare_x_not_x_##notationReference() const \
    { \
        static auto __return = QVariant(QVariantList(notations)); \
        return __return; \
    }

#define Q_ANNOTATION_COMPOSE(NAME, CLASSIFICATION, VALUE, STATIC) \
    QVariantHash \
    { \
        {QStringLiteral("n"), QStringLiteral(#NAME)}, {QStringLiteral("c"), CLASSIFICATION}, \
            {QStringLiteral("v"), VALUE}, \
        { \
            QStringLiteral("s"), STATIC \
        } \
    }

#define Q_ANNOTATION_DECLARE_VALUE(NAME, CLASSIFICATION, VALUE) \
    const QVariantHash NAME = Q_ANNOTATION_COMPOSE(NAME, CLASSIFICATION, VALUE, true);

#define Q_ANNOTATION_DECLARE(NAME, CLASSIFICATION) \
    Q_ANNOTATION_DECLARE_VALUE(NAME, CLASSIFICATION, true);

#define Q_ANNOTATION_DECLARE_FUNC(NAME, CLASSIFICATION) \
    static const QVariant NAME(const QVariant &value = {}) \
    { \
        return Q_ANNOTATION_COMPOSE(NAME, CLASSIFICATION, value, false); \
    }
