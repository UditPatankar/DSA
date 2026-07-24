#include <bits/stdc++.h>
using namespace std;

int main() {
   vector<int> nums = {3, 4, 2, 13, 56, 77, 3, 0};
   long long max1 = LLONG_MIN;
   long long max2 = LLONG_MIN;

   for(int i = 0; i < nums.size(); i++) {

      if(nums[i] > max1) {
         max2 = max1;
         max1 = nums[i];
      }
      else if(nums[i] > max2 && nums[i] != max1) {
         max2 = nums[i];
      }
   }

   if(max2 == LLONG_MIN) {
      cout << "max2 does not exist!" << endl;
   } 
   else {
      cout << max2 << endl;
   }
   // T.C = O(n);

   return 0;
}