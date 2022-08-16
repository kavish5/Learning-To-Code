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
  vector<int> dfs(vector<vector<int>> adjacency, int size) {
    vector<bool> visited(size, false);
    vector<int> dfsTraversal;
    for (int i = 0; i < size; i++) {
      if (!visited[i]) {
        stack<int> stack;
        stack.push(i);
        while (!stack.empty()) {
          int s = stack.top();
          stack.pop();
          if (!visited[s]) {
            dfsTraversal.push_back(s);
            visited[s] = true;
          }
          for (auto i = adjacency[s].begin(); i != adjacency[s].end(); i++) {
            if (!visited[*i]) {
              stack.push(*i);
            }
          }
        }
      }
    }
    return dfsTraversal;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> adjacency = {
      {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 0, 1}, {0, 0, 0, 1}};
  int graphSize = adjacency.size();
  cout << sol.dfs(adjacency, graphSize) << endl;
  return 0;
}