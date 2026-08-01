#include <bits/stdc++.h>
using namespace std;

// MAJORITY ELEMENT - the elements that appears more than n/2 times in an array, assume majority always exist in input array

// # Brute Force - TC: O(N^2) & SC: O(1)
/* int findMajority(vector<int> &nums) {

   for(int i = 0; i < nums.size(); i++) {
      int count = 0;

      for(int j = 0; j < nums.size(); j++) {
         if(nums[j] == nums[i]) count++;
      }
      
      if(count > nums.size()/2) return nums[i];
   }

   return 0;
} */

// # Better - TC: O(N + m) & SC: O(N)
/* int findMajority(vector<int> &nums) {
   unordered_map<int, int> freq;
   int majority = 0;
   int maxi = 0;

   for(auto x : nums) {
      freq[x]++;
   }
   for(auto entry : freq) {
      if(entry.second > maxi) {
         maxi = entry.second;
         majority = entry.first;
      }
   }

   return majority; 
} */

// # Boyer-Moore Voting Algorithm
// # Optimal - TC: O(N) & SC: O(1)
int findMajority(vector<int> &nums) {
   int majority = 0;
   int count = 0;
   
   for(int i = 0; i < nums.size(); i++) {
      if(count == 0) {
         majority = nums[i];
         count++;
      }
      else if(nums[i] == majority) {
         count++;
      }
      else {
         count--;
      }
   }

   return majority;
}


int main() {
   vector<int> nums = {2, 2, 3, 3, 1, 2, 2, 3, 3, 3, 3};
   cout << findMajority(nums) << endl;
   return 0;
}