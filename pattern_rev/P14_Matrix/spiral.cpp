#include <bits/stdc++.h>
using namespace std;
/* 
Spiral Matrix Traversal
Given a matrix, return all elements in spiral order.
Input: {
   {1, 2, 3, 4},
   {5, 6, 7, 8},
   {9, 10, 11, 12},
   {13, 14, 15, 16}
};
*/
vector<int> printSpiral(vector<vector<int>> &matrix) {
   vector<int> spiral;
   int m = matrix.size(); // rows
   int n = matrix[0].size(); // columns
   int left = 0; int top = 0;
   int right = n-1; int bottom = m-1;

   while(left <= right && top <= bottom) {
      // l -> r
      for(int i = left; i <= right; i++) {
         spiral.push_back(matrix[top][i]);
      }
      top++;
      // t -> b
      if(top <= bottom) {
         for(int i = top; i <= bottom; i++) {
            spiral.push_back(matrix[i][right]);
         }
         right--;
      }
      // l <- r
      if(left <= right) {
         for(int i = right; i >= left; i--) {
            spiral.push_back(matrix[bottom][i]);
         }
         bottom--;
      }
      // b -> t
      if(top <= bottom) {
         for(int i = bottom; i >= top; i--) {
            spiral.push_back(matrix[i][left]);
         }
         left++;
      }
   }
   return spiral;
}
int main() {
   vector<vector<int>> matrix = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}
   };
   vector<int> spiral = printSpiral(matrix);
   for(auto x : spiral) {
      cout << x << " ";
   }
   return 0;
}