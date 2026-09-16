#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>> &nums) {
   sort(nums.begin(), nums.end());
   vector<vector<int>> result;
   result.push_back(nums[0]);

   for(int i = 1; i < nums.size(); i++) {
      auto &lastInterval = result.back();
      if(lastInterval[1] >= nums[i][0]) {  // eg. [1, 2] [2, 6]
         // overlapping
         lastInterval[1] = max(nums[i][1], lastInterval[1]);
      }
      else {
         // not overlapping
         result.push_back(nums[i]);
      }
   }
   return result;
}

int main() {
   vector<vector<int>> nums = { {4,7}, {1,3}, {2,6}, {15,18}, {8,10} };
   vector<vector<int>> result = mergeIntervals(nums);

   for(auto x : result) {
      cout << "[" << x[0] << " " << x[1] << "]" << ",";
   }
   return 0;
}