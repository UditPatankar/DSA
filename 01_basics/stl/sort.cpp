//1. Given vector<int> v = {9, 2, 7, 1, 5}, sort ascending and print, 
   // then sort descending and print (using greater<int>()).
//2. Given vector<pair<int,int>> v = {{3,1}, {1,9}, {2,5}}, sort by .first ascending using default sort 
   // (no comparator needed), print result. Then sort the same vector by .second ascending using a custom lambda comparator, print result.
//3. Given sorted vector<int> v = {2, 4, 4, 4, 6, 8}, use lower_bound and upper_bound to find and 
   // print how many times 4 appears in the vector.
//4. Given sorted vector<int> v = {10, 20, 30, 40, 50}, use lower_bound to check if 25 exists in the vector.

#include<bits/stdc++.h>
using namespace std;

int main() {
   //1: sort
   vector<int> v = {9, 2, 7, 1, 5};
   sort(v.begin(), v.end());
   for(auto x : v) {
      cout << x << ' ';
   }
   cout << endl;
   sort(v.begin(), v.end(), greater<int>()) ;
   for(auto x : v) {
      cout << x << ' ';
   }
   cout << endl;

   //2: comparator- a custom rule
   vector<pair<int,int>> vv = {{3,1}, {1,9}, {2,5}};
   sort(vv.begin(), vv.end());
   for(auto p : vv) {
      cout << p.first << ' ' << p.second << endl;
   }
   sort(vv.begin(), vv.end(), [](pair<int, int> a, pair<int, int> b) {
      return a.second < b.second;
   });
   for(auto p : vv) {
      cout << p.first << ' ' << p.second << endl;
   }

   //3: binary search functions
   vector<int> vec = {2, 4, 4, 4, 6, 8};
   int count = upper_bound(vec.begin(), vec.end(), 4) - lower_bound(vec.begin(), vec.end(), 4);
   cout << count << endl;

   //4:
   vector<int> v2 = {10, 20, 30, 40, 50};
   auto it = lower_bound(v2.begin(), v2.end(), 25);
   cout << ((it != v2.end() && *it == 25) ? "found" : "not found") << endl;;

   //5: 
   // sort it according to second element,
   // if second are same, then sort it according to first bu tin descending
   vector<pair<int, int>> p = { {1, 2}, {2, 1}, {4, 1} };
   sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b) {
      return (a.second == b.second) ? a.first > b.first : a.second < b.second;
   });
   for(auto x : p) {
      cout << x.first << ' ' << x.second << endl;
   }


   return 0;
}