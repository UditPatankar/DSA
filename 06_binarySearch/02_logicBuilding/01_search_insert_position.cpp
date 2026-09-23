#include <bits/stdc++.h>
using namespace std;
/* 
Search Insert Position
For the given sorted array, & target, return the index of target if found,
else return the index where target would be if was inserted in sorted order
*/
int findPosition(const vector<int> &nums, int target) {
   // so you need to find the first values that's either equal to or greater than target
   // ? >= target : lower bound
   int n = nums.size();
   int position = n;
   int low = 0; int high = n-1;

   while(low <= high) {
      int mid = low + ((high-low) / 2);
      if(nums[mid] >= target) {
         position = mid;
         high = mid-1;
      }
      else low = mid+1;
   }
   return position;
}

int main() {
   vector<int> nums = {1,2,3,5,6};
   int target = 4;
   cout << "Correct Position: " << findPosition(nums, target) << endl;
   return 0;
}