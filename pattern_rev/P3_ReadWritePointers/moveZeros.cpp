#include <bits/stdc++.h>
using namespace std;
/* 
Move Zeroes to End
Move all zeroes to the end, maintaining relative order of non-zero elements, in-place.
Input: nums = {0, 0, 0, 1, 0, 3, 12} → expected: {1,3,12,0,0,0,0}
Edge case: nums = {0, 0, 0} → expected: {0,0,0}
*/
void moveZeros(vector<int> &nums) {
   // find the 1st 0
   int write = 0;
   for(int i = 0; i < nums.size(); i++) {
      if(nums[i] == 0) { write = i; break; }
   }
   for(int read = write+1; read < nums.size(); read++) {
      if(nums[read] != 0) {
         swap(nums[write++], nums[read]);
      }
   }
}

int main() {
   vector<int> nums = {0, 0, 0, 1, 0, 3, 12};
   moveZeros(nums);
   for(auto x : nums) {
      cout << x << " ";
   }
   return 0;
}