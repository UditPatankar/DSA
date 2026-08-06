#include <bits/stdc++.h>
using namespace std;

// Leaders in array - everything to the right is smaller than it

// # Brute Force - TC: O(N^2) & SC: O(1)
/* vector<int> findLeader(vector<int> &nums) {
   vector<int> leaders;

   for(int i = 0; i < nums.size(); i++) {
     int isLeader = 1;
     for(int j = i+1; j < nums.size(); j++) {
         if(nums[j] > nums[i]) {
            isLeader = 0;
            break;
         }
     }
     if(isLeader) leaders.push_back(nums[i]);
   }

   return leaders;
} */

// # Better/Optimal - TC: O(N) & SC: O(N) including the op space otherwise it's O(1)
vector<int> findLeader(vector<int> &nums) {
   vector<int> leaders;
   int maxi = INT_MIN;
   
   for(int i = nums.size()-1; i >= 0; i--) {
      if(nums[i] > maxi) {
         maxi = nums[i];
         leaders.push_back(nums[i]);
      }
   }

   // return it in original order
   reverse(leaders.begin(), leaders.end());
   return leaders;
}

int main() {

   vector<int> nums = {21, 22, 12, 3, 0, 6, 5};
   vector<int> leaders = findLeader(nums);
   
   for(auto x : leaders) {
      cout << x << " ";
   }
   
   return 0;
}