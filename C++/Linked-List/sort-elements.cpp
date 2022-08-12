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
  ListNode* sortList(ListNode* node) {
    if (node == NULL) {
      return node;
    }
    int count[3] = {0, 0, 0};
    ListNode* cur = node;
    while (cur->next) {
      count[cur->val] += 1;
      cur = cur->next;
    }
    int i = 0;
    cur = node;
    while (cur) {
      if (count[i] == 0) {
        i++;
      } else {
        cur->val = i;
        --count[i];
        cur = cur->next;
      }
    }
    return node;
  }
};

int main() {
  Solution sol;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(1);
  head->next->next->next->next = new ListNode(0);
  head->next->next->next->next->next = new ListNode(2);
  head->next->next->next->next->next->next = new ListNode(1);
  head->next->next->next->next->next->next->next = new ListNode(2);
  cout << sol.sortList(head) << endl;
  return 0;
}