#include <bits/stdc++.h>
using namespace std;

// NEXT PERMUTATION
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer
// It means suppose all the permutation of the given integers are placed in the container in an sorted 
// fashion (ascending) then next permutation is the which comes just after the given integers, and if //
// the given integer is last itself then the next will be the first in the container, ex: for 3, 2, 1  
// the next perm will be 1, 2, 3 coz {[1, 2, 3] [1, 3, 2] [2, 1, 3] [2, 3, 1] [3, 1, 2] [3, 2, 1]}

// steps: {2, 1, 5, 4, 3, 0, 0}
   // - find the longest prefix match 
      // (find the break point a[i] < a[i+1]) start from the last : 1
   // - from i+1 to n-1 find a[j] > a[i], 
      // start from the back bcoz since there was no break point till i it means from n-1 to i things are sorted in ascending order : 5, 4, 3, 0, 0
   // - swap them a[j] & a[i] : {2, 3, 5, 4, 1, 0, 0}
      // - *note: the part from n-1 to i+1 is still sorted : 5, 4, 1, 0, 0 
   // - so the next perm for this part will be reverse of this : 0, 0, 1, 4, 5 i.e. {2, 3, 0, 0, 1, 4, 5}

// # Optimal - TC: O(N) & SC: O(1) 
void findNextPermutation(vector<int> &nums) {
   int n = nums.size();
   int ind = -1;

   // find break point
   for(int i = n-2; i >= 0; i--) {
      if(nums[i] < nums[i+1]) {
         ind = i;
         break;
      }
   }

   // if no break point found - means this is the last permutation in the container, just return the 1st one
   if(ind == -1) {
      reverse(nums.begin(), nums.end());
      return;
   }

   // find & swap with greater
   for(int i = n-1; i > ind; i--) {
      if(nums[i] > nums[ind]) {
         swap(nums[i], nums[ind]);
         break;
      }
   }

   // reverse the subarray
   reverse(nums.begin() + ind+1, nums.end());
}

int main() {

   vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
   findNextPermutation(nums);

   for(auto x : nums) {
      cout << x << " ";
   }

   return 0;
}