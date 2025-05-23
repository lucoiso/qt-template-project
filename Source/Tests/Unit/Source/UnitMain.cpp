// Copyright Notices: [...]

#include <catch2/catch_all.hpp>

#include <QtPlugin>
Q_IMPORT_PLUGIN(UserInterfacePlugin)

// User defined modules
#include "UserInterface.hpp"

std::int32_t main(const std::int32_t InArgC, char** InArgV)
{
    Catch::Session Session;

    if (const std::int32_t Result = Session.applyCommandLine(InArgC, InArgV);
        Result != 0)
    {
        return Result;
    }

    return Session.run();
}