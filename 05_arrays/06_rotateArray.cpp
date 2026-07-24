#include <bits/stdc++.h>
using namespace std;

// "left-rotate" array by k place

// #Brute Force: TC: O(n) & SC: O(k)
/* void rotate(vector<int> &nums, int k) {
   int n = nums.size();
   if(n <= 1) return;

   k = k % n;
   if(k == 0) return; // multiples of k

   vector<int> temp(k);

   // copy first k elements
   for(int i = 0; i < k; i++) {
      temp[i] = nums[i];
   }

   // shift rest of them to front
   for(int i = k; i < n; i++) {
      nums[i-k] = nums[i]; 
   }

   // put back the first k elements at end
   for(int i = n-k; i < n; i++) {
      nums[i] = temp[i-(n-k)];
   }
} */

// Optimal: TC: O(n) & SC: O(1)
void reverse(vector<int> &a, int start, int end) {
   int i = start;
   int j = end - 1;

   while(i < j) {
      swap(a[i++], a[j--]);
   }
}

void rotate(vector<int> &nums, int k) {
   int n = nums.size();
   if(n <= 1) return;

   k = k % n;
   if(k == 0) return;

   reverse(nums, 0, k); // O(k)
   reverse(nums, k, n); // O(n-k)
   reverse(nums, 0, n); // O(n)

   // TC: O(k + n - k + n) = O(2n) -> O(n)
   // SC: O(1)
}


int main() {
   vector<int> nums = {1, 2, 2, 3, 4, 5, 6, 6, 7};
   rotate(nums, 3);

   for(auto x : nums) {
      cout << x << " ";
   }

   return 0;
}