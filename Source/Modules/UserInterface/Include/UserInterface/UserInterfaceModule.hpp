// Copyright Notices: [...]

#ifndef USERINTERFACE_MODULE_HPP
#define USERINTERFACE_MODULE_HPP

#include <QtCore/QtGlobal>

#ifdef USERINTERFACE_BUILD_DLL
    #define USERINTERFACE_API Q_DECL_EXPORT
#else
    #define USERINTERFACE_API Q_DECL_IMPORT
#endif

#endif // defined(USERINTERFACE_MODULE_HPP)