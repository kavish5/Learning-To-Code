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
  string removeConsecutiveCharacter(string s) {
    int len = s.length();
    if (len < 2) {
      return s;
    }
    string result = "";
    for (int i = 0; i < len; i++) {
      if (s[i] != s[i + 1]) {
        result += s[i];
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  string input = "aabbccdcc";
  cout << sol.removeConsecutiveCharacter(input) << endl;
  return 0;
}