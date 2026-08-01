#include <bits/stdc++.h>
using namespace std;

// SORT ARRAY of 0's 1's and 2's

// # Brute Force - TC: O(N log N) & SC: O(N)

/* void mergeArr(vector<int> &nums, int low, int mid, int high) {
   vector<int> temp;
   int i = low;
   int j = mid+1;

   while(i <= mid && j <= high) {
      if(nums[i] <= nums[j]) {
         temp.push_back(nums[i++]);
      }
      else {
         temp.push_back(nums[j++]);
      }
   }

   while(i <= mid) {
      temp.push_back(nums[i++]);
   }
   while(j <= high) {
      temp.push_back(nums[j++]);
   }

   for(int k = 0; k < temp.size(); k++) {
      nums[low + k] = temp[k];
   }
}

void sortArr(vector<int> &nums, int low, int high) {
   if(low == high) return; // base case - single element

   int mid = (low+high)/2;
   sortArr(nums, low, mid); // left half - assuming you get this part sorted
   sortArr(nums, mid+1, high); // right half - assuming you get this part sorted
   mergeArr(nums, low, mid, high); // Induction - just merge them to final in sorted fashion
}
 */

// # Better - TC: O(2N) & SC: O(1)
/* void sortArr(vector<int> &nums, int n) {
   int count0 = 0;
   int count1 = 0;
   int count2 = 0;
   
   for(int i = 0; i < n; i++) {
      if(nums[i] == 0) count0++;
      else if(nums[i] == 1) count1++;
      else count2++;
   }

   for(int i = 0; i < n; i++) {
      if(i < count0) nums[i] = 0;
      else if(i < count0+count1) nums[i] = 1;
      else nums[i] = 2;
   }
} */

// # Dutch National Flag Algorithm (3-pointers)
// # Optimal - TC: O(N) & SC: O(1)
void sortArr(vector<int> &nums, int n) {
   int low = 0;
   int mid = 0;
   int high = n-1;

   while(mid <= high) {
      if(nums[mid] == 0) {
         swap(nums[mid], nums[low]);
         mid++;
         low++;
      }
      else if(nums[mid] == 1) {
         mid++;
      }
      else {
         swap(nums[mid], nums[high]);
         high--;
      }
   }
}

int main() {
   vector<int> nums = {2, 0, 1}; // {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};
   int n = nums.size();
   sortArr(nums, n);

   for(auto x : nums) {
      cout << x << " ";
   }

   return 0;
}