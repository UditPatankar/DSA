#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Find the Nth root of M (i.e., find an integer X such that X^N = M).
If no exact integer root exists, return -1.

Key Idea:
- Use Binary Search in range [1, M] to find candidate 'mid'.
- To prevent integer overflow when calculating mid^N, multiply step-by-step 
  and exit early as soon as the product exceeds M.
*/

// Helper function to safely compute mid^N relative to M:
// Returns:
// 1 -> if mid^N == M (Exact match)
// 0 -> if mid^N < M  (Need a bigger number)
// 2 -> if mid^N > M  (Need a smaller number)
long long power(int mid, int N, int M) {
   long long ans = 1;
   
   for(int i = 1; i <= N; i++) {
      ans *= mid;
      
      // Stop early if ans exceeds M to avoid integer overflow
      if(ans > M) return 2;
   }
   
   if(ans == M) return 1; // Exact match found
   return 0;              // ans < M
} 

int NthRoot(int N, int M) {
   int low = 1; 
   int high = M;

   // Binary search for the Nth root
   while(low <= high) {
      int mid = low + ((high - low) / 2);
      
      int midN = power(mid, N, M);
      
      // Exact root found!
      if(midN == 1) return mid;
      
      // mid^N < M -> mid is too small, look in the right half
      else if(midN == 0) low = mid + 1;
      
      // mid^N > M -> mid is too big, look in the left half
      else high = mid - 1;
   }
   
   // No integer Nth root exists
   return -1;
}

int main() {
   int N = 3;
   int M = 8;
   int X = NthRoot(N, M);
   
   cout << "The " << N << "th root of " << M << " is: " << X << endl; // Output: 2
   return 0;
}