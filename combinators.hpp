
#pragma once

#include <functional>

namespace combinators {

// combinators

// Psi (The Blackbird)
auto _psi = [](auto f, auto g) {
  return [=](auto x, auto y) { return f(g(x), g(y)); };
};

// more convenient binary operations

auto _and = std::logical_and{};

} // namespace combinators
