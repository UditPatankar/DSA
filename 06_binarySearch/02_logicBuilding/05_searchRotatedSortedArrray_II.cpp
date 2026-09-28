#include <bits/stdc++.h>
using namespace std;
/* 
Given an integer array (duplicates present) & an target
the array us rotated & sorted.
if the target is present return true, else false
*/

// Algo: 
// 1. Divide the search space, [low, mid, high]
// 2. if: target if on mid, return mid
// 3. edge case: only now you cannot decide which part is sorted (a[low] == a[mid] == a[high]) - 
   // 3(l) ,3,3,1,2, 3(m) ,3,3,3,3, 3(h)
   // since a[mid] != target, we can shrink the space -> low++, high-- & continue until
   // 1(l) ,2, 3(m) ,3, 3(h)

// 4. now you can find the sorted part
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
      if(nums[mid] == target) return true; 

      // 3. edge case - we shrink the space
      else if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
         low++; high--;
         continue;
      }
      
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
   return false;
}
int main() {
   vector<int> nums = {3,3,3,1,2,3,3,3,3,3,3};
   int target = 1;
   int result = search(nums, target);
   cout << "Is the target present:" << result << endl;
   return 0;
}