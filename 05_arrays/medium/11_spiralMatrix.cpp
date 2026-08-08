#include <bits/stdc++.h>
using namespace std;

// SPIRAL MATRIX 

// # Optimal - TC: O(mn) & SC: O(1)

vector<int> findSpiral(vector<vector<int>> &matrix) {
   int m = matrix.size();  // no. of rows
   int n = matrix[0].size(); // no. of columns
   vector<int> spiral;
   
   int left = 0, right = n-1;
   int top = 0, bottom = m-1;

   while(left <= right && top <= bottom) {

      // move right
      for(int i = left; i <= right; i++) {
         spiral.push_back(matrix[top][i]); // u r moving on the top row
      }
      top++;

      // move bottom
      for(int i = top; i <= bottom; i++) {
         spiral.push_back(matrix[i][right]); // u r moving on the right column
      }
      right--;

      // move left - only if bottom rows exists
      if(top <= bottom) {
         for(int i = right; i >= left; i--) {
            spiral.push_back(matrix[bottom][i]); // u r moving on the bottom row
         }
         bottom--;
      }

      // move top - only if left column exists
      if(left <= right) {
         for(int i = bottom; i >= top; i--) {
            spiral.push_back(matrix[i][left]); // u r moving on the left column
         }
         left++;  
      }
   }

   // doubt - why aren't we checking for top row & righ column existence, as we are doing for bottom row & left column
   // -> coz we are checking to make sure that the row/column is not already processed/touched in the "current iteration"
   // but top row & right column is the very first row/column in the current iteration & also untouched
   // coz while(left <= right && top <= bottom) already checks it

   return spiral;
}

int main() {
   vector<vector<int>> matrix ={
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}
   };

   vector<int> spiral = findSpiral(matrix);

   for(auto x : spiral) {
      cout << x << " ";
   }

   return 0;
}