#include <bits/stdc++.h>
using namespace std;

// given array nums, and integer val, you need to remove all the occurrences of val 
// and shift rest of the numbers on front and return the integer k (the number of elements not eqault to val)
// array size does not matter even if it stays same after removal of val.
// ex: {3,2,2,3} val=2, op should be 2 & array can be {3,3,_,_} does not matter what's at _,_

int removeElement(vector<int> &nums, int val){
   auto it1 = remove(nums.begin(), nums.end(), val); // it does not remove anything, it just shift "the duplicate" of elements that are not equal to 'val' at front
   
   int k = 0;
   auto it2 = nums.begin();

   while(it2 != nums.end()) {

      if(it2 == it1) break;
      k++;
      it2++;
   }

   return k;
}

int main() {
   vector<int> nums = {3,2,2,3,4,0,1,2};
   cout << removeElement(nums, 2) << endl;

   for(auto x : nums) {
      cout << x << " ";
   }

   return 0;
}