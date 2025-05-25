#ifndef STRING_SORT_TESTER_H
#define STRING_SORT_TESTER_H

#include <vector>
#include <string>
#include <fstream>
#include "StringGenerator.h"

struct ComparisonCounter {
    size_t count = 0;
};

class StringSortTester {
    StringGenerator generator;

public:
    using SortFunction = void(*)(std::vector<std::string>&, ComparisonCounter&);

    void runTests(SortFunction sortFunc, const std::string& sortName);
};

#endif // STRING_SORT_TESTER_H