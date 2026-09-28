#include <bits/stdc++.h>
using namespace std;
/* 
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
*/

// Algo: 
// 1. Divide the search space, [low, mid, high]
// 2. Identify the sorted part, compare & save the min
// 3. Eliminate the sorted part - update the search space
// 4. Repeat.

// # TC O(log n)
int searchMin(const vector<int> &nums) {
   int n = nums.size();
   int low = 0;
   int high = n-1;
   int mini = INT_MAX;

   while(low <= high) {
      // if the space is already sorted
      if(nums[low] <= nums[high]) {
         mini = min(mini, nums[low]);
         break;
      }

      int mid = low + ((high-low) / 2);
      // if left is sorted, 
      if(nums[low] <= nums[mid]) { // <= coz low & mid could be on same index - already sorted
         mini = min(mini, nums[low]);  // grab the mini 
         low = mid + 1; // & update search space to right (the unsorted part)
      }
      // else right is sorted, 
      else {
         mini = min(mini, nums[mid]);  // grab the mini 
         high = mid - 1;   // & update the search space to left (the unsorted part)
      }
   }

   return mini;
}

int main() {
   vector<int> nums = {7,8,9,10,11,4,5,6};
   int result = searchMin(nums);
   cout << "Minimum value present:" << result << endl;
   return 0;
}