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
  ListNode* removeDuplicates(ListNode* node) {
    if (node == NULL) {
      return node;
    }
    unordered_map<int, int> map;
    ListNode* cur = node;
    ListNode* prev = NULL;
    while (cur->next) {
      if (map.find(cur->val) != map.end()) {
        prev->next = cur->next;
        delete (cur);
      } else {
        map[cur->val] = 1;
        prev = cur;
      }
      cur = prev->next;
    }
    return node;
  }
};

int main() {
  Solution sol;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(3);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);
  cout << sol.removeDuplicates(head) << endl;
  return 0;
}