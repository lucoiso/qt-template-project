// Copyright Notices: [...]

#include <benchmark/benchmark.h>

#include <QtPlugin>
Q_IMPORT_PLUGIN(UserInterfacePlugin)

// User defined modules
#include "UserInterface.hpp"

std::int32_t main(std::int32_t InArgC, char** InArgV)
{
    benchmark::Initialize(&InArgC, InArgV);
    benchmark::RunSpecifiedBenchmarks();

    return EXIT_SUCCESS;
}