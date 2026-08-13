#include <bits/stdc++.h>
using namespace std;

// MAJORITY ELEMENT II - appears > floor(n/3)

// # Brute Force - TC: O(n) & SC: O(n)
/* vector<int> findMajII(vector<int> &nums) {
   vector<int> maj;
   unordered_map<int, int> freq;

   for(auto x : nums) {
      freq[x]++;
   }

   for(auto entry : freq) {
      if(entry.second > floor(nums.size()/3)) maj.push_back(entry.first);
   }

   return maj;
} */

// # Optimal - TC: O(N) & SC: O(1) extended voting algorithm
vector<int> findMajII(vector<int> &nums) {
   vector<int> maj;

   int maj1 = INT_MIN, c1 = 0;
   int maj2 = INT_MIN, c2 = 0;

   for(int i = 0; i < nums.size(); i++) {
      if(nums[i] == maj1) c1++;
      else if(nums[i] == maj2) c2++;
      else if(c1 == 0) { maj1 = nums[i]; c1 = 1; }
      else if(c2 == 0) { maj2 = nums[i]; c2 = 1; }
      else { c1--; c2--; }
   }
   
   c1 = 0; c2 = 0;
   for(auto x : nums) {
      if(x == maj1) c1++;
      else if(x == maj2) c2++;
   }

   if(c1 > nums.size()/3) maj.push_back(maj1);
   if(c2 > nums.size()/3) maj.push_back(maj2);
   return maj;
}

int main() {
   vector<int> nums = {2, 3, 1, 1, 2, 1, 3, 2};
   vector<int> maj = findMajII(nums);

   for(auto x : maj) {
      cout << x << " ";
   }

   return 0;
}