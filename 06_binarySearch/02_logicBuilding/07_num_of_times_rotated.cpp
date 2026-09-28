#include <bits/stdc++.h>
using namespace std;

/* 
Given an array of unique integers that was originally sorted in ascending order and 
then rotated a certain number of times to the right, 
find the total number of times the array was rotated.
*/

// Algo (Min Approach):
// The rotation count is simply equal to the INDEX of the MINIMUM element.
// 1. Divide the search space using Binary Search.
// 2. If the current search space is already completely sorted (nums[low] <= nums[high]),
//    the minimum element is at 'low'. Update mini/minIndex and break.
// 3. Otherwise, identify which half is sorted:
//    - If left side is sorted (nums[low] <= nums[mid]), nums[low] is the minimum in this range.
//      Save it and move search space to the unsorted right half (low = mid + 1).
//    - If right side is sorted, nums[mid] is the minimum in this range.
//      Save it and move search space to the unsorted left half (high = mid - 1).

int findRotationCount(const vector<int> &nums) {
   int n = nums.size();
   int low = 0;
   int high = n - 1;
   int mini = INT_MAX; 
   int minIndex = -1;

   while (low <= high) {
      // If the current search space is already fully sorted
      if (nums[low] <= nums[high]) {
         if (nums[low] < mini) {
            mini = nums[low];
            minIndex = low;
         }
         break;
      }

      int mid = low + ((high - low) / 2);

      // Identify the sorted part & grab the mini & minIndex from it
      if (nums[low] <= nums[mid]) {  
         // Left side is sorted -> nums[low] is the minimum in this half
         if (nums[low] < mini) {
            mini = nums[low];
            minIndex = low;
         }
         low = mid + 1;  // Move to the unsorted right half
      } 
      else {
         // Right side is sorted -> nums[mid] is the minimum in this half
         if (nums[mid] < mini) {
            mini = nums[mid];
            minIndex = mid;
         }
         high = mid - 1; // Move to the unsorted left half
      }
   }

   // The index of the minimum element directly represents the rotation count
   return minIndex;
}

int main() {
   vector<int> nums = {4, 5, 6, 7, 8, 1, 2, 3};
   int result = findRotationCount(nums);
   cout << "Given array's rotation count is: " << result << endl; // Output: 5
   return 0;
}