#include <bits/stdc++.h>
using namespace std;

// Count Subarray sum equals to K - return the no. of subarrays whose sum euqals to K

// # Brute Force - TC: O(N^2) & SC: O(1)
/* int countSubarray(vector<int> &nums, int k) {
   int count = 0;

   for(int i = 0; i < nums.size(); i++) {
      int sum = 0;
      for(int j = i; j < nums.size(); j++) {
         sum += nums[j];
         if(sum == k) {
            count++;
         }
      }
   }
   return count;
}
 */

// # Better/Optimal - TC: O(N) & SC: O(1)
int countSubarray(vector<int> &nums, int k) {
   unordered_map<int, int> mp;
   mp[0] = 1;
   int pf = 0;
   int count = 0;

   for(int i = 0; i < nums.size(); i++) {
      pf += nums[i];

      int rem = pf - k;
      if(mp.find(rem) != mp.end()) {
         count += mp[rem];
      }

      mp[pf]++;
   }

   return count;
}


int main() {   
   vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
   cout << countSubarray(nums, 3);

   return 0;
}