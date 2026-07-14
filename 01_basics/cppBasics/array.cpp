#include<bits/stdc++.h>
using namespace std;

int main() {
   int arr[4];
   cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
   cout << arr[2] << endl; 

   // 2D array
   int a[3][5]; 

   a[1][4] = 200;
   cout << a[1][4] << endl;
   cout << a[2][2]; // garbage value;

   return 0;
}