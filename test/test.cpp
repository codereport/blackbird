#include <iostream>
#include "combinators.hpp"

int main() {
    int a{5};
    auto modifying_function = [](auto& x){x++; return x;};
    auto identity = [](auto x){return std::forward<decltype(x)>(x);};
    auto combined = combinators::_b(identity, modifying_function);
    combined(a);
    std::cout << a;
}
