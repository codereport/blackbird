
#pragma once

#include <cmath>
#include <functional>
#include <utility>

namespace combinators {

/////////////////
// combinators //
/////////////////

// I (no bird name)
auto _id = std::identity{};

// B (The Bluebird)
auto _b = [](auto f, auto g) { return [=](auto&& x) { return f(g(std::forward<decltype(x)>(x))); }; };

// BB (The Bluebird^2)
auto _bb = [](auto f, auto g, auto h) { return [=](auto x) { return f(g(h(x))); }; };

// BBB (The Bluebird^3)
auto _bbb = [](auto f, auto g, auto h, auto i) { return [=](auto x) { return f(g(h(i(x)))); }; };

// B1 (The Blackbird)
auto _b1 = [](auto f, auto g) { return [=](auto x, auto y) { return f(g(x, y)); }; };

// C (The Cardinal) aka `flip` in Haskell
auto _c = [](auto f) { return [=](auto x, auto y) { return f(y, x); }; };

// D2 (The Dovekie)
auto _d2_ = [](auto f, auto g, auto h) { return [=](auto x, auto y) { return g(f(x), h(y)); }; };

// K (Kestrel)
auto _l_ = [](auto x, auto y) { return x; };

// KI
auto _r_ = [](auto x, auto y) { return y; };

// Phi (The Phoenix)
auto _phi = [](auto f, auto g, auto h) {
    return [=](auto&& x) { return g(f(std::forward<decltype(x)>(x)), h(std::forward<decltype(x)>(x))); };
};

// Phi1 (The Pheasant)
auto _phi1_ = [](auto f, auto g, auto h) { return [=](auto x, auto y) { return g(f(x, y), h(x, y)); }; };

// Psi (The Psi Bird)
auto _psi = [](auto f, auto g) {
    return [=](auto&& x, auto&& y) { return f(g(std::forward<decltype(x)>(x)), g(std::forward<decltype(y)>(y))); };
};

// W (The Warbler)
auto _w = [](auto f) { return [=](auto x) { return f(x, x); }; };

/////////////////////////////////////////////
// more convenient binary/unary operations //
/////////////////////////////////////////////

auto _eq    = [](auto x) { return [x](auto y) { return x == y; }; };
auto _eq_   = std::equal_to{};
auto _neq_  = std::not_equal_to{};
auto _lt    = [](auto x) { return [x](auto y) { return x > y; }; };
auto lt_    = [](auto x) { return [x](auto y) { return y < x; }; };
auto _lt_   = std::less{};
auto _lte_  = std::less_equal{};
auto _gt_   = std::greater{};
auto _gte   = [](auto x) { return [x](auto y) { return x >= y; }; };
auto _gte_  = std::greater_equal{};
auto _plus  = [](auto x) { return [x](auto y) { return x + y; }; };
auto _plus_ = std::plus{};
auto _mul   = [](auto x) { return [x](auto y) { return x * y; }; };
auto _mul_  = std::multiplies{};
auto _sub   = [](auto x) { return [x](auto y) { return x - y; }; };
auto sub_   = [](auto x) { return [x](auto y) { return y - x; }; };
auto _sub_  = std::minus{};
auto _mod   = [](auto x) { return [x](auto y) { return x % y; }; };
auto mod_   = [](auto x) { return [x](auto y) { return y % x; }; };
auto _mod_  = std::modulus{};
auto _pow_  = [](auto x, auto y) { return std::pow(x, y); };
auto _div   = [](auto x) { return [x](auto y) { return x / y; }; };
auto div_   = [](auto x) { return [x](auto y) { return y / x; }; };
auto _div_  = std::divides{};
auto _or_   = std::logical_or{};
auto _and_  = std::logical_and{};
auto _neg   = std::negate{};
auto _not   = std::logical_not{};
auto _sign  = [](auto x) { return x > 0 ? 1 : x < 0 ? -1 : 0; };
auto _sqrt  = [](auto x) { return std::sqrt(x); };
auto _min_  = [](auto x, auto y) { return std::min(x, y); };
auto _max_  = [](auto x, auto y) { return std::max(x, y); };

// conversions
auto _int    = [](auto x) { return static_cast<int>(x); };
auto _uint   = [](auto x) { return static_cast<unsigned int>(x); };
auto _bool   = [](auto x) { return static_cast<bool>(x); };
auto _float  = [](auto x) { return static_cast<float>(x); };
auto _double = [](auto x) { return static_cast<double>(x); };

template <int N>
auto _nth = [](auto t) { return std::get<N>(t); };
auto _fst = [](auto t) { return std::get<0>(t); };
auto _snd = [](auto t) { return std::get<1>(t); };

auto _rshift_  = [](auto x, auto y) { return x >> y; };
auto _bit_and_ = std::bit_and{};
auto _bit_xor_ = std::bit_xor{};

auto _odd  = [](auto x) { return (x % 2) == 1; };
auto _even = [](auto x) { return (x % 2) == 0; };

}  // namespace combinators
