#include <bits/stdc++.h>
using namespace std;

/*
Problem: Capacity To Ship Packages Within D Days (LeetCode 1011)

Goal:
Find the minimum ship capacity required to ship all packages in the given order 
within 'days' days.

Key Observations:
- Minimum possible capacity (low) = max(weights). 
  (The ship MUST be able to carry at least the heaviest single package).
- Maximum possible capacity (high) = sum(weights). 
  (Ship carries all packages in 1 single day).
- Range to Binary Search: [max(weights), sum(weights)].
*/

// Helper function to find the heaviest single package
int maxEl(const vector<int> &w) {
   int maxi = INT_MIN;
   for (int i = 0; i < w.size(); i++) {
      maxi = max(w[i], maxi);
   }
   return maxi;
}

// Helper function to find total weight of all packages
int total(const vector<int> &w) {
   int totalWeight = 0;
   for (int i = 0; i < w.size(); i++) {
      totalWeight += w[i];
   }
   return totalWeight;
}

// Helper function to calculate how many days are needed for a given ship capacity
int requiredDays(const vector<int> &w, int cap) {
   int days = 1;  // Start on Day 1
   int load = 0;  // Current weight on the ship for the current day

   for (int i = 0; i < w.size(); i++) {
      // If adding this package exceeds capacity, start a new day
      if (load + w[i] > cap) {
         days++;
         load = w[i]; // Place item onto the ship for the next day
      }
      // Otherwise, keep loading packages on the same day
      else {
         load += w[i];
      }
   }
   return days;
}

int shipWithinDays(const vector<int> &w, int days) {
   // Search space: [heaviest item, total sum of all items]
   int low = maxEl(w);
   int high = total(w);
   
   int ans = high; // Default answer is high (shipping everything in 1 day)

   // Binary Search on Answer Space
   while (low <= high) {
      int mid = low + ((high - low) / 2); // Candidate capacity

      // If 'mid' capacity is enough to ship within allowed 'days'
      if (requiredDays(w, mid) <= days) {
         ans = mid;        // Save 'mid' as a potential answer
         high = mid - 1;   // Try to find a smaller valid capacity on the left
      } 
      else {
         low = mid + 1;    // Capacity is too small (takes too many days), search right
      }
   }
   
   return ans;
}

int main() {
   vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int days = 5;
   
   int ans = shipWithinDays(weights, days);
   cout << "Minimum required capacity: " << ans << endl; // Output: 15
   
   return 0;
}