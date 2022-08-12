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
  void reverseQueue(queue<int> q, int k) {
    if (q.empty() == true || k > q.size()) return;
    if (k <= 0) return;
    stack<int> s;
    for (int i = 0; i < k; i++) {
      s.push(q.front());
      q.pop();
    }
    while (!s.empty()) {
      q.push(s.top());
      s.pop();
    }
    for (int i = 0; i < q.size() - k; i++) {
      q.push(q.front());
      q.pop();
    }
  }
};

int main() {
  Solution sol;
  int k = 5;
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);
  q.push(7);
  q.push(8);
  q.push(9);
  q.push(10);
  q.push(11);
  q.push(12);
  sol.reverseQueue(q, k);
}