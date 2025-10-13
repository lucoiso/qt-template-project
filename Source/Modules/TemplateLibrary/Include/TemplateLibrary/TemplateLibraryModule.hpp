// Copyright Notices: [...]

#ifndef TEMPLATELIBRARY_MODULE_HPP
#define TEMPLATELIBRARY_MODULE_HPP

#ifdef BUILD_DLL
    #define TEMPLATELIBRARY_API _declspec(dllexport)
#else
    #define TEMPLATELIBRARY_API _declspec(dllimport)
#endif

#endif // defined(TEMPLATELIBRARY_MODULE_HPP)