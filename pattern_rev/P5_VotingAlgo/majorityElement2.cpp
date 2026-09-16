#include <bits/stdc++.h>
using namespace std;
/* 
Majority Element II
Given an array, find all elements that appear more than n/3 times.
Input: nums = {1,1,1,3,3,2,2,2}
*/
vector<int> majorityELements(vector<int> &nums) {
   int n = nums.size();
   vector<int> result;
   int maj1 = INT_MIN; int maj2 = INT_MIN;
   int c1 = 0; int c2 = 0;

   for(auto x : nums) {
      if(x == maj1) c1++;  // increment
      else if(x == maj2) c2++;   // increment
      else if(c1 == 0) { maj1 = x; c1++; }   // update major1
      else if(c2 == 0) { maj2 = x; c2++; }   // update major2
      else { c1--; c2--; } // decrement
   }

   // verify 
   c1 = 0; c2 = 0;
   for(auto x : nums) {
      if(x == maj1) c1++;
      else if(x == maj2) c2++;
   }
   
   // place only valid major
   if(c1 > floor(n/3)) result.push_back(maj1);
   if(c2 > floor(n/3)) result.push_back(maj2);
   return result;
}
int main() {
   vector<int> nums = {1,1,1,1,3,3,2,2};
   vector<int> result = majorityELements(nums);
   for(auto x : result) {
      cout << x << " ";
   }
   return 0;
}