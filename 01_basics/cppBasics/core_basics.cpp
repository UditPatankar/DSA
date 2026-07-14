#include<bits/stdc++.h>
using namespace std;

void increamentOne(int x) { //pass by value
   x += 1;
   cout << "Inside function: " << x << endl;
}
void increamentTwo(int &x) { //pass by reference
   x += 2;
   cout << "Inside function: " << x << endl;
}
void increamentThree(int *p) {
   *p += 3;
   cout << "Inside function: " << *p << endl;
}
void printArr(int arr[], int size) {
   for(int i = 0; i < size; i++) {
      //cout << arr[i] << ' ';
      cout << *arr << ' ';
      arr++;
   }
}

int main() {
   // POINTERS : stores an address

   int x = 10; // x is house, 10 is person living in it
   int* ptr = &x; // ptr holds address of house x

   cout << x << endl;
   cout << ptr << endl; // address
   cout << &x << endl; // address, & means 'address of'
   cout << *ptr << endl; // deference, * means go to the address ptr holds

   *ptr = 20; // go to address of x and update the value to 20
   cout << x << endl; // 20
   ptr = nullptr;
   
   // REFERENCES : is just an nick name for a variable

   int y = 30;
   int& ref = y; // y and ref both are two name for the same house
   cout << y << ref << endl;
   
   y = 40;
   cout << y << ref << endl;
   cout << &y <<  ' ' << &ref << endl; // same address
   
   // pointer vs reference :-
   int a = 10, b = 20;
   int* p = &a;
   int& r = a;
   p = &b; // p switched target address from a->b
   r = b; // r or a = copied value of b
   cout << *p << ' ' << a << endl;

   // -------------------------------
   // Pass by value/reference/pointer:-
   int m = 10;
   increamentOne(m); // 11
   cout << "Outside fucntion: " << m << endl; // 10
   increamentTwo(m); // 12
   cout << "Outside fucntion: " << m << endl; // 12
   increamentThree(&m); // 15
   cout << "Outside fucntion: " << m << endl; // 15

   //-------------------------------
   // Array Deacay: when paased to fucntion array decays or converts to pointer
   int arr[5] = {1, 2, 3, 4, 5};
   printArr(arr, 5); // function gets the pointer pointing to first element

   return 0;
}