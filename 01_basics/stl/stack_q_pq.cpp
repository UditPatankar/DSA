// Practice Problems — Stack/Queue/Priority_queue

//1. Push {10, 20, 30, 40} onto a stack, then pop elements one by one and print them 
   // (should print in reverse: 40 30 20 10) — this demonstrates LIFO behavior directly.
//2. Push {10, 20, 30, 40} onto a queue, then pop elements one by one and print them 
   // (should print in original order: 10 20 30 40) — demonstrates FIFO.
//3. Write a function bool isBalanced(string s) that checks if brackets in a string are balanced — 
   // e.g., "(())" → true, "(()" → false. Use a stack: push ( when seen, pop when ) is seen, 
   // return false if you try to pop an empty stack. 
   // (This is a genuinely famous interview question — good one to have in your back pocket early.)
//4. Given vector<int> v = {5, 2, 8, 1, 9}, push all into a max-heap priority_queue and pop all elements,
   // printing them (should print in descending order: 9 8 5 2 1). Then do the same with a min-heap (should print ascending).

#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string s) {
   stack<char> st;
   for(auto c : s) {
      if(c == '(') {
         st.push(c);
      }
      else if(c == ')') {
         if(st.empty()) return false;
         st.pop();
      }
   }
   return st.empty();
}

int main() {
   //1:
   stack<int> s;
   s.push(10);
   s.push(20);
   s.push(30);
   s.push(40);
   for(int i = 1; i < 5; i++) {
      cout << s.top() << ' ';
      s.pop();
   } // 40 30 20 10  LIFO
   cout << endl;

   //2:
   queue<int> q;
   q.push(10);
   q.push(20);
   q.push(30);
   q.push(40);
   for(int i = 1; i < 5; i++) {
      cout << q.front() << ' ';
      q.pop();
   } // 10 20 30 40  FIFO
   cout << endl;

   //3:
   cout << isBalanced("())") << endl;
   cout << isBalanced("(((") << endl;
   cout << isBalanced("((()))") << endl;
   cout << isBalanced("(()(()") << endl;
   
   //4:
   vector<int> v = {5, 2, 8, 1, 9};
   priority_queue<int> pq; //max-heap
   for(auto x : v) {
      pq.push(x);
   }
   for(int i = 0; i < v.size(); i++) {
      cout << pq.top() << ' ';
      pq.pop();
   }
   cout << endl;

   priority_queue<int, vector<int>, greater<int>> minPq; // min-heap
   for(auto x : v) {
      minPq.push(x);
   }
   for(int i = 0; i < v.size(); i++) {
      cout << minPq.top() << ' ';
      minPq.pop();
   }
   cout << endl;

   return 0;
}