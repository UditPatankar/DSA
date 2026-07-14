#include<bits/stdc++.h>
using namespace std;

struct Student {
   string name;
   int age;
};

struct Node {
   int data;
   Node* next; // pointer for next node - this links nodes together
};

int main() {
   Student s1;
   s1.name = "Rahul";
   s1.age = 20;

   Student s2 = {"Riya", 19};
   Student* ptr = &s2;
   cout << (*ptr).name << endl;
   cout << ptr->name << ' ' << ptr->age << endl;

   // Node first = {10, nullptr};
   // Node second = {20, nullptr};
   // first.next = &second;

   // The above version is STACK version where variable first and second lives on stack - memory is managed automatically.
   // Below is the HEAP version - actual node lives on heap and the first and second are just pinters - you need to free the memory manually.

   Node* first = new Node(); // new will create a node on heap and will return it's address
   first->data = 10;
   first->next = nullptr;

   Node* second = new Node();
   second->data = 20;
   second->next = nullptr;

   first->next = second; // bcoz next is a pointer and second is holding address of node2, therefore now first's next is pointing to node2.
   // [Nodes1: 10 | next] -> [Node2: 20 | next] -> nullptr

   return 0;
}