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
  vector<int> getReverse(vector<int>& nums) {
    int end = nums.size() - 1;
    int start = 0;
    int temp = 0;
    while (start < end) {
      temp = nums[start];
      nums[start++] = nums[end];
      nums[end--] = temp;
    }
    return nums;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {-1, 0, 1, 2, -1, 4};
  cout << sol.getReverse(nums) << endl;
  return 0;
}