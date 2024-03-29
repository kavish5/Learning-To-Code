/*
Approach 1 could be naive approach of mod by 2 followed by divide by 2.
Approach 2 could be to to AND number with N and N-1 like 1000 & 0111 resulting
in 0
*/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vector) {
  for (auto element : vector) {
    os << element << " ";
  }
  return os;
}

class Solution {
 public:
  int convert(int a, int b) {
    int xorResult = a ^ b;
    return countSetBits(xorResult);
  }

  unsigned int countSetBits(unsigned int n) {
    unsigned int count = 0;
    while (n) {
      n &= (n - 1);
      count++;
    }
    return count;
  }
};

int main() {
  Solution s;
  int a = 10;
  int b = 20;
  cout << s.convert(a, b) << endl;
  return 0;
}