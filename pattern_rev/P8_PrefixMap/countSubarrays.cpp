#include <bits/stdc++.h>
using namespace std;
/* 
Count Subarrays with Sum K
Given an array, count the number of subarrays whose sum equals K.
nums = {1, -1, 0, 2, 3, -2, 4}; K = 3;
*/
int countSubarrays(const vector<int> &nums, int k) {
   unordered_map<int, int> prefixMap; 
   int currentSum = 0;
   int count = 0;  
   prefixMap[0] = 1; // since, at this point currentSum is 0

   for(int i = 0; i < nums.size(); i++) {
      currentSum += nums[i];
      
      int targetSum = currentSum - k;
      
      if(prefixMap.find(targetSum) != prefixMap.end()) {
         count += prefixMap[targetSum];
         // suppose prefixMap[targetSum] = x it means there are total x starts that ends at this index which gives sum k
      }

      prefixMap[currentSum]++;
   }
   return count;
}
int main() {
   vector<int> nums = {1, -1, 0, 2, 3, -2, 4};
   int K = 3;
   int ans = countSubarrays(nums, K);
   cout << ans << endl;
   return 0;
}