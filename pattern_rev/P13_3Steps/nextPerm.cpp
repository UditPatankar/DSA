#include <bits/stdc++.h>
using namespace std;
/* 
Next Permutation
Given an array, rearrange it into the next lexicographically greater permutation. If none exists, 
return the lowest possible order.
nums = {2, 1, 5, 4, 3, 0, 0}
*/
void findNextPermutation(vector<int> &nums) {
   int n = nums.size();
   int dip = -1; 
   // 1. find the dip
   for(int i = n-2; i >= 0; i--) {
      if(nums[i] < nums[i+1]) { dip = i; break; }
   }
   // edge-case: if no dip found - this is the last permutation
   if(dip == -1) { reverse(nums.begin(), nums.end()); return; }
   // 2. find number just > nums[dip] & swap
   for(int i = n-1; i > dip; i--) {
      if(nums[i] > nums[dip]) {
         swap(nums[i], nums[dip]);
         break;
      }
   }
   // 3. reverse the part (dip+1, n-1)
   reverse(nums.begin()+dip+1, nums.end());
}
int main() {
   vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
   findNextPermutation(nums);

   for(auto x : nums) {
      cout << x << " ";
   }
   return 0;
}