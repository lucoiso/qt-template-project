// Copyright Notices: [...]

#ifndef USER_INTERFACE_MODULE_HPP
#define USER_INTERFACE_MODULE_HPP

#include <QtCore/QtGlobal>

#ifdef BUILD_DLL
    #define USER_INTERFACE_API Q_DECL_EXPORT
#else
    #define USER_INTERFACE_API Q_DECL_IMPORT
#endif

#endif // defined(USER_INTERFACE_MODULE_HPP)