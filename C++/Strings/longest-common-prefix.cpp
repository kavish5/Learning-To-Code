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
  string longestCommonPrefix(vector<string>& strs) {
    string result = strs[0];
    int size = strs.size();
    for (int i = 1; i < size; i++) {
      int j;
      for (j = 0; j < strs[i].size(); j++) {
        if (result[j] != strs[i][j]) {
          break;
        }
      }
      result = result.substr(0, j);
      if (result == "") {
        return result;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<string> strs = {"ab", "a"};
  cout << sol.longestCommonPrefix(strs) << endl;
  return 0;
}