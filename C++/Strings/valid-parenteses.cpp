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
  bool isValid(string s) {
    stack<char> st;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        st.push(s[i]);
      } else {
        if (st.empty() || (st.top() == '(' && s[i] != ')') ||
            (st.top() == '{' && s[i] != '}') ||
            (st.top() == '[' && s[i] != ']')) {
          return false;
        }
        st.pop();
      }
    }
    return st.empty();
  }
};

int main() {
  Solution sol;
  string input = "()[]{}";
  cout << sol.isValid(input) << endl;
  return 0;
}