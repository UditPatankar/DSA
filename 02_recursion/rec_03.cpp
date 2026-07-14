#include<bits/stdc++.h>
using namespace std;
// reverse array, check palindrome

void reverseArray(int i, vector<int> &v, int n) {
   if(i >= n/2) return;
   swap(v[i], v[n-1-i]);
   reverseArray(i+1, v, n);
}

bool isPalindrome(int i, string s) {
   if(i >= s.size()/2) return true;
   if(s[i] != s[s.size()-1-i]) return false;
   return isPalindrome(i+1, s);
}

int main() {
   int n = 0;
   cin >> n;
   vector<int> v(n);
   for(auto &x : v) cin >> x;
   for(auto x : v) cout << x << ' ';
   cout << endl;
   reverseArray(0, v, n); 
   for(auto x : v) cout << x << ' '; 
   cout << endl;

   cout << "is palindrome: " << isPalindrome(0, "racecar") << endl;
   
   return 0;
}