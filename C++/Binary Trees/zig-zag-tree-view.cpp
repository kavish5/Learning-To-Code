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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    bool flag = false;
    if (!root) {
      return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      vector<int> nodes(size);
      for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();
        nodes[i] = node->val;
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      if (flag) {
        reverse(nodes.begin(), nodes.end());
      }
      flag = !flag;
      result.push_back(nodes);
    }
    return result;
  }
};

int main() {
  Solution sol;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(8);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);
  cout << sol.zigzagLevelOrder(root) << endl;
  return 0;
}