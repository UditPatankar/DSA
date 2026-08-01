#include <bits/stdc++.h>
using namespace std;

// MAXIMUM SUBARRAY - out of all the subarray which gives maximum sum

// # Brute Force - TC: O(N^2) & SC: O(1)
/* vector<int> findMaxSubarray(vector<int> &nums) {
   vector<int> maxSubarray;

   int start = -1;
   int end = -1;
   int maxi = nums[0];

   for(int i = 0;i < nums.size(); i++) {
      int sum = 0;
      for(int j = i; j < nums.size(); j++) {
         sum += nums[j];
         if(sum > maxi) {
            maxi = sum;
            start = i;
            end = j;
         }
      }
   }

   for(int i = start; i <= end; i++) {
      maxSubarray.push_back(nums[i]);
   }

   return maxSubarray;
}
 */


// # Kadane's Algorithm :
   // - keep adding up
   // - check & update the max
   // - "Do not carry negative (keep the sum >= 0)" 

// # Optimal - TC: O(N) & SC: O(1) 
vector<int> findMaxSubarray(vector<int> &nums) {
   vector<int> maxSubarray;
   int maxi = INT_MIN;
   int start = -1;
   int end = -1;
   int sum = 0;

   for(int i = 0; i < nums.size(); i++) { 
      if(sum == 0) start = i; 
      sum += nums[i]; // keep adding up

      if(sum > maxi) { // update the max
         maxi = sum;
         end = i;
      }

      if(sum < 0) sum = 0; // do not carry negative sum
   }

   for(int i = start; i <= end; i++) {
      maxSubarray.push_back(nums[i]);
   }

   return maxSubarray;
}

int main() {
   vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};
   vector<int> maxSubarray = findMaxSubarray(nums);

   for(auto x : maxSubarray) {
      cout << x << " ";
   }
   return 0;
}