// Practice Problems:
// 1. Write a function swapValues(int a, int b) using pass-by-value and show it does NOT swap the original values. Then rewrite it using pass-by-reference and show it DOES swap them.
// 2. Write a function that takes a pointer to an integer and doubles the value it points to.
// 3. Declare an array of 5 integers, write a function int findMax(int arr[], int size) that returns the largest element.
// 4. Write a function reverseArray(int arr[], int size) that reverses an array in-place (no extra array) — this forces you to think about indices and swapping, which is core DSA thinking.
// 5. Create a 2D array (3x3), write a function to print it row by row, and another to find the sum of all elements.
// Practice struct:
// 6. Create a struct Book with title (string), pages (int), and price (float). Create 2 Book variables, fill their data, and print them.
// 7. Write a function void printBook(Book b) that takes a Book by value and prints it. Then write void printBookRef(Book &b) that takes it by reference. Call both — behavior looks the same here, but think about why reference is more efficient for structs (hint: think about what "copying" means when the struct has multiple fields, especially a string).
// 8. Create a struct Node with int data and Node* next (exactly like above). Manually create 3 nodes, link them together (node1->next = node2, etc.), and print all 3 values using the ->next->next chaining shown above.

#include<bits/stdc++.h>
using namespace std;

void swapValues_A(int a, int b) {
   int temp = a;
   a = b;
   b = temp;
}
void swapValues_B(int &a, int &b) {
   int temp = a;
   a = b;
   b = temp;
}
void doubleValue(int *x) {
   *x *=2;
}
int findMax(int arr[], int size) {
   int max = arr[0];
   for(int i = 1; i < size; i++) {
      max = (max <= arr[i]) ? arr[i] : max;
   }
   return max;
}
void reverseArr(int arr[], int size) {
   for(int i = 0; i < size/2; i++) {
      int temp = arr[i];
      arr[i] = arr[size-i-1];
      arr[size-i-1] = temp;
   }
}
void printMatrix(int mtrx[][3], int rows, int cols) {
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
         cout << mtrx[i][j] << ' ';
      }
      cout << endl;
   }
}
int findSum(int mtrx[][3], int rows, int cols) {
   int sum = 0;
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
         sum += mtrx[i][j];
      }
   }
   return sum;
}
// struct:
struct Book {
   string title;
   int pages;
   float price;
};
void printBook(Book b) {
   b.title = "Rich Daddy";
   cout << b.title << endl;
}
void printBookRef(Book &b) {
   b.title = "Power Laws";
   cout << b.title << endl;
}
struct Node {
   int data;
   Node* next;
};

int main() {
   //1:
   int a = 10, b = 20;
   swapValues_A(a, b);
   cout << "a: " << a << '\n' << "b: " << b << endl << endl;
   swapValues_B(a,b);
   cout << "a: " << a << '\n' << "b: " << b << endl << endl;
   
   //2:
   int x = 20;
   doubleValue(&x);
   cout << "x: " << x << endl << endl;

   //3:
   int arr[5] = {1, 2, 0, 4, 5};
   cout << "max: " << findMax(arr, 5) << endl;

   //4:
   for(auto val : arr) {
      cout << val << ' ';
   }
   cout << endl;

   reverseArr(arr, 5);
   for(auto val : arr) {
      cout << val << ' ';
   }

   //5: 
   int matrix[3][3] = {
      {1, 2, 3}, 
      {10, 20, 30}, 
      {4, 5, 6}
   };
   cout << endl;
   printMatrix(matrix, 3, 3);
   cout << endl << findSum(matrix, 3, 3) << endl;

   //6: 
   Book bookOne = {"Atomic Habits", 400, 40.45};
   Book bookTwo = {"Subtle art of not giving a fuck", 200, 85.20};
   cout << bookOne.title << ' ' << bookOne.pages << ' ' << bookOne.price << endl;   
   cout << bookTwo.title << ' ' << bookTwo.pages << ' ' << bookTwo.price << endl;   

   //7:
   printBook(bookOne);
   cout << bookOne.title << endl;
   printBookRef(bookTwo); // pass by reference is more efficient because : imagine bigger data or 100 data fields ina n struct, conpying them on every fucntion call will waste lot of memory and time.
   cout << bookTwo.title << endl;

   //8:
   Node* first = new Node();
   first->data = 10;
   first->next = nullptr;

   Node* second= new Node();
   second->data = 20;
   second->next = nullptr;

   Node* third = new Node();
   third->data = 30;
   third->next = nullptr;
   
   first->next = second;
   second->next = third;

   cout << first->data << endl;
   cout << first->next->data << endl;
   cout << first->next->next->data << endl;

   return 0;
}