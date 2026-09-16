#include <bits/stdc++.h>
using namespace std;
/* 
Rearrange Array Elements by Sign
Given an array with an equal number of positive and negative integers, rearrange so signs alternate, starting with positive, preserving relative order within each sign.
Input: nums = {3,1,-2,-5,2,-4}
*/
vector<int> rearrange(vector<int> &nums) {
   vector<int> result(nums.size());
   int pos = 0;
   int neg = 1;
   for(auto x : nums) {
      if(x > 0) {
         result[pos] = x;
         pos += 2;
      }
      else {
         result[neg] = x;
         neg += 2;
      }
   }

   return result;
}

vector<int> rearrange2(vector<int> &nums) {
   vector<int> pos;
   vector<int> neg;

   // put positive & negative in separate arrays
   for(auto x : nums) {
      if(x > 0) pos.push_back(x);
      else neg.push_back(x);
   }

   // put them in correct postions in original array
   // pos is smaller
   if(pos.size() < neg.size()) {
      for(int i = 0; i < pos.size(); i++) {
         nums[i*2] = pos[i];  // even index of nums
         nums[i*2+1] = neg[i];   // odd index of nums
      }
      // rest from the neg
      int ind = pos.size();
      for(int i = pos.size()*2; i < nums.size(); i++) {
         nums[i] = neg[ind++];
      }
   }
   // neg is smaller
   else {
      for(int i = 0; i < neg.size(); i++) {
         nums[i*2] = pos[i];  // even index of nums
         nums[i*2+1] = neg[i];   // odd index of nums
      }
      // rest from the pos
      int ind = neg.size();
      for(int i = neg.size()*2; i < nums.size(); i++) {
         nums[i] = pos[ind++];
      }
   }
   return nums;
}

int main() {
   // equal +ives & -ives
   vector<int> nums = {-1, -2, 1, -3, -4, 2, 3, 4};
   vector<int> result = rearrange(nums);
   for(auto x : result) {
      cout << x << " ";
   }
   cout << endl;

   // unequal 
   vector<int> nums2 = {-60, -50, -40, -30, -20, -10, 1, 2, 3};
   vector<int> result2 = rearrange2(nums2);
   for(auto x : result2) {
      cout << x << " ";
   }
   return 0;
}