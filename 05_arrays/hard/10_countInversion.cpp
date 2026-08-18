#include <bits/stdc++.h>
using namespace std;

// COUNT INVERSIONS
// Inversions - pairs in array such that for all i&j < n,
// a[i] > a[j] where i < j

// # Brute Force - TC: O(N^2) & SC: O(1)
/* int countInversions(vector<int> &nums) {
   int result = 0;

   for(int i = 0; i < nums.size()-1; i++) {
      for(int j = i+1; j < nums.size(); j++) {
         if(nums[i] > nums[j]) result++;
      }
   }

   return result;
} */

// Optimal - TC: O(N log N) & SC: O(N)
void merge(vector<int> &nums, int low, int mid, int high, int &result) {
   vector<int> temp;

   int left = low;
   int right = mid + 1;

   while(left <= mid && right <= high) {
      // left is smaller
      if(nums[left] <= nums[right]) { 
         temp.push_back(nums[left++]); 
      }
      
      // right is smaller
      else if(nums[left] > nums[right]) { 
         result += (mid-left)+1;         // count inversions
         temp.push_back(nums[right++]); 
      }
   }

   // copy leftout elements
   while(left <= mid) { temp.push_back(nums[left++]); }
   while(right <= high) { temp.push_back(nums[right++]); }

   // copy to original array
   for(int i = low; i <= high; i++) {
      nums[i] = temp[i-low];
   }
}

void mergeSort(vector<int> &nums, int low, int high, int &result) {
   if(low >= high) return; // base case
   int mid = (low + high) / 2; // divide
   mergeSort(nums, low, mid, result); // call on left half
   mergeSort(nums, mid+1, high, result); // call on right half
   merge(nums, low, mid, high, result);  // merge & sort the sorted left & right
}

int countInversions(vector<int> &nums) {
   int result = 0;
   mergeSort(nums, 0, nums.size()-1, result);

   return result;
}

int main() {
   vector<int> nums = {5, 4, 2, 3, 1};
   int result = countInversions(nums);

   cout << result;

   return 0;
}