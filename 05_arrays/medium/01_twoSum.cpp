#include <bits/stdc++.h>
using namespace std;

// TWO SUM - Check if a pair with given sum exists in Array

// # Brute Force - TC: O(N^2) & SC: O(1)
/* pair<int, int> twoSum(vector<int> &nums, int target) {
   for(int i = 0; i < nums.size(); i++) {
      for(int j = i+1; j < nums.size(); j++) {
         if(nums[i] + nums[j] == target) {
            return {i, j};
         }
      }
   }
   return {-1, -1};
} */

// # Better / Optimal 1 - TC: O(2N) && SC: O(N)
/* pair<int, int> twoSum(vector<int> &nums, int target) {
   unordered_map<int, int> mpp;
   
   for(int i = 0; i < nums.size(); i++) {
      mpp[nums[i]] = i;
   }

   for(int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      
      if(mpp.find(complement) != mpp.end() && mpp[complement] != i) {
         return {i, mpp[complement]};
      }
   }
   
   return {-1, -1};
} */

// # Better / Optimal 2 - TC: O(N) & SC: O(N)
pair<int, int> twoSum(vector<int> &nums, int target) {
   unordered_map<int, int> hMap;

   for(int i = 0; i < nums.size(); i++) {
      
      if(hMap.find(target-nums[i]) != hMap.end()) {
         return {i, hMap[target-nums[i]]};
      }
      hMap[nums[i]] = i; 
   }
   
   return {-1, -1};
}

int main() {
   vector<int> nums = {3, 2, 4, 5}; // {2, 6, 5, 8, 11};
   int target = 6;
   pair<int, int> ind = twoSum(nums, target);

   cout << ind.first << " " << ind.second << endl;

   return 0;
}