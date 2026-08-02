#include <bits/stdc++.h>
using namespace std;

// REARRANGE ARRAY elements by sign - 
// having equal no of +ive & -ive elements, 
// arrange them alternatively such that each consecutive is of opposite sign
// first element should be +ive & preserve their relative order

// # Brute Force - TC:  O(N) & SC: O(N)
/* vector<int> rearrangeElements(vector<int> nums) {
   vector<int> pos;
   vector<int> neg;
   int p = 0;
   int n = 0;

   for(auto x : nums) {
      if(x > 0) pos.push_back(x);
      else neg.push_back(x);
   }

   for(int i = 0; i < nums.size(); i++) {
      if(i % 2 == 0) {
         nums[i] = pos[p++];
      }
      else {
         nums[i] = neg[n++];
      }
   }

   return nums;
} */  

// Better/Optimal - TC: O(N) & SC: O(1)
vector<int> rearrangeElements(vector<int> nums) {
   vector<int> newNums(nums.size());
   int p = 0;
   int n = 1;

   for(int i = 0; i < nums.size(); i++) { 
      if(nums[i] > 0) {
         newNums[p] = nums[i];
         p += 2;
      }
      else {
         newNums[n] = nums[i];
         n += 2;
      }
   }

   return newNums;
}

// variant 2-
vector<int> rearrangeArray(vector<int> &nums) {
   vector<int> pos, neg;

   for(auto x : nums) {
      if(x > 0) pos.push_back(x);
      else neg.push_back(x);
   }

   if(pos.size() > neg.size()) {
      for(int i = 0; i < neg.size(); i++) {
         nums[i*2] = pos[i]; // put +ive on even index
         nums[i*2+1] = neg[i]; // put -Ive on odd index
      }
      int index = neg.size(); // put leftover elements
      for(int i = neg.size()*2; i < nums.size(); i++) {
         nums[i] = pos[index];
         index++;
      }
   } 
   else {
      for(int i = 0; i < pos.size(); i++) {
         nums[i*2] = pos[i];
         nums[i*2+1] = neg[i];
      }
      int index = pos.size();
      for(int i = pos.size()*2; i< nums.size(); i++) {
         nums[i] = neg[index];
         index++;
      }
   }

   return nums;
}

int main() {
   vector<int> nums = {-1, -2, 1, -3, -4, 2, 3, 4};
   vector<int> newNums = rearrangeElements(nums);

   for(auto x : newNums) {
      cout << x << "  ";
   }
   cout << endl;

   // variant 2
   vector<int> arr = {-60, -50, -40, -30, -20, -10, 1, 2, 3};
   vector<int> newArr = rearrangeArray(arr);

   for(auto x : newArr) {
      cout << x << "  ";
   }

   return 0;
}