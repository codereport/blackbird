
#pragma once

#include <functional>

#define FWD(x) std::forward<decltype(x)>(x)
#define ARG auto&&

namespace combinators {

/////////////////
// combinators //
/////////////////

// B (The Bluebird)
auto _b = [](auto f, auto g) { return [=](ARG x) { return f(g(FWD(x))); }; };

// BB (The Bluebird^2)
auto _bb = [](auto f, auto g, auto h) { return [=](ARG x) { return f(g(h(FWD(x)))); }; };

// BBB (The Bluebird^3)
auto _bbb = [](auto f, auto g, auto h, auto i) { return [=](ARG x) { return f(g(h(i(FWD(x))))); }; };

// B1 (The Blackbird)
auto _b1 = [](auto f, auto g) { return [=](ARG x, ARG y) { return f(g(FWD(x), FWD(y))); }; };

// C (The Cardinal) aka `flip` in Haskell
auto _c = [](auto f) { return [=](ARG x, ARG y) { return f(FWD(y), FWD(x)); }; };

// K (Kestrel)
auto _l_ = [](ARG x, ARG y) { return FWD(x); };

// KI
auto _r_ = [](ARG x, ARG y) { return FWD(y); };

// Phi (The Phoenix)
auto _phi = [](auto f, auto g, auto h) { return [=](ARG x) { return g(f(FWD(x)), h(FWD(x))); }; };

// Phi1 (The Pheasant)
auto _phi1_ = [](auto f, auto g, auto h) { return [=](ARG x, ARG y) { return g(f(FWD(x), FWD(y)), h(FWD(x), FWD(y))); }; };

// Psi (The Psi Bird)
auto _psi = [](auto f, auto g) { return [=](ARG x, ARG y) { return f(g(FWD(x)), g(FWD(y))); }; };

// W (The Warbler)
auto _w = [](auto f) { return [=](ARG x) { return f(FWD(x), FWD(x)); }; };

/////////////////////////////////////////////
// more convenient binary/unary operations //
/////////////////////////////////////////////

auto _eq    = [](ARG x) { return [x](ARG y) { return FWD(x) == FWD(y); }; };
auto _eq_   = std::equal_to{};
auto _neq_  = std::not_equal_to{};
auto _lt    = [](ARG x) { return [x](ARG y) { return FWD(x) > FWD(y); }; };
auto lt_    = [](ARG x) { return [x](ARG y) { return FWD(y) < FWD(x); }; };
auto _lt_   = std::less{};
auto _lte_  = std::less_equal{};
auto _gt_   = std::greater{};
auto _gte   = [](ARG x) { return [x](ARG y) { return FWD(x) >= FWD(y); }; };
auto _gte_  = std::greater_equal{};
auto _plus  = [](ARG x) { return [x](ARG y) { return FWD(x) + FWD(y); }; };
auto _plus_ = std::plus{};
auto _mul   = [](ARG x) { return [x](ARG y) { return FWD(x) * FWD(y); }; };
auto _mul_  = std::multiplies{};
auto _sub   = [](ARG x) { return [x](ARG y) { return FWD(x) - FWD(y); }; };
auto sub_   = [](ARG x) { return [x](ARG y) { return FWD(y) - FWD(x); }; };
auto _sub_  = std::minus{};
auto _mod   = [](ARG x) { return [x](ARG y) { return FWD(x) % FWD(y); }; };
auto mod_   = [](ARG x) { return [x](ARG y) { return FWD(y) % FWD(x); }; };
auto _mod_  = std::modulus{};
auto _or_   = std::logical_or{};
auto _and_  = std::logical_and{};
auto _not   = std::logical_not{};
auto _min_  = [](ARG a, ARG b) { return std::min(FWD(a), FWD(b)); };
auto _max_  = [](ARG a, ARG b) { return std::max(FWD(a), FWD(b)); };
auto _fst   = [](ARG t) { return std::get<0>(t); };
auto _snd   = [](ARG t) { return std::get<1>(t); };
auto _bool  = [](ARG e) { return static_cast<bool>(e); };

auto _odd  = [](ARG x) { return (x % 2) == 1; };
auto _even = [](ARG x) { return (x % 2) == 0; };

}  // namespace combinators
