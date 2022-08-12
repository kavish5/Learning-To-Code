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

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  long long multiplyTwoLists(ListNode* first, ListNode* second) {
    if (first == NULL || second == NULL) {
      return 0;
    }
    long long N = 1000000007;
    long long num1 = 0, num2 = 0;
    while (first) {
      num1 = (num1 * 10) % N + first->val;
      first = first->next;
    }
    while (second) {
      num2 = (num2 * 10) % N + second->val;
      second = second->next;
    }
    return ((num1 % N) * (num2 % N)) % N;
  }
};

int main() {
  Solution sol;
  ListNode* headA = new ListNode(1);
  headA->next = new ListNode(2);
  ListNode* headB = new ListNode(2);
  headB->next = new ListNode(3);
  cout << sol.multiplyTwoLists(headA, headB) << endl;
  return 0;
}