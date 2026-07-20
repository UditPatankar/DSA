#include<bits/stdc++.h>
using namespace std;

// Merge Sort Algorithm: an divide & conquer sorting algo that keep dividing the large unsorted array till it can't be further divided i.e single element and then keep merging it back up in sorted fashion
// 1. divide the array in two parts, keep dividing them till it's left with single element.
// 2. since the single element arrray is already sorted, now merge those two single parts in sorted fashion.
// 3. Repeat this merge & sort step for each level from bottom to top, untill you merge the final two halves into single final sorted array.

// *Notice - this looks like "recursion" where we break a bigger problem into smaller sub-problems till we reach the smallest problem which we can solve trivially.

// Time Complexity : O(n log n) in all cases, dividing(log n) and comparing each elements (n)
// Space Complexity: O(n), not an in-place sorting algo.
// Stability : "stable" - Because your condition gives strict priority to the element coming from the left sub-array when values are identical, 13a is guaranteed to land in the final array ahead of 13b.How

void merge(int arr[], int low, int mid, int high) {
   vector<int> temp;

   // compare left array element with right array element.
   int left = low;
   int right = mid + 1;

   while(left <= mid && right <= high) {
      if(arr[left] <= arr[right]) { // Stable
         temp.push_back(arr[left]);
         left++;
      }
      else {
         temp.push_back(arr[right]);
         right++;
      }
   }
   
   //copy remaining elements from left array
   while(left <= mid) {
      temp.push_back(arr[left]);
      left++;
   }

   //copy remaining elements from right array
   while(right <= high) {
      temp.push_back(arr[right]);
      right++;
   }

   //copy the sorted array back to original array
   for(int i = low; i <= high; i++) {
      arr[i] = temp[i - low];
   }
}

void mergeSort(int arr[], int low, int high) {

   // 1. BASE CASE: If the range has 1 element (low >= high), stop dividing. It's already sorted.
   if(low >= high) return;

   // 2. DIVIDE: Find the middle index: mid = (low + high) / 2.
   int mid = (low + high) / 2;

   // 3. *Hypothesis (CONQUER): Recursively call mergeSort on smaller left & right sub-array and assume it sorts them correctly.
   mergeSort(arr, low, mid); 
   mergeSort(arr, mid+1, high);

   // 4. *Induction (COMBINE): Do the final operation to get the final solution out of the smaller solution.
   merge(arr, low, mid, high);
}

int main() {
   int arr[] = {13, 8, 6, 33, 60, 13, 40};
   int n = sizeof(arr) / sizeof(arr[0]);
   
   // array before sorting 
   cout << "Before Merge sort: ";
   for(const auto& x : arr) {
      cout << x << " ";
   }
   cout << endl;

   //sorting-
   mergeSort(arr, 0, n-1);

   // array before sorting 
   cout << "After Merge sort: ";
   for(const auto& x : arr) {
      cout << x << " ";
   }
   cout << endl;

   return 0;
}