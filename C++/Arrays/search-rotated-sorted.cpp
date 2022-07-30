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
  int search(vector<int>& nums, int target) {
    int size = nums.size();
    if (size < 1) {
      return -1;
    }
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[low] <= nums[mid]) {
        if (nums[low] <= target && nums[mid] > target) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        if (nums[high] >= target && nums[mid] < target) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  cout << sol.search(nums, target) << endl;
  return 0;
}