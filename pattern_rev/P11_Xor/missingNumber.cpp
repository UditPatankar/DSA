#include <bits/stdc++.h>
using namespace std;
/* 
Missing Number
Given n distinct numbers from range [0,n], find the missing one.
Input: nums = {3, 0, 1} → expected: 2
Input: nums = {0, 1} → expected: 2
*/
int findMissing(vector<int> &nums) {
   int xorSum = 0;
   for(int i = 0; i < nums.size(); i++) {
      xorSum ^= nums[i];
      xorSum ^= i;
   }
   xorSum ^= nums.size();
   return xorSum;
}
int main() {
   vector<int> nums = {0, 1};
   int missing = findMissing(nums);
   cout << missing << endl;
   return 0;
}