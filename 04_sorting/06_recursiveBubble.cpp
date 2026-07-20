#include<bits/stdc++.h>
using namespace std;

// Recursive Bubbe Sort:
void bubble_sort(int arr[], int n) {
   
   if(n == 1) return; // Base case : single element
   int didSwap = 0;

   for(int i = 0;i < n-1; i++) { // Induction: you just "sort the last element" of "current range" & assume recursive call will sort the rest of the ranges
      if(arr[i] > arr[i+1]) {
         swap(arr[i], arr[i+1]);
         didSwap = 1; 
      }
   }

   if(didSwap == 0) return; // no swap - everything is sorted at this point

   bubble_sort(arr, n-1); // Hypothesis: assume it correctly sorts the smaller range
}

int main() {
   int arr[] = {13, 8, 6, 33, 60, 13, 40};
   int n = sizeof(arr) / sizeof(arr[0]);
   
   // array before sorting
   cout << "Before Recursive-Bubble sort: "; 
   for(const auto& x : arr) {
      cout << x << " ";
   }
   cout << endl;

   //sorting -
   bubble_sort(arr, n);

   // array after sorting
   cout << "After Recursive-Bubble sort: "; 
   for(const auto& x : arr) {
      cout << x << " ";
   }
   cout << endl;
   
   return 0;
}