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
  bool isAnagram(string s, string t) {
    // if (s == t) {
    //   return true;
    // }
    // if (s.size() != t.size()) {
    //   return false;
    // }
    // sort(s.begin(), s.end());
    // sort(t.begin(), t.end());
    // return s == t;

    if (s == t) {
      return true;
    }
    if (s.size() != t.size()) {
      return false;
    }
    int map[26] = {};
    for (int i = 0; i < s.size(); i++) {
      map[s[i] - 'a']++;
      map[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (map[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  string inputA = "anagram";
  string inputB = "nagaram";
  cout << sol.isAnagram(inputA, inputB) << endl;
  return 0;
}