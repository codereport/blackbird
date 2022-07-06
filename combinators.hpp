
#pragma once

#include <functional>

namespace combinators {

/////////////////
// combinators //
/////////////////

// B (The Bluebird)
auto _b = [](auto f, auto g) { //
  return [=](auto x) { return f(g(x)); };
};

// Phi (The Phoenix)
auto _phi = [](auto f, auto g, auto h) {
  return [=](auto x) { return g(f(x), h(x)); };
};

// Psi (The Psi Bird)
auto _psi = [](auto f, auto g) {
  return [=](auto x, auto y) { return f(g(x), g(y)); };
};

/////////////////////////////////////////////
// more convenient binary/unary operations //
/////////////////////////////////////////////

auto _eq = [](auto x) { return [x](auto y) { return x == y; }; };
auto _eq_ = std::equal_to{};
auto _or = std::logical_or{};
auto _and = std::logical_and{};

} // namespace combinators
