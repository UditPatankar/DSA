#include <bits/stdc++.h>
using namespace std;
/* 
Pascal's Triangle
Given a number of rows, print Pascal's Triangle up to that many rows.
Input: n = 5
*/
void printPascalTriangle(const int &n) {
   // print 1st row
   cout << 1 << endl; 
   vector<int> prev = {1};

   // 2nd row to nth row
   for(int i = 1; i < n; i++) {
      vector<int> curr(i+1);
      
      curr[0] = 1; curr[i] = 1; // first & last el 
      for(int j = 1; j < i; j++) {
         curr[j] = prev[j] + prev[j-1]; // rest of the el
      }
      // print current row
      for(auto x : curr) {
         cout << x << " ";
      }
      cout << endl;
      // update previous row
      prev = curr;
   }  
}
int main() {
   int n = 5;
   printPascalTriangle(n);
   return 0;
}