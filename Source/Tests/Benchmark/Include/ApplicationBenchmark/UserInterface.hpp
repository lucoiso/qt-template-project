// Copyright Notices: [...]

#pragma once

#include <benchmark/benchmark.h>

static void Placeholder(benchmark::State& State)
{
    for ([[maybe_unused]] const auto _ : State)
    {
    }
}
BENCHMARK(Placeholder);