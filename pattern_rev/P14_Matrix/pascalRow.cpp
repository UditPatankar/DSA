#include <bits/stdc++.h>
using namespace std;
/* 
Given an integer n, return the n-th row of Pascal's Triangle.
Assume the row numbering is 1-indexed.
Example:
Input: n = 6
Output: [1, 5, 10, 10, 5, 1]
*/
void pascalRow(int n) {
   n--;  // for 1-indexed
   int lastEl = 1;
   
   cout << lastEl << " ";  // first element
   
   for(int i = 1; i <= n; i++) {
      
      int currEl = (lastEl * (n-(i-1))) / i; // (last * (row - (column-1))) / column
      
      cout << currEl << " ";
      
      lastEl = currEl;
   }
}

int main() {
   int n = 6;
   pascalRow(n);
   return 0;
}