#include <bits/stdc++.h>
using namespace std;
/* 
3 SUM - Find the triplet whose sum = 0
Triplet should be unique, index should be unique 
[-1, 0, 1] and [0, 1, -1] are not unique
*/
vector<vector<int>> findTriplets(vector<int> &nums) {
   if(nums.empty()) return {};
   int n = nums.size();
   vector<vector<int>> result;
   sort(nums.begin(), nums.end());

   for(int i = 0; i < n-2; i++) {
      // skip duplicate for 1st value of triplet
      if(i > 0 && nums[i] == nums[i-1]) continue;
      int l = i+1;
      int r = n-1;

      while(l < r) {
         int sum = nums[i] + nums[l] + nums[r]; 
         if(sum == 0) {
            result.push_back({nums[i], nums[l], nums[r]});

            // skip duplicates for 2nd & 3rd value of triplet
            while(l < r && nums[l+1] == nums[l]) l++;
            while(r > l && nums[r-1] == nums[r]) r--;
            l++; r--;
         }
         else if(sum < 0) l++;
         else r--;
      }
   }

   return result;
}
int main() {
   vector<int> nums = {-1, 0, 1, 2, -1, -4};
   vector<vector<int>> result = findTriplets(nums);
   for(auto x : result) {
      for(auto y : x) {
         cout << y << " ";
      }
      cout << endl;
   }
   return 0;
}