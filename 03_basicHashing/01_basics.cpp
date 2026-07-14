#include<bits/stdc++.h>
using namespace std;

// Hashing: simply means to store and retrieve data in O(1) average time complexity [almost all the time]
// * Worst-case is O(N) if collisions chain up, but this is extremely rare.
// two steps: 
// 1. computation - converting the key to an array index (using hash function) and storing the value/{key, value} at the at index.
// 2. fetching - retrieving value directly using that index

 //suppose given an array [2, 4, 3, 5, 2, 12, 3, 5]
   // and given some queries: {2, 5, 12, 0} and for each query you are asked
   // how many time that number appears in an array?
   // if using brute force - 
         // int fun(int arr, int target) {
         //    int count = 0;
         //    for(int i = 0; i < n; i++) {
         //       if(arr[i] == target) count++;
         //    }
         //    return count;
         // }
   // Time complexity: for each query loop runs N time and so for Q queries it's Q*N -> O(Q*N)
   // now if Q= 10'5 and N= 10'5 -> O(10'10) 
   // since 10'8 operations takes 1sec so 10'10 will take 100secs, thats not good!

   // Optimal solution - use HASHING

int main() {
   int arr[8] = {2, 4, 3, 5, 2, 12, 3, 5}; // max element is 12
   int hash[13] = {0};  // creates an array of size 13: index 0 to 12

   // pre-computing
   for(auto x : arr) {
      hash[x]++;
   }

   // fetching
   cout << hash[3] << endl; // the key(element) itself act as a index of hash array

   for(int i = 0; i < 13; i++) {
      cout << i << "->" << hash[i] << endl; // i: key and value: count/frequency
   }

   // PROBLEM: what if max element is 10'9, we cannot decalre an array of that size, i.e we cannot perform array hashing.
   // SOLUTION: use map-based hashing.
   return 0;
}