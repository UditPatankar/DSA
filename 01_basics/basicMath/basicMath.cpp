#include<bits/stdc++.h>
using namespace std;

// COUNT DIGIT:
int countDigits(int n) { // O(log10 n) coz the loop will run = number of times you are diving by 10
   int count = 0;
   while(n > 0) {
      n = n/10;
      count++;
   }
   //or
   //int count = (int) (log10(n) + 1);
   return count;
}

// REVERSE NUMBER:
int reverseNumber(int n) { // O(log10(n))
   int rev = 0;
   while(n > 0) {
      int temp = n % 10;
      n = n/10;
      rev = (rev*10) + temp;
   }
   return rev;
}

//PALINDROME:
bool isPanlindrome(int n) { // O(log10(n))
   int org = n;
   int rev = 0;
   while(n > 0) {
      int last = n % 10;
      n = n/10;
      rev = (rev * 10) + last;
   }
   return (rev == org);
}

//ARMSTRONG:
bool isArmstrong(int n) {
  int org = n;
  int dup = n;
  int digit = 0;
  int sum = 0;

  while(n > 0) { //O(log10(n))
   n = n/10;
   digit++;
  }

  while(dup > 0) { //O(log10(n))
      int temp = dup % 10;
      dup = dup/10;
      sum += round(pow(temp, digit));
  }
  return (sum == org);
}

//PRINT THE DIVISORS:
void printDivisor(int n) { 
   int d = 1;
   // while(d <= n) { //O(n)
   //    if(n % d == 0) 
   //       cout << d << ' ';
   //    d++;
   // }
   // cout << endl;
   vector<int> v;
   for(int i = 1; i*i <= n; i++) { //O(sqrt(n))
      if(n % i == 0) {
         v.push_back(i);
         if(n/i != i) v.push_back(n/i);
      }
   }
   sort(v.begin(), v.end()); // (d log(d)); d=number of divisors
   for(auto x : v) cout << x << ' '; // O(d)
   cout << endl;
}

//PRIME NUMBER:
bool isPrime(int n) {
   if(n <= 1) return false;
   if(n == 2) return true;
   if(n % 2 == 0) return false;

   for(int i = 2; i*i <= n; i++) { //O(sqrt(n))
      if(n % i == 0) return false;
   }
   return true;
}

//GCD:
int findGCD(int a, int b) {
   while(b != 0) {
      int rem = a % b;  
      a = b;
      b = rem;
   }
   return a;
}

// FIBONACCI SERIES -
void printFibonacciSeries(int n) {
   if(n == 0) return;
   if(n == 1) { cout << 0 << endl; return; }

   long long prev = 0;
   long long curr = 1;
   cout << prev << ' ' << curr;

   for(int i = 3; i <= n; i++) {
      long long next = prev + curr;
      cout << ' ' << next;
      prev = curr;
      curr = next;
   }
   cout << endl;
}
// FIBONACCI NUMBER -
void printFibonacciNumber(int n) {
   if(n == 0 || n == 1) { cout << n << endl; return; }

   long long prev = 0;
   long long curr = 1;

   for(int i = 2; i <= n; i++) {
      long long next = prev + curr;
      prev = curr;
      curr = next;
   }
   cout << curr << endl;
}

int main() {
   cout << countDigits(77899) << endl;
   cout << reverseNumber(10400) << endl;
   cout << isPanlindrome(1221) << endl;
   cout << isArmstrong(1634) << endl;
   printDivisor(35);
   cout << isPrime(5) << endl;
   cout << findGCD(28, 42) << endl;
   printFibonacciSeries(69);
   printFibonacciNumber(8);

   return 0;
}