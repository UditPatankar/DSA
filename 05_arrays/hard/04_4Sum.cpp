#include <bits/stdc++.h>
using namespace std;

// 4 SUM - find all the quadruplets whose sum is target
// all quadruplet must be unique 
// with unique indices

// # Optimal - TC: O(N^3) & SC: O(1)
vector<vector<int>> fourSum(vector<int> &nums, long long target) {
   vector<vector<int>> result;
   int n = nums.size();

   sort(nums.begin(), nums.end());

   for(int i = 0; i < n-3; i++) {
      
      // skip duplicates for 1st position
      if(i > 0 && nums[i] == nums[i-1]) continue;
      
      for(int j = i+1; j < n-2; j++) {
         // skip duplicates for 2nd position
         if(j > i+1 && nums[j] == nums[j-1]) continue;

         int l = j+1; 
         int r = n-1;

         while(l < r) {
            long long sum = (long long) nums[i] + nums[j] + nums[l] + nums[r]; // addition happens in int, casting first operand will automatically cast rest of the addition to long long
            if(sum == target) {
               result.push_back({nums[i], nums[j], nums[l], nums[r]});

               // skip duplicates for 3rd & 4th position
               while(l < r && nums[l+1] == nums[l]) l++;
               while(l < r && nums[r-1] == nums[r]) r--;

               l++; r--;
            }
            else if(sum < target) l++;
            else r--;
         }
      }
   }
   return result;
}

int main() {
   vector<int> nums = {1000000000, 1000000000, 1000000000, 1000000000}; // {-3, -2, -1, 0, 0, 1, 2, 3}; 
   long long target = 4000000000;

   vector<vector<int>> result = fourSum(nums, target);

   for(auto x : result) {
      for(auto y : x) {
         cout << y << " ";
      }
      cout << endl;
   }

   return 0;
}