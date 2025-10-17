// Copyright Notices: [...]

#pragma once

#include <QObject>
#include <QtQml/qqml.h>

namespace UserInterface
{
    /**
     * Object to manage the list of existing of data
     */
    class USERINTERFACE_API TemplateObject : public QObject
    {
        Q_OBJECT
        QML_ELEMENT
        
        /** The name of the current object */
        Q_PROPERTY(QString Name READ GetName WRITE SetName NOTIFY signal_NameChanged)
        QString m_Name {};

    public:
        /** Contructor */
        explicit TemplateObject(QObject* const InParent = nullptr);

        /** Destructor */
        ~TemplateObject() = default;

        /** Set the name of the object */
        void SetName(const QString& InValue);

        /** Get the name of the object */
        const QString& GetName() const;

    signals:
        /** Signal to notify whenever the name changes */
        void signal_NameChanged();
    };
}; // namespace UserInterface