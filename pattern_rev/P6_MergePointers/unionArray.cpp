#include <bits/stdc++.h>
using namespace std;
/* 
Union of Two Sorted Arrays
Given two sorted arrays (may have internal duplicates), return their union — all distinct elements, sorted.
Input: arr1 = {1, 2, 2, 3, 4}, arr2 = {2, 3, 5, 6} → expected: {1,2,3,4,5,6}
*/
vector<int> unionArray(vector<int> &a1, vector<int> &a2) {
   vector<int> ans;
   int m = a1.size(); int n = a2.size();
   int l = 0; int r = 0;

   while(l < m && r < n) {
      int el;
      if(a1[l] < a2[r]) { el = a1[l++]; }
      else if(a2[r] < a1[l]) { el = a2[r++]; }
      else { el = a1[l++]; r++; }

      if(ans.empty() || ans.back() != el) {
         ans.push_back(el);
      }
   }
   while(l < m) {
      if(ans.empty() || ans.back() != a1[l]) {
         ans.push_back(a1[l]);
      }
      l++;
   }
   while(r < n) {
      if(ans.empty() || ans.back() != a2[r]) {
         ans.push_back(a2[r]);
      }
      r++;
   }
   return ans;
}

int main() {
   vector<int> arr1 = {1, 2, 2, 3, 4};
   vector<int> arr2 = {2, 3, 5, 6};
   vector<int> unionArr = unionArray(arr1, arr2);
   for(auto x : unionArr) {
      cout << x << " ";
   }
   return 0;
}