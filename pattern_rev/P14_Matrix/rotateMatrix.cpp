#include <bits/stdc++.h>
using namespace std;
/* 
Rotate Matrix by 90 Degrees
Given an n x n matrix, rotate it 90 degrees clockwise in-place.
Input:
{1,2,3}
{4,5,6}
{7,8,9}
*/
void rotateMatrix(vector<vector<int>> &matrix, int s) {
   // transpose
   for(int i = 0; i < s; i++) {
      for(int j = i; j < s; j++) {
        if(i != j) {
            swap(matrix[i][j], matrix[j][i]);
        }
      }
   }

   // reverse 
   for(int i = 0; i < s; i++) {
      for(int j = 0; j < s/2; j++) {
         swap(matrix[i][j], matrix[i][s-j-1]);
      }
   }
}  
int main() {
   vector<vector<int>> matrix = {
      {1,2,3},
      {4,5,6},
      {7,8,9}
   };
   rotateMatrix(matrix, 3);
   for(auto r : matrix) {
      for(auto c : r) {
         cout << c << " ";
      }
      cout << endl;
   }
   return 0;
}