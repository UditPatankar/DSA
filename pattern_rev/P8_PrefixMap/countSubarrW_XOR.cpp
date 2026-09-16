#include <bits/stdc++.h>
using namespace std;

// Count the subarrays with sum XOR as k
// hint -> a^b = c then a^c = b
//             'prev'  'k'     'x'  => prev^k = x; prev = x^k
// <-------------|--------------|>
int subarrXOR(vector<int> &nums, int k) {
   unordered_map<int, int> mp;   // count the xor
   int subArrayCount = 0;
   int x = 0;

   mp[0] = 1; // since, we have one xor 0 at this point 

   for(int i = 0; i < nums.size(); i++) {
      x ^= nums[i];
      int prev = x^k;
      if(mp.find(prev) != mp.end()) {
         subArrayCount += mp[prev];
      }
      mp[x]++;
   }
   return subArrayCount;
}

int main() {
   vector<int> nums = {4, 2, 2, 6, 4};
   int count = subarrXOR(nums, 6);

   cout << count << " ";
   return 0;
}