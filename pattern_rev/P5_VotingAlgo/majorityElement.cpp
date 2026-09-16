#include <bits/stdc++.h>
using namespace std;
/* 
Majority Element
Given an array, find the element that appears more than n/2 times. Assume it always exists.
Input: nums = {2,2,1,1,1,2,2}
*/
int findMajor(vector<int> &nums) {
   int major = nums[0];
   int count = 0;
   for(auto x : nums) {
      if(count == 0) { major = x; count = 1; }  // fresh candidate
      else if(x == major) count++;  // current candidate
      else count--;  // different candidate
   }
   return major;
}
int main() {
   vector<int> nums = {2,2,1,1,1,2,2};
   int major = findMajor(nums);
   cout << major << endl;
   return 0;
}