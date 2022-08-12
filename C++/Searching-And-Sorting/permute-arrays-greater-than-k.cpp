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
  bool isSumPossible(vector<int> inputA, vector<int> inputB, int target) {
    sort(inputA.begin(), inputA.end());
    sort(inputB.begin(), inputB.end(), greater<int>());
    int size = inputA.size();
    for (int i = 0; i < size; i++) {
      if (inputA[i] + inputB[i] < target) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<int> inputA = {2, 1, 3};
  vector<int> inputB = {7, 9, 8};
  int target = 10;
  cout << sol.isSumPossible(inputA, inputB, target) << endl;
  return 0;
}