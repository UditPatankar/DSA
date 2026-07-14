#include<bits/stdc++.h>
using namespace std;

   // PROBLEM: what if max element is 10'9, we cannot decalre an array of that size, i.e we cannot perform array hashing.
   // SOLUTION: use map-based hashing.

int main() {
   vector<int> arr = {100000, -3, -4, -3, 100000, 10, 4};
   map<int, int> mp; // use unordered_map<int, int> for O(1)

   for(auto x : arr) {
      mp[x]++;
   }

   for(auto x : mp) {
      cout << x.first << " -> " << x.second << endl; 
      // stored key:value pair in sorted fashion and also
      // space took = number of elements
      // But in array you took space = max element
      // ** map saved a lil space compared to array **
   }

   // TIME COMPLEXITY: map takes O(log N); N=size of map "always"
   // **Use unordered_map which takes O(1) in almost all cases, 
   // except for wrost-case of collision- when sfucntion maps multiple keys to smae array index

   return 0;
}