// 1. Create an empty vector, push 5 user-relevant values into it (e.g., 10,20,30,40,50), 
// then remove the last two using pop_back, and print the final vector.
// 2. Write a function void insertAtBeginning(vector<int>& v, int val) 
// that inserts val at index 0 (use insert).
// 3. Write a function int sumVector(vector<int>& v) 
// that returns sum of all elements — use a range-based for loop.
// 4. Create a vector<vector<int>> of size 3x3, 
// fill it with values 1 to 9 using nested loops (not manual initialization), then print it.

#include<bits/stdc++.h>
using namespace std;

void insertAtBeginning(vector<int> &v, int val) {
   v.insert(v.begin(), val);
}
int sumVector(vector<int> &v) {
   int sum = 0;
   for(auto val : v) {
      sum += val;
   }
   return sum;
}

int main() {
   //1:
   vector<int> v;
   v.push_back(10);
   v.emplace_back(20);
   v.push_back(30);
   v.push_back(10);
   v.push_back(40);
   v.pop_back();

   for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
      cout << *it << ' ';
   }
   cout << endl;

   //2:
   insertAtBeginning(v, 5);
   for(auto val : v) {
      cout << val << ' ';
   }
   cout << endl;

   //3:
   cout << sumVector(v) << endl;

   //4:
   vector<vector<int>> matrix(3, vector<int>(3, 0));
   int incr = 1;
   for(auto &row : matrix) {
      for(auto &val : row) {
         val += incr;
         incr++;
      }
   }

   for(auto row : matrix) {
      for(auto val : row) {
         cout << val << ' ';
      }
      cout << endl;
   }
   cout << endl;

   return 0;
}