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
  int getFrequency(string input) {
    unordered_map<char, int> map;
    int len = input.length();
    for (int i = 0; i < len; i++) {
      if (map[input[i]]) {
        map[input[i]] += 1;
      } else {
        map[input[i]] = 1;
      }
    }
    int result = 0;
    for (auto it : map) {
      if (it.second > 1) {
        cout << it.first << " " << it.second << endl;
        result++;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  string input = "helloworld";
  cout << sol.getFrequency(input) << endl;
  return 0;
}