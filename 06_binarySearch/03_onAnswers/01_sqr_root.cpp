#include <bits/stdc++.h>
using namespace std;

/* 
Problem:
Given a positive integer `num`, find and return its square root.
If `num` is not a perfect square, return the floor value (the largest integer whose square is <= `num`).

Key Logic:
- The answer must lie in the range [1, num].
- If `mid * mid <= num`, then `mid` COULD be our answer. We save `mid` as a potential answer 
  and try searching for a LARGER valid number on the RIGHT side (`low = mid + 1`).
- If `mid * mid > num`, `mid` is too large, so we search for a SMALLER number on the LEFT side (`high = mid - 1`).
*/

int findSquareRoot(int num) {
   // Edge case: Square root of 0 is 0
   if (num == 0) return 0;

   int ans = 1;
   int low = 1;
   int high = num;

   while (low <= high) {
      int mid = low + ((high - low) / 2);

      // Use (long long) to prevent integer overflow when mid * mid is computed
      if ((long long)mid * mid <= num) {
         ans = mid;        // `mid` can be or answer, save it!
         low = mid + 1;    // Try to find a bigger candidate on the right
      } 
      else {
         high = mid - 1;   // `mid` square is too big, search on the left
      }
   }

   return ans;
}

int main() {
   int num = 35;
   int result = findSquareRoot(num);
   cout << "Square root of " << num << " is " << result << endl; 
   return 0;
}