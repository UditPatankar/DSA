#include <bits/stdc++.h>
using namespace std;

// PASCAL'S TRIANGLE - 
// combinator : nCr = n! / r! * (n-r)! ; n = row, r = column

// # Print entire triangle, TC: O(N^2) & SC: O(N^2)
void printPascalsTriangle(int n) {
   vector<vector<int>> result;  // contains all n rows
 
   if(n == 0 ) return;

   for(int i = 0; i < n; i++) {
      vector<int> currentRow(i + 1);

      for(int j = 0; j <= i; j++) {
         if(j == 0 || j == i) {  
            currentRow[j] = 1;   // first & last element
         }
         else {                  
            vector<int> prevRow = result[i - 1];
            currentRow[j] = prevRow[j] + prevRow[j - 1]; // rest of the elements
         }
      }
      
      result.push_back(currentRow);
   }

   for(auto row : result) {
      for(auto x : row) {
         cout << x << " ";
      }
      cout << endl;
   }
}

// Print specific element - TC: O(r) & SC: O(1)
void printElement(int n, int r) {
   int numer = 1, denom = 1;
   
   for(int i = 1; i <= r; i++) {
     denom = denom * i;
     numer = numer * (n - (i-1));
   }
   
   int result = numer / denom;
   cout << result << endl;
}

// Print specific row - TC: O(r) & SC: O(1)
void printRow(int row) {
   int res = 1;

   for(int i = 0; i <= row; i++) {
      if(i == 0 || i == row) cout << 1 << " ";
      else {
         res = (res * (row - (i - 1))) / i;            // formula: (lastEl * (row - (column - 1))) / column)
         cout << res << " ";
      }
   }
}

int main() {
   printPascalsTriangle(6);
   printElement(5, 3);
   printRow(5);
   
   return 0;
}