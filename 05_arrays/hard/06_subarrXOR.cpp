#include <bits/stdc++.h>
using namespace std;

// Count the subarrays with sum XOR as k

// # Brute Force - TC: O(N^2) & SC: O(1)
/* int subarrXOR(vector<int> &nums, int k) {
   int n = nums.size();
   int count = 0;

   for(int i = 0; i < n; i++) {
      int xorSum = 0;
      for(int j = i; j < n; j++) {
         xorSum ^= nums[j];
         if(xorSum == k) count++;
      }
   }
   return count;
} */

// Optimal - TC: O(N) & SC: O(N)
// hint -> a^b = c then a^c = b
int subarrXOR(vector<int> &nums, int k) {
   unordered_map<int, int> mp;   // count the xor
   int count = 0;
   int xorSum = 0;

   mp[0] = 1;

   for(int i = 0; i < nums.size(); i++) {
      xorSum ^= nums[i];

      if(mp.find(xorSum^k) != mp.end()) {
         count += mp[xorSum^k];
      }
      mp[xorSum]++;
   }

   return count;
}

int main() {
   vector<int> nums = {4, 2, 2, 6, 4};
   int count = subarrXOR(nums, 6);

   cout << count << " ";
   return 0;
}