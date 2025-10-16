// Copyright Notices: [...]

#ifndef APPLICATION_MODULE_HPP
#define APPLICATION_MODULE_HPP

#include <QtCore/QtGlobal>

#ifdef APPLICATION_ABUILD_DLL
    #define APPLICATION_API Q_DECL_EXPORT
#else
    #define APPLICATION_API Q_DECL_IMPORT
#endif

#endif // defined(APPLICATION_MODULE_HPP)