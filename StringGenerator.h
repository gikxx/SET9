#ifndef STRINGGENERATOR_H
#define STRINGGENERATOR_H

#ifndef STRING_GENERATOR_H
#define STRING_GENERATOR_H

#include <vector>
#include <string>
#include <random>

class StringGenerator {
private:
  std::mt19937 rng;
  std::uniform_int_distribution<int> lengthDist;
  std::uniform_int_distribution<int> charDist;

  static const std::string ALPHABET;

public:
  StringGenerator();

  std::string randomString();

  std::vector<std::string> generateRandom(int n);

  std::vector<std::string> generateReverseSorted(int n);

  std::vector<std::string> generateAlmostSorted(int n);
};

#endif // STRING_GENERATOR_H

#endif //STRINGGENERATOR_H
