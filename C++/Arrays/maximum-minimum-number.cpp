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

struct Pair {
  int min;
  int max;
};

class Solution {
 public:
  Pair getMinMax(vector<int>& nums) {
    int size = nums.size();
    struct Pair result;
    int index;
    if (size % 2 == 0) {
      bool isGreater = nums[0] < nums[1];
      result.max = isGreater ? nums[1] : nums[0];
      result.min = isGreater ? nums[0] : nums[1];
      index = 2;
    } else {
      result.max = nums[0];
      result.min = nums[0];
      index = 1;
    }
    while (index < size - 1) {
      if (nums[index] < nums[index + 1]) {
        if (result.max < nums[index + 1]) {
          result.max = nums[index + 1];
        }
        if (result.min > nums[index]) {
          result.min = nums[index];
        }
      } else {
        if (result.max < nums[index]) {
          result.max = nums[index];
        }
        if (result.min > nums[index + 1]) {
          result.min = nums[index + 1];
        }
      }
      index += 2;
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {-1, 0, 1, 2, -1, 4};
  Pair result = sol.getMinMax(nums);
  cout << result.min << " " << result.max;
  return 0;
}