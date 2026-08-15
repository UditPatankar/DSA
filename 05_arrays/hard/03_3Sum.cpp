#include <bits/stdc++.h>
using namespace std;

// 3 SUM - fidn triplet whose sum = 0
// each triplet must be unique
// each index in a triplet should be unique

// # Brute Force - TC: O(N^3) & SC: O(no. of triplets)
/* vector<vector<int>> findTriplets(vector<int> &nums) {
   int n = nums.size();
   set<vector<int>> st;

   for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
         for(int k = j+1; k < n; k++) {
            if(nums[i] + nums[j] + nums[k] == 0) {
               vector<int> temp = {nums[i], nums[j], nums[k]};
               sort(temp.begin(), temp.end());
               st.insert(temp);
            }
         }
      }
   }

   vector<vector<int>> result(st.begin(), st.end());
   return result;
} */

// # Optimal - TC: O(N^2) & SC: O(1)
vector<vector<int>> findTriplets(vector<int> &nums) {
   vector<vector<int>> result;
   int n = nums.size();

   sort(nums.begin(), nums.end());

   for(int i = 0; i < n-2; i++) {
      
      // skip duplicate for 1st element
      if(i > 0 && nums[i] == nums[i-1]) continue;

      int left = i+1;
      int right = n-1;

      while(left < right) {
         int sum = nums[i] + nums[left] + nums[right];
         if(sum == 0) {
            result.push_back({nums[i], nums[left], nums[right]});

            // skip duplicates for 2nd & 3rd positions
            while(left < right && nums[left+1] == nums[left]) left++;
            while(left < right && nums[right-1] == nums[right]) right--;
            
            left++;
            right--;
         }
         else if(sum < 0) left++;
         else right--;
      }
   }

   return result;
}

int main() {
   vector<int> nums = {-1, 0, 1, 2, -1, -4};
   vector<vector<int>> triplets = findTriplets(nums);

   for(auto x : triplets) {
      for(auto y : x) {
         cout << y << " ";
      }
      cout << endl;
   }

   return 0;
}