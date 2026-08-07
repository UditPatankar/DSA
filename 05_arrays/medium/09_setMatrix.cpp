#include <bits/stdc++.h>
using namespace std;

// SET MATRIX ZEROES
// Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's.

/* // # Brute Force for positive matrix - TC: O(N^3) & SC:(1) 
void markRows(vector<vector<int>> &matrix, int i, int j, int n) {
   for(int j = 0; j < n; j++) {
      if(matrix[i][j] != 0) {
         matrix[i][j] = -1;
      }
   }
} 
void markCols(vector<vector<int>> &matrix, int i, int j, int m) {
   for(int i = 0; i < m; i++) {
      if(matrix[i][j] != 0) {
         matrix[i][j] = -1;
      }
   }
}
void setMatrixZeroes(vector<vector<int>> &matrix, int m, int n) {
   for(int i = 0; i < m; i++) { // O(m x n) x (m + n) 
      for(int j = 0; j < n; j++) {
         if(matrix[i][j] == 0) {
            markRows(matrix, i, j, n); // mark the non-zeroes in row as -1
            markCols(matrix, i, j, m); //mark the non-zeroes in column as -1
         }
      }
   }

   // mark all the -1's as zeroes
   for(int i = 0; i < m; i++) { // O(m x n)
      for(int j = 0; j < n; j++) {
         if(matrix[i][j] == -1) {
            matrix[i][j] = 0;
         }
      }
   }

   // O(m x n) x (m + n) + (m x n) -> O(N^3) + (N^2) -> O(N^3) if m & n are rough of size N
}
 */

// # Brute Force for all the integer matrix - TC: O(m x n) & SC: O(m + n)
/* void setMatrixZeroes(vector<vector<int>> &matrix, int m, int n) {
   vector<bool> rows(m, false);
   vector<bool> cols(n, false);

   // find zeroes & mark the corresponding rows/cols true
   for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
         if(matrix[i][j] == 0) {
            rows[i] = true;
            cols[j] = true;
         }
      }
   }

   // zero all the cells whose rows/cols are true
   for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
         if(rows[i] || cols[j]) {
            matrix[i][j] = 0;
         }
      }
   }
} */

// Optimal - TC: O(mn) & SC: O(1)
void setMatrixZeroes(vector<vector<int>> &matrix, int m, int n) {
   // use first row & column of matrix itself instead of extra space
   // rows(m, 0) -> matrix[i][0] first col will track the rows
   // cols(n, 0) -> matrix[0][j] first row will track the columns

   int col0 = 1; // edge case - keep the 1st row & col separate
   for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
         if(matrix[i][j] == 0) {
            matrix[i][0] = 0; // mark the row

            if(j != 0)
               matrix[0][j] = 0; // mark the column
            else 
               col0 = 0;
         }
      }
   }

   // except the 1st row & column, set rest fo the matrix
   for(int i = 1; i < m; i++) {
      for(int j = 1; j < n; j++) {
         if(matrix[i][j] != 0) {

            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
               matrix[i][j] = 0;
            } 
         }
      }
   }
   
   // check row0 first coz it leaves inside the matrix
   if(matrix[0][0] == 0) {
      for(int j = 1; j < n; j++) matrix[0][j] = 0;
   }
   
   // if you check this first - you may overwrite the row0(inside the matrix)
   if(col0 == 0) {
      for(int i = 0; i < m; i++) matrix[i][0] = 0;
   }
}

int main() {
   vector<vector<int>> matrix = {
      {1, 1, 1, 1},
      {1, 0, 0, 1},
      {1, 1, 0, 1},
      {1, 1, 1, 1}
   };

   setMatrixZeroes(matrix, 4, 4);

   for(auto row : matrix) {
      for(auto x : row) {
         cout << x << " ";
      }
      cout << endl;
   }

   return 0;
}