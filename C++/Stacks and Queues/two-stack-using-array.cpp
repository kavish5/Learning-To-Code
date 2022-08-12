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
  int size, topA, topB;
  int* arr;

 public:
  Solution(int n) {
    size = n;
    arr = new int[n];
    topA = -1;
    topB = size;
  }

  void pushA(int n) {
    if (topA < topB - 1) {
      arr[topA] = n;
      topA++;
    } else {
      cout << "Overflow";
      exit(1);
    }
  }

  void pushB(int n) {
    if (topA < topB - 1) {
      arr[topB] = n;
      topB--;
    } else {
      cout << "Overflow";
      exit(1);
    }
  }

  int popA() {
    if (topA >= 0) {
      int x = arr[topA];
      topA--;
      return x;
    } else {
      cout << "Underflow";
      exit(1);
    }
  }

  int popB() {
    if (topB < size) {
      int x = arr[topB];
      topB++;
      return x;
    } else {
      cout << "Underflow";
      exit(1);
    }
  }
};

int main() {
  Solution sol(5);
  sol.pushA(5);
  sol.pushB(10);
  sol.popA();
  sol.popB();
  sol.pushA(8);
  return 0;
}