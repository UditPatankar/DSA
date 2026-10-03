#include <bits/stdc++.h>
using namespace std;

/* 
Problem:
Given a sorted array where every element appears twice except for one unique element,
find and return that single unique element.

Key Pattern / Observation:
- To the LEFT of the single element:
  Pairs start at EVEN indices and end at ODD indices -> (even, odd)
- To the RIGHT of the single element:
  Pairs start at ODD indices and end at EVEN indices -> (odd, even)

We can use Binary Search based on this pattern to cut our search space in half.
*/

int findSingle(const vector<int> &nums) {
   int n = nums.size();

   // --- STEP 1: Handle Edge Cases ---
   // If the array has only 1 element, that must be our target.
   if (n == 1) return nums[0];

   // Check if the very first element is unique.
   if (nums[0] != nums[1]) return nums[0];

   // Check if the very last element is unique.
   if (nums[n-1] != nums[n-2]) return nums[n-1];


   // --- STEP 2: Define Search Space ---
   // Since we already checked index 0 and index (n-1), 
   // we can safely search between index 1 and index (n-2).
   int low = 1;
   int high = n - 2;


   // --- STEP 3: Binary Search ---
   while (low <= high) {
      int mid = low + ((high - low) / 2);

      // Check if mid itself is the single unique element
      // (It is not equal to its left neighbor AND not equal to its right neighbor)
      if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
         return nums[mid];
      }

      // Check if we are currently standing in the LEFT half:
      // Pattern for left half: (even index == next) OR (odd index == previous)
      if ((mid % 2 == 0 && nums[mid] == nums[mid+1]) || 
          (mid % 2 != 0 && nums[mid] == nums[mid-1])) {
         
         // Target is further to the right, so eliminate the left half
         low = mid + 1; 
      } 
      else {
         // Otherwise, we are in the right half:
         // Target is further to the left, so eliminate the right half
         high = mid - 1;
      }
   }

   return -1; // Fallback (should not be reached if input is valid)
}

int main() {
   vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
   int result = findSingle(nums);
   cout << "Single Element: " << result << endl; 
   return 0;
}