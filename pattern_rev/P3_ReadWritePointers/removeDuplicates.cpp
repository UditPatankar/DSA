#include <bits/stdc++.h>
using namespace std;
/* 
Remove Duplicates from Sorted Array
Given a sorted array, remove duplicates in-place so each element appears once, return count of unique elements. First k positions must hold the unique values in order.
Input: nums = {1, 1, 2, 2, 2, 3, 4, 4} → expected: return 4, array becomes {1,2,3,4,...}
*/
int removeDuplicates(vector<int> &nums) {
   if(nums.empty()) return 0;
   int write = 0; // last unique item
   for(int read = 1; read < nums.size(); read++) {
      if(nums[read] != nums[write]) {
         write++;
         nums[write] = nums[read];
      }
   }
   return write + 1;
}

int main() {
   vector<int> nums = {1, 1, 2, 2, 2, 3, 4, 4};
   int k = removeDuplicates(nums);
   cout << k << endl;
   for(auto x : nums) {
      cout << x << " ";
   }
   return 0;
}