#include <bits/stdc++.h> 
using namespace std;
/* 
Given two integers r and c, return the element at the r-th row and c-th column of Pascal's Triangle.
Assume rows and columns are 1-indexed.
Example:
Input: r = 7, c = 4
Output: 20
*/
int pascalElement(int r, int c) {
   r--; c--; // for 1-indexed
   long long x = 1; long long y = 1;
   
   int k = min(c, r-c); // do minimum iterations
   for(int i = 1; i <= k; i++) {
      x = x * (r-(i-1));
      y = y * i;
   }

   long long ans = x/y;
   return ans;
}

int main() {
   int r = 7; int c = 4;
   int ans = pascalElement(r, c);
   cout << ans << endl;
   return 0;
}