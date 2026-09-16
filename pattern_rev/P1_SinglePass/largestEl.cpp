#include <bits/stdc++.h>
using namespace std;

// Largest Element in Array
// Given an array of integers, find and return the largest element.
// Input: nums = {3, 7, 1, 9, 4}

int findLargest(vector<int> &a) {
   if(a.size() < 1) return -1;

   int largest = a[0];
   for(int i = 1; i < a.size(); i++) {
      largest = max(largest, a[i]);
   }
   return largest;
}

int main() {
   vector<int> a = {3, 7, 1, 9, 4};
   int largest = findLargest(a);
   cout << largest << endl;
   return 0;
}