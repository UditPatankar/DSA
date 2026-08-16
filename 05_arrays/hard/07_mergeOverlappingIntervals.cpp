#include <bits/stdc++.h>
using namespace std;

// MERGE OVERLAPPING SUB-INTERVALS - 

// # Optimal - TC: O(N log N) & SC: O(1) excluding output space
vector<vector<int>> mergeIntervals(vector<vector<int>> &nums) {
   if(nums.size() <= 1) return nums;

   sort(nums.begin(), nums.end());
   vector<vector<int>> result;
   result.push_back(nums[0]); // push 1st interval

   for(int i = 1; i < nums.size(); i++) {
      auto &lastInt = result.back(); 

      if(nums[i][0] <= lastInt[1]) {   // comapre with last interval in result
         lastInt[1] = max(lastInt[1], nums[i][1]);
      }
      else {
         result.push_back(nums[i]);
      }
   }

   return result;
}

int main() {
   vector<vector<int>> nums = { {4,7}, {1,3}, {2,6}, {15,18}, {8,10} };
   vector<vector<int>> result = mergeIntervals(nums);

   for(auto x : result) {
      cout << x[0] << " " << x[1] << ",";
   }
   return 0;
}