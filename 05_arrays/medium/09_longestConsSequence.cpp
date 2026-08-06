#include <bits/stdc++.h>
using namespace std;

// LONGEST CONSECUTIVE SEQUENCE - Google
// return the length 


// # Brute Force - TC: O(N^2) & SC: O(1)
/* int linearSearch(vector<int> a, int y) {
   int found = 0;
   for(int i = 0; i < a.size(); i++) {
      if(a[i] == y) {
         found = 1;
         break;
      }
   }

   return found;
}

int longestConsecutiveSequence(vector<int> &nums) {
   int n = nums.size();
   int longest = 1; 

   for(int i = 0; i < n; i++) {
      int x = nums[i];
      int count = 1;

      while(linearSearch(nums, x+1)) {
         count++;
         x = x+1;
      }

      longest = max(longest, count);
   }

   return longest;
}
 */

// Better - TC: O(N log N) & SC: O(1)
/* int longestConsecutiveSequence(vector<int> &nums) {
   int n = nums.size();
   if(n == 0) return 0;

   sort(nums.begin(), nums.end());

   int longest = 1;
   int count = 1;

   for(int i = 0; i < n-1; i++) {
      
      // skip duplicates 
      if(nums[i+1] == nums[i]) {
         continue;
      }

      // count consecutives - if next = current+1
      if(nums[i+1] == nums[i]+1) {
         count++;
      } 
      // break streak - sequence ended
      else {
         longest = max(longest, count);
         count = 1;
      }
   }

   return max(longest, count);
}
 */

// Optimal - TC: O(N) & SC: O(N)
int longestConsecutiveSequence(vector<int> &nums) {
   int n = nums.size();
   if(n == 0) return 0;
   unordered_set<int> st;

   for(auto x : nums) { // O(N)
      st.insert(x);
   }

   int longest = 1;

   for(auto it : st) { // O(N)
      
      // only if current el has no prev value in the set
      if(st.find(it - 1) == st.end()) {
         int x = it; // start of the sequence
         int count = 1;
         
         while(st.find(x+1) != st.end()) { // move till sequence ends
            count++;
            x = x+1;
         }

         // once sequence ends, check for longest
         longest = max(longest, count);
      }
   }   

   return longest;
}

// TC: the inner while loop only runs for the start of the sequence, it do not run for each iteration
// so in total the while loop runs is size of set (N in worst case)
// so in total the outer & inner loop runs is O(N) + O(N)

// because every element in the set gets visited by the inner while loop at most once, no matter which "start" triggered it. 
// So even though it's syntactically nested, you're not doing O(n) work for each outer iteration

int main() {

   vector<int> nums = {102, 4, 100, 1, 101, 3, 2, 1, 1};
   int ans = longestConsecutiveSequence(nums);
   cout << ans << endl;

   return 0;
}