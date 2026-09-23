#include <bits/stdc++.h>
using namespace std;
/* 
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
*/

// #Using LB, UB
// lower bound - return either the 1st occ of the target, or out of all the values>target retrun the smallest
int lb(const vector<int> &nums, int target) {
   int low = 0;
   int high = nums.size()-1;
   int ans = nums.size();
   while(low <= high) {
      int mid = low + ((high-low)/2);
      if(nums[mid] >= target) {
         ans = mid;
         high = mid-1;
      }
      else low = mid+1;
   }
   return ans;
}
// upper bound -  out of all the values>target retrun the smallest
int ub(const vector<int> &nums, int target) {
   int low = 0;
   int high = nums.size()-1;
   int ans = nums.size();
   while(low <= high) {
      int mid = low + ((high-low)/2);
      if(nums[mid] > target) {
         ans = mid;
         high = mid-1;
      }
      else low = mid+1;
   }
   return ans;
}
pair<int, int> searchRange(const vector<int> &nums, int target) {
   int n = nums.size();
   int first = lb(nums, target);
   int last = ub(nums, target);

   // first check if the target exist?
   if(first == n || nums[first] != target) return {-1, -1};

   // now since the target exist, return the occ safely
   return {first, last-1};
}

// #using binary search w/o lb,ub 
pair<int, int> searchRangeWbs(const vector<int> &nums, int target) {
   int n = nums.size();
   int low = 0;
   int high = n-1;
   int first = -1;
   int last = -1;

   // find first
   while(low <= high) {
      int mid = low + ((high-low) / 2);
      // if value=target found, save the index & look on left for smaller index
      if(nums[mid] == target) {
         first = mid;
         high = mid-1;
      }
      // if value>target found, look for target on left
      else if(nums[mid] > target) high = mid-1;
      else low = mid+1;
   }

   // check if target exist
   if(first == -1) return {-1, -1};

   low = 0; high = n-1;
   // find last
   while(low <= high) {
      int mid = low + ((high-low) / 2);
      // if value=target found, save the index & look on right for larger index
      if(nums[mid] == target) {
         last = mid;
         low = mid+1;
      }
      // if value<target found, look for target on right
      else if(nums[mid] < target) low = mid+1;
      else high = mid-1;
   }
   
   return {first, last};
}

int main() {
   vector<int> nums = {2, 3, 4, 5, 7, 7, 8, 10, 10};
   int target = 10;

   pair<int, int> result = searchRange(nums, target);
   cout << "The first & last occurence of target is:" << result.first << "," << result.second << endl;

   pair<int, int> result2 = searchRangeWbs(nums, target);
   cout << "(Wbs) The first & last occurence of target is:" << result2.first << "," << result2.second << endl;
   return 0;
}