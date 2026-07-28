#include <bits/stdc++.h>
using namespace std;

// Return the length of the Longest sub-array with given sum K (positive)

// (positive)
// # Brute Force - TC: O(n^2) & SC: O(1)
/* int findLengthOfSubArray(vector<int> &nums, int K) {
   int maxLen = 0;

   for(int i = 0; i < nums.size(); i++) {
      int sum = 0;
      
      for(int j = i; j < nums.size(); j++) {
         sum += nums[j];
         if(sum == K) {
            maxLen = max(maxLen, j-i+1);
         }
         else if(sum > K) {
            break;
         }
      }
   }

   return maxLen;
} */

// (both +ve & -ve)
// # Optimal - TC: O(n) & SC: O(1)
int findLengthOfSubArray(vector<int> nums, int K) {
   unordered_map<int,int> pfSum;
   int curr_sum = 0;
   int maxLen = 0;
   
   pfSum[0] = -1; // Base case - what if single element & is 0

   for(int i = 0; i < nums.size(); i++) {
      curr_sum += nums[i];

      if(pfSum.find(curr_sum - K) != pfSum.end()) {
         maxLen = max(maxLen, i - pfSum[curr_sum - K]);
      }

      if(pfSum.find(curr_sum) == pfSum.end()) {
         pfSum[curr_sum] = i;
      }
   }

   return maxLen;
}

int main() {
   vector<int> nums = {3}; //{0, 1, -1, 1, 3};
   int K = 3;
   cout << findLengthOfSubArray(nums, K) << endl;

   return 0;
}