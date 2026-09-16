#include <bits/stdc++.h>
using namespace std;
/* 
Merge Two Sorted Arrays w/o extra space-
*/

// Variant 1 
void variant1(vector<int> &nums1, vector<int> &nums2) {
   // calculate size
   int s = nums1.size();
   int n = nums2.size();
   int m = s-n;

   int l = m-1;   // read pointer for a
   int r = n-1;   // read pointer for b
   int w = s-1;   // write pointer

   while(l >= 0 && r >= 0) {
      if(nums1[l] > nums2[r]) {
         nums1[w] = nums1[l];
         w--; l--;
      }
      else {
         nums1[w] = nums2[r];
         w--; r--;
      }
   }

   // if l exhaust, put remaining elements from nums2
   while(r >= 0) {
      nums1[w] = nums2[r];
      w--; r--;
   }
}

// Variant 2
void variant2(vector<int> &a, vector<int> &b) {
   int m = a.size();
   int n = b.size();

   // assume a single conceptual array a+b
   int total = m + n;

   // initial gap 
   int gap = (total + 1) / 2; // (total / 2) + (total % 2);
   
   // at gap 1 array gets sorted
   while(gap > 0) {
      // compare & swap all the elements with current gap
      int l = 0; 
      int r =  l + gap;

      while(r < total) {
         // Now there can be 3 cases

         // both l & r are inside a
         if(l < m && r < m) { 
            if(a[l] > a[r]) swap(a[l], a[r]);
         }
         // l inside a & r inside b
         else if(l < m && r >= m) { 
            if(a[l] > b[r-m]) swap(a[l], b[r-m]);
         }
         // both l & r inside b
         else {   
            if(b[l-m] > b[r-m]) swap(b[l-m], b[r-m]);
         }

         l++; r++;
      }

      // reduce the gap, if current gap was 1 its's already sorted
      if(gap == 1) break;
      gap = (gap + 1) / 2; // (gap / 2) + (gap % 2);
   }
}

int main() {
   // Testing Variant 1
   vector<int> nums1 = {4, 5, 6, 0, 0, 0}; // m+n
   vector<int> nums2 = {1, 2, 3};   // n
   variant1(nums1, nums2);
   cout << "Output for variant 1: ";
   for(auto x : nums1) {
      cout << x << " ";
   }
   cout << "\n";
   
   // Testing Variant 2
   vector<int> a = {1, 4, 8, 10};
   vector<int> b = {2, 3, 9};
   variant2(a, b);
   cout << "Output for variant 2: ";
   for(auto x : a) {
      cout << x << " ";
   }
   cout << ",";
   for(auto x : b) {
      cout << x << " ";
   }
   cout << "\n";

   return 0;
}
