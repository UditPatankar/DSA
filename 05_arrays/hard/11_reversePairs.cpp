#include <bits/stdc++.h>
using namespace std;

// COUNT REVERSE PAIRS 
// reverse pairs - if i<j<n, a[i] > 2*a[j] the  a[i], a[j] is a reverse pair 

// TC: O(N log N) & SC: O(N)
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

void countPairs(vector<int> &nums, int low, int mid, int high, int &result) {
   int right = mid+1;

   for(int i = low; i <= mid; i++) {
      while(right <= high && nums[i] > 2*nums[right]) right++;
      result += right - (mid+1);
   }
}

void mergeSort(vector<int> &nums, int low, int high, int &result) {
   if(low >= high) return;
   int mid = (low + high) / 2;
   mergeSort(nums, low, mid, result);
   mergeSort(nums, mid+1, high, result);

   countPairs(nums, low, mid, high, result);

   merge(nums, low, mid, high);
}

int reversePairs(vector<int> &nums) {
   int result = 0;
   mergeSort(nums, 0, nums.size()-1, result);

   return result;
}

int main() {
   vector<int> nums = {2, 4, 3, 5, 1};
   int result = reversePairs(nums);

   cout << result << endl;

   return 0;
}