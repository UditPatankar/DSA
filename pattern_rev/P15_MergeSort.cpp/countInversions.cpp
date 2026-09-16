#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high, int &count) {
   vector<int> temp;
   int l = low;
   int r = mid+1;

   // merge -
   while(l <= mid && r <= high) {
      if(nums[l] <= nums[r]) {
         temp.push_back(nums[l++]);
      }
      // a[l] > a[r]
      else {
         count += ( (mid-l) + 1 );
         temp.push_back(nums[r++]);
      }
   }

   while(l <= mid) {
      temp.push_back(nums[l++]);
   }
   while(r <= high) {
      temp.push_back(nums[r++]);
   }

   for(int i = low; i <= high; i++) {
      nums[i] = temp[i-low]; 
   }
}

void mergeSort(vector<int> &nums, int low, int high, int &count) {
   if(low >= high) return;
   // divide 
   int mid = (low + high) / 2;

   mergeSort(nums, low, mid, count);
   mergeSort(nums, mid+1, high, count);
   merge(nums, low, mid, high, count);
}

int countInversions(vector<int> &nums) {
   int n = nums.size();
   int count = 0;

   mergeSort(nums, 0, n-1, count);

   return count;
}

int main() {
   vector<int> nums = {5, 4, 2, 3, 1};
   int result = countInversions(nums);

   cout << result;

   return 0;
}