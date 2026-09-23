#include <bits/stdc++.h>
using namespace std;
/* 
For an given sorted array return the index of th e lower bound of x. 
Means return the index of the first element that is >= x
if there is no lower bound then return the size of the array
*/

// # Brute Force: TC O(n)
/* int findLB(const vector<int> &nums, int x) {
   for(int i = 0; i < nums.size(); i++) {
      if(nums[i] >= x) return i;
   }
   return nums.size();
} */

/* int findUB(const vector<int> &nums, int x) {
   for(int i = 0; i < nums.size(); i++) {
      if(nums[i] > x) return i;
   }
   return nums.size();
} */

// # Optimal: TC O(log n)
int findLB(const vector<int> &nums, int x) {
   int n = nums.size();
   int ans = n;
   int low = 0;
   int high = n-1;

   // perform binary search:
   while(low <= high) {
      int mid = low + ((high-low) / 2);
      // can be your ans, search on left for smaller index
      if(nums[mid] >= x) {
         ans = mid;
         high = mid-1;
      }
      // it's smaller than x, search on right
      else low = mid+1;
   }
   return ans;
}

int findUB(const vector<int> &nums, int x) {
   int n = nums.size();
   int ans = n;
   int low = 0; int high = n-1;

   while(low <= high) {
      int mid = low + ((high-low) / 2);
      // can be you ans, look on left for smaller index
      if(nums[mid] > x) {
         ans = mid;
         high = mid-1;
      }
      // it's smaller than x, look on right for larger element
      else low = mid+1;
   } 
   return ans;
}

int main() {
   vector<int> nums = {1,2,3,3,5,8,8,10,10,11,11,12};
   int x = 10;
   cout << "Index of lower bound of 10: " << findLB(nums, x) << endl;
   cout << "Index of uppwer bound of 10: " << findUB(nums, x) << endl;
   return 0;
}