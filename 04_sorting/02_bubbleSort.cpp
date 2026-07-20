#include<bits/stdc++.h>
using namespace std;

// Bubble Sort:
// 1. Choose the range in unsorted array, start with 0 to n-1
// 2. swap the adjacent elements if (a[i] > a[i+1])
// 3. now you have LARGEST element sorted at index n-1 and unsorted in 0 to n-2
// 4. update the range to (0 to n-2)
// 5. repeat shrinking process till range 0 to 1.

// Time Complexity - O(n2) in Worst/Avg
// In best case - O(n), already sorted - no swap happened on 1st iteration
// Space Complexity - O(1)

void bubble_sort(int arr[], int n) {
   for(int i = 0; i < n-1; i++) { // no. of times you will change the range
      int didSwap = 0;

      for(int j = 0; j < (n-1)-i; j++) { // the range
         if(arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
            didSwap = 1;
         }
      }
      if(didSwap == 0) {
         break; // Best Case, already sorted
      } 
   }

   cout << "After Bubble sort: ";
   for(int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main() {
   int arr[] = {13, 8, 6, 33, 60, 13, 40};
   int n = sizeof(arr) / sizeof(arr[0]);
   
   // array before sorting
   cout << "Before Bubble sort: "; 
   for(const auto& x : arr) {
      cout << x << " ";
   }
   cout << endl;

   //sorting -
   bubble_sort(arr, n);

   return 0;
}
