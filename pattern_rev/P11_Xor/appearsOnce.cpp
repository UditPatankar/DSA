#include <bits/stdc++.h>
using namespace std;
/* 
Single Number
Every element appears twice except one — find it. Aim for O(n) time, O(1) space.
Input: nums = {4, 1, 2, 1, 2} → expected: 4
*/
int findTarget(vector<int> &nums) {
   int xorSum = 0;
   for(auto x : nums) {
      xorSum ^= x;
   }
   return xorSum;
}
int main() {
   vector<int> nums = {4, 1, 2, 1, 2};
   cout << findTarget(nums) << endl;
   return 0;
}