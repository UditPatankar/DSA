#include <bits/stdc++.h>
using namespace std;

// CONTIGUOUS SUBARRAY -
// find the max length of subarray with equal no. of 0's & 1's

// Optimal - TC: O(N) & SC: O(N)
int findMaxLength(vector<int> nums) {
   unordered_map<int, int> mp;
   int maxLen = 0;
   int sum = 0;
   mp[0] = -1; // base case 
   
   for(int i = 0; i < nums.size(); i++) {
      // treat 0 as -1 & 1 as +1, so they can cancel each other
      sum += (nums[i] == 1) ? 1 : -1; 

      if(mp.find(sum) != mp.end())
         maxLen = max(maxLen, i-mp[sum]);
      
      if(mp.find(sum) == mp.end()) 
         mp[sum] = i;
   }
   return maxLen;
}

int main() {
   vector<int> nums = {0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1};
   int ans = findMaxLength(nums);
   cout << ans;
   return 0;
}