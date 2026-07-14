#include<bits/stdc++.h>
using namespace std;

//Approach: IBH
//1. what function does?
//2. Base case: what smallest/simplest input gives?
//3. Hypothesis: what smaller input gives? (assume it's correct)
//4. Induction: one operation to combine that into my answer
//5. Is the input shrinking towards the base case?

void printName(int n) {
   //1. prints name N times
   //2. on input 1 it prints name 1 time
   //3. on N-1 it shoult print name N-1 times
   //4. I just need to print name one time after (N-1)times is printed to get the final output/solution
   //5. yes, on every recursive call input shrinks towards the base cae
   if(n == 1) { // Base
      cout << "anshu" << endl; 
      return;
   } 
   printName(n-1); // Hypothesis/Recursive call: assume it prints 1 to (n-1) times
   cout << "anshu" << endl; // Induction step
   //time & space: O(n)
}
void printNumbers(int n) {
   if(n == 1) {
      cout << 1 << ' ';
      return;
   }
   printNumbers(n-1); // assume it prints 1 to n-1 correctly 
   cout << n << ' ';
}
void printNumbers_rev(int n) {
   if(n == 1) {
      cout << 1 << ' ';
      return;
   }
   cout << n << ' '; // Induction: print n
   printNumbers_rev(n-1); // Hypothesis: assume it print (n-1) to 1 correctly
}

//------------------------------
void printName(int i, int n) {
   if(i > n) return;
   cout << "anshu" << endl; 
   printName(i+1, n);
      // OR - both will produce the same output but the only difference is direction of there work : going down/coming backup
   // printName(i+1, n);
   // cout << "anshu" << endl;
}
void printNumbers(int i, int n) {
   if(i > n) return;
   cout << i << ' ';
   printNumbers(i+1, n);
}
void printNumbers_rev(int i, int n) {
   if(i < 1) return;
   printNumbers_rev(i-1, n);
   cout << i << ' ';
}

int main() {
   // Use of "FUNCTIONAL Recursion"-

   printName(4); // print name N times
   printNumbers(9); // print 1 to n numbers
   cout << endl;
   printNumbers_rev(9); // print n to 1 numbers
   cout << endl;

   // Use of "PARAMETERIZED Recursion"-
   
   printName(1, 4);
   printNumbers(1, 9);
   cout << endl;
   printNumbers_rev(9, 9);
   cout << endl;

   return 0;
}