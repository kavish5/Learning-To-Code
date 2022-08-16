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
  vector<int> bfs(vector<vector<int>> adjacency, int size) {
    vector<int> bfsTraversal;
    vector<bool> visited(size, false);
    for (int i = 0; i < size; i++) {
      if (!visited[i]) {
        queue<int> q;
        visited[i] = true;
        q.push(i);
        while (!q.empty()) {
          int currentNode = q.front();
          q.pop();
          bfsTraversal.push_back(currentNode);
          for (int index = 0; index < adjacency[currentNode].size(); index++) {
            if (adjacency[currentNode][index] == 1 && !visited[index]) {
              visited[index] = true;
              q.push(index);
            }
          }
        }
      }
    }
    return bfsTraversal;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> adjacency = {
      {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 0, 1}, {0, 0, 0, 1}};
  int graphSize = adjacency.size();
  cout << sol.bfs(adjacency, graphSize) << endl;
  return 0;
}