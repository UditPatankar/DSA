#include <bits/stdc++.h>
using namespace std;
/* 
Set Matrix Zeroes
Given an m x n matrix, if an element is 0, set its entire row and column to 0.
Input: matrix = {
      {1, 1, 1, 1}, 
      {1, 0, 0, 1},
      {1, 1, 0, 1},
      {1, 1, 1, 1}
   };
*/
void setMatrix(vector<vector<int>> &matrix, int rows, int cols) {
   // column tracker: matrix(0, c)
   // row tracker: matrix(x, r)
   int col0 = 1; 

   for(int r = 0; r < rows; r++) {
      for(int c = 0; c < cols; c++) {
         // mark tracker row & column
         if(matrix[r][c] == 0) { 
            matrix[r][0] = 0; // mark the row
            if(c==0) { col0 = 0; }
            else { matrix[0][c] = 0; }// column
         }
      }
   }

   // set matrix, except row 0 & column 0
   for(int r = 1; r < rows; r++) {
      for(int c = 1; c < cols; c++) {
         if(matrix[r][c] != 0) {
            if(matrix[r][0] == 0 || matrix[0][c] == 0) {
               matrix[r][c] = 0;
            }
         }
      }  
   }
   // set row 0 & column 0
   if(matrix[0][0] == 0) {
      for(int c = 0; c < cols; c++) {
         matrix[0][c] = 0;
      }
   }
   if(col0 == 0) {
      for(int r = 0; r < rows; r++) {
         matrix[r][0] = 0;
      }
   }
}

int main() {
   vector<vector<int>> matrix = {
      {1, 1, 1, 1}, 
      {1, 0, 0, 1},
      {1, 1, 0, 1},
      {1, 1, 1, 1}
   };
   setMatrix(matrix, 4, 4);
   for(auto r : matrix) {
      for(auto c : r) {
         cout << c << " ";
      }
      cout << endl;
   }
   return 0;
}