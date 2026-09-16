#include <bits/stdc++.h>
using namespace std;
/* 
Left Rotate Array by 1
Rotate the array left by one position in-place.
Input: nums = {1, 2, 3, 4, 5} → expected: {2,3,4,5,1}
*/

void leftRotateByOne(vector<int> &nums) {
   if(nums.size() < 2) return;
   int first = nums[0];
   for(int i = 1; i < nums.size(); i++) {
      nums[i-1] = nums[i];
   }
   nums[nums.size()-1] = first;
}

/* 
Left Rotate Array by D places
Rotate the array left by D positions in-place.
Input: nums = {1, 2, 3, 4, 5, 6, 7}, D = 3 → expected: {4,5,6,7,1,2,3}
Edge case: D = 9 → should behave same as D = 2 (9 % 7 = 2)
*/
void reverseArr(vector<int> &nums, int start, int end) {
   int l = start;
   int r = end-1;
   while(l < r) {
      swap(nums[l++], nums[r--]);
   }
}
void leftRotateByD(vector<int> &nums, int d) {
   int n = nums.size();
   if(n < 2) return;
   d %= n;
   if(d == 0) return;
   reverseArr(nums, 0, d);
   reverseArr(nums, d, n);
   reverseArr(nums, 0, n);
}

int main() {
   vector<int> nums = {1, 2, 3, 4, 5};
   leftRotateByOne(nums);
   for(auto x : nums) {
      cout << x << " ";
   }
   cout << endl;

   vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7};
   leftRotateByD(nums2, 3);
   for(auto x : nums2) {
      cout << x << " ";
   }
   return 0;
}