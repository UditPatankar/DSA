#include <bits/stdc++.h>
using namespace std;

/* Array representing a permutation of the integers from 1 to n with one element missing. Find the missing element in the array. */

// #Brute Force - TC: O(n^2) & SC: O(1)
/* int findMissing(vector<int> &nums, int m) {
   for(int i = 1; i <= m; i++) {
      int found = 0;
     
      for(int j = 0; j < nums.size(); j++) {
         if(nums[j] == i) {
            found = 1;
            break;
         }
      }
      if(found == 0) return i;
   }
   return 0;
}  */

// Better - TC: O(n) & SC: O(n)
/* int findMissing(vector<int> &nums, int m) {
   vector<int> hArr(m+1);

   for(auto x : nums) {
      hArr[x]++;
   }
   
   for(int i = 1; i <= m; i++) {
      if(hArr[i] == 0) return i;
   }

   return 0;
} */

// Optimal1 - TC: O(n) & SC: O(1)
/* int findMissing(vector<int> &nums, int m) {

   // find sum from 1 to m
   int sum1 = (m * (m + 1)) / 2;
 
   // find sum of array
   int sum2 = 0;
   for(auto x : nums) {
      sum2 += x;
   }

   return sum1 - sum2;
} */

// Optimal2 - TC: O(n) & SC: O(1) *** this is better coz xor never gets larger than the largest value, but the sum (in previous solution) can go beyond and we might need long long for it, this is slightly better in SC
int findMissing(vector<int> &nums, int m) {
   
   int xorSum = 0;

   for(int i = 0; i < nums.size(); i++) {
      xorSum = xorSum^(i+1); // this xors everything from 1 to m-1, coz if m is 8 then array size is 7 & last index will be 6
      xorSum = xorSum^nums[i]; // here the missing element never enters the xor sum, so it never gets cancel out
   }
   // for(auto x : nums) {
   //    xorSum = xorSum^x;
   // }
   return xorSum^m;
}

int main() {
   vector<int> nums = {8, 7, 2, 4, 1, 5, 3};
   int m = 8;
   cout << findMissing(nums, m) << endl;

   return 0;
}