#include <bits/stdc++.h>
using namespace std;
/* 
Longest Subarray with Sum K (positives only)
Given an array of positive integers and an integer K, find the length of the longest subarray whose sum equals K.
Input: nums = {2,3,5,1,9}, K = 8
*/
int findLongestSubarray(vector<int> &nums, int k) {
   int n = nums.size();
   int l = 0; int r = 0; // ends
   int sum = 0;   // tracker
   int maxLen = 0;   // answer
   
   while(r < n) {
      sum += nums[r];

      while(sum > k && l <= r) {
         sum -= nums[l];
         l++;  // shrink for invalid window
      }

      if(sum == k) {
         maxLen = max(maxLen, r-l+1);  // update answer for valid window
      }

      r++;  // grow r
   }
   return maxLen;
}

int main() {
   vector<int> nums = {10, 5, 2, 7, 1, 9};
   int k = 15;
   cout << findLongestSubarray(nums, k) << endl;
   return 0;
}