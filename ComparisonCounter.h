#ifndef COMPARISON_COUNTER_H
#define COMPARISON_COUNTER_H

#include <string>

struct ComparisonCounter {
  size_t count = 0;

  bool lcpCompare(const std::string& a, const std::string& b);
  void reset();
};

#endif // COMPARISON_COUNTER_H