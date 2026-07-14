#include<bits/stdc++.h>
using namespace std;

// //void
// void printName() {
//    cout << "Udit" << endl;
// }

// //return 
// int giveAge() {
//    return 22;
// }

// //parameterized
// void print(string s) {
//    cout << s << endl;
// }

// int main() {
//    printName();
//    cout << giveAge() << endl;
//    print("Good Morning");

//    return 0;
// }

// pass by value (copy)
void doAddition(int num) {
   cout << num << endl;
   num += 5;
   cout << num << endl;
   num += 5;
   cout << num << endl;
}

// pass by reference
void changeIt(string &str) {
   str[0] = 'T';
}

int main() {
   int num = 10;
   doAddition(num); 
   cout << num << endl;

   string str = "Raj";
   changeIt(str);
   cout << str << endl;
   return 0;
}