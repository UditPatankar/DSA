#include <bits/stdc++.h>
using namespace std;

// return the UNION of two given sorted arrays - all unique elements in sorted fashion

// #Brute Force : TC: O(N log N) & SC: O(m + n) if all the elements are unique in both arrays
/* vector<int> findUnion(vector<int> &a1, vector<int> &a2) {
   int m = a1.size();
   int n = a2.size();
   set<int> st;

   // O(m log m)
   for(int i = 0; i< m; i++) {
      st.insert(a1[i]); 
   }

   // O(n log (m+n)) : there were already m elements in the set, for the first element it will take O(log m+1)
   for(int i = 0; i < n; i++) {
      st.insert(a2[i]); 
   }

   // O(m + n)
   vector<int> unionArray;
   for(auto x : st) {
      unionArray.push_back(x);
   }
   
   // total TC: O((m log m) + (n log (m+n)) + (m+n)) -> O(N log N) assuming m & n are roughly pf same size N
   return unionArray;
} */

// Optimal : O(N)  & SC: O(1) excluding the memory used to store the output
vector<int> findUnion(vector<int> &a1, vector<int> &a2) {
   int n1 = a1.size();
   int n2 = a2.size();
   vector<int> unionArr;

   int l = 0;
   int r = 0;
   while(l < n1 && r < n2) {
      int val;

      if(a1[l] < a2[r]) { // if a1 is smaller
         val = a1[l++];
      }
      else if(a2[r] < a1[l]) { // if a2 is smaller
         val = a2[r++];
      }
      else { // equal
         val = a1[l++];
         r++;
      }

      if(unionArr.size() == 0 || unionArr.back() != val) {
         unionArr.push_back(val);
      }
   }

   // if one of the array exhausted
   while(l < n1) {
      if(unionArr.empty() || unionArr.back() != a1[l]) {
         unionArr.push_back(a1[l]);
      }
      l++;
   }
   
   while(r < n2) {
      if(unionArr.empty() || unionArr.back() != a2[r]) {
         unionArr.push_back(a2[r]);
      }
      r++;
   }

   // TC: O(n1 + n2) -> O(N) if n1 & n2 are roughly of same size N 
   return unionArr;
}

int main() {
   vector<int> a1 = {1, 2, 3, 3, 4, 5, 5};
   vector<int> a2 = {5, 6, 6, 7, 8, 9, 9};

   vector<int> unionArr = findUnion(a1, a2);

   for(auto x : unionArr) {
      cout << x << " ";
   }

   return 0;
}