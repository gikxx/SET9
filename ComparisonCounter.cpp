//
// Created by 1 on 26.05.2025.
//

#include "ComparisonCounter.h"

struct ComparisonCounter {
  size_t count = 0;

  bool lcpCompare(const std::string& a, const std::string& b) {
    size_t i = 0;
    size_t len = std::min(a.size(), b.size());
    while (i < len) {
      count++;
      if (a[i] != b[i]) {
        return a[i] < b[i];
      }
      ++i;
    }
    return a < b;
  }

  void reset() { count = 0; }
};