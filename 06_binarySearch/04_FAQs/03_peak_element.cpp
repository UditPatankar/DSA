#include <bits/stdc++.h>
using namespace std;

/* 
Problem:
A peak element is an element that is strictly greater than both its left and right neighbors.
(For boundary elements, we only compare with the single available neighbor).

Key Logic:
- If an element is on an INCREASING slope (nums[mid] < nums[mid + 1]), a peak MUST exist on the RIGHT side.
- If an element is on a DECREASING slope (nums[mid] > nums[mid + 1]), a peak MUST exist on the LEFT side.
- This allows us to use Binary Search in O(log N) time.
*/

int findPeak(const vector<int> &nums) {
   int n = nums.size();

   // --- STEP 1: Handle Edge Cases ---
   // 1. Array has only 1 element -> It is automatically a peak.
   if (n == 1) return nums[0];

   // 2. First element is greater than second element -> First element is a peak.
   if (nums[0] > nums[1]) return nums[0];

   // 3. Last element is greater than second-last element -> Last element is a peak.
   if (nums[n - 1] > nums[n - 2]) return nums[n - 1];


   // --- STEP 2: Define Search Space ---
   // Since index 0 and index (n-1) are already checked,
   // we only need to search from index 1 to (n-2).
   int low = 1;
   int high = n - 2;


   // --- STEP 3: Binary Search ---
   while (low <= high) {
      int mid = low + ((high - low) / 2);

      // Check if mid is greater than both its left and right neighbors (Found Peak!)
      if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
         return nums[mid];
      }

      // If mid is smaller than the element on its right, we are on an UPWARD slope.
      // So, at least one peak exists in the RIGHT half.
      if (nums[mid] < nums[mid + 1]) {
         low = mid + 1; // Eliminate left half
      } 
      // Otherwise, we are on a DOWNWARD slope.
      // So, at least one peak exists in the LEFT half.
      else {
         high = mid - 1; // Eliminate right half
      }
   }

   return -1; // Fallback
}

int main() {
   vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
   int result = findPeak(nums);
   cout << "Peak element: " << result << endl; // Output: 6 (or 2)
   return 0;
}