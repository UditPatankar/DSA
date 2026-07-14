#include<bits/stdc++.h>
using namespace std;

int main() {
   // suppose it is mentioned that only lower-case/only upper-case alphabets are used - just take hash[26]
   string s = "Hello World";   
   int hash[256] = {0};

   // pre-compute
   for(auto c : s) {
      hash[c]++;
   }
   // fetching
   cout << hash[' '] << endl;

   // *Note: for character hashing we can always use array, coz there are only 256 characters/symbols

   return 0;
}