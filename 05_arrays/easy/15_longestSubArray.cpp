#include <bits/stdc++.h>
using namespace std;

// Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.
 
// Brute Force - TC: O(n^2) & SC: O(1)
/* int findLongestSubArray(vector<int> &nums) {
   int maxLen = 0;

   for(int i = 0; i < nums.size(); i++) {
      int sum = 0;
      
      for(int j = i; j < nums.size(); j++) {
         sum += nums[j];

         if(sum == 0) {
            maxLen = max(maxLen, j - i + 1);
         }
      }
   }

   return maxLen;
} */

// # Optimal - TC: O(n) & SC: O(n)
int findLongestSubArray(vector<int> &nums) {
   unordered_map<int, int> pfSum;
   int maxLen = 0;
   int sum = 0;

   pfSum[0] = -1;

   for(int i = 0; i < nums.size(); i++) {
      sum += nums[i];

      if(pfSum.find(sum) != pfSum.end()) {
         maxLen = max(maxLen, i - pfSum[sum]);
      }

      if(pfSum.find(sum) == pfSum.end()) {
         pfSum[sum] = i;
      }
   }

   return maxLen;
}

int main() {
   vector<int> nums = {9, -3, 3, -1, 6, -5};
   cout << findLongestSubArray(nums);

   return 0;
}