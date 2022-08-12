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
  vector<int> findCommon(vector<int> inputA, vector<int> inputB,
                         vector<int> inputC) {
    vector<int> result;
    int i = 0, j = 0, k = 0;
    int sizeA = inputA.size();
    int sizeB = inputB.size();
    int sizeC = inputC.size();
    int prevA, prevB, prevC;
    prevA = INT_MIN;
    prevB = INT_MIN;
    prevC = INT_MIN;
    while (i < sizeA && j < sizeB && k < sizeC) {
      while (inputA[i] == prevA && i < sizeA) {
        i++;
      }
      while (inputB[i] == prevB && j < sizeB) {
        j++;
      }
      while (inputC[i] == prevC && k < sizeC) {
        k++;
      }
      if (inputA[i] == inputB[j] && inputB[j] == inputC[k]) {
        result.push_back(inputA[i]);
        prevA = inputA[i++];
        prevB = inputA[j++];
        prevC = inputA[k++];
      } else if (inputA[i] < inputB[j]) {
        prevA = inputA[i++];
      } else if (inputB[j] < inputC[k]) {
        prevB = inputB[j++];
      } else {
        prevC = inputC[k++];
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> inputA = {1, 2, 3, 7};
  vector<int> inputB = {3, 7, 9, 11};
  vector<int> inputC = {4, 7, 8, 10};
  cout << sol.findCommon(inputA, inputB, inputC) << endl;
  return 0;
}