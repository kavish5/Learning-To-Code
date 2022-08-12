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
  vector<int> ceilingNumbers(vector<int> input, int target) {
    int size = input.size();
    int high = size - 1;
    int low = 0;
    int mid;
    vector<int> result;
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (input[mid] == target) {
        break;
      } else if (input[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    if (mid != 0) {
      result.push_back(input[mid - 1]);
    }
    if (mid != size - 1) {
      result.push_back(input[mid + 1]);
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> input = {2, 4, 5, 6, 7, 7};
  int target = 7;
  cout << sol.ceilingNumbers(input, target) << endl;
  return 0;
}