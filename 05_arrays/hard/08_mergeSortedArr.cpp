#include <bits/stdc++.h>
using namespace std;

// MERGE SORTED ARRAYS - w/o extra space

// # Brute Force - TC: O(m+n) & SC: O(m+n)
/* void mergeSortedArr(vector<int> &a1, int m, vector<int> &a2, int n) {
   vector<int> temp;
   int l = 0; 
   int r = 0;

   while(l < m && r < n) {
      if(a1[l] <= a2[r]) {
         temp.push_back(a1[l]); l++;
      }
      else {
         temp.push_back(a2[r]); r++;
      }  
   }

   while(l < m) {
      temp.push_back(a1[l]); l++;
   }
   while((r < n)) {
      temp.push_back(a2[r]); r++;
   }

   for(int i = 0; i < m+n; i++) {
      a1[i] = temp[i];
   }
}
 */

// # Optimal - TC: O(m+n) & SC: O(1) 
void mergeSortedArr(vector<int> &A, int m, vector<int> &B, int n) {
   int k = m+n-1; // last indx of A
   int i = m-1;   
   int j = n-1;   // last indx of B

   while(i >= 0 && j >= 0) {
      if(A[i] > B[j]) {
         A[k] = A[i];   k--; i--;
      }
      else if(A[i] <= B[j]) {
         A[k] = B[j];   k--; j--;
      }
   }

   // if B is exhausted means A is already sorted
   // if A is exhausted, put B values at k in A

   while(j >= 0) {
      A[k] = B[j];   k--; j--;
   }
} 

int main() {
   vector<int> nums1 = {4, 5, 6, 0, 0, 0}; //{1, 2, 3, 9, 10, 0, 0, 0, 0};
   vector<int> nums2 = {1, 2, 3}; //{4, 5, 6, 7};

   mergeSortedArr(nums1, 3, nums2, 3);

   for(auto x : nums1) {
      cout << x << " ";
   }
   return 0;
}