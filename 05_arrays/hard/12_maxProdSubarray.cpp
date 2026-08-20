#include <bits/stdc++.h>
using namespace std;

// MAXIMUM PRODUCT SUBARRAY -

// # Brute Force - TC: O(N^2) & SC: O(1)
/* int maxProdSubarray(vector<int> &nums) {
   int maxProd = nums[0];

   for(int i = 0; i < nums.size(); i++) {
      int prod = 1;
      for(int j = i; j < nums.size(); j++) {
         prod *= nums[j];
         maxProd = max(maxProd, prod);
      }
   }

   return maxProd;
}
 */

// # Opitmal1 - TC: O(N) & SC: O(1)
/* int maxProdSubarray(vector<int> &nums) {
   int maxProd = nums[0];
   int currMax = nums[0];
   int currMin = nums[0];

   for(int i = 1; i < nums.size(); i++) {
      int prevMax = currMax;
      int prevMin = currMin;

      currMax = max({
         nums[i],
         prevMax * nums[i],
         prevMin * nums[i]
      });

      currMin = min({
         nums[i],
         prevMin * nums[i],
         prevMax * nums[i]
      });

      maxProd = max(maxProd, currMax);
   }

   return maxProd;
} */

// # Optimal2 - TC: O(N) & SC: O(1) 
int maxProdSubarray(vector<int> &nums) {
   int n = nums.size();
   int maxProd = nums[0];
   int prefix = 1; 
   int suffix = 1;

   for(int i = 0; i < n; i++) {
      // if prefix or suffix hits 0, update it to 1
      prefix = prefix == 0 ? 1 : prefix;
      suffix = suffix == 0 ? 1 : suffix;

      prefix *= nums[i];
      suffix *= nums[n-1-i];

      maxProd = max({maxProd, prefix, suffix});
   }

   return maxProd;
}

int main() {
   vector<int> nums = {2, 3, -2, 4, -2, 0, -1}; // {2, 0, 3, 2};
   int result = maxProdSubarray(nums);

   cout << result << endl;
   
   return 0;
}