#include <bits/stdc++.h>
using namespace std;
/* 
Check if Array Is Sorted
Given an array, return true if sorted in non-decreasing order, false otherwise.
Input: nums = {1, 2, 2, 4, 5} → expected: true
Input: nums = {1, 3, 2, 4} → expected: false
 */
bool checkSorted(vector<int> &nums) {
   if(nums.size() < 2) return true;
   for(int i = 1; i < nums.size(); i++) {
      if(nums[i] < nums[i-1]) {
         return false;
      }
   }
   return true;
}

int main() {
   vector<int> nums = {1, 2, 2, 4, 5};
   bool isSorted = checkSorted(nums);
   cout << isSorted << endl;
   return 0;
}