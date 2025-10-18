// Copyright Notices: [...]

#include "UserInterface/Components/TemplateObject.hpp"
#include "TemplateLibrary/TemplateLibrary.hpp"

using namespace UserInterface;

TemplateObject::TemplateObject(QObject* const InParent)
    : QObject(InParent)
{
    SetName(QString::fromStdString(TemplateLibrary::GetString()));
}

void TemplateObject::SetName(const QString& InValue)
{
    if (InValue != m_Name)
    {
        m_Name = InValue;
        emit signal_NameChanged();
    }
}

const QString& TemplateObject::GetName() const
{
    return m_Name;
}