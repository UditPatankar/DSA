#include <bits/stdc++.h>
using namespace std;

// Longest Subarray with sum 0

// # Brute Force - TC: O(N^2) & SC: O(1)
/* vector<int> longestSubarr(vector<int> &nums) {
   int maxLen = 0;
   int start = 0;
   int end = 0;

   for(int i = 0; i < nums.size(); i++) {
      int sum = 0;
      for(int j = i; j < nums.size(); j++) {
         sum += nums[j];

         if(sum == 0) {
            if(maxLen < j-i+1) {
               maxLen = j-i+1;
               start = i;
               end = j;
            }
         }
      }
   }

   vector<int> result(nums.begin()+start, nums.begin()+end+1);
   return result;
} */

// # Optimal - TC: O(N) & SC: O(N)
vector<int> longestSubarr(vector<int> &nums) {
   unordered_map<int, int> mp;
   int maxLen = 0;
   int start = 0;
   int end = 0;

   int pfSum = 0;
   mp[0] = -1;

   for(int i = 0; i < nums.size(); i++) {
      pfSum += nums[i];

      if(mp.find(pfSum) != mp.end()) {
         if(maxLen < i-mp[pfSum]) {
            maxLen = i-mp[pfSum];
            start = mp[pfSum] + 1;
            end = i;
         }
      }

      if(mp.find(pfSum) == mp.end()) {
         mp[pfSum] = i;
      }
   }
   vector<int> result(nums.begin()+start, nums.begin()+end+1);
   return result;
}

int main() {
   vector<int> nums = {9, -3, 3, -1, 6, -5};
   vector<int> result = longestSubarr(nums);

   for(auto x : result) {
      cout << x << " ";
   }

   return 0;
}