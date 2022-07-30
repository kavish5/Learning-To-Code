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
  bool containsDuplicate(vector<int>& nums) {
    int size = nums.size();
    unordered_map<int, int> map;
    for (int i = 0; i < size; i++) {
      map[nums[i]] += 1;
      if (map[nums[i]] > 1) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << sol.containsDuplicate(nums) << endl;
  return 0;
}