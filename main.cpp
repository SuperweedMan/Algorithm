#include "SelectSort.h"
#include <iostream>

struct CompileString {};
#define COMPILE_STRING(x) []() {                                               \
    struct Str : public CompileString {                                        \
        constexpr operator std::string_view() const { return {x, sizeof(x)}; } \
    };                                                                         \
    return Str{};                                                              \
}()

int main() {
    SelectSort<double> a{};
    SelectSort<int> b{};
    std::vector<int> c{1, 5, 48, 56, 1};
    std::vector<double> d{0.15, 12.0, 50., 10.};
    std::vector f{1, 2, 3};
    a.sort(d);
    b.sort(c);
    for (auto i = c.begin(); i != c.end(); ++i)
        std::cout << *i;
    std::cout << std::endl;
    for (auto j = d.begin(); j != d.end(); ++j)
        std::cout << *j;
    std::cout << std::endl;

    constexpr auto str1 = COMPILE_STRING("float");
    constexpr auto str2 = COMPILE_STRING("int");
    std::cout << std::is_same_v<decltype(str1), decltype(str2)> << std::endl;
    std::cout << std::is_same_v<decltype(str1), float> << std::endl;
    std::cout << std::is_same_v<decltype(str2), int> << std::endl;
    std::cout << std::is_same_v<decltype(str1), int> << std::endl;
    return 0;
}