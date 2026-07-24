#include<bits/stdc++.h>
using namespace std;

// Quick Sort Algorithm - uses divide and conquer technique

// pick a pivot: first element (but, last, middle or random element) 
// now place a left pointer 'l' on first index and right pointer 'r' on last index
// now move 'l' rightwards, and stop if element 'greater' than pivot is found
// and move 'r' leftwards, and stop if element 'smaller' than pivot found
// swap a[l] with a[r]
// keep doing this moving and swapping process until 'l' and 'r' crosses each other,
// once they cross each other, swap a[r] with pivot - because that is the last smaller value known & everything right to it still larger/equal to pivot.
// You have you pivot at the sorted postion/index - (left part: smaller) < pivot < (right part: greater)

// "Recurse" : apply this recursively on the left and right part.

int partition(int arr[], int low, int high) {

   // Choose random pivot - worst case probability becomes extremely low
   int randomIndex = low + (rand() % (high - low + 1));
   swap(arr[low], arr[randomIndex]);

   int pivot = arr[low];
   int l = low;
   int r = high;

   while(l < r) { // keep moving and swapping until 'l' and 'r' they cross/meet

      while(arr[l] <= pivot && l < high) { // skip until finds strictly greater than pivot
         l++;
      }
      while(arr[r] >= pivot && r > low) { // skip untill finds strictly smaller than pivot
         r--;
      }

      if(l < r) { // swap 'l' & 'r' ONLY if they have not crossed/met.
         swap(arr[l], arr[r]);
      }
   }

   // swap pivot ONLY if arr[r] is smaller than pivot & 'l' and 'r' have crossed/met
   if(l >= r && arr[r] < pivot) {
      swap(arr[r], arr[low]);
   }
  
   return r;
}

void quick_sort(int arr[], int low, int high) {

   // Base case - 
   if(low >= high) return;

   // Induction - just sort the pivot (first element)
   int partitionIndex = partition(arr, low, high);

   // Hypotheis - assume recursive call will sort rest of the elements
   quick_sort(arr, low, partitionIndex-1); // sort left
   quick_sort(arr, partitionIndex+1, high); // sort right
}

int main() {
   int arr[] = {13, 8, 6, 33, 60, 13, 40}; // {8, 7, 6, 5, 4, 3, 2, 1};
   int n = sizeof(arr) / sizeof(arr[0]);
   
   // array before sorting
   cout << "Before Quick sort: "; 
   for(const auto& x : arr) {
      cout << x << " ";
   }
   cout << endl;

   //sorting -
   quick_sort(arr, 0, n-1);

   // array after sorting
   cout << "After Quick sort: "; 
   for(const auto& x : arr) {
      cout << x << " ";
   }
   cout << endl;

   return 0;
}