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
  vector<int> findPair(vector<int>& nums, int difference) {
    vector<int> result;
    unordered_map<int, int> map;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      map[nums[i]]++;
      if (difference == 0 && map[nums[i]] > 1) {
        result.push_back(nums[i]);
        result.push_back(nums[i]);
      }
    }
    for (int i = 0; i < size; i++) {
      if (map.find(nums[i] + difference) != map.end()) {
        result.push_back(nums[i]);
        result.push_back(difference + nums[i]);
        return result;
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 8, 30, 40, 100};
  int difference = -60;
  cout << sol.findPair(nums, difference) << endl;
  return 0;
}