#include <bits/stdc++.h>
using namespace std;
/* 
Given a sorted array nums of distinct integers and a target value x, 
find both the floor and the ceiling of x in the array
floor: a <= x, either equal or just smaller(largest out of all the smaller values)
ceil: a >= x, either equal or just greater(smallest out of all the larger values) -> lower bound
*/
int findCeil(const vector<int> &nums, int target, int low, int high) {
   int ceil = -1;
   while(low <= high) {
      int mid = low + ((high-low) / 2);
      if(nums[mid] >= target) {
         ceil = nums[mid];
         high = mid-1; // move on left, in search of smallest larger value
      }
      else low = mid+1;
   }
   return ceil;
}
int findFloor(const vector<int> &nums, int target, int low, int high) {
   int floor = -1;
   while(low <= high) {
      int mid = low + ((high-low) / 2);
      if(nums[mid] <= target) {
         floor = nums[mid];
         low = mid+1;   // move on right, in search of largest smaller value
      }
      else high = mid-1;
   }
   return floor;
}

pair<int, int> floorCeil(const vector<int> &nums, int target) {
   int n = nums.size();
   int position = n;
   int low = 0; int high = n-1;

   int floor = findFloor(nums, target, low, high);
   int ceil = findCeil(nums, target, low, high);
   return {floor, ceil};
}

int main() {
   vector<int> nums = {1, 2, 8, 10, 11, 12, 19};
   int target = 5;
   pair<int, int> result = floorCeil(nums, target);
   cout << "Floor & Ceil of 5:" << result.first << "," << result.second << endl;
   return 0;
}