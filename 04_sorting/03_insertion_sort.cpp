#include<bits/stdc++.h>
using namespace std;

// Insertion Sort -
// 1. Iterate on array, 
// 2. choose the current element: current = i;
// 3. now if(current != 0 && previous > current) then swap,
// 4. now your current is at i-1, so again check the above condition and swap if true

// Basically we choose the current val in array and keep comparing and moving it on left till it's possible

// Time Complexity: O(n2) Wrost/Avg and O(n) in Best i.e already sorted
// Space Complexity: O(1)

void insertionSort(int arr[], int n) {
   for(int i = 1; i < n; i++) {
      int current = i;

      while(current != 0 && arr[current-1] > arr[current]) { // if any cond'n fails we move forward in array
         swap(arr[current], arr[current-1]);
         current--; 
      }
   }

   /// array after sorting-
   cout << "After Insertion sort: "; 
   for(int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;

}

int main() {
   int arr[] = {13, 8, 6, 33, 60, 13, 40};
   int n = sizeof(arr) / sizeof(arr[0]);
   
   // array before sorting
   cout << "Before Insertion sort: "; 
   for(const auto& x : arr) {
      cout << x << " ";
   }
   cout << endl;

   //sort-
   insertionSort(arr, n);

   return 0;
}