#include <bits/stdc++.h>
using namespace std;
/* 
Count Reverse Pairs -
if i < j < n & a[i] > 2*a[j] then it's a reverse pair
*/

void merge(vector<int> &nums, int low, int mid, int high) {
   vector<int> temp;
   int left = low; int right = mid+1;

   while(left <= mid && right <= high) {
      if(nums[left] <= nums[right]) {
         temp.push_back(nums[left++]);
      }
      else {
         temp.push_back(nums[right++]);
      }
   }

   while(left <= mid) {
      temp.push_back(nums[left++]);
   }
   while(right <= high) {
      temp.push_back(nums[right++]);
   }

   for(int i = low; i <= high; i++) {
      nums[i] = temp[i - low];
   }
}

void countPairs(vector<int> &nums, int low, int mid, int high, int &count) {
   int r = mid+1;

   // ex: [6, 7, 8] [1, 2, 3, 5]
   // for each element on left check till what element on right it forms a pair
   // 6 will for till 2, 7 will form till 3
   for(int i = low; i <= mid; i++) {
      while(r <= high && nums[i] > 2 * nums[r]) r++;
      count += r-(mid+1);
   }
}

void mergeSort(vector<int> &nums, int low, int high, int &count) {
   if(low >= high) return;
   int mid = (low + high) / 2;
   mergeSort(nums, low, mid, count);
   mergeSort(nums, mid+1, high, count);

   countPairs(nums, low, mid, high, count);

   merge(nums, low, mid, high);
}

int reversePairs(vector<int> &nums) {
   int count = 0;
   mergeSort(nums, 0, nums.size()-1, count);

   return count;
}

int main() {
   vector<int> nums = {2, 4, 3, 5, 1};
   int result = reversePairs(nums);

   cout << result << endl;

   return 0;
}