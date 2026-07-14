#include<bits/stdc++.h>
using namespace std;
// sum, factorial

//functional-
int sum(int n) {
   if(n == 1) return 1; // base
   return sum(n-1) + n; // hypothessi + induction
}
int factorial(int n) {
   if(n == 0) return 1;
   return n * factorial(n-1);
}

//parameterized-
int sum(int i, int n) {
   if(i == n) return n;
   return i + sum(i+1, n);
}
int factorial(int i, int n) {
   if(i == n) return n;
   return i * factorial(i+1, n);
}

int main() {
   cout << sum(4) << endl; 
   cout << factorial(4) << endl;

   //__________
   cout << sum(1, 4) << endl;
   cout << factorial(1, 4) << endl;

   return 0;
}