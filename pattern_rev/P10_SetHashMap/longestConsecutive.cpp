#include <bits/stdc++.h>
using namespace std;
/* 
Longest Consecutive Sequence
Given an unsorted array, find the length of the longest sequence of consecutive integers.
Input: nums = {102, 4, 100, 1, 101, 3, 2, 1, 1}
*/
int longestConsecutive(vector<int> &nums) {
   if(nums.empty()) return 0;
   unordered_set<int> st;
   int longest = 1;  // longest so far
   for(auto x : nums) { st.insert(x); }
   
   for(auto num : st) {
      // check if num is start of any seq (no prev value for num)
      if(st.find(num-1) == st.end()) {
         int x = num; // start some seq
         int count = 1; // track this seq length

         while(st.find(x+1) != st.end()) {
            count++;
            x++;
         }
         longest = max(longest, count);
      }
   }
   return longest;
}
int main() {
   vector<int> nums = {102, 4, 100, 1, 101, 3, 2, 1, 1};
   int ans = longestConsecutive(nums);
   cout << ans << endl;
   return 0;
}