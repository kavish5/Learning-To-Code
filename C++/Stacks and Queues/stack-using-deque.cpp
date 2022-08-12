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

class MyStack {
 private:
  deque<int> q;

 public:
  MyStack() {}

  void push(int x) {
    q.push_back(x);
    for (int i = 0; i < q.size() - 1; i++) {
      int x = q.front();
      q.pop_front();
      q.push_back(x);
    }
  }

  int pop() {
    int x = -1;
    if (!q.empty()) {
      x = q.front();
      q.pop_front();
    }
    return x;
  }

  int top() {
    if (!q.empty()) {
      return q.front();
    } else {
      return -1;
    }
  }

  bool empty() { return q.empty(); }
};

int main() {}