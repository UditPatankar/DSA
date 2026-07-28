#include <bits/stdc++.h>
using namespace std;

// ## Remove duplicates from sorted array
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

// Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

// The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

// #Brute Force : O(n log n + n)
/* int removeDuplicates(vector<int> &nums, int n) {
   set<int> st;
   for(int i = 0; i < n; i++) {
      st.insert(nums[i]); // O(log n)
   }
   
   int i = 0;
   for(auto x : st) {
      nums[i] = x;
      i++;
   }
   return i;
} */


// #Optimal : O(n)
int removeDuplicates(vector<int> &nums, int n) {
   int p1 = 0; // last unique element found

   for(int p2 = 1; p2 < n; p2++) {
      if(nums[p2] != nums[p1]) {
         p1++;
         nums[p1] = nums[p2];
      }
   }
   
   return p1 + 1;
}

int main() {
   vector<int> nums = {1, 2, 2, 3, 3, 3};
   cout << removeDuplicates(nums, nums.size()) << endl;

   for(auto x : nums) {
      cout << x << " ";
   }

   return 0;
}

