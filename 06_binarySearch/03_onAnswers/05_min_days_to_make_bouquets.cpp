#include <bits/stdc++.h>
using namespace std;

/*
Problem: Minimum Days to Make m Bouquets (LeetCode 1482)

Goal:
Find the minimum number of days needed to make 'm' bouquets.
To make 1 bouquet, we need 'k' ADJACENT flowers that have already bloomed.

Key Ideas:
- Minimum possible days (low) = min element in array (first flower blooms).
- Maximum possible days (high) = max element in array (all flowers bloomed).
- Use Binary Search in range [min, max] to find the smallest valid day.
*/

// TC: O(2N + N * log (Mx-Mn))

// Helper function to find the minimum element in the array
int minEl(const vector<int> &nums) {
   int mini = INT_MAX;
   for (int i = 0; i < nums.size(); i++) {
      mini = min(nums[i], mini);
   }
   return mini;
}

// Helper function to find the maximum element in the array
int maxEl(const vector<int> &nums) {
   int maxi = INT_MIN;
   for (int i = 0; i < nums.size(); i++) {
      maxi = max(nums[i], maxi);
   }
   return maxi;
}

// Helper function to check if we can form at least 'm' bouquets on 'day'
int isPossible(const vector<int> &nums, int day, int m, int k) {
   int counter = 0;  // Count of consecutive bloomed flowers
   int bouquets = 0; // Total bouquets formed

   for (int i = 0; i < nums.size(); i++) {
      // If the flower has bloomed by this day
      if (nums[i] <= day) {
         counter++;
      } 
      // Streak broken: count complete bouquets from the streak and reset
      else {
         bouquets += (counter / k);
         counter = 0;
      }
   }

   // Count any remaining bouquets from the last streak
   bouquets += (counter / k);

   // Return 1 if we can form at least 'm' bouquets, else 0
   return bouquets >= m ? 1 : 0;
}

int minDays(const vector<int> &nums, int m, int k) {
   int n = nums.size();

   // Impossible case: Not enough total flowers to form 'm' bouquets of size 'k'
   // Cast to long long to prevent integer overflow
   if (n < (long long)m * k) return -1;

   // Search space range: [min(bloomDay), max(bloomDay)]
   int low = minEl(nums);
   int high = maxEl(nums);
   int ans = -1;

   // Binary Search for the minimum days
   while (low <= high) {
      int mid = low + ((high - low) / 2); // Candidate day

      // If it's possible to make 'm' bouquets on 'mid' day
      if (isPossible(nums, mid, m, k) == 1) {
         ans = mid;        // Save 'mid' as a valid candidate
         high = mid - 1;   // Try to find a smaller valid day on the left
      } 
      else {
         low = mid + 1;    // Not enough bouquets, need more days (search right)
      }
   }

   return ans;
}

int main() {
   vector<int> days = {7, 7, 7, 7, 13, 11, 12, 7};
   int m = 2;
   int k = 3;

   int ans = minDays(days, m, k);
   cout << "Minimum days to make " << m << " bouquets: " << ans << endl; 

   return 0;
}