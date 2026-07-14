#include<bits/stdc++.h>
using namespace std;

void print1(int n) {
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         cout << '*';
      }
      cout << endl;
   }   
}
void print2(int n) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= i; j++) {
         cout << '*';
      }
      cout << endl;
   }
}
void print3(int n) {
   for(int i = 1; i <=n; i++) {
      for(int j = 1; j <= i; j++) {
         cout << j;
      }
      cout << endl;
   }
}
void print4(int n) {
   for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= i; j++) {
         cout << i;
      }
      cout << endl;
   }
}
void print5(int n) {
   for(int i = 0; i < n; i++) {
      for(int j = 1; j <= n-i; j++) {
         cout << '*';
      }
      cout << endl;
   }
}
void print6(int n) {
   for(int i = 0; i < n; i++) {
      for(int j = 1; j <= n-i; j++) {
         cout << j;
      }
      cout << endl;
   }
}
void print7(int n) {
   for(int i = 0; i < n; i++) {
      //space
      for(int j = 1; j <= n-1-i; j++) {
         cout << ' ';
      }
      //star1
      for(int j = 1; j <= i+1; j++) {
         cout << '*';
      }
      //star2
      for(int j = 1; j <= i; j++) {
         cout << '*';
      }
      cout << endl;
   }
}
void print701(int n) {
   for(int i = 0; i < n; i++) {
      // space
      for(int j = 1; j <= (n-i-1); j++) {
         cout << ' ';
      }
      // stars
      for(int j = 1; j <= ((2*i)+1); j++) {
         cout << '*';
      }
      // space 
      for(int j = 1; j <= (n-i-1); j++) {
         cout << ' ';
      }
      cout << endl;
   }
}
void print8(int n) {
   for(int i = 0; i < n; i++) {
      //space
      for(int j = 1; j <= i; j++) {
         cout << '_';
      }
      //stars
      for(int j = 1; j <= 2*(n-i)-1; j++) {
         cout << '*';
      }
      //space 
      for(int j = 1; j <= i; j++) {
         cout << '_';
      }
      cout << endl;
   }
}
void print9(int n) {
   // first half
  for(int i = 0; i < n/2; i++) {
      for(int j = 1; j <= (n/2)-i-1; j++) {
         cout << ' ';
      }
      for(int j = 1; j <= 2*i+1; j++) {
         cout << '*';
      }
      for(int j = 1; j <= (n/2)-i-1; j++) {
         cout << ' ';
      }
      cout << endl;
  }

  //second half
  for(int i = 0; i < n/2; i++) {
      for(int j = 1; j <= i; j++) {
         cout << ' ';
      }
      for(int j = 1; j <= 2*(n/2 - i)-1; j++) {
         cout << '*';
      }
      for(int j = 1; j <= i; j++) {
         cout << ' ';
      }
      cout << endl;
  }
}
void print10(int n) {
   for(int i = 1; i <= 2*n-1; i++) {
      int stars = i;
      if(i > n) stars = 2*n-i;
      for(int j = 1; j <= stars; j++) {
         cout << '*';
      }
      cout << endl;
   }
}
void print11(int n) {
   for(int i = 1; i <= n; i++) {
      int x = i%2==0 ? 0 : 1;
      for(int j = 1; j <= i; j++) {
         cout << x;
         x = !x;
      }
      cout << endl;
   }
}
void print12(int n) {
   for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= i; j++) cout << j;
      for(int j = 1; j <= 2*(n-i); j++) cout << ' ';
      for(int j = i; j >= 1; j--) cout << j;
      cout << endl;
   }
}
void print13(int n) {
   int x = 1;
   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= i; j++) {
         cout << x << ' ';
         x++;
      }
      cout << endl;
   }
}
void print14(int n) {
  for(int i = 1; i <= n; i++) {
      for(char ch = 'A'; ch < 'A'+i; ch++) {
         cout << ch << ' ';
      }
      cout << endl;
  }
}
void print15(int n) {
   for(int i = 1; i <= n; i++) {
      for(char ch = 'A'; ch <= 'A'+(n-i); ch++) {
         cout << ch;
      }
      cout << endl;
   }
}
void print16(int n) {
   char ch = 'A';
   for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= i; j++) {
         cout << ch;
      }
      cout << endl;
      ch++;
   }
}
void print17(int n) {
   for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n-i; j++) cout << ' '; // space
      for(int j = 0; j < i; j++) cout << (char)('A'+j); // first half
      for(int j = i; j > 1; j--) cout << (char)('A'+j-2); // second half
      cout << endl;
   }
}
void print18(int n) {
   for(int i = 1; i <= n; i++) {
      for(int j =0; j < i; j++) cout << (char)('A'+(n-i)+j) << ' ';
      cout << endl;
   }
}
void print19(int n) {
   for(int i = 1; i <= 2*n; i++) {
      int stars = i<=n ? (n-i+1) : i-n;
      int spaces = i<=n ? 2*i-2 : (2*n-i)*2;
      for(int j = 1; j <= stars; j++) cout << '*';
      for(int j = 1; j <= spaces; j++) cout << ' ';
      for(int j = 1; j <= stars; j++) cout << '*';
      cout << endl;
   }
}
void print20(int n) {
   for(int i = 1; i < 2*n; i ++) {
      int stars = i<=n ? i : 2*n-i;
      int spaces = i<=n ? 2*(n-i) : i-(2*n-i);
      for(int j = 1; j <= stars; j++) cout << '*';
      for(int j = 1; j <= spaces; j++) cout << ' ';
      for(int j = 1; j <= stars; j++) cout << '*';
      cout << endl;
   }
}
void print21(int n) {
   for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
         cout << ((i==1 || i==n || j==1 || j==n) ? '*' : ' ');
      }
      cout << endl;
   }
}
// concentric square pattern
void print22(int n) {
   for(int i = 0; i < 2*n-1; i++) {
      for(int j = 0; j < 2*n-1; j++) {
         int right = (2*n-2)-j;
         int left = j;
         int top = i;
         int bottom = (2*n-2)-i;

         cout << n-(min({right, left, top, bottom})) << ' ';
      }
      cout << endl;
   }
}
// sequential matrix
void print23(int n) {
   //int num = 1;
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         cout << n*i+j+1 << ' ';
      }
      cout << endl;
   }
}
//snake matrix
void print24(int n) {
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         if(i%2==0) {
            cout << n*i+j+1 << ' ';
         }
         else {
            cout << n*i+(n-j) << ' ';
         }
      }
      cout << endl;
   }
}


int main() {
   int t;
   cin >> t;
   for(int i = 1; i <= t; i++) { 
      int n;
      cin >> n;
      print24(n);
   }

   return 0;
}


