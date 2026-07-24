#include <bits/stdc++.h>
using namespace std;

// return INTERSECTION of two given 'sorted' arrays - common elements, preserve the duplicates 

// TC: O(N) & SC: O(1) excluding the memory used to store the output
vector<int> findIntersection(vector<int> &a1, vector<int> &a2) {
   int n1 = a1.size();
   int n2 = a2.size();
   vector<int> interArr;

   int l = 0;
   int r = 0;
   while(l < n1 && r < n2) {

      if(a1[l] == a2[r]) {
         interArr.push_back(a1[l]);
         l++;
         r++;
      }
      else if(a1[l] < a2[r]) {
         l++;
      }
      else {
         r++;
      }
   }

   // TC: O(n1 + n2) -> O(N) assuming n1 & n2 are roughly of same size N
   return interArr;
}

// return INTERSECTION of two given arrays - common unique elements, any order

vector<int> findIntersection2(vector<int> &a1, vector<int> &a2) {
   unordered_set<int> st;
   vector<int> interArr;
   
   for(auto x : a1) {
      st.insert(x);
   }

   for(auto x : a2) {
      if(st.count(x)) {
         interArr.push_back(x);
         st.erase(x);
      }
   }

   return interArr;
}

int main() {
   vector<int> a1 = {10, 10, 20, 30, 30, 40, 50, 50};
   vector<int> a2 = {10, 20, 20, 30, 30, 40, 40, 50, 50, 60};

   vector<int> interArr = findIntersection(a1, a2);

   for(auto x : interArr) {
      cout << x << " ";
   }
   cout << endl;

   //-------------

   vector<int> v1 = {1, 3, 3, 2, 0, 3, 4, 5};
   vector<int> v2 = {4, 0, 0, 5, 5, 2, 2};

   vector<int> interArr2 = findIntersection2(v1, v2);

   for(auto x : interArr2) {
      cout << x << " ";
   }

   return 0;
}