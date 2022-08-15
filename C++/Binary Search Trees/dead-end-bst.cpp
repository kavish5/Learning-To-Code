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

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool hasDeadEnd(TreeNode* root) {
    if (!root) {
      return false;
    }
    unordered_map<int, int> nodeMap;
    nodeMap[0] = 1;
    findAllNodes(root, nodeMap);
    return checkAllNodes(root, nodeMap);
  }

  void findAllNodes(TreeNode* root, unordered_map<int, int>& nodeMap) {
    if (!root) {
      return;
    }
    nodeMap[root->val] = 1;
    findAllNodes(root->left, nodeMap);
    findAllNodes(root->right, nodeMap);
  }

  bool checkAllNodes(TreeNode* root, unordered_map<int, int>& nodeMap) {
    if (!root) {
      return false;
    }
    if (!root->left && !root->right) {
      int previous = root->val - 1;
      int next = root->val + 1;
      if (nodeMap.find(previous) != nodeMap.end() &&
          nodeMap.find(next) != nodeMap.end()) {
        return true;
      }
    }
    return checkAllNodes(root->left, nodeMap) ||
           checkAllNodes(root->right, nodeMap);
  }
};

int main() {
  Solution sol;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->left->left = new TreeNode(2);
  root->left->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(8);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);
  cout << sol.hasDeadEnd(root) << endl;
  return 0;
}