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
  int findMinDifference(vector<int>& nums, int m) {
    int size = nums.size();
    if (m > size) {
      return -1;
    }
    sort(nums.begin(), nums.end());
    int diff = INT_MAX;
    int curDiff = 0;
    for (int i = 0; i < size - m + 1; i++) {
      curDiff = nums[i + m - 1] - nums[i];
      if (curDiff < diff) {
        diff = curDiff;
      }
    }
    return diff;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {12, 4,  7,  9,  2,  23, 25, 41, 30,
                      40, 28, 42, 30, 44, 48, 43, 50};
  int m = 7;
  cout << sol.findMinDifference(nums, m) << endl;
  return 0;
}