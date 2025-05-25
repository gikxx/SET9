#include <algorithm>
#include <random>
const std::string ALPHABET =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "!@#%:;^&*()-.";

class StringGenerator {
private:
  std::mt19937 rng;
  std::uniform_int_distribution<int> lengthDist;
  std::uniform_int_distribution<int> charDist;

public:
  StringGenerator()
    : rng(std::random_device{}()),
      lengthDist(10, 200),
      charDist(0, (int) ALPHABET.size() - 1) {
  }

  std::string randomString() {
    int len = lengthDist(rng);
    std::string s(len, ' ');
    for (int i = 0; i < len; ++i) {
      s[i] = ALPHABET[charDist(rng)];
    }
    return s;
  }

  std::vector<std::string> generateRandom(int n) {
    std::vector<std::string> result;
    result.reserve(n);
    for (int i = 0; i < n; ++i) {
      result.push_back(randomString());
    }
    return result;
  }

  std::vector<std::string> generateReverseSorted(int n) {
    auto arr = generateRandom(n);
    std::sort(arr.begin(), arr.end());
    std::reverse(arr.begin(), arr.end());
    return arr;
  }

  std::vector<std::string> generateAlmostSorted(int n) {
    auto arr = generateRandom(n);
    std::sort(arr.begin(), arr.end());
    int swaps = n / 20;
    std::uniform_int_distribution<int> dist(0, n - 2);
    for (int i = 0; i < swaps; ++i) {
      int pos = dist(rng);
      std::swap(arr[pos], arr[pos + 1]);
    }
    return arr;
  }
};
