#include<bits/stdc++.h>
using namespace std;

// fibonacci series/number
int fibonacciNumber(int n) {
   if(n == 0 || n == 1) return n;
   
   return (fibonacciNumber(n-1) + fibonacciNumber(n-2));
}

// sort an array : using loops
void sortArray(int i, vector<int> &vec, int n) {
   for(int i = 0; i < n-1; i++) {
      for(int j = 0; j < n-i-1; j++) {
         if(vec[j] > vec[j+1]) swap(vec[j], vec[j+1]);
      }
   }
}

// check sorted array- use recursion
bool isSorted(vector<int> &v, int i) {
   if(i == v.size()-1) return true; // base for smallest slice/single element array
   if(v[i] > v[i+1]) return false; // check for that one element: 1st > 2nd ?
   return isSorted(v, i+1); // assume will return correct op for rest of the portion
}

// find max in array-
int findMax(vector<int> &v, int i) {
   if(i == v.size()-1) return v[i]; // Base: smallest slice
   int maxOfRest = findMax(v, i+1);
   return (v[i] > maxOfRest) ? v[i] : maxOfRest; 
}

int main() { 
   // int n = 0;
   // cin >> n;
   cout << fibonacciNumber(8) << endl;

   vector<int> vec = {9, 10, 3, 6, 8, 0, 1};
   sortArray(0, vec, vec.size());
   for(auto x : vec) {
      cout << x << ' ';
   }
   cout << endl;

   cout << isSorted(vec, 0) << endl;
   cout << findMax(vec, 0) << endl;

   return 0;
}