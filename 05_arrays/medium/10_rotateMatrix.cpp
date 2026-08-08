#include <bits/stdc++.h>
using namespace std;

// ROTATE MATRIX BY 90 degree

// # Brute Force - TC: O(mn) & SC: O(mn) - also "optimal" for non-square matrix
/* 
vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix, int m, int n) {
   vector<vector<int>> newMatrix(m, vector<int>(n, 0));

   for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
         newMatrix[i][j] = matrix[(n-1)-j][i];
      }
   }

   return newMatrix;
}
 */

// # Optimal - TC: O(mn) & SC: (1) only for square matrix
void rotateMatrix(vector<vector<int>> &matrix) {
   int n = matrix.size();

   // transpose
   for(int i = 0; i < n; i++) {
      for(int j = i; j < n; j++) {
         if(i != j) {
            swap(matrix[i][j], matrix[j][i]);
         }
      }
   }

   // reverse
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n/2; j++) {
         swap(matrix[i][j], matrix[i][(n-1)-j]);
      }
   }
}

int main() {
   vector<vector<int>> matrix = {
      {1,  2,  3,  4},
      {5,  6,  7,  8},
      {9,  10, 11, 12},
      {13, 14, 15, 16}
   };

   rotateMatrix(matrix);

   for(auto row : matrix) {
      for(auto x : row) {
         cout << x << " ";
      }
      cout << endl;
   }

   return 0;
}