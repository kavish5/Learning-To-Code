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
  int postfixEvaluation(string str) {
    stack<int> stack;
    int len = str.length();
    for (int i = 0; i < len; i++) {
      if (isdigit(str[i])) {
        stack.push(int(str[i] - '0'));
      } else {
        int x = stack.top();
        stack.pop();
        int y = stack.top();
        stack.pop();
        if (str[i] == '+') {
          stack.push(y + x);
        } else if (str[i] == '-') {
          stack.push(y - x);
        } else if (str[i] == '/') {
          stack.push(y / x);
        } else if (str[i] == '*') {
          stack.push(y * x);
        }
      }
    }
    return stack.top();
  }
};

int main() {
  Solution sol;
  string str = "231*+9-";
  cout << sol.postfixEvaluation(str) << endl;
  return 0;
}