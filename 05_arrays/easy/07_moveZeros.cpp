#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// #Brute Force : TC: O(n) & SC: O(n)
/* void moveZeros(vector<int> &nums) {
   int n = nums.size();
   vector<int> temp;

   // copy non-zeros to temp
   for(int i = 0; i < n; i++) {
      if(nums[i] != 0) {
         temp.push_back(nums[i]);
      }
   }

   // put non-zeros at front in nums
   for(int i = 0; i < temp.size(); i++) {
      nums[i] = temp[i];
   }

   // put all the zeros at end in nums
   for(int i = temp.size(); i < n; i++) {
      nums[i] = 0;
   }
} */

// Optimal : TC:O(n) & SC: O(1)
void moveZeros(vector<int> &nums) {
   int n = nums.size();

   int j = -1; // tracks the first zero found
   for(int i = 0; i < n; i++) {
      if(nums[i] == 0) {
         j = i;
         break;
      }
   }

   // return if no zeros were found
   if(j == -1) return;
   
   // find non-zeros after the first zero & keep swapping them
   for(int i = j+1; i < n; i++) {
      if(nums[i] != 0) {
         swap(nums[i], nums[j]);
         j++;
      }
   }
}

int main() {
   vector<int> nums = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
   moveZeros(nums);

   for(auto x : nums) {
      cout << x << " ";
   }

   return 0;
}