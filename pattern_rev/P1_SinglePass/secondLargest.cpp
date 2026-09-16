#include <bits/stdc++.h>
using namespace std;

/* Second Largest Element (without sorting)
Given an array of integers, find the second largest distinct element without sorting the array. Return -1 if it doesn't exist.
Input: nums = {8, 8, 3, 5, 3, 9, 9} */

int findSecondLargest(vector<int> &a) {
   if(a.size() < 2) return -1;
   int firstMax = a[0];
   int secondMax = -1;

   for(int i = 1; i < a.size(); i++) {
      if(a[i] > firstMax) {
         secondMax = firstMax;
         firstMax = a[i];
      }
      else if(a[i] > secondMax && a[i] != firstMax) {
         secondMax = a[i];
      }
   }

   return secondMax;
}

int main() {
   vector<int> a = {8, 8, 3, 5, 3, 9, 9};
   int secondLargest = findSecondLargest(a);
   cout << secondLargest << endl;
   return 0;
}