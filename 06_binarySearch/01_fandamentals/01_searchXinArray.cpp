#include <bits/stdc++.h>
using namespace std;
/* 
Search target in given "Sorted Array", if found return it's index, otherwise -1
Do it on O(log N) TC.
*/
   // Binary Search - O(log N), this many steps it takes to divide array by 2 until we reach single
// #Iterative code  
int search(vector<int> &nums, int target) {
   // initial search space 
   int low = 0; 
   int high = nums.size()-1;

   // search target, update search space
   while(low <= high) {
      int mid = low + ((high-low) / 2);   // divide the search space
      
      if(nums[mid] == target) return mid; // found
      else if(nums[mid] > target) high = mid-1; // search left half
      else low = mid+1; // search on right
   }
   return -1;  // not found
}

// #Recursive code
int bs(vector<int> &nums, int low, int high, int target) {
   // base case
   if(low > high) return -1;

   // hypothesis & induction
   int mid = low + ((high-low) / 2);
   
   if(nums[mid] == target) return mid;
   else if(nums[mid] > target) {
      high = mid-1;
      return bs(nums, low, high, target); // call on left space
   }
   else {
      low = mid+1;
      return bs(nums, low, high, target); // call on right space
   }
}

int main() {
   vector<int> nums = {-10, -5, -4, -2, -1, 0, 3, 5, 7, 8, 11, 15, 20};
   cout << "index of 0: " << search(nums, 0) << endl;
   cout << "index of -4: " << bs(nums, 0, nums.size()-1, -4) << endl;
   return 0;
}