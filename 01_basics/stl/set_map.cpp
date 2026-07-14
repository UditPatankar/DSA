// Practice Problems — Set/Map

//1. Given vector<int> v = {4, 2, 7, 2, 4, 9, 7}, insert all elements into a set<int>, 
   // then print the set (should be sorted, duplicates removed).
//2. Given the same vector, use an unordered_map<int,int> to count frequency of each element, 
   // then print element -> count for each.
//3. Write a function bool hasDuplicate(vector<int>& v) that returns true if any element repeats, 
   // using an unordered_set (insert each element, if count() shows it already exists, 
   // return true immediately — this is a classic O(n) pattern instead of the naive O(n²) nested-loop approach).
//4. Given two vectors v1 = {1,2,3,4,5} and v2 = {3,4,5,6,7}, find their common elements using a set
   // (insert v1 into a set, then loop through v2 checking .count() for each — print common elements).

#include<bits/stdc++.h>
using namespace std;

bool hasDuplicate(vector<int> &v) {
   unordered_set<int> st;
   for(auto val : v) {
      if(st.count(val) != 0) return true;
      st.insert(val);
   }
   return false;
}

int main() {
   //1:
   vector<int> v = {4, 2, 7, 2, 4, 9, 7};
   set<int> st;
   for(auto val : v) {
      st.insert(val);
   }
   for(auto val : st) {
      cout << val << ' ';
   }
   cout << endl;

   //2:
   unordered_map<int, int> freq;
   for(auto val : v) {
      freq[val]++; // val as key and count as value
   }
   for(auto val : freq) {
      cout << val.first << ' ' << val.second << endl;
   }

   //3:
   cout << hasDuplicate(v) << endl;

   //4:
   vector<int> v1 = {1, 2, 3, 4, 5};
   vector<int> v2 = {3, 4, 5, 6, 7};
   set<int> s;
   for(auto x : v1) {
      s.insert(x);
   }
   for(auto x : v2) {
      if(s.count(x) != 0) cout << x << ' ';
   }

   return 0;
}