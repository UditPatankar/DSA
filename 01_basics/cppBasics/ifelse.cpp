#include<bits/stdc++.h>
using namespace std;

int main() {
   int age;
   cin >> age;

   if(age < 18) {
      cout << "Not eligible.";
   }
   else if(age < 57) {
      cout << "eligible for job.";
      if(age >= 55) {
         cout << "retirement soon.";
      }
   }
   else if(age == 57) {
      cout << "retirement time.";
   }
   
   
   return 0;
}