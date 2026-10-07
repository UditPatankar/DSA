#include <bits/stdc++.h>
using namespace std;

/*
Problem: Koko Eating Bananas (LeetCode 875)

Find the minimum integer eating speed 'k' (bananas per hour) so that 
Koko can eat all bananas in the piles within 'h' hours.

Key Idea:
- Minimum possible speed (low) = 1 banana/hr.
- Maximum required speed (high) = max(piles) bananas/hr.
- Binary search over the speed range [1, max(piles)].
*/

// Helper function to find the maximum element in the piles
int maxEl(const vector<int> &nums) {
   int maxi = INT_MIN;
   for(int i = 0; i < nums.size(); i++) {
      maxi = max(nums[i], maxi);
   }
   return maxi;
}

// Helper function to calculate total hours required at speed 'mid'
long long calculateTotalHours(const vector<int> &nums, int mid) {
   long long totalH = 0;
   for(int i = 0; i < nums.size(); i++) {
      // to avoid floor value
      totalH += ceil(nums[i] + (mid - 1)) / mid; 
   }
   return totalH;
}

int minEatingSpeed(const vector<int> &nums, int h) {
   int k = 0;
   int low = 1; 
   int high = maxEl(nums);

   // Binary search for the minimum valid speed k
   while(low <= high) {
      int mid = low + ((high - low) / 2); // Candidate eating speed
      
      long long totalH = calculateTotalHours(nums, mid);

      // If Koko can finish within 'h' hours at speed 'mid'
      if(totalH <= h) {
         k = mid;         // Save 'mid' as a potential answer
         high = mid - 1;  // Try to find a smaller speed on the left
      }
      else {
         low = mid + 1;   // Speed is too slow, try a larger speed on the right
      }
   }
   return k;
}

int main() {
   vector<int> piles = {30, 11, 23, 4, 20};
   int h = 5;
   int k = minEatingSpeed(piles, h);
   
   cout << "The minimum eating speed is " << k << " per hour" << endl; 
   return 0;
}