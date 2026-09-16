#include <bits/stdc++.h>
using namespace std;

// KADANE
/* 
Think about what can happen when nums[i] arrives
Suppose:
nums[i] = x
A maximum/minimum product ending at this position can come from three possibilities:
Option 1: Start a new subarray
x
Maybe the previous product is hurting us.
Example:
[-2, 3]
At 3:
3
is better than:
-2 × 3 = -6
So we need nums[i]. */

/* Option 2: Extend the previous maximum
prevMax × x
Example:
[2, 3]
At 3:
prevMax = 2
2 × 3 = 6
Good. */

/* Option 3: Extend the previous minimum
This is the important one.
Suppose:
[-2, 3, -4]
Before -4:
prevMax = 3
prevMin = -6
Now multiply by -4:
prevMax × -4 = 3 × -4 = -12
prevMin × -4 = -6 × -4 = 24
The previous minimum became the new maximum! */

long long maxProdSubarray(vector<int> &nums) {
   int n = nums.size();
   long long maxProd = nums[0];

   // we need to track both min product & max product "so far"
   // coz in future the min product can give us the final max product
   long long currMin = nums[0];
   long long currMax = nums[0];

   for(int i = 1; i < n; i++) {
      // at previous index
      long long prevMin = currMin;
      long long prevMax = currMax;

      // at current index, 3 possible currMin, currMax, maxProduct
      // nums[i] itself, extend min, extend max
      currMin = min({   
         (long long)nums[i],
         prevMin * nums[i],
         prevMax * nums[i]
      });
      currMax = max({
         (long long)nums[i],
         prevMin * nums[i],
         prevMax * nums[i]
      });
      maxProd = max(maxProd, currMax);
   }

   return maxProd;
}

/* long long maxProdSubarray(vector<int> &nums) {
   int n = nums.size();
   long long maxProd = nums[0];
   long long prefixProd = 1;
   long long suffixProd = 1;

   for(int i = 0; i < n; i++) {
      prefixProd = prefixProd == 0 ? 1 : prefixProd;
      suffixProd = suffixProd == 0 ? 1 : suffixProd;

      prefixProd *= nums[i];
      suffixProd *= nums[n-1-i];

      maxProd = max({maxProd, prefixProd, suffixProd});
   }

   return maxProd;
} */

int main() {
   vector<int> nums = {2,3,-2,-5,6,0,-1,4};
   long long result = maxProdSubarray(nums);

   cout << result << endl;
   
   return 0;
}