#ifndef CPROPERTYNAMEVALIDATOR_H
#define CPROPERTYNAMEVALIDATOR_H

#include <QValidator>
#include <Core/Resource/Script/Property/Properties.h>

/** QValidator subclass that checks if a property name is valid */
class CPropertyNameValidator : public QValidator
{
    Q_OBJECT

    /** The property being validated against */
    IProperty* mpProperty;

    /** String to use to override the type name. If empty, the property's normal type name is used. */
    QString mTypeNameOverride;

public:
    CPropertyNameValidator(QObject* pParent = 0);

    /** Perform validation */
    QValidator::State validate(QString& rInput, int& rPos) const;

public slots:
    /** Set the property to validate against */
    void SetProperty(IProperty* pProp);

    /** Set the type name override */
    void SetTypeNameOverride(const QString& kNewTypeName);
};

#endif // CPROPERTYNAMEVALIDATOR_H
