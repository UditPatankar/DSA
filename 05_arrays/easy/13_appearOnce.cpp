#include <bits/stdc++.h>
using namespace std;

// Given an array where each number appears twice except one number that appears only once, return that

// # Brute Force - TC: O(n^2) & SC: O(1)
// int findNumber(vector<int> &nums) {
//    for(int i = 0; i < nums.size(); i++) {
//       int count = 0;

//       for(int j = 0; j < nums.size(); j++) {
//          if(nums[i] == nums[j]) {
//             count++;
//          }
//       }
//       if(count == 1) return nums[i];
//    }
//    return -1;
// } 

// # Better - TC: O(n log n) & SC: O(1)
/* int findNumber(vector<int> &nums) {
   sort(nums.begin(), nums.end());

   int single = 0;
   for(int i = 0; i < nums.size(); i += 2) {
      if(i == nums.size() -1) {
         single = nums[i];
         break;
      }
      else if (nums[i] != nums[i+1]) {
         single = nums[i];
         break;
      }
   }

   return single;
} */

// # Better/Optimized - TC: O(n) & SC: O(u), u is no. of unique elements
/* int findNumber(vector<int> &nums) {
   unordered_map<int, int> hMap;

   for(auto x : nums) {
      hMap[x]++;
   }

   for(auto entry : hMap) {
      if(entry.second == 1) return entry.first;
   }

   return -1;
} */

// # Optimal - TC: O(n) & SC: O(1) 
int findNumber(vector<int> &nums) {
   int xorSum = 0;
   for(auto x : nums) {
      xorSum ^= x;
   }

   return xorSum;
}

int main() {
   vector<int> nums = {3, 2, 3, 2, 6, 4, 5, 6 ,7, 4, 7};
   cout << findNumber(nums) << endl;

   return 0;
}