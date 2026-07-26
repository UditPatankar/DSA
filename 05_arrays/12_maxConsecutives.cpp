#include <bits/stdc++.h>
using namespace std;

// return the maximum consecutive ones in the given array

// TC: O(n) & SC: O(1)
int findMaxConsecutives(vector<int> &nums) {

   int count = 0;
   int maxOnes = 0;
   for(auto x : nums) {
      if(x == 1) {
         count++;
      }
      else {
         maxOnes = (count > maxOnes) ? count : maxOnes;
         count = 0;
      }
   }

   // what if max cons are at last - 
   return (count > maxOnes) ? count : maxOnes;
}

int main() {
   vector<int> nums = {1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1};
   cout << findMaxConsecutives(nums) << endl;

   return 0;
}