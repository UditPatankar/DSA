#include <bits/stdc++.h>
using namespace std;
/* 
Leaders in an Array
Find all elements that are greater than every element to their right.
Input: nums = {10,22,12,3,0,6}
*/
vector<int> findLeaders(const vector<int> &nums) {
   vector<int> leaders;
   int currentLeader = nums[nums.size()-1];
   leaders.push_back(currentLeader);

   for(int i = nums.size()-2; i >= 0; i--) {
      if(nums[i] > currentLeader) {
         currentLeader = nums[i];
         leaders.push_back(currentLeader);
      }
   }
   reverse(leaders.begin(), leaders.end());
   return leaders;
}

int main() {
   vector<int> nums = {10, 22, 12, 3, 0, 6};
   vector<int> leaders = findLeaders(nums);
   for(auto x : leaders) {
      cout << x << " ";
   }
   return 0;
}