#include "benchmark.h"
#include "baillie_test.hpp"
#include <functional>
#include <string>

static void BM_rabinMiller(benchmark::State& state) {

  for (auto _ : state) {
      int k = 4;
      auto res = baillieTest(state.range(0));
      state.counters["IS PRIME"] = res; 
  }
  state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_rabinMiller)->DenseRange(1, std::stol(std::getenv("MAX_INT_BAILLIE_TEST") ) )->Complexity();
BENCHMARK_MAIN();
