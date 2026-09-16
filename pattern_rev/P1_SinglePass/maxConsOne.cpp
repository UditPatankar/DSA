#include <bits/stdc++.h>
using namespace std;
/* 
Maximum Consecutive Ones
Given a binary array, find max consecutive 1s.
Input: nums = {1, 1, 0, 1, 1, 1, 0, 1} → expected: 3
Input: nums = {0, 0, 0} → expected: 0
*/
int maxConsOne(vector<int> &nums) {
   int maxOne = 0;
   int curr = 0;
   for(int i = 0; i < nums.size(); i++) {
      if(nums[i] == 1) curr++;
      else {
         maxOne = max(maxOne, curr);
         curr = 0;
      }
   }
   return max(maxOne, curr);
}

int main() {
   vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1};
   int maxOne = maxConsOne(nums);
   cout << maxOne << endl;
   return 0;
}