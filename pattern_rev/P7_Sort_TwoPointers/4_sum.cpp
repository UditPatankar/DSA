#include <bits/stdc++.h>
using namespace std;
/* 
Find quadruplets having sum 0
each quadruplet should be unique with unique indices
*/
vector<vector<int>> findQuadruplets(vector<int> &nums) {
   int n = nums.size();
   if(n < 4) return {};
   
   vector<vector<int>> result;
   sort(nums.begin(), nums.end());
   
   for(int i = 0; i < n-3; i++) {
      if(i > 0 && nums[i] == nums[i-1]) continue;
      for(int j = i+1; j < n-2; j++) {
         if(j > i+1 && nums[j] == nums[j-1]) continue;
         int l = j+1;
         int r = n-1;

         while(l < r) {
            int sum = nums[i] + nums[j] + nums[l] + nums[r];
            if(sum == 0) {
               result.push_back({nums[i], nums[j], nums[l], nums[r]});

               if(l < r && nums[l+1] == nums[l]) l++;
               if(r > l && nums[r-1] == nums[r]) r--;

               l++;
               r--;
            }
            else if(sum < 0) l++;
            else r--;
         }
      }
   }
   return result;
}
int main() {
   vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
   vector<vector<int>> ans = findQuadruplets(nums);
   for(auto x : ans) {
      for(auto y : x) {
         cout << y << " ";
      }
      cout << endl;
   } 
   return 0;
}