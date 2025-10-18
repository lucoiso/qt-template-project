// Copyright Notices: [...]

#pragma once

#include <cstdint>

namespace Application
{
    /** Run application */
    [[nodiscard]] std::int32_t APPLICATION_API Run(std::int32_t InArgc, char* InArgv[]);
} // namespace Application