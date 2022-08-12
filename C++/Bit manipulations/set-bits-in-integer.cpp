/*
1 + 1 = 10; carry 1
10 + 1 = 11; carry 1
1 + 0 = 1; carry 0
0 + 1 = 1; carry 0
0 + 0 = 0; carry 0
1 can be carry
*/
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
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  unsigned int countSetBits(unsigned int n) {
    unsigned int count = 0;
    while (n) {
      n &= (n - 1);
      count++;
    }
    return count;
  }
};

int main() {
  Solution sol;
  int n = 98765;
  cout << sol.countSetBits(n) << endl;
  return 0;
}