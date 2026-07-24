#include <bits/stdc++.h>
using namespace std;

// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// just imagine it as an sorted array in circle 1, 2, 3, 4 now even if you start from random element and it's still sorted ex: 3, 4, 1, 2
// -> an array is sorted and rotated only if -
// It has exactly 1 drop and if it does than a[0] > a[last]


bool check(vector<int> &nums) {
   int n = nums.size();
   int drop = 0;

   for(int i = 0; i < n - 1; i++) {
      if(nums[i] > nums[i+1]) {
         drop++;
         if(drop > 1) return false;
      }
   }

   if(drop == 1 && nums[n-1] > nums[0]) return false;
   return true;
}

int main() {
   vector<int> nums = {5, 6, 7, 8, 1, 2, 3, 4};

   cout << check(nums) << endl;
   // T.C = O(n);

   return 0;
}