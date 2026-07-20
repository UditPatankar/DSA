#include<bits/stdc++.h>
using namespace std;

// Selection Sort Algorithm:
// 1. choose a range in the given unsorted array, start with i = 0; (0 to n-1)
// 2. find the minimum in the current range, 
// 3. swap the minimum with current first index of the range, 0
// 4. now we have sorted portion of array, (0 to last index of the range)
// 5. update the range, i = i+1, 
// 6. repeat this till range (n-2 to n-1).

// Time Complexity - O(n2) in all cases
// Space Complexity - O(1)

// example: 
void selection_sort(int arr[], int n) {
   for(int i = 0; i < n-1; i++) { // update the range
      int mini = i;

      //find minimum in current range
      for(int j = i; j < n; j++) {
         if(arr[j] < arr[mini]) {
            mini = j;
         }
      }

      //swap 1st in range with minimum
      int temp = arr[i];
      arr[i] = arr[mini];
      arr[mini] = temp;
   }

   // array after sorting 
   cout << "After selection sort: ";
   for(int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main() {
   int arr[] = {13, 8, 6, 33, 60, 13, 40};
   int n = sizeof(arr) / sizeof(arr[0]);
   
   // array before sorting 
   cout << "Before selection sort: ";
   for(const auto& x : arr) {
      cout << x << " ";
   }
   cout << endl;

   //sorting -
   selection_sort(arr, n);

   return 0;
}
