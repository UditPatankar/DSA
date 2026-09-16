#include <bits/stdc++.h>
using namespace std;
/* 
Longest Subarray with Sum K (positive + negative)
Same as above, but the array can contain negative numbers.
Input: nums = {1,2,3,1,1,1,4}, K = 5
*/
int longestSubarray(const vector<int> &nums, int k) {
   unordered_map<int, int> prefix;
   int n = nums.size();
   int maxLen = 0;
   int sum = 0;
   prefix[0] = -1;

   for(int i = 0; i < n; i++) {
      sum += nums[i];
      if(prefix.find(sum-k) != prefix.end()) {
         maxLen = max(maxLen, i-prefix[sum-k]);
      }
      if(prefix.find(sum) == prefix.end()) {
         prefix[sum] = i;
      }
   }
   return maxLen;
}
int main() {
   vector<int> nums = {1,2,3,-2,2,-1,1,1,1,1,4};
   int k = 5;
   cout << longestSubarray(nums, k);
   return 0;
}