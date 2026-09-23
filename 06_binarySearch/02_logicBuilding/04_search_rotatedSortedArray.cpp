#include <bits/stdc++.h>
using namespace std;
/* 
Given an integer array with "uniques elements", & an target
the array us rotated & sorted.
find the target & return it's index, if not found return -1
*/

// Algo: 
// 1. Divide the search space, [low, mid, high]
// 2. if: target if on mid, return mid
// if left is sorted- 
   // target in range, search space = left
   // not in range, search space = right
// else right is sorted-
   // in range, search space = right
   // not in range, search space = left

// # TC O(log n)
int search(const vector<int> &nums, int target) {
   int n = nums.size();
   int low = 0;
   int high = n-1;

   while(low <= high) {
      // 1. Divide the search space, [low, mid, high]
      int mid = low + ((high-low) / 2);

      // 2. if: target if on mid, return mid
      if(nums[mid] == target) return mid; 
      
      // if left is sorted-
      // target in range, search space = left
      // not in range, search space = right
      else if(nums[low] <= nums[mid]) {
         if(nums[low] <= target && target < nums[mid]) high = mid-1;  
         else low = mid+1;  
      }
      // else right is sorted-
      // in range, search space = right
      // not in range, search space = left
      else {
         if(nums[mid] < target && target <= nums[high]) low = mid+1; 
         else high = mid-1;  
      }
   }
   return -1;
}
int main() {
   vector<int> nums = {7,8,9,1,2,3,4,5,6};
   int target = 4;
   int result = search(nums, target);
   cout << "The index for the given target is:" << result << endl;
   return 0;
}