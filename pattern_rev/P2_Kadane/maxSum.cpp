#include <bits/stdc++.h>
using namespace std;
/* 
. Maximum Subarray Sum (Kadane's Algorithm)
Given an array, find the contiguous subarray with the largest sum.
Input: nums = {-2,1,-3,4,-1,2,1,-5,4}
*/

vector<int> maxSubarray(vector<int> &nums) {
   vector<int> result;   
   
   int maxSum = INT_MIN;
   int sum = 0;
   int s = 0; // track current start
   int start = 0; int end = 0;   // holds max subarray indexes

   for(int i = 0; i < nums.size(); i++) {
      if(sum == 0) s = i;  // new start
      sum += nums[i];   // track sum

      if(sum > maxSum) {   // update max & save index that this max
         maxSum = sum;
         start = s;
         end = i;
      }

      if(sum < 0) sum = 0; // do not carry -ive
   }

   for(int i = start; i <= end; i++) {
      result.push_back(nums[i]);
   }
   return result;
}

int main() {
   vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
   vector<int> result = maxSubarray(nums);
   for(auto x : result) {
      cout << x << " ";
   }
   return 0;
}