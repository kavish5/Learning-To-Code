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
#include <unordered_map>
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
  int searchNumber(vector<int> input, int target, int k) {
    int size = input.size();
    int i = 0;
    while (i < size) {
      if (input[i] == target) {
        return i;
      }
      i += max(1, abs(input[i] - target) / k);
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> input = {2, 4, 5, 7, 7, 6};
  int target = 6;
  int k = 2;
  cout << sol.searchNumber(input, target, k) << endl;
  return 0;
}