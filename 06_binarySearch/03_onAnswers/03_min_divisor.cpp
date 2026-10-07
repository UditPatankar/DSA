#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find the Smallest Divisor Given a Threshold (LeetCode 1283)

Goal:
Find the smallest divisor such that the sum of ceil(nums[i] / divisor) <= threshold (limit).

Key Ideas:
- Minimum possible divisor (low) = 1.
- Maximum possible divisor (high) = max(nums).
- Use Binary Search in range [1, max(nums)].
- Integer Ceiling Formula: ceil(A / B) == (A + B - 1) / B.
*/

// Helper function to find the maximum element in the array
int maxEl(const vector<int> &nums) {
   int maxi = INT_MIN;
   for (int i = 0; i < nums.size(); i++) {
      maxi = max(nums[i], maxi);
   }
   return maxi;
}

int minDivisor(const vector<int> &nums, int limit) {
   int n = nums.size();
   
   // If the number of elements exceeds limit, even a divisor of infinity 
   // gives sum = n * 1 = n, which would still exceed limit.
   if (n > limit) return -1;

   int low = 1;
   int high = maxEl(nums);
   int ans = -1;
   
   while (low <= high) {
      int mid = low + ((high - low) / 2); // Candidate divisor
      
      // Use long long to avoid potential integer overflow during summation
      long long sum = 0; 
      
      for (int i = 0; i < nums.size(); i++) {
         // Ceil division using integer arithmetic
         sum += (nums[i] + mid - 1) / mid;
      }
      
      // If total sum is within the allowed limit
      if (sum <= limit) {
         ans = mid;        // Save 'mid' as a valid candidate
         high = mid - 1;   // Search for a smaller divisor on the left
      } 
      else {
         low = mid + 1;    // Divisor is too small (sum is too high), search right
      }
   }
   
   return ans;
}

int main() {
   vector<int> nums = {1, 2, 3, 4, 5};
   int limit = 8;
   
   int ans = minDivisor(nums, limit);
   cout << "The minimum divisor is: " << ans << endl; 
   return 0;
}