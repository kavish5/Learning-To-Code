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
  vector<int> getPredecessorSuccessor(TreeNode* root, TreeNode*& predecessor,
                                      TreeNode*& successor, int key) {
    vector<int> result;
    if (!root) {
      return result;
    }
    if (root->val == key) {
      if (root->left) {
        TreeNode* temp = root->left;
        while (temp->right) {
          temp = temp->right;
        }
        predecessor = temp;
      }
      if (root->right) {
        TreeNode* temp = root->right;
        while (temp->left) {
          temp = temp->left;
        }
        successor = temp;
      }
      result.push_back(predecessor->val);
      result.push_back(successor->val);
      return result;
    }
    if (root->val > key) {
      successor = root;
      getPredecessorSuccessor(root->left, predecessor, successor, key);
    } else {
      predecessor = root;
      getPredecessorSuccessor(root->right, predecessor, successor, key);
    }
    result.push_back(predecessor->val);
    result.push_back(successor->val);
    return result;
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
  TreeNode* predecessor = NULL;
  TreeNode* succesor = NULL;
  int key = 3;
  cout << sol.getPredecessorSuccessor(root, predecessor, succesor, key) << endl;
  return 0;
}