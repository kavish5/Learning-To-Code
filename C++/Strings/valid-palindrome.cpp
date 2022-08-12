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
  bool isPalindrome(string s) {
    // int len = s.length();
    // string checker = "";
    // for (int i = 0; i < len; i++) {
    //   if (isupper(s[i])) {
    //     s[i] = s[i] + 32;
    //     checker += s[i];
    //   } else if (islower(s[i]) || isdigit(s[i])) {
    //     checker += s[i];
    //   }
    // }
    // int right = checker.length() - 1;
    // int left = 0;
    // while (left < right) {
    //   if (checker[left] != checker[right]) {
    //     return false;
    //   }
    //   left++;
    //   right--;
    // }
    // return true;

    int start = 0, end = s.length() - 1;
    while (start < end) {
      if (!isalnum(s[start])) {
        start++;
      } else if (!isalnum(s[end])) {
        end--;
      } else {
        if (tolower(s[start++]) != tolower(s[end--])) {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  string input = "a";
  cout << sol.isPalindrome(input) << endl;
  return 0;
}