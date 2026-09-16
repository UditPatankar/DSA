#include <bits/stdc++.h>
using namespace std;
/* 
   largest subarray with sum 0
*/
vector<int> findLarestSubarray(vector<int> &nums) {
   unordered_map<int, int> pMap;
   int start = 0; int end = 0;
   int maxLen = 0;
   int sum = 0;
   pMap[0] = -1; 

   for(int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      // if the prefix sum appeared before,
      // means elements b/w these indexes has sum 0
      if(pMap.find(sum) != pMap.end()) {
         if(maxLen < i-pMap[sum]) {
            maxLen = i-pMap[sum];
            start = pMap[sum] + 1;
            end = i;
         }
      }

      // store only 1st occurence of  prefix sum, to get longest subarray
      if(pMap.find(sum) == pMap.end()) {
         pMap[sum] = i;
      }
   }

   vector<int> ans(nums.begin()+start, nums.begin()+end+1);
   return ans;
}
int main() {
   vector<int> nums = {9, -3, 3, -1, 6, -5};
   vector<int> ans = findLarestSubarray(nums);
   for(auto x : ans) {
      cout << x << " ";
   } 
   return 0;
}