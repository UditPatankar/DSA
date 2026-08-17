#include <bits/stdc++.h>
using namespace std;

// Find the missing & repeating item
// given array contains [1 to n=size] each apppears exactly once but A appears twice & B is missing
// return array: [A, B] not [B, A]

// # Brute Force - TC: O(n log n) & SC: O(1)
/* vector<int> missingAndRepeating(vector<int> &nums) {
   int n = nums.size();
   sort(nums.begin(), nums.end());

   int repeating = 0;
   int missing = 0;

   if(nums[0] != 1) missing = 1;
   else if(nums[n-1] != n) missing = n;

   for(int i = 0; i < n-1; i++) {
      // look for repeating 
      if(nums[i+1] == nums[i]) repeating = nums[i];

      // look for missing
      if(nums[i+1] == nums[i]+2) missing = nums[i] + 1;
   }

   return {repeating, missing};
} */

// # Better - TC: O(2n) & SC: O(n)
/* vector<int> missingAndRepeating(vector<int> &nums) {
   int n = nums.size();
   unordered_map<int, int> mp;

   for(auto x : nums) {
      mp[x]++;
   }

   int repeating = -1; int missing = -1;
   for(int i = 1 ; i <= n; i++) {
      if(mp[i] == 0) missing = i;
      if(mp[i] == 2) repeating = i;

      if(repeating != -1 && missing != -1) break;
   }

   return {repeating, missing};
} */

// # Optimal - TC: O(N) & SC: O(1)
vector<int> missingAndRepeating(vector<int> &nums) {
   int n = nums.size();
   
   // x = repeating, y = missing
   // x - y = S - SN
   // (x - y)(x + y) = Sq - SqN
   // x + y = (Sq - SqN) / (x - y)

   long long S = 0; long long Sq = 0;     // sum & sq sum of array
   long long SN = (n*(n+1)) / 2;          // sum of n numbers
   long long SqN = (n*(n+1)*(2*n+1)) / 6; // sum of sq of n numbers
   
   for(auto x : nums) {
      S += x;
      Sq += (long long)x*x;
   }

   long long exp1 = S - SN;
   long long exp2 = (Sq - SqN) / exp1;

   long long x = (exp1 + exp2) / 2;
   long long y = x - exp1;

   return { (int)x, (int)y };
}

int main() {
   vector<int> nums = {3, 6, 4, 2, 2, 1};
   vector<int> result = missingAndRepeating(nums);

   cout << result[0] << " " << result[1];

   return 0;
}