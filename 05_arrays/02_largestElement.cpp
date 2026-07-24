#include <bits/stdc++.h>
using namespace std;

int main() {
   vector<int> nums = {3, 4, 2, 13, 56, 77, 3, 0};
   int largest = nums[0];

   for(int i = 0; i < nums.size(); i++) {
      if(nums[i] > largest) {
         largest = nums[i];
      }
   }

   cout << largest << endl;
   // T.C = O(n);

   return 0;
}