#include<bits/stdc++.h>
using namespace std;

// Recursive Insertion Sort:
void insertion_sort(int arr[], int i, int n) {
   
   // Base case - all elements have been processed and inserted
   if(i == n) return; 

   int current = i;

   // Induction - move the element at index 'i' leftward to its correct relative position
   while(current != 0 && arr[current-1] > arr[current]) { 
      swap(arr[current], arr[current-1]);
      current--;
   }

   // Hypothesis - assume the recursive call successfully handles all elements from i+1 to n-1
   insertion_sort(arr, i+1, n);
}

int main() {
   int arr[] = {13, 8, 6, 33, 60, 13, 40};
   int n = sizeof(arr) / sizeof(arr[0]);
   
   // array before sorting
   cout << "Before Recursive-Insertion sort: "; 
   for(const auto& x : arr) {
      cout << x << " ";
   }
   cout << endl;

   //sorting -
   insertion_sort(arr, 0, n);

   // array after sorting
   cout << "After Recursive-Insertion sort: "; 
   for(const auto& x : arr) {
      cout << x << " ";
   }
   cout << endl;
   
   return 0;
}