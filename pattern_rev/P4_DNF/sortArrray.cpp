#include <bits/stdc++.h>
using namespace std;
/* 
Sort an Array of 0s, 1s, and 2s
Given an array containing only 0s, 1s, and 2s, sort it in a single pass.
Input: nums = {2,0,2,1,1,0}
*/
void sortArray(vector<int> &nums) {
   // 0 to low-1: 0's
   // low to mid-1: 1's
   // high+1 to n-1: 2's
   // mid to high: unsorted   
   int low = 0; int mid = 0;
   int high = nums.size()-1;

   // move until unsorted section is vanished
   while(mid <= high) {
      if(nums[mid] == 0) {
         swap(nums[low], nums[mid]);
         low++; mid++;
      }
      else if(nums[mid] == 1) mid++;
      else swap(nums[mid], nums[high--]); 
   }
}
int main() {
   vector<int> nums = {2,0,2,1,1,0};
   sortArray(nums);
   for(auto x : nums) {
      cout << x << " ";
   }
   return 0;
}