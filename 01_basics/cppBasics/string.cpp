#include<bits/stdc++.h>
using namespace std;

int main() {
   string s = "Programming";
   cout << s[0] << endl;
   s[s.size()] = '!';
   cout << s.size();
   cout << s[s.size()];

   return 0;
}