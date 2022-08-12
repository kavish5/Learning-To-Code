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
  vector<int> findTwoUniques(vector<int> input) {
    vector<int> result;
    int x = 0, y = 0;
    int xorResult = input[0];
    for (int i = 1; i < input.size(); i++) {
      xorResult ^= input[i];
    }
    int setBit = xorResult & ~(xorResult - 1);
    for (int i = 0; i < input.size(); i++) {
      if (input[i] & setBit) {
        x = x ^ input[i];
      } else {
        y = y ^ input[i];
      }
    }
    result.push_back(x);
    result.push_back(y);
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> input = {2, 3, 7, 9, 11, 2, 3, 11};
  cout << sol.findTwoUniques(input) << endl;
  return 0;
}