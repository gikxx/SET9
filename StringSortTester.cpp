#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "ComparisonCounter.h"
#include "StringGenerator.h"

class StringSortTester {
  StringGenerator generator;

public:
  using SortFunction = void(*)(std::vector<std::string>&, ComparisonCounter&);

  void runTests(SortFunction sortFunc, const std::string& sortName) {
    std::ofstream outFile(sortName + "_results.csv");
    outFile << "ArraySize,DataType,AvgTimeMs,AvgComparisons\n";

    auto randomMax = generator.generateRandom(3000);
    auto reverseMax = generator.generateReverseSorted(3000);
    auto almostMax = generator.generateAlmostSorted(3000);

    std::vector<std::pair<std::string, std::vector<std::string> > > testSets = {
      {"Random", randomMax},
      {"Reverse", reverseMax},
      {"AlmostSorted", almostMax}
    };

    for (int size = 100; size <= 3000; size += 100) {
      for (auto& [dataType, fullData] : testSets) {
        uint64_t totalComparisons = 0;
        double totalTimeMs = 0;
        const int repeats = 5;

        for (int r = 0; r < repeats; ++r) {
          std::vector<std::string> data(fullData.begin(), fullData.begin() + size);

          ComparisonCounter cmp;

          auto start = std::chrono::high_resolution_clock::now();
          sortFunc(data, cmp);
          auto end = std::chrono::high_resolution_clock::now();
          std::chrono::duration<double, std::milli> diff = end - start;

          totalTimeMs += diff.count();
          totalComparisons += cmp.count;
        }

        outFile << size << "," << dataType << "," << (totalTimeMs / repeats) << "," << (totalComparisons / repeats) <<
            "\n";
        std::cout << sortName << " " << dataType << " size " << size << " time(ms): " << (totalTimeMs / repeats) <<
            " cmp: " << (totalComparisons / repeats) << std::endl;
      }
    }
    outFile.close();
  }
};
